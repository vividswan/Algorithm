import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
class Guard implements Comparable<Guard>{
    private int st;
    private int ed;
    private int value;

    public int getValue() {
        return value;
    }

    public int getEd() {
        return ed;
    }

    public int getSt() {
        return st;
    }

    public Guard(int st, int ed, int value){
        this.st = st;
        this.ed = ed;
        this.value = value;
    }

    @Override
    public int compareTo(Guard o) {
        return Integer.compare(this.value, o.value);
    }
}
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

class Solution {
    public static int[] parent;
    public static int find(int idx){
        if(idx==parent[idx]) return idx;
        else return parent[idx] = find(parent[idx]);
    }
    public static void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return;
        if(a>b) parent[a] = b;
        else parent[b] = a;
    }
    public static PriorityQueue<Guard> pq = new PriorityQueue<>();
    public static int[][] vis;
    public static int[][] map;
    public static int n;
    public static int len;
    public static int[] dx = {0, 0, -1, 1};
    public static int[] dy = {1, -1, 0, 0};
    public static int cnt;

    public void bfs(int nowX, int nowY){
        vis[nowX][nowY] = cnt;
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(nowX,nowY));
        while(!q.isEmpty()){
            Node node = q.poll();
            int x = node.getX();
            int y = node.getY();
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y +dy[i];
                if(nx<0||ny<0||nx>=n||ny>=n) continue;
                if(Math.abs(map[x][y]-map[nx][ny])> len) {
                    if(vis[nx][ny] != 0){
                        pq.offer(new Guard(vis[x][y],vis[nx][ny],Math.abs(map[x][y]-map[nx][ny])));
                    }
                    continue;
                }
                if(vis[nx][ny]!=0) continue;
                else{
                    vis[nx][ny] = cnt;
                    q.offer(new Node(nx,ny));
                }
            }
        }
    }


    public int solution(int[][] land, int height) {
        n = land.length;
        map = new int[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                map[i][j] = land[i][j];
            }
        }
        len = height;
        vis = new int[n][n];
        for(int i =0; i<n; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==0){
                    cnt++;
                    bfs(i,j);
                }
            }
        }
        parent = new int[cnt+1];
        int res = 0;
        for(int i=0; i<=cnt; i++) parent[i] = i;
        while (!pq.isEmpty()){
            Guard guard = pq.poll();
            int st = guard.getSt();
            int ed =guard.getEd();
            int value =guard.getValue();

            if(find(st)==find(ed)) continue;
            else if(st==0||ed==0) continue;
            else {
                merge(st,ed);
                res += value;
            }
        }
        return res;
    }
}