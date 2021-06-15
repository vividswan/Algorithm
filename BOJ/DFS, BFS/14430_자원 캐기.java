import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node{
    private int x;
    private int y;

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public Node(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class Main {
    public static int n,m;
    public static int[] dx = {0,1};
    public static int[] dy = {1,0};
    public static int[][] map;
    public static int[][] vis;
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
                vis[i][j] = -1;
            }
        }
        vis[1][1] = map[1][1];

        Queue<Node> q  = new LinkedList<>();
        q.offer(new Node(1,1));
        while (!q.isEmpty()){
            Node node = q.poll();
            int x = node.getX();
            int y = node.getY();
            for(int i=0; i<2; i++){
                int nx = x +dx[i];
                int ny = y +dy[i];
                if (nx>n || ny >m) continue;
                int nVis = vis[x][y] + map[nx][ny];
                if (vis[nx][ny] >= nVis) continue;
                vis[nx][ny] = nVis;
                q.offer(new Node(nx,ny));
            }
        }
        bw.write(String.valueOf(vis[n][m])+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}