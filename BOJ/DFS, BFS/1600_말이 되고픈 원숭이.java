import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node{
    int x;
    int y;
    int k;

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public int getK() {
        return k;
    }

    public Node(int x, int y, int k){
        this.x = x;
        this.y = y;
        this.k = k;
    }
}

public class Main {

    public static int val,w,h;
    public static int[][] map;
    public static int[][][] vis;
    public static int[] dx ={0,0,1,-1};
    public static int[] dy ={1,-1,0,0};
    public static int[] jdx = {-2,-2,1,-1,2,2,1,-1};
    public static int[] jdy = {-1,1,2,2,1,-1,-2,-2};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        val = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        w = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        map = new int[h+1][w+1];
        vis = new int[val+1][h+1][w+1];
        for(int i=1; i<=h; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=w; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                for(int l =0; l<=val; l++) vis[l][i][j] = -1;
            }
        }
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(1,1,val));
        vis[val][1][1] = 0;
        while (!q.isEmpty()){
            Node node = q.poll();
            int x = node.getX();
            int y = node.getY();
            int k = node.getK();
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<1||ny<1||nx>h||ny>w) continue;
                if (map[nx][ny]==1) continue;
                if(vis[k][nx][ny] != -1) continue;
                vis[k][nx][ny] = vis[k][x][y] +1;
                q.offer(new Node(nx,ny,k));
            }
            if(k>0){
                for(int i=0; i<8; i++){
                    int nx = x + jdx[i];
                    int ny = y + jdy[i];
                    if(nx<1||ny<1||nx>h||ny>w) continue;
                    if (map[nx][ny]==1) continue;
                    if(vis[k-1][nx][ny] != -1) continue;
                    vis[k-1][nx][ny] = vis[k][x][y] +1;
                    q.offer(new Node(nx,ny,k-1));
                }
            }
        }
        int res = (int)1e9;
        for(int i=0; i<=val; i++){
            if(vis[i][h][w]==-1) continue;
            else res = Math.min(res,vis[i][h][w]);
        }
        if(res == (int)1e9) bw.write("-1\n");
        else bw.write(String.valueOf(res+"\n"));
        bw.flush();
        br.close();
        bw.close();
    }
}