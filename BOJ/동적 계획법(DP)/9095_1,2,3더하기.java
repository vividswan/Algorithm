import java.util.Scanner;

public class Main{

    static int dp[] =new int[11];

    public class 9095_1,2,3더하기{
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        for(int i=4;i<=10;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for(int i=1; i<=t; i++){
            int n = scanner.nextInt();
            System.out.println(dp[n]);
        }
    }
}