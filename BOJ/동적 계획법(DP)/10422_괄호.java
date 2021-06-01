import java.io.*;

public class Main {
    public static final int MOD = 1000000007;
    public static final int MAX = 5000;
    public static long[] dp = new long[MAX+1];
    public static int t;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        dp[0] = 1L;
        for(int i=2; i<=MAX; i+=2){
            for(int j=2; j<=i;j+=2){
                dp[i] += dp[j-2] * dp[i - j];
                dp[i] %= MOD;
            }
        }
        t = Integer.parseInt(br.readLine());
        for(int i = 0; i<t; i++){
            int now = Integer.parseInt(br.readLine());
            bw.write(String.valueOf(dp[now])+"\n");
        }
        bw.flush();
        br.close();
        bw.close();

    }
}