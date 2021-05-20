import java.io.*;
import java.util.StringTokenizer;

class Pair{
    private int x;
    private int y;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Pair(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class Main {

    public static int m,n;
    public static int[][] map;
    public static int[][] dp;
    public static int[] dx = {0,0,-1,1};
    public static int[] dy = {1,-1,0,0};

    public static int dfs(Pair pair){
        int x = pair.getX();
        int y = pair.getY();
        if(x==m && y==n){
            return 1;
        }
        if(dp[x][y]==-1){
            dp[x][y] = 0;
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<1||ny<1||nx>m||ny>n) continue;
                if(map[nx][ny]>=map[x][y] ) continue;
                dp[x][y] += dfs(new Pair(nx,ny));
            }
        }
        return dp[x][y];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        map = new int[m+1][n+1];
        dp = new int[m+1][n+1];

        for(int i=1; i<=m; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++){
                map[i][j]= Integer.parseInt(st.nextToken());
                dp[i][j] = -1;
            }
        }
        bw.write(String.valueOf(dfs(new Pair(1,1)))+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}