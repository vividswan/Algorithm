import java.util.Scanner;

public class 1로 만들기{
    public static int[] dp;
    public static int n;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        dp = new int[n+1];
        dp[1] = 0;
        for(int i=2;i<=n;i++){
            int result = dp[i-1]+1;
            if(i%2==0) result = Math.min(result,dp[i/2]+1);
            if(i%3==0) result = Math.min(result,dp[i/3]+1);
            if(i%5==0) result = Math.min(result,dp[i/5]+1);
            dp[i] = result;
        }
        System.out.println(dp[n]);
    }

}