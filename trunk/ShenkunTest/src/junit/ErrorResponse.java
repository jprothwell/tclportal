package junit;

import junit.inter.Request;
import junit.inter.Response;

public class ErrorResponse implements Response{
	
	private Request originalReqeust;
	
	private Exception originalException;
	
	public ErrorResponse(Request request,Exception ex){
		this.originalReqeust = request;
		this.originalException = ex;
	}
	public Request getOriginalRequest(){
		return this.originalReqeust;
	}
	public Exception getOriginalException(){
		return this.originalException;
	}

}
