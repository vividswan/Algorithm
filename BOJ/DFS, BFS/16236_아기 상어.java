import java.io.*;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

class Fish implements Comparable<Fish>{
    private int x;
    private int y;
    private int value;

    public Fish(int x, int y, int value){
        this.x = x;
        this.y = y;
        this.value = value;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getValue() {
        return value;
    }

    @Override
    public int compareTo(Fish other) {
        if(this.value==other.value && this.x == other.x) return Integer.compare(this.y, other.y);
        else if(this.value == other.value) return Integer.compare(this.x, other.x);
        else return Integer.compare(this.value, other.value);
    }
}

class Pair{
    private int x;
    private int y;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
    public Pair(int x,int y){
        this.x = x;
        this.y = y;
    }
}

public class 16236_아기 상어 {
    public static int n, cnt, sharkSize=2, nowEat;
    public static int[][] map;
    public static int nowX, nowY;
    public static int[] dx = {-1,1,0,0};
    public static int[] dy = {0,0,-1,1};
    public static boolean bfs(){
        PriorityQueue<Fish> pq = new PriorityQueue<>();
        int[][] vis = new int[n+1][n+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                vis[i][j]=-1;
            }
        }
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(nowX,nowY));
        vis[nowX][nowY] = 0;
        while(!q.isEmpty()){
            Pair pair = q.poll();
            int x = pair.getX();
            int y = pair.getY();
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<1||ny<1||nx>n||ny>n) continue;
                if(vis[nx][ny]!=-1) continue;
                if(map[nx][ny]> sharkSize) continue;
                vis[nx][ny] = vis[x][y]+1;
                q.offer(new Pair(nx,ny));
                if(map[nx][ny]>0 && map[nx][ny]<sharkSize)  pq.offer(new Fish(nx,ny,vis[nx][ny]));
            }
        }
        if(pq.isEmpty()) return false;
        else {
            Fish fish = pq.poll();
            int nx = fish.getX();
            int ny = fish.getY();
            nowEat++;
            cnt+=vis[nx][ny];
            map[nx][ny] = 0;
            nowX = nx;
            nowY = ny;
            if(nowEat==sharkSize) {
                sharkSize++;
                nowEat = 0;
            }
            return true;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        map = new int[n+1][n+1];
        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j]==9){
                    nowX = i;
                    nowY = j;
                    map[i][j]=0;
                }
            }
        }
        while (true){
            if(!bfs()) break;
        }
        bw.write(String.valueOf(cnt));
        bw.flush();
        br.close();
        bw.close();
    }
}