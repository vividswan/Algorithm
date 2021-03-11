import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node{
    private int x;
    private int y;
    public Node(int  x, int y){
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

public class 미로 탈출 {
    public static int n,m;
    public static int[][] map;
    public static int[][] vis;
    public static int[] dx = {0,0,-1,1};
    public static int[] dy = {1,-1,0,0};
    public static Queue<Node> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n+1][m+1];
        vis = new int[n+1][m+1];
        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            for(int j=1; j<=m; j++){
                map[i][j] = str.charAt(j-1) - '0';
                vis[i][j] = -1;
            }
        }
        vis[1][1] = 1;
        q.offer(new Node(1,1));
        while(!q.isEmpty()){
            Node node = q.poll();
            for(int i=0; i<4; i++){
                int nx = node.getX() + dx[i];
                int ny = node.getY() + dy[i];
                if(nx<1||ny<1||nx>n||ny>m) continue;
                if(vis[nx][ny] != -1) continue;
                vis[nx][ny] = vis[node.getX()][node.getY()]+1;
                q.offer(new Node(nx,ny));
            }
        }
        bw.write(String.valueOf(vis[n][m])+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}