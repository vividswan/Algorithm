import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int[][] dp = new int[1001][1001];
    public static final int MOD = 10007;

    public static void main(String[] args) throws IOException {
        for (int i = 0; i < 1001; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i < 1001; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        bw.write(String.valueOf(dp[n][m])+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}