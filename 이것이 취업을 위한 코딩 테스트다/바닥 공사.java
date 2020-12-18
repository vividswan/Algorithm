import java.util.Scanner;

public class 바닥 공사{

    public static final int  MOD =  796796;
    public static int[] dp;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 3;
        for(int i = 3;i<=n;i++){
            dp[i] += dp[i-1] % MOD;
            dp[i] += dp[i-2] * 2 % MOD;
            dp[i] %= MOD;
        }
        System.out.println(dp[n]);

    }

}