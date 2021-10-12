import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static final int MAX = 1000000;
    public static int[] dp = new int[MAX+1];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            int now = Integer.parseInt(st.nextToken());
            dp[now] = Math.max(dp[now], dp[now-1]+1);
        }
        int res = 0;
        for(int i=0; i<=MAX; i++) res = Math.max(res,dp[i]);

        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}