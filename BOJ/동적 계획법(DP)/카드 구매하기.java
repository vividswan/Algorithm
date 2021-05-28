import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static int[] arr;
    public static int[] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        arr = new int[n+1];
        dp = new int[n+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            dp[i] = arr[i];
        }
        for(int i=1; i<=n; i++){
            int cnt = 1;
            while (i*cnt <= n){
                for(int j= i*cnt; j<=n; j++){
                    dp[j] = Math.max(dp[j], dp[i*cnt]+dp[j-i*cnt]);
                }
                cnt++;
            }
        }
        bw.write(String.valueOf(dp[n])+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}