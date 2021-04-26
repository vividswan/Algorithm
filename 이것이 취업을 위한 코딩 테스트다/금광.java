import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int t;
    public static int n,m;
    public static int[][] map;
    public static int [][] dp;
    public static int[] dx = {-1,0,1};

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        t = Integer.parseInt(st.nextToken());
        for(int k=0; k<t; k++){
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            map = new int[n+1][m+1];
            dp = new int[n+1][m+1];
            st = new StringTokenizer(br.readLine());
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            for(int i=1; i<=n; i++) dp[i][1] = map[i][1];
            for(int j=1; j<=m; j++){
                for(int i=1; i<=n; i++){
                    for(int l=0; l<3; l++){
                        int nx = i+dx[l];
                        int ny = j+1;
                        if(nx<1||ny<1||nx>n||ny>m) continue;;
                        dp[nx][ny] = Math.max(dp[nx][ny],dp[i][j]+map[nx][ny]);
                    }
                }
            }
            int res = 0;
            for(int i=1; i<=n; i++) res = Math.max(res, dp[i][m]);
            bw.write(String.valueOf(res)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}