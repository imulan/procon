import java.util.Scanner;

public class J0062{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int[] nums = new int[10];
		
		while(sc.hasNext()){
			String s = sc.next();
		
			for(int i=0; i<10; i++)
				nums[i] = Integer.parseInt("" + s.charAt(i));
			
			for(int i=0; i<9; i++){
				for(int j=0; j<9-i;	j++){
					nums[j] = (nums[j] + nums[j+1])%10;	
				}
			}
		
			System.out.println(nums[0]);
		}
	
	}
}