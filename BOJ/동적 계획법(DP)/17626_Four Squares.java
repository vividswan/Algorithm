
import java.io.*;
import java.util.Arrays;

public class Main {
    public static int n;
    public static int[] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw= new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        dp = new int[n+1];
        Arrays.fill(dp,n);
        int cnt = 1;
        while (true){
            if (cnt*cnt > n) break;
            dp[cnt*cnt] = 1;
            cnt++;
        }
        for(int i=1; i<=n; i++){
            int val = 1;
            while (true){
                if (val*val >= i) break;
                dp[i] = Math.min(dp[i],dp[i-val*val]+1);
                val++;
            }
        }
        bw.write(dp[n]+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}