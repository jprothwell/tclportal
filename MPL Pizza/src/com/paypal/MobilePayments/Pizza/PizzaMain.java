package com.paypal.MobilePayments.Pizza;


import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Currency;
import java.util.Locale;

import com.paypal.android.MEP.CheckoutButton;
import com.paypal.android.MEP.PayPal;
import com.paypal.android.MEP.PayPalActivity;
import com.paypal.android.MEP.PayPalPayment;
import com.paypal.MobilePayments.Pizza.AdjustAmounts;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.DialogInterface.OnDismissListener;
import android.content.DialogInterface.OnMultiChoiceClickListener;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup.LayoutParams;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.RelativeLayout;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.AdapterView.OnItemSelectedListener;

public class PizzaMain extends Activity implements OnClickListener, OnItemSelectedListener, OnMultiChoiceClickListener, OnDismissListener {
    /** Called when the activity is first created. */
	
	final static public int PAYPAL_BUTTON_ID = 10001;
	
	//So we can easily reference the different sizes and delivery methods
	final static public int SIZE_SMALL = 0;
	final static public int SIZE_MEDIUM = 1;
	final static public int SIZE_LARGE = 2;
	
	final static public int METHOD_PICKUP = 0;
	final static public int METHOD_DELIVERY = 1;
	
	private int _size = SIZE_SMALL;
	private int _number = 1;
	private int _method = METHOD_PICKUP;
	
	//Local references to our amounts and description
	private double _theSubtotal;
	private double _taxAmount;
	private String _pizzaDescription;
	
	//All the booleans we will use -- what toppings, whether the payment was already started,
	//and whether the PayPal Library was initialized
	private boolean _cheese = false;
	private boolean _pepperoni = false;
	private boolean _mushrooms = false;
	private boolean _onions = false;
	private boolean _launchedPayment = false;
	private boolean _paypalLibraryInit = false;
	
	//Static instance of PayPal
	private static PayPal ppObj;
	
	//Lets us keep a reference to the "Pay with PayPal" button
	private CheckoutButton _launchPayPalButton;
	
	//Reference to our number formatter (used for to format the amounts)
	private NumberFormat _df;
	
	//Keeps a reference to the progress dialog 
	private ProgressDialog _progressDialog;

	//The runnables are declared so we can make sure they are run on whatever thread we want
	
	//This lets us show the PayPal Button after the library has been initialized
    final Runnable showPayPalButtonRunnable = new Runnable() {
        public void run() {
            showPayPalButton();
        }
    };
    
