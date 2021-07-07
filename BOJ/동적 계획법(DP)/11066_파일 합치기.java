import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int t,k;
    public static long[] arr;
    public static long[] sum;
    public static long[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        t= Integer.parseInt(br.readLine());
        for(int l=0; l<t; l++){
            k = Integer.parseInt(br.readLine());
            arr = new long[k+1];
            dp = new long[k+1][k+1];
            sum = new long[k+1];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i=1; i<=k; i++){
                arr[i] = Long.parseLong(st.nextToken());
                sum[i] = sum[i-1] + arr[i];
            }
            for(int i=1; i<k; i++){
                for(int j=1; j+i<=k; j++){
                    dp[j][j+i] = (long)1e9;
                    for(int t = 0; t<i; t++){
                        dp[j][j+i] = Math.min(dp[j][j+i],dp[j][j+t]+dp[j+t+1][j+i]);
                    }
                    dp[j][j+i] += sum[j+i]-sum[j-1];
                }
            }
            bw.write(String.valueOf(dp[1][k])+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}