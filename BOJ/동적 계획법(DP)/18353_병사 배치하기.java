import java.io.*;
import java.util.StringTokenizer;

public class 18353_병사 배치하기 {
    public static int[] arr;
    public static int[] dp;
    public static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n+1];
        dp = new int[n+1];
        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
            dp[i] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(arr[i]<arr[j]) dp[i] = Math.max(dp[i],dp[j]+1);
            }
        }
        int maxVal = 0;
        for(int i = 1; i<=n;i++) maxVal = Math.max(maxVal,dp[i]);
        int result = n - maxVal;
        bw.write(String.valueOf(result)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}