import java.io.*;
import java.util.StringTokenizer;

public class 게임 개발 {

    public static int n,m;
    public static int[][] map;
    public static boolean[][] vis;

    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, 1, 0, -1};
    public static int nowX;
    public static int nowY;
    public static int nowDir;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n+1][m+1];
        vis = new boolean[n+1][m+1];

        st = new StringTokenizer(br.readLine());
        nowX = Integer.parseInt(st.nextToken())+1;
        nowY = Integer.parseInt(st.nextToken())+1;
        nowDir = Integer.parseInt(st.nextToken());
        vis[nowX][nowX] = true;

        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=m; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int cnt = 0;
        int result = 1;
        while(true){
            cnt++;
            if(cnt==5) {
                int nextDir = (nowDir + 2) % 4;
                int nx = nowX + dx[nextDir];
                int ny= nowY + dy[nextDir];
                if(map[nx][ny]==1) break;
                else{
                    cnt = 0;
                    nowX = nx;
                    nowY = ny;
                }
            }
            int nextDir = nowDir - cnt;
            if(nextDir<0) nextDir += 4;
            int nx = nowX + dx[nextDir];
            int ny = nowY + dy[nextDir];
            if(nx<1||ny<1||nx>n||ny>m) continue;
            if(vis[nx][ny]) continue;
            if(map[nx][ny] == 1) continue;
            vis[nx][ny] = true;
            result++;
            cnt = 0;
            nowDir = nextDir;
            nowX = nx;
            nowY = ny;
        }

        bw.write(String.valueOf(result));
        bw.flush();
        br.close();
        bw.close();
    }
}