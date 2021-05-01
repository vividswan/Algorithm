import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Node implements Comparable<Node>{
    private int x;
    private int y;
    private int val;
    public Node(int val, int x, int y){
        this.val = val;
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getVal() {
        return val;
    }

    @Override
    public int compareTo(Node other) {
        return Integer.compare(this.val, other.val);
    }
}

public class Main {

    public static int t;
    public static int n;
    public static int[][] map;
    public static  boolean[][] vis;
    public static  int[] dx ={0,0,1,-1};
    public static  int[] dy ={1,-1,0,0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        t = Integer.parseInt(st.nextToken());

        for(int k=0; k<t; k++){
            st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken());
            map = new int[n+1][n+1];
            vis = new boolean[n+1][n+1];
            int res = 0;

            for(int i=1; i<=n; i++){
                st = new StringTokenizer(br.readLine());
                for(int j=1; j<=n; j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            PriorityQueue<Node> pq = new PriorityQueue<>();
            pq.offer(new Node(map[1][1],1,1));
            vis[1][1] = true;
            while(!pq.isEmpty()){
                Node node = pq.poll();
                int x = node.getX();
                int y = node.getY();
                int val = node.getVal();
                if(x==n&&y==n) res = val;
                for(int i=0; i<4; i++){
                    int nx = x +dx[i];
                    int ny = y +dy[i];
                    if(nx<1||ny<1||nx>n||ny>n) continue;
                    if(vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    pq.offer(new Node(val+map[nx][ny],nx,ny));
                }
            }
            bw.write(String.valueOf(res)+"\n");

        }
        bw.flush();
        br.close();
        bw.close();


    }

}