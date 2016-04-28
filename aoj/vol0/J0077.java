import java.util.Scanner;

public class J0077{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){
			String str = sc.next();
			StringBuffer ans = new StringBuffer();
			int i=0;
			//System.out.println(str.length());
			
			while(i != str.length()){
				if(str.charAt(i) == '@'){
					++i;		
					char c = str.charAt(i);
					int k = Integer.parseInt(String.valueOf(c));
					//System.out.println("k=" +k);
					++i;
					c=str.charAt(i);	
					for(int j=0; j<k; j++){
						ans.append(c);
					}
					++i;
				}
				else{
					ans.append(str.charAt(i));
					++i;
				}
			
			}
			System.out.println(ans);	
		}
	
	}
}