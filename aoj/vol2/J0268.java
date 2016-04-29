import java.util.Scanner;
import java.math.BigDecimal;

public class J0268{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long q = sc.nextLong();
		
		for(long z=0; z<q; z++){
			String str = sc.next();
			int[] a = new int[8];
		
			for(int i=0; i<8; i++){
				if(str.charAt(i) >= 'a'){
					a[i] = (int)str.charAt(i) - 'a' + 10;
				}
				else{
					a[i] = Integer.parseInt(str.charAt(i) + "");
				}
				//System.out.println(a[i]);
			}
		
			StringBuffer sb = new StringBuffer();
			for(int i=0; i<8; i++){
				sb.append(a[i]/8);
				if(a[i]/8>0) a[i]-=8;
				sb.append(a[i]/4);
				if(a[i]/4>0) a[i]-=4;
				sb.append(a[i]/2);
				if(a[i]/2>0) a[i]-=2;
				sb.append(a[i]/1);
			}			
		
			//System.out.println(sb);
			
			int minus=0;
			BigDecimal ans = new BigDecimal("0");
			
			if(sb.charAt(0)=='1') minus=1;
			
			for(int i=1; i<32; i++){
				if(sb.charAt(i)=='1'){
					BigDecimal tnp = new BigDecimal(Math.pow(2.0, 24-i));
					ans = ans.add( tnp );
				}
			}
			
			if(minus==1) System.out.print("-");
			System.out.print(ans);
			
			int scale = ans.scale();
			if(scale==0) System.out.print(".0");
	
			System.out.println();
		}
	
	}
}