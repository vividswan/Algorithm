import java.io.*;
import java.util.StringTokenizer;

public class 금광 {
    public static int [][] dp;
    public static int [][] map;
    public static int t;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        t = Integer.parseInt(st.nextToken());
        for(int k=0;k<t;k++){
            int n, m;
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            dp = new int[n+2][m+2];
            map = new int[n+2][m+2];
            st = new StringTokenizer(br.readLine());
            for(int i=1; i<=n;i++){
                for(int j=1;j<=m;j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            for(int j=1;j<=n;j++) dp[j][1] = map[j][1];
            for(int j=2;j<=m;j++){
                for(int i=1;i<=n;i++){
                    for(int l=0;l<3;l++){
                        dp[i][j] = Math.max(dp[i][j],map[i][j]+dp[i-1+l][j-1]);
                    }
                }
            }
            int val = 0;
            for(int i=1;i<=n;i++) {
                val = Math.max(val,dp[i][m]);
            }
            bw.write(String.valueOf(val)+'\n');
            bw.flush();
        }
        br.close();
        bw.close();
    }
}