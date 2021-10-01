import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class 1463_1로 만들기{
    static int dp[];
    static int n;

    private static int recursion(int idx){
        if(idx==1) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int ans = recursion(idx-1)+1;
        if(idx%3==0) ans = Math.min(ans,recursion(idx/3)+1);
        if(idx%2==0) ans = Math.min(ans,recursion(idx/2)+1);
        dp[idx]=ans;
        return ans ;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        dp = new int[n+1];
        scanner.close();
       Arrays.fill(dp,-1);
       System.out.println(recursion(n));
    }
}
