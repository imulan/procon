import java.util.Scanner;
import java.math.BigInteger;

public class J3181{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        BigInteger dp[][];
        dp = new BigInteger[1001][101];

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=k; j++)
            {
                dp[i][j] = BigInteger.ZERO;
            }
        }
        dp[0][k]=BigInteger.ONE;

        for(int i=k-1; i>=0; i--)
        {
            BigInteger sum[];
            sum = new BigInteger[100];
            for(int j=0; j<100; j++) sum[j]=BigInteger.ZERO;

            for(int j=0; j<=n; j++)
            {
                sum[j%(i+1)] = sum[j%(i+1)].add(dp[j][i+1]);
                dp[j][i]=sum[j%(i+1)];
            }
        }

        System.out.println(dp[n][0]);
    }
}
