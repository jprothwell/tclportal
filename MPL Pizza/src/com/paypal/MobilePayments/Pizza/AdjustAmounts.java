package com.paypal.MobilePayments.Pizza;
import java.io.Serializable;
import java.text.DecimalFormat;

import com.paypal.android.MEP.MEPAddress;
import com.paypal.android.MEP.PaymentAdjuster;
import com.paypal.android.MEP.MEPAmounts;

public class AdjustAmounts implements PaymentAdjuster, Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1423827998570968857L;

	public MEPAmounts adjustAmount(MEPAddress address, String currency, float amount, float tax, float shipping) {
		MEPAmounts amounts = new MEPAmounts();
		
		//demo adjust amounts implementation that makes the tax 10% of the amount if 
		//the state is California, 8% otherwise, and leaves the rest the same
		amounts.setCurrency(currency);
		amounts.setPaymentAmount(amount);
		
		//make sure we do the null checks on the state string...
		if (address.getState() != null && address.getState().length() > 0 && address.getState().indexOf("CA") > -1) {
			float taxAmount = amount * .1f;
			DecimalFormat twoDForm = new DecimalFormat("#.##");
			amounts.setTax(Float.valueOf(twoDForm.format(taxAmount)));
		}
		else {
			float taxAmount = amount * .08f;
			DecimalFormat twoDForm = new DecimalFormat("#.##");
			amounts.setTax(Float.valueOf(twoDForm.format(taxAmount)));
		}
		amounts.setShipping(shipping);
			
		return amounts;
	}
}
