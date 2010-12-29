package junit;

import junit.framework.TestCase;
import junit.inter.Request;
import junit.inter.RequestHandler;
import junit.inter.Response;

public class TestDefaultController extends TestCase{
	
	private DefaultController controller;
	
	protected void setUp() throws Exception{
		controller = new DefaultController();
	}
	
	public void testMethod(){
		throw new RuntimeException("implement me");
	}
	
	public void testProcessRequest(){
		Request reqeust = new TestRequest();
	}
	public void testProcessRequestAnswersErrorResponse(){
		TestRequest request = new TestRequest("testError");
		TestExceptionHandle handler = new TestExceptionHandle();
		controller.addHandler(request, handler);
		Response response = controller.processRequest(request);
		assertNotNull("",response);
		assertEquals(ErrorResponse.class,response.getClass());
	}
	
	private class TestExceptionHandle implements RequestHandler{
		public Response process(Request request) throws Exception{
			throw new Exception("error processing request");
		}
	}
	private class TestRequest implements Request{
		
		private static final String DEFAULT_NAME = "default name";
		
		private String name;
		
		public TestRequest(String name){
			this.name = name;
		}
		
		public TestRequest(){
			this(DEFAULT_NAME);
		}
		public String getName() {
			return this.name;
		}
		
	}
}

