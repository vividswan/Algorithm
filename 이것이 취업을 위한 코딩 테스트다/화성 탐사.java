import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Node implements  Comparable<Node>{
    private int x;
    private int y;
    private int value;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getValue() {
        return value;
    }

    public Node(int x, int y, int value){
        this.x = x;
        this.y = y;
        this.value = value;
    }

    @Override
    public int compareTo(Node other) {
        return Integer.compare(this.value, other.value);
    }
}

public class 화성 탐사 {
    public static int t, n;
    public static int[][] map;
    public static int[][] distTable;
    public static PriorityQueue<Node> pq;
    public static final int INF = (int) 1e9;
    public static int dx[] = {1,-1,0,0};
    public static int dy[] = {0,0,1,-1};

    public static void dijkstra(){
        distTable[1][1]=map[1][1];
        Node firstNode = new Node(1,1,distTable[1][1]);
        pq = new PriorityQueue<>();
        pq.offer(firstNode);
        while(!pq.isEmpty()){
            Node node = pq.poll();
            int x = node.getX();
            int y = node.getY();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<1||ny<1||nx>n||ny>n) continue;
                int nextValue = distTable[x][y] + map[nx][ny];
                if(nextValue < distTable[nx][ny]){
                    Node nextNode = new Node(nx,ny,nextValue);
                    distTable[nx][ny] = nextValue;
                    pq.offer(nextNode);
                }
            }
        }
        return;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        t = Integer.parseInt(st.nextToken());

        for(int k=0; k<t; k++){
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            map = new int[n+1][n+1];
            distTable = new int[n+1][n+1];
            for(int i=1;i<=n;i++){
                st = new StringTokenizer(br.readLine());
                for(int j=1; j<=n; j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                    distTable[i][j] = INF;
                }
            }
            dijkstra();
            bw.write(String.valueOf(distTable[n][n])+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}