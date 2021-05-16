import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node{
    private int x;
    private int y;
    private int key;

    public Node(int x, int y, int key){
        this.x = x;
        this.y = y;
        this.key = key;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getKey() {
        return key;
    }
}

public class Main {
    public static int n;
    public static int m;
    public static int[][] map;
    public static int[][][] vis;
    public static int[] dx = {0,0,1,-1};
    public static int[] dy = {1,-1, 0,0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n+1][m+1];
        vis = new int[2][n+1][m+1];

        for(int i=1; i<=n; i++){
            String line = br.readLine();
            for(int j=1; j<=m; j++){
                map[i][j] = line.charAt(j-1) - '0';
                vis[0][i][j] = -1;
                vis[1][i][j] = -1;
            }
        }

        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(1,1,1));
        vis[1][1][1] = 1;
        while (!q.isEmpty()){
            Node node = q.poll();
            int x = node.getX();
            int y = node.getY();
            int key = node.getKey();
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<1||ny<1||nx>n||ny>m) continue;
                if(map[nx][ny]==1){
                    if(key==0) continue;
                    else{
                        if(vis[0][nx][ny]==-1){
                            vis[0][nx][ny] = vis[key][x][y]+1;
                            q.offer(new Node(nx,ny,0));
                        }
                    }
                }
                else if(vis[key][nx][ny]==-1){
                    vis[key][nx][ny] = vis[key][x][y]+1;
                    q.offer(new Node(nx,ny,key));
                }
            }
        }
        int res = -1;
        if(vis[0][n][m]==-1 && vis[1][n][m] ==-1) res = -1;
        else if(vis[0][n][m]==-1) res = vis[1][n][m];
        else if(vis[1][n][m]== -1) res = vis[0][n][m];
        else res = Math.min(vis[0][n][m], vis[1][n][m]);
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}