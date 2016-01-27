import java.util.*;
import java.io.*;
import java.math.*;

public class 592C{

	public static BigInteger gcd(BigInteger p,BigInteger q){
		if( (p.remainder(q)).equals(BigInteger.ZERO)) return q;
		else return gcd(q,p.remainder(q));
	}

	public static BigInteger lcm(BigInteger p,BigInteger q){
		return p.divide(gcd(p,q)).multiply(q);
	}


	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		String str=sc.next();
		BigInteger t = new BigInteger(str);
		str=sc.next();
		BigInteger w = new BigInteger(str);
		str=sc.next();
		BigInteger b = new BigInteger(str);

		//w>=bとなるように交換
		if(w.compareTo(b)==-1){
			BigInteger tt = w;
			w=b;
			b=tt;
		}
		//System.out.println("w="+w+" ,b="+b);

		BigInteger ans = BigInteger.ZERO;
		BigInteger Q = t.divide(lcm(w,b));
		BigInteger R = t.remainder(lcm(w,b));
		//System.out.println("Q="+Q+" R="+R);

		ans = ans.add(t.divide(lcm(w,b)));

		if(R.compareTo(b.subtract(BigInteger.ONE))==-1){
			ans=ans.add((Q.add(BigInteger.ONE)).multiply(R));
			ans=ans.add( Q.multiply(b.subtract(R.add(BigInteger.ONE))) );
		}
		else{
			ans=ans.add((Q.add(BigInteger.ONE)).multiply(b.subtract(BigInteger.ONE)));
		}

		//System.out.println("ans="+ans);
		if(ans.equals(BigInteger.ZERO)) System.out.println("0/1");
		else System.out.println(ans.divide(gcd(t,ans)) + "/" + t.divide(gcd(t,ans)));
	}
}
