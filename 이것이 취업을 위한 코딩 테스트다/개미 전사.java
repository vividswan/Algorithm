import java.io.*;
import java.util.StringTokenizer;

public class 개미전사 {

    public static int n;
    public static int[] arr;
    public static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n+1];
        dp = new int[n+1];
        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++){
            arr[i]=Integer.parseInt(st.nextToken());
            if(i>1) dp[i] = Math.max(dp[i-1],dp[i-2]+arr[i]);
        }
        bw.write(String.valueOf(dp[n]));
        bw.flush();
        br.close();
        bw.close();
    }
}