import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair{
    private int x;
    private int y;
    public Pair(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}

public class Main {
    public static int n,m;
    public static int[][] map;
    public static int[][] vis;
    public static int[] dx = {0,0,-1,1};
    public static int[] dy = {-1,1,0,0};
    public static int startX, startY;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n+1][m+1];
        vis = new int[n+1][m+1];
        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=m; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] == 2){
                    startX = i;
                    startY = j;
                }
                if(map[i][j]==0) continue;
                vis[i][j] = -1;
            }
        }

        vis[startX][startY] = 0;
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(startX, startY));
        while (!q.isEmpty()){
            Pair pair = q.poll();
            int x  = pair.getX();
            int y  = pair.getY();
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny= y + dy[i];
                if(nx<1||ny<1||nx>n||ny>m) continue;
                if(map[nx][ny]==0) continue;
                if (vis[nx][ny]!=-1) continue;
                vis[nx][ny] = vis[x][y]+1;
                q.offer(new Pair(nx,ny));
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                bw.write(String.valueOf(vis[i][j])+" ");
            }
            bw.write("\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}