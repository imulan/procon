import java.util.Scanner;

public class J0169{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		while(true){
			String str = sc.nextLine();
			String[] nums = str.split(" ");
			int[] a = new int[nums.length];
			int ace=0, score=0;
			boolean flag = true;
			
			if(nums[0].equals("0")) break;
			
			for(int i=0; i<nums.length; i++) {
				a[i] = Integer.parseInt(nums[i]);
				if(a[i] == 1) ace++;
				else if(a[i]>9 && a[i]<14) score+=10;
				else score+=a[i];
				
				if(score>21) {
					score=0;
					flag = false;
					break;
				}
			}
			
			if(score +1*ace > 21) {
				flag = false;
				score=0;
			}
			
			int tt = score;
					
			if(flag){
				for(int i=0; i<=ace; i++){
					if(tt + 1*i + 11*(ace-i) <= 21) {
						score = tt + 1*i + 11*(ace-i);
						break;
					} 	
				}
			}
		
			System.out.println(score);
		}	

	}
}