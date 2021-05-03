import java.util.PriorityQueue;

class Node implements Comparable<Node>{
    private int x;
    private int y;
    private int val;
    private int dir;
    public Node(int x, int y, int val, int dir){
        this.x = x;
        this.y = y;
        this.val = val;
        this.dir = dir;
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

    public int getDir() {
        return dir;
    }

    @Override
    public int compareTo(Node o) {
        return Integer.compare(this.val, o.val);
    }
}

class Solution {

    public static int[] dx = {0,0,-1,1};
    public static int[] dy = {1,-1,0,0};
    public static int[][] map;
    public static int[][][] vis;
    public static int n;

    public static void bfs(){
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(0,0,0,3));
        pq.offer(new Node(0,0,0,0));
        for(int i=0; i<4; i++) vis[i][0][0] = 0;
        while (!pq.isEmpty()){
            Node node = pq.poll();
            int x = node.getX();
            int y = node.getY();
            int val = node.getVal();
            int dir = node.getDir();
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=n) continue;
                if(map[nx][ny]==1) continue;
                if(dir==i){
                    if(vis[dir][nx][ny] > val+100 || vis[dir][nx][ny] == -1){
                        vis[dir][nx][ny] = val+100;
                        pq.offer(new Node(nx,ny,vis[dir][nx][ny],i));
                    }
                }
                else{
                    if(vis[dir][nx][ny] > val+600 || vis[dir][nx][ny] == -1 ){
                        vis[dir][nx][ny] = val+600;
                        pq.offer(new Node(nx,ny,vis[dir][nx][ny],i));
                    }
                }
            }
        }
    }

    public int solution(int[][] board) {
        n = board.length;
        map = new int[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                map[i][j] = board[i][j];
            }
        }
        vis = new int[4][n][n];
        for(int i=0; i<4; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    vis[i][j][k] = -1;
                }
            }
        }
        bfs();
        int answer = (int)1e9;
        for(int i=0; i<4; i++) {
            if(vis[i][n-1][n-1]==-1) continue;
            answer = Math.min(answer,vis[i][n-1][n-1]);
        }
        return answer;
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] board = {{0,0,1,0},{0,0,0,0},{0,1,0,1},{1,0,0,0}};
        Solution s = new Solution();
        s.solution(board);
    }
}