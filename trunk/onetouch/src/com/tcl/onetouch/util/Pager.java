package com.tcl.onetouch.util;

import java.util.ArrayList;
import java.util.List;

public class Pager<E>
{

	public static final int PAGE_LEN = 5;

	private int pageNo = 1;// ��ǰҳ��

	private int entryCount;// ��¼����

	private int pageSize = 20;// һҳ��ʾ��¼����

	private String requestUrl;

	@SuppressWarnings("unchecked")
	private List datas;

	private E condition;

	public E getCondition()
	{
		return condition;
	}

	public void setCondition(E condition)
	{
		this.condition = condition;
	}

	public Pager()
	{
	}

	public Pager(String requestUrl, int pageNo, int pageSize)
	{
		setRequestUrl(requestUrl);
		pageSize = pageSize <= 0 ? 20 : pageSize;
		pageNo = (pageNo < 1) ? 1 : pageNo;
		setPageNo(pageNo);
		setPageSize(pageSize);
	}

	public List<Integer> getPrePageNos()
	{
		List<Integer> ret = new ArrayList<Integer>();

		int maxPageNum = getMaxPageNo();
		int firstPageNum = getFirstPageNo();

		int len = PAGE_LEN * 2;
		int preNum = pageNo - PAGE_LEN;
		int nextNum = pageNo + PAGE_LEN;
		if (preNum < firstPageNum)
		{
			preNum = firstPageNum;
			nextNum = preNum + len;
		}

		if (nextNum > maxPageNum)
		{
			nextNum = maxPageNum;
			preNum = nextNum - len;
		}
		preNum = preNum < firstPageNum ? firstPageNum : preNum;

		for (int i = preNum; i < pageNo; i++)
		{
			ret.add(i);
		}

		return ret;
	}
	
	public List<Integer> getPrePageNums()
	{
		List<Integer> ret = new ArrayList<Integer>();
		int maxPageNum = getMaxPageNo();
		if(PAGE_LEN > maxPageNum)
		{
			for(int i =1 ; i <= maxPageNum;i++)
				ret.add(i);
			return ret;
		}
		else
		{
			int mid = PAGE_LEN/2;
			if(pageNo<mid)
			{
				for(int i =1 ; i <=PAGE_LEN ;i++)
					ret.add(i);
				return ret;
			}
			else if((maxPageNum - pageNo)<mid)
			{
				
			}
			else
			{
				
			}
		}
		
		return null;
	}
	
	public  List<Integer> getPageNumbers()
	 {
		List<Integer> ret = new ArrayList<Integer>();
		if(entryCount==0) 
		{
			return ret;
		}
		int maxPageNum = getMaxPageNo();
		if(PAGE_LEN >= maxPageNum)
		{
			for(int i =1 ; i <= maxPageNum;i++)
				ret.add(i);
			return ret;
		}
		else
		{
			int mid = PAGE_LEN/2;
			if(pageNo<=mid)
			{
				for(int i =1 ; i <=PAGE_LEN ;i++)
				{
					ret.add(i);
				}
				if((maxPageNum-PAGE_LEN)>1)
				{
					ret.add(-1);//��ʾ...
				}
				ret.add(maxPageNum);//���ҳ����?
				return ret;
			}
			else if((maxPageNum - pageNo)<=mid)
			{
				ret.add(1);//��һҳ
				if((maxPageNum - PAGE_LEN)>2)
				{
					ret.add(-1);//��ʾ...
				}
				for(int i=maxPageNum - PAGE_LEN;i<=maxPageNum;i++)
				{
					if(i>1)
					{
						ret.add(i);
					}
				}
				return ret;
			}
			else
			{
				ret.add(1);
				if((pageNo - mid)>2)
				{
					ret.add(-1);//��ʾ...
				}
				for(int i=pageNo - mid;i<=pageNo+mid;i++)
				{
					if(i>1)
					{
						ret.add(i);
					}
				}
				if((maxPageNum - (pageNo+mid))>2)
				{
					ret.add(-1);//��ʾ...
				}
				ret.add(maxPageNum);
				
				return ret;
			}
		}
	 }

	public List<Integer> getNextPageNos()
	{
		List<Integer> ret = new ArrayList<Integer>();

		int maxPageNum = getMaxPageNo();
		int firstPageNum = getFirstPageNo();

		int len = PAGE_LEN * 2;
		int preNum = pageNo - PAGE_LEN;
		int nextNum = pageNo + PAGE_LEN;
		if (preNum < firstPageNum)
		{
			preNum = firstPageNum;
			nextNum = preNum + len;
		}

		if (nextNum > maxPageNum)
		{
			nextNum = maxPageNum;
			preNum = nextNum - len;
		}
		preNum = preNum < firstPageNum ? firstPageNum : preNum;

		for (int i = pageNo + 1; i <= nextNum; i++)
		{
			ret.add(i);
		}

		return ret;
	}

	public int getFirstResult()
	{
		return pageSize * (pageNo - 1);
	}

	public int getPageSize()
	{
		return pageSize;
	}

	public void setPageSize(int pageSize)
	{
		this.pageSize = pageSize;
	}

	public int getPageNo()
	{
		return pageNo;
	}

	public void setPageNo(int num)
	{
		pageNo = num;
	}

	public int getEntryCount()
	{
		return entryCount;
	}

	public void setEntryCount(int entryCount)
	{
		this.entryCount = entryCount;
	}

	public int getFirstPageNo()
	{
		return 1;
	}

	public int getPrePageNo()
	{
		if (pageNo <= 1)
		{
			return 1;
		} else
		{
			return pageNo - 1;
		}
	}

	public int getNextPageNo()
	{
		int nextPageNum = pageNo + 1;
		int maxPageNum = getMaxPageNo();
		nextPageNum = nextPageNum > maxPageNum ? maxPageNum : nextPageNum;
		return nextPageNum;
	}

	public int getMaxPageNo()
	{
		int maxPageNum = entryCount / pageSize;
		int m = entryCount % pageSize;
		if (m != 0)
		{
			maxPageNum++;
		}
		return maxPageNum;
	}

	public String getRequestUrl()
	{
		return requestUrl;
	}

	public void setRequestUrl(String requestUrl)
	{
		this.requestUrl = requestUrl;
	}

	@SuppressWarnings("unchecked")
	public List getDatas()
	{
		return datas;
	}

	@SuppressWarnings("unchecked")
	public void setDatas(List datas)
	{
		this.datas = datas;
	}

	public void addParam(String name, String value)
	{
		requestUrl += ("&" + name + "=" + value);
	}
}
