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

    public static int n;
    public static int[][] map;
    public static int[] dx = {0,0,1,-1};
    public static int[] dy = {-1,1,0,0};
    public static boolean recursion(int val){
        int startNum = map[1][1];
        for(int j=0;j<=val; j++){
            int st = startNum - val + j;
            int ed = startNum + j;
            boolean[][] vis = new boolean[n+1][n+1];
            Queue<Pair> q = new LinkedList<>();
            vis[1][1] = true;
            q.offer(new Pair(1,1));
            while (!q.isEmpty()){
                Pair pair = q.poll();
                int x = pair.getX();
                int y = pair.getY();

                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx<1||ny<1||nx>n||ny>n) continue;
                    if(vis[nx][ny]) continue;
                    if(map[nx][ny]<st || map[nx][ny]>ed) continue;
                    vis[nx][ny] = true;
                    q.offer(new Pair(nx,ny));
                }
            }
            if(vis[n][n]) return true;

        }
        return false;
    }
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        map = new int[n+1][n+1];
        for(int i = 1; i<=n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int le =0;
        int ri = 200;
        int ans = -1;
        while (le <= ri){
            int mid = (le+ri)/2;
            if(recursion(mid)) {
                ans = mid;
                ri = mid-1;
            }
            else le = mid+1;
        }
        bw.write(String.valueOf(ans)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}