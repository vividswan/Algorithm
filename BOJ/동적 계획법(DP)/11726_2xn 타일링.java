import java.util.Scanner;

public class 11726_2xn 타일링{

    public static int dp[];
    public final static int MOD = 10007;

    public static int recursion(int idx){
        if(dp[idx]!=0) return dp[idx];
        if(idx==1) return 1;
        if(idx==2) return 2;
        return dp[idx] = (recursion(idx-1)+recursion(idx-2))%MOD;
    }

    public static void main(String[] args) {
        int n;
        Scanner scanner = new Scanner(System.in);
        n=scanner.nextInt();
        dp = new int[n+1];
        System.out.println(recursion(n));
    }
}