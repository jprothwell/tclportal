package junit.inter;

public interface RequestHandler {
	
	Response process(Request request) throws Exception;
}
