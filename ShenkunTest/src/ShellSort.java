
public class ShellSort {
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int[] as = {3,7,9,2,8,6};
		int h = 0;
		while(h<as.length){
			h = 3*h+1;
		}
		
		while(h>0){
			int out,in;
			for(out=1;out<as.length;out++){
				int temp = as[out];
				in = out;
				while(in>h-1&&as[in-h]>=temp){
					as[in] = as[in-h];
					in = in - h;
				}
				as[in] = temp;
			}
			h = (h-1)/3;
		}
		
		for(int i:as){
			System.out.print(i);
		}
	}

}
