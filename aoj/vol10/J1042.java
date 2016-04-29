import java.util.Scanner;

public class J1042{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
	
		while(true){
			String s = sc.nextLine();
			if(s.equals("END OF INPUT")) break;
			
			String[] array = s.split(" ");
			for(int i=0; i<array.length; i++){
				System.out.print(array[i].length());
			}
			System.out.println();
		}
	
	}
}