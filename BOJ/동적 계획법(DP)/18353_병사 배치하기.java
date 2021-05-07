import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int n, res;
    public static int[] val;
    public static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        val = new int[n];
        dp = new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            val[i] = Integer.parseInt(st.nextToken());
            dp[i] = 1;
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(val[i] > val[j]){
                    dp[j] = Math.max(dp[j],dp[i]+1);
                }
            }
        }
        for(int i=0; i<n; i++) res = Math.max(res,dp[i]);

        bw.write(String.valueOf(n - res)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}