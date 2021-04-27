import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int n;
    public static int[] time;
    public static int[] value;
    public static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        time = new int[n+1];
        value = new int[n+1];
        dp = new int[n+1];

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            time[i] = Integer.parseInt(st.nextToken());
            value[i] = Integer.parseInt(st.nextToken());
        }

        int res = 0;
        for(int i=n-1; i>=0; i--){
            int totTime = time[i] + i;
            if(totTime>n) dp[i] = res;
            else {
                dp[i] = Math.max(res, value[i]+dp[totTime]);
                res = dp[i];
            }
        }

        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}