import java.util.Scanner;

public class J0219{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		while(true){
			StringBuffer[] ice = new StringBuffer[10];
		
			int n = sc.nextInt();
			if(n==0) break;
		
			for(int i=0; i<10; i++)
				ice[i] = new StringBuffer("-");
			
			for(int i=0; i<n; i++){
				int a = sc.nextInt();
				
				if(ice[a].toString().equals("-")){
					ice[a].delete(0,1);
					ice[a].append("*");
				}
				else{
					ice[a].append("*");
				}
			}
		
			for(int i=0; i<10; i++)
				System.out.println(ice[i]);
		}
		
	
	}
}