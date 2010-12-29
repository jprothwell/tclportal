import java.util.ArrayList;
import java.util.List;


public class ListTest2 {

	public static List getList() {
		List list = new ArrayList();
		list.add("中国人");
		list.add("中国");
		for(int i=0;i<list.size();i++){
			for(int j=0;j<list.size();j++){
				boolean b = list.get(j).toString().indexOf(list.get(i).toString())!=-1;
				if(i!=j&&b){
					list.remove(list.get(i));
				}
			}
		}
		return list;
	}
}
