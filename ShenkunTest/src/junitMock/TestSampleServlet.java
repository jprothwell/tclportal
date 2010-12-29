package junitMock;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

import junit.framework.TestCase;

public class TestSampleServlet extends TestCase{
	
	private SampleServlet servlet;
	
	private MockControl controlHttpServlet;
	
	private HttpServletRequest mockHttpHttpServletRequest;
	
	private MockControl controlHttpSession;
	
	private HttpSession mockHttpSession;
	
	protected void setUp(){
		servlet = new SampleServlet();
	
	}
}
