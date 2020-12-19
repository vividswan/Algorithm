import java.util.Scanner;

public class 효율적인 화폐 구성 {

    public static final int MAX = 10001;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();

        int[] list = new int[n];

        for(int i=0;i<n;i++){
            list[i] = scanner.nextInt();
        }

        int[] dp = new int[m+1];
        for(int i=1;i<=m;i++) dp[i] = MAX;

        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                if(j-list[i]<0) continue;
                dp[j] = Math.min(dp[j],dp[j-list[i]]+1);
            }
        }
        if(dp[m]==MAX) System.out.println(-1);
        else System.out.println(dp[m]);
    }
}