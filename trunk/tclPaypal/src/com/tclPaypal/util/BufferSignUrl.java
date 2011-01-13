package com.tclPaypal.util;

import com.tclPaypal.domain.Business;

public class BufferSignUrl {

	public static String getSignUrl(Business business) {
		StringBuilder sb = new StringBuilder();
		sb.append("status=ok&tradeId=");
		sb.append(business.getOrdernum());
		return sb.toString();
	}

}
