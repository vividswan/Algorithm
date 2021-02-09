import java.io.*;
import java.util.StringTokenizer;

public class 편집 거리 {
    public static String str1;
    public static String str2;
    public static int[][] dp;
    public static int n,m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        str1 = st.nextToken();
        n = str1.length();

        st = new StringTokenizer(br.readLine());
        str2 = st.nextToken();
        m = str2.length();

        dp = new int[n+1][m+1];
        for(int i=1;i<=n;i++) dp[i][0] = i;
        for(int i=1;i<=m;i++) dp[0][i] = i;

        for(int i=1;i<=n;i++){
            for(int j=1; j<=m; j++){
                if(str1.charAt(i-1)!=str2.charAt(j-1)){
                    dp[i][j] = Math.min(dp[i-1][j],Math.min(dp[i][j-1],dp[i-1][j-1])) + 1;
                }
                else dp[i][j] = dp[i-1][j-1];
            }
        }
        bw.write(String.valueOf(dp[n][m]));
        bw.flush();
        br.close();
        bw.close();
    }
}