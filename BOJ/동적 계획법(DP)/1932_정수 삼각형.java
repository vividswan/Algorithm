import java.io.*;
import java.util.StringTokenizer;

public class 1932_정수 삼각형 {

    public static int n;
    public static int[][] map;
    public static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        map = new int[n+1][n+2];
        dp = new int[n+1][n+2];
        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=i;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dp[1][1] = map[1][1];

        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i][j] = Math.max(dp[i][j], map[i][j]+dp[i-1][j-1]);
                dp[i][j] = Math.max(dp[i][j], map[i][j]+dp[i-1][j]);
            }
        }
        int value = 0;
        for(int i=1;i<=n;i++) value = Math.max(value,dp[n][i]);
        bw.write(String.valueOf(value));
        bw.flush();
        br.close();
        bw.close();
    }
}