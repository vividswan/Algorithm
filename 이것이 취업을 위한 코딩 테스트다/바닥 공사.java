import java.io.*;
import java.util.StringTokenizer;

public class 바닥공사 {
    public static int n;
    public static int[] dp;
    public static final int MOD = 796796;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        dp = new int[n+1];
        dp[1] = 1;
        dp[2] = 3;
        for(int i=3; i<=n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;
        }
        bw.write(String.valueOf(dp[n]));
        bw.flush();
        br.close();
        bw.close();
    }
}