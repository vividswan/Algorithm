import java.io.*;
import java.util.StringTokenizer;

public class 음료수 얼려 먹기 {
    public static int n,m,cnt;
    public static int[][] map;
    public static boolean[][] vis;
    public static int[] dx = {0,0,1,-1};
    public static int[] dy = {1,-1,0,0};
    public static void dfs(int x, int y){
        vis[x][y] = true;
        for(int i=0; i<4;i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<1||ny<1||nx>n||ny>m) continue;
            if(map[nx][ny]==1) continue;
            if(vis[nx][ny]) continue;
            dfs(nx,ny);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n+1][m+1];
        vis = new boolean[n+1][m+1];
        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            for(int j=1; j<=m; j++){
                map[i][j] = str.charAt(j-1) - '0';
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(vis[i][j]) continue;
                if(map[i][j]==1) continue;
                cnt++;
                dfs(i,j);
            }
        }
        bw.write(String.valueOf(cnt)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}