    //This lets us run a loop to check the status of the PayPal Library init
    final Runnable checkforPayPalInitRunnable = new Runnable() {
        public void run() {
            checkForPayPalLibraryInit();
        }
    };
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        loadMainPage();
    }
    
    public void loadMainPage() {
        setContentView(R.layout.main);
        
        //do the setup for the Home page -- add the Pay button
        findViewById(R.id.Buy).setOnClickListener(this);
    }

    public void loadCustomizePage() {
    	setContentView(R.layout.customize);
    	//set up the spinner for the Pizza sizes
    	
    	Spinner sizeSpinner = (Spinner) findViewById(R.id.Spinner01);
    	sizeSpinner.setPrompt("Select a size");
        ArrayAdapter <CharSequence> sizeAdapter;
		sizeAdapter = new ArrayAdapter <CharSequence> (this, android.R.layout.simple_spinner_item);
        sizeAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
		sizeAdapter.add("Small ($7.99)");
		sizeAdapter.add("Medium ($9.99)");
		sizeAdapter.add("Large ($11.99)");
		sizeSpinner.setAdapter(sizeAdapter);
		sizeSpinner.setOnItemSelectedListener(this);
		sizeSpinner.setSelection(_size);
	
		//Set up the click listeners for the buttons
		findViewById(R.id.Button03).setOnClickListener(this);
		findViewById(R.id.Continue).setOnClickListener(this);
		
		//Start the PayPal Library initialization
		startPayPalInit();
    }
    
    public void loadFinalizePage() {
    	setContentView(R.layout.finalize);
    	
    	//Set up the finalize page
       	Spinner numberSpinner = (Spinner) findViewById(R.id.Spinner02);
       	numberSpinner.setPrompt("Select number of pizzas");
        ArrayAdapter <CharSequence> numberAdapter;
        numberAdapter = new ArrayAdapter <CharSequence> (this, android.R.layout.simple_spinner_item);
        numberAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        numberAdapter.add("One");
        numberAdapter.add("Two");
        numberAdapter.add("Three");
		numberSpinner.setAdapter(numberAdapter);
		numberSpinner.setOnItemSelectedListener(this);
		numberSpinner.setSelection(_number - 1);
		
      	Spinner methodSpinner = (Spinner) findViewById(R.id.Spinner03);
      	methodSpinner.setPrompt("Select method");
        ArrayAdapter <CharSequence> methodAdapter;
        methodAdapter = new ArrayAdapter <CharSequence> (this, android.R.layout.simple_spinner_item);
        methodAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        methodAdapter.add("Pickup");
        methodAdapter.add("Delivery");
        methodSpinner.setAdapter(methodAdapter);
        methodSpinner.setOnItemSelectedListener(this);
        methodSpinner.setSelection(_method);
		
    	findViewById(R.id.ReviewOrder).setOnClickListener(this);
    }
    
    public void loadReviewPage() {
    	setContentView(R.layout.review);
    	
    	//Do all our setup of the Review page
    	
    	//Set up our DecimalFormatter for our amounts
    	_df = (DecimalFormat)DecimalFormat.getCurrencyInstance(Locale.ENGLISH);
    	_df.setCurrency(Currency.getInstance("USD"));
    	String size = "Small";
    	switch (_size) {
    	case SIZE_SMALL: size = "Small"; break;
    	case SIZE_MEDIUM: size = "Medium"; break;
    	case SIZE_LARGE: size = "Large"; break;
    	}
    	
    	//Set up all the Pizza-related strings
    	_pizzaDescription = _number + " " + size + " Pizzas";
    	if (_number == 1) {
    		_pizzaDescription = _number + " " + size + " Pizza";
    	}
    	
    	((TextView) findViewById(R.id.NumberOfPizzas)).setText(_pizzaDescription);
    	double priceAmount = 7.99;
    	String price = "7.99";
    	if (_number == 1) {
    		if (_size == SIZE_SMALL) {
    			price = "7.99";
    			priceAmount = 7.99;
    		} else if (_size == SIZE_MEDIUM) {
    			price = "9.99";
    			priceAmount = 9.99;
    		} else {
    			price = "11.99";
    			priceAmount = 11.99;
    		}
    	}
    	if (_number == 2) {
    		if (_size == SIZE_SMALL) {
    			price = "9.99";
    			priceAmount = 9.99;
    		} else if (_size == SIZE_MEDIUM) {
    			price = "15.99";
    			priceAmount = 15.99;
    		} else {
    			price = "19.99";
    			priceAmount = 19.99;
    		}
    	}
    	else if (_number == 3) {
    		if (_size == SIZE_SMALL) {
    			price = "11.99";
    			priceAmount = 11.99;
    		} else if (_size == SIZE_MEDIUM) {
    			price = "20.99";
    			priceAmount = 20.99;
    		} else {
    			price = "25.99";
    			priceAmount = 25.99;
    		}
    	}
    	
    	((TextView) findViewById(R.id.Price)).setText("$" + price);
    	
    	//hide toppings, if they're not used
    	if (!_cheese) {
    		((TextView) findViewById(R.id.ExtraCheesePrice)).setText("$0.00");
    	}
    	if (!_pepperoni) {
    		((TextView) findViewById(R.id.PepperoniPrice)).setText("$0.00");
    	}
    	if (!_mushrooms) {
    		((TextView) findViewById(R.id.MushroomsPrice)).setText("$0.00");
    	}
    	if (!_onions) {
    		((TextView) findViewById(R.id.OnionsPrice)).setText("$0.00");
    	}
    	
    	if (_cheese) {
    		priceAmount += 2.00;
    	}
    	if (_pepperoni) {
    		priceAmount += 2.00;
    	}
    	if (_mushrooms) {
    		priceAmount += 2.00;
    	}
    	if (_onions) {
    		priceAmount += 2.00;
    	}
    	
    	_theSubtotal = priceAmount;//saving this here so we can access it later
    	((TextView) findViewById(R.id.SubtotalPrice)).setText(_df.format(priceAmount));
    	if (_method == METHOD_PICKUP) {
    		((TextView) findViewById(R.id.DeliveryFeePrice)).setText("$0.00");
    		((TextView) findViewById(R.id.MethodType)).setText("Pick Up");
    	}
    	else {
    		priceAmount += 2.00;
    	}
    	//to account for tax
    	_taxAmount = priceAmount * .08;
    	priceAmount += _taxAmount;
    	((TextView) findViewById(R.id.TaxPrice)).setText(_df.format(_taxAmount));
    	((TextView) findViewById(R.id.TotalPrice)).setText(_df.format(priceAmount));
    	    	
    	//Check if the PayPal Library has been initialized yet. If it has, show the "Pay with PayPal button"
    	//If not, show a progress indicator and start a loop that keeps checking the init status
    	if (_paypalLibraryInit) {
    		((RelativeLayout) findViewById(R.id.RelativeLayout01)).addView(_launchPayPalButton);    		
       		((RelativeLayout) findViewById(R.id.RelativeLayout01)).setGravity(Gravity.CENTER_HORIZONTAL);
    	}
    	else {
        	//Display a progress dialog to the user and start checking for when the initialization is completed
        	_progressDialog = new ProgressDialog( this );
        	_progressDialog.setProgressStyle(ProgressDialog.STYLE_SPINNER);
        	_progressDialog.setMessage("Loading PayPal Payment Library");
        	_progressDialog.setCancelable(false);
        	_progressDialog.show();	
        	Thread newThread = new Thread(checkforPayPalInitRunnable);
        	newThread.start();
    	}
    }
    
    public void loadResultsPage() {
    	setContentView(R.layout.results);
    	
		//Set up the click listeners for the buttons
		findViewById(R.id.BuyMore).setOnClickListener(this);
		findViewById(R.id.Done).setOnClickListener(this);
    }
    
    //This method is called if the Review page is being loaded but the PayPal Library is not
    //initialized yet. 
    private void checkForPayPalLibraryInit() {
    	//Loop as long as the library is not initialized
    	while (_paypalLibraryInit == false) {
    		try {
    			//wait 1/2 a second then check again
				Thread.sleep(500);
			} catch (InterruptedException e) {
				//Show an error to the user
				AlertDialog.Builder builder = new AlertDialog.Builder(this);
				builder.setMessage("Error initializing PayPal Library")
				       .setCancelable(false)
				       .setPositiveButton("OK", new DialogInterface.OnClickListener() {
				           public void onClick(DialogInterface dialog, int id) {
				               //Could do anything here to handle the error
				           }
				       });
				AlertDialog alert = builder.create();
				alert.show();
			}
    	}
    	//If we got here, it means the library is initialized.
    	//So, add the "Pay with PayPal" button to the screen
    	runOnUiThread(showPayPalButtonRunnable);
    }
    
	@Override
	public void onClick(View arg0) {
		if (arg0 == (Button)findViewById(R.id.Buy)) {
			//load the Customize page when the Buy button is clicked
			loadCustomizePage();
		}
		else if (arg0 == (Button)findViewById(R.id.Button03)) {
			//Shows the pop-up where the user can select toppings
			((Button)findViewById(R.id.Continue)).setVisibility(View.GONE);
			final CharSequence[] items = {"Extra Cheese", "Pepperoni", "Mushrooms", "Onions"};

			AlertDialog.Builder builder = new AlertDialog.Builder(this);
			builder.setTitle("Choose your toppings");
			boolean[] myBools = {_cheese, _pepperoni, _mushrooms, _onions};
			builder.setMultiChoiceItems(items, myBools, this);
			builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.dismiss();
				}
			});
			AlertDialog alert = builder.create();
			alert.setOnDismissListener(this);
			alert.show();
		}
		else if (arg0 == (Button)findViewById(R.id.Continue)) {
			loadFinalizePage();
		}
		else if (arg0 == (Button)findViewById(R.id.ReviewOrder)) {
			loadReviewPage();
		}
		else if (arg0 == (Button)findViewById(R.id.BuyMore)) {
			loadMainPage();
		}
		else if (arg0 == (Button)findViewById(R.id.Done)) {
			finish();
		}
		else if (arg0 == (CheckoutButton)findViewById(PAYPAL_BUTTON_ID)) {
			//Using _launchedPayment to make sure we don't launch the PayPal Library activity twice,
			//if the user repeatedly presses the "Pay with PayPal" button
			if (_launchedPayment == false) {
		    	_launchedPayment = true;
		    	//When the user presses the 'Pay with PayPal' button, set up the new payment
		    	PayPalPayment newPayment = new PayPalPayment();
		    	String subTotalString = _df.format(_theSubtotal);
		    	subTotalString = subTotalString.replace("$", "");
		    	
		    	//Set the payment amount
		    	newPayment.setAmount(subTotalString);
		    	String taxString = _df.format(_taxAmount);
		    	taxString = taxString.replace("$","");
		    	
		    	//Set the payment tax amount
		    	newPayment.setTax(taxString);
		    	if (_method == METHOD_DELIVERY) {
		    		newPayment.setShipping("2.00");
		    		//Forces the user to go to the review page
		    		ppObj.setShippingEnabled(true);
		    	}
		    	
		    	//Set the payment currency
		    	newPayment.setCurrency("USD");
		    	
		    	//Set the recipient. This is the account that will receive the payment
		    	newPayment.setRecipient("us_biz_1183069476_biz@paypal.com");
		    	
		    	//Sets the merchant name that is displayed to the end-user
		    	newPayment.setMerchantName("Pizza Express");
		    	
		    	//Sets the item description that is displayed by the user
		    	newPayment.setItemDescription(_pizzaDescription);
		    	
		    	//Set up the PayPal intent 
		    	Intent payPalIntent = new Intent(this, PayPalActivity.class);
		    	
		    	//Put in the payment object
		    	payPalIntent.putExtra(PayPalActivity.EXTRA_PAYMENT_INFO, newPayment);
				AdjustAmounts adjustClass = new AdjustAmounts();
				
				//Put in the Adjust Amounts class (this is used when the user selects an address,
				//to adjust the shipping amount or tax based on the user's address
				payPalIntent.putExtra(PayPalActivity.EXTRA_PAYMENT_ADJUSTER, adjustClass);
				
				//Start the PayPal Library activity
		    	this.startActivityForResult(payPalIntent, 1);
			}
		}
	}

	@Override
	public void onItemSelected(AdapterView<?> arg0, View arg1, int arg2,
			long arg3) {
		//Lets us track the spinner view 
		if (arg0 == findViewById(R.id.Spinner01)) {
			_size = arg2;//0 is small, 1 is medium, 2 is large
		} else if (arg0 == findViewById(R.id.Spinner02)) {
			_number = arg2 + 1;
		} else if (arg0 == findViewById(R.id.Spinner03)) {
			_method = arg2;
		}
		
	}

	@Override
	public void onNothingSelected(AdapterView<?> arg0) {
		// TODO Auto-generated method stub
	}

	@Override
	public void onClick(DialogInterface arg0, int arg1, boolean arg2) {
		//this is the topping selector
		if (arg1 == 0) {
			_cheese = arg2;
		} else if (arg1 == 1) {
			_pepperoni = arg2;
		} else if (arg1 == 2) {
			_mushrooms = arg2;
		} else {
			_onions = arg2;
		}
	}
	
	//PayPal Activity Results. This handles all the responses from the PayPal Payments Library
	@Override
	public void onActivityResult(int requestCode, int resultCode, Intent data) {
		//Reset the _launchedPayment variable so the user can press "Pay with PayPal" again
		_launchedPayment = false;

		//Avoid an exception for setting a parent more than once
		if(_launchPayPalButton != null) {
			((RelativeLayout) findViewById(R.id.RelativeLayout01)).removeView(_launchPayPalButton);		
		}
		
		if (requestCode != 1) {//We called "startActivityForResult" with resultCode of 1, so 
			//only handle where requestCode = 1
			return;
		}
		
		switch(resultCode) {
		case Activity.RESULT_OK:
			//The payment succeeded
			String transactionID = data.getStringExtra(PayPalActivity.EXTRA_TRANSACTION_ID);
			this.paymentSucceeded(transactionID);
			break;
		case Activity.RESULT_CANCELED:
			//The payment was canceled
			this.paymentCanceled();
			break;
		case PayPalActivity.RESULT_FAILURE:
			//The payment failed -- we get the error from the EXTRA_ERROR_ID and EXTRA_ERROR_MESSAGE
			String errorID = data.getStringExtra(PayPalActivity.EXTRA_ERROR_ID);
			String errorMessage = data.getStringExtra(PayPalActivity.EXTRA_ERROR_MESSAGE);
			this.paymentFailed(errorID, errorMessage);
		}
	}
	
    public void paymentSucceeded(String transactionID){
    	//We could show the transactionID to the user
		loadResultsPage();
		((TextView)findViewById(R.id.ResultsTitle)).setText("Success!");
		if(_method == METHOD_PICKUP) {
			((TextView)findViewById(R.id.ResultsText1)).setText("Your order is being prepared!");
		} else if(_method == METHOD_DELIVERY) {
			((TextView)findViewById(R.id.ResultsText1)).setText("Your order is on its way!");
		}
		((TextView)findViewById(R.id.ResultsText2)).setText("Estimated time: 30 minutes.");
		((TextView)findViewById(R.id.ResultsText3)).setText("Transaction ID: " + transactionID);
    }	
	
	public void paymentFailed(String errorID, String errorMessage){
		//We could let the user know the payment failed here
		loadResultsPage();
		((TextView)findViewById(R.id.ResultsTitle)).setText("Failure!");
		((TextView)findViewById(R.id.ResultsText1)).setText("We're sorry, but your payment failed.");
		((TextView)findViewById(R.id.ResultsText2)).setText("Error: " + errorMessage);
		((TextView)findViewById(R.id.ResultsText3)).setText("Error ID: " + errorID);
    }
	    
    public void paymentCanceled(){
    	//We could tell the user that the payment was canceled
		loadResultsPage();
		((TextView)findViewById(R.id.ResultsTitle)).setText("Canceled.");
		((TextView)findViewById(R.id.ResultsText1)).setText("Your payment has been canceled.");
		((TextView)findViewById(R.id.ResultsText2)).setText("Your account was not charged.");
		((TextView)findViewById(R.id.ResultsText3)).setText("");
    }
    
    protected void startPayPalInit() {
        // Fire off a thread to do some work that we shouldn't do directly in the UI thread
        Thread t = new Thread() {
            public void run() {
                initPayPal();
            }
        };
        t.start();
    }
	    
	@Override
	public void onDismiss(DialogInterface arg0) {
		findViewById(R.id.Continue).setVisibility(View.VISIBLE);	
	}
	
   private void showPayPalButton() {
       // Back in the UI thread -- show the "Pay with PayPal" button
   		((RelativeLayout) findViewById(R.id.RelativeLayout01)).addView(_launchPayPalButton);
   		((RelativeLayout) findViewById(R.id.RelativeLayout01)).setGravity(Gravity.CENTER_HORIZONTAL);
   		_progressDialog.dismiss();   
   }
   
   private void initPayPal() {
	   	//Initialize the PayPal Library -- this is happening in a background thread
	   	
	   	//Passing through the app id and the server (Sandbox in this case)
	   	if(ppObj == null) {
	   		ppObj = PayPal.initWithAppID(this.getBaseContext(), "APP-80W284485P519543T", PayPal.ENV_SANDBOX);
	   	} else {
	   		ppObj = PayPal.getInstance();
	   	}
	   	
	   	//Set the language
	   	ppObj.setLang("en_US");
	   	
	   	//Set whether shipping is enabled. If shipping is enabled, the user will be shown the shipping
	   	//address and get a chance to change to a different shipping address
	   	ppObj.setShippingEnabled(_method == METHOD_PICKUP ? false : true);
	   	
	   	//Enabling dynamic amount calculation will let us modify the tax and shipping amount
	   	//based on the address the user chose. If we enable this, we must be sure to
	   	//pass through our "AdjustAmounts" class to the PayPal Library activity 
	   	ppObj.enableDynamicAmountCalculation();
	    	
	   	//Get the "Pay with PayPal button" -- it will be added to the screen later
	   	_launchPayPalButton = ppObj.getPaymentButton(PayPal.BUTTON_278x43, this, PayPal.PAYMENT_TYPE_HARD_GOODS);
	   	RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);
	   	params.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
	   	params.bottomMargin = 10;
	   	_launchPayPalButton.setLayoutParams(params);
	   	_launchPayPalButton.setId(PAYPAL_BUTTON_ID);
	   	_launchPayPalButton.setOnClickListener(this);
	  	_paypalLibraryInit = true;//the PayPal Library is initialized, set the boolean to true
	}
}