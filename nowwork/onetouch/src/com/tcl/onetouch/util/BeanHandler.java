package com.tcl.onetouch.util;



import java.beans.BeanInfo;
import java.beans.IntrospectionException;
import java.beans.Introspector;
import java.beans.PropertyDescriptor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;


/**
 * POJO������
 * ��������ͬʱ����getter && setter����,����ΪPUBLIC����
 * @author ibmsz
 *
 */

public class BeanHandler
{
	
	/**
	 * ��ȡ����
	 * @param obj
	 * @return
	 */
	public static Map<String, Object> getPropertyValueMap(Object obj)
	{
		Map<String,Object> ret = new HashMap<String,Object>();
		
		BeanInfo info = null;
		try
		{
			info = Introspector.getBeanInfo(obj.getClass());
		} catch (IntrospectionException e)
		{
			throw new RuntimeException(e);
		}
		
		PropertyDescriptor[] ds = info.getPropertyDescriptors();
		for(PropertyDescriptor d : ds)
		{
			Method rMethod = d.getReadMethod();
			Method wMethod = d.getWriteMethod();
			if(rMethod == null || wMethod == null)
			{
				continue;
			}
			if(Modifier.isPublic(rMethod.getModifiers()) && Modifier.isPublic(wMethod.getModifiers()))
			{
				String name = d.getName();
				//��ȡֵ
				Object value = null;
				try
				{
					value = rMethod.invoke(obj, null);
				} catch (IllegalArgumentException e)
				{
					throw new RuntimeException(e);
				} catch (IllegalAccessException e)
				{
					throw new RuntimeException(e);
				} catch (InvocationTargetException e)
				{
					throw new RuntimeException(e);
				}
				ret.put(name, value);
			}
		}
		return ret;
	}
	
	public static Map<String,String> getStringPropertyValueMap(Object obj)
	{
		if(obj == null)
		{
			return null;
		}
		Map<String,Object> vm = getPropertyValueMap(obj);
		Map<String,String> ret = new HashMap<String,String>();
		Set<String> ks = vm.keySet();
		for(String k : ks)
		{
			Object v = vm.get(k);
			if(v != null)
			{
				ret.put(k, v.toString());
			}else
			{
				ret.put(k, null);
			}
		}
		return ret;
	}
}
