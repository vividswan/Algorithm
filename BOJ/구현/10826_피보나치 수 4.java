import java.io.*;
import java.math.BigInteger;

public class Main {
    public static int n;
    public static BigInteger[] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        dp = new BigInteger[n+1];
        dp[0] = BigInteger.ZERO;
        if (n>=1) dp[1] = BigInteger.ONE;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1].add(dp[i-2]);
        }
        bw.write(dp[n]+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}