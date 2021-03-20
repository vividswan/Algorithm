import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 효율적인 화폐 구성 {
    public static int n,m;
    public static int[] arr;
    public static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n];
        dp = new int[m+1];
        for(int i=1; i<=m; i++) dp[i] = m+1;
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        for(int i=0; i<n; i++){
            int value = arr[i];
            for(int j=1; j<=m; j++){
                int now = j-value;
                if(now >= 0){
                    if(dp[now] != m+1){
                        dp[j] = Math.min(dp[now]+1,dp[j]);
                    }
                }
            }
        }

        if(dp[m]==m+1) bw.write("-1\n");
        else bw.write(dp[m]+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}