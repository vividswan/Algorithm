import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n,m;
    public static int[][] map;
    public static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n+1][m+1];
        dp = new int[n+1][m+1];

        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=m; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = Math.max(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j] = Math.max(dp[i][j], dp[i][j-1]);
                dp[i][j] += map[i][j];
            }
        }
        bw.write(String.valueOf(dp[n][m])+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}