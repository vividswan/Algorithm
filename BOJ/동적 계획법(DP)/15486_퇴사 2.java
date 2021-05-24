import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int[] time;
    public static int[] value;
    public static int[] dp;
    public static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        time = new int[n+1];
        value = new int[n+1];
        dp = new int[n+2];
        for(int i=1; i<=n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            time[i] = Integer.parseInt(st.nextToken());
            value[i] = Integer.parseInt(st.nextToken());
        }
        for(int i=n; i>=1; i--){
            if (i + time[i] > n+1) dp[i] = dp[i+1];
            else {
                dp[i] = Math.max(dp[i+1], dp[i+time[i]]+value[i]);
            }
        }
        bw.write(String.valueOf(dp[1])+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}