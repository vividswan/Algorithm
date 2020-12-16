import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class 개미 전사{

    public static int n;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<n;i++){
            int num = scanner.nextInt();
            list.add(num);
        }

        int[][] dp = new int[101][2];
        dp[0][1]=list.get(0);
        for(int i=1;i<n;i++){
            dp[i][0] = Math.max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0]+list.get(i);
        }
        System.out.println(Math.max(dp[n-1][0],dp[n-1][1]));
    }
}