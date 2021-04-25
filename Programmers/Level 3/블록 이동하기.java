import java.util.LinkedList;
import java.util.Queue;

class Node{
    private int x;
    private int y;
    private int dir;

    public Node(int dir, int x, int y){
        this.x = x;
        this.y = y;
        this.dir = dir;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getDir() {
        return dir;
    }
}

class Solution {

    public static int[][][] vis;
    public static int n;
    public static int inf;
    public static Queue<Node> q = new LinkedList<>();

    public int solution(int[][] board) {
        n = board.length;
        inf = n*n + 1;
        vis = new int[2][n][n];
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n;k++){
                    vis[i][j][k] = inf;
                }
            }
        }
        q.offer(new Node(0,0,0));
        vis[0][0][0] = 0;
        while (!q.isEmpty()){
            Node node = q.poll();
            int dir = node.getDir();
            int x = node.getX();
            int y = node.getY();
            int nextCnt = vis[dir][x][y] + 1;
            if(dir==0){
                if(y+2<n && board[x][y+2]==0 && vis[0][x][y+1]==inf){
                    vis[0][x][y+1] = nextCnt;
                    q.offer(new Node(0,x,y+1));
                }
                if(y-1>=0 && board[x][y-1]==0 && vis[0][x][y-1]==inf){
                    vis[0][x][y-1] = nextCnt;
                    q.offer(new Node(0,x,y-1));
                }
                if(x+1<n && board[x+1][y]==0 && board[x+1][y+1]==0 && vis[0][x+1][y]==inf){
                    vis[0][x+1][y] = nextCnt;
                    q.offer(new Node(0,x+1,y));
                }
                if(x-1>=0 && board[x-1][y]==0 && board[x-1][y+1]==0 && vis[0][x-1][y]==inf){
                    vis[0][x-1][y] =  nextCnt;
                    q.offer(new Node(0,x-1,y));
                }
                if(x+1<n && board[x+1][y]==0 && board[x+1][y+1]==0 && vis[1][x][y+1]==inf){
                    vis[1][x][y+1] =  nextCnt;
                    q.offer(new Node(1,x,y+1));
                }
                if(x+1<n && board[x+1][y]==0 && board[x+1][y+1]==0 && vis[1][x][y]==inf){
                    vis[1][x][y] =  nextCnt;
                    q.offer(new Node(1,x,y));
                }
                if(x-1>=0 && board[x-1][y]==0 && board[x-1][y+1]==0 && vis[1][x-1][y+1]==inf){
                    vis[1][x-1][y+1] =  nextCnt;
                    q.offer(new Node(1,x-1,y+1));
                }
                if(x-1>=0 && board[x-1][y]==0 && board[x-1][y+1]==0 && vis[1][x-1][y]==inf){
                    vis[1][x-1][y] =  nextCnt;
                    q.offer(new Node(1,x-1,y));
                }
            }
            else{
                if(x+2<n && board[x+2][y]==0 && vis[1][x+1][y]==inf){
                    vis[1][x+1][y] = nextCnt;
                    q.offer(new Node(1,x+1,y));
                }
                if(x-1>=0 && board[x-1][y]==0 && vis[1][x-1][y]==inf){
                    vis[1][x-1][y] = nextCnt;
                    q.offer(new Node(1,x-1,y));
                }
                if(y+1<n && board[x][y+1]==0 && board[x+1][y+1]==0 && vis[1][x][y+1]==inf){
                    vis[1][x][y+1] = nextCnt;
                    q.offer(new Node(1,x,y+1));
                }
                if(y-1>=0 && board[x][y-1]==0 && board[x+1][y-1]==0 && vis[1][x][y-1]==inf){
                    vis[1][x][y-1] = nextCnt;
                    q.offer(new Node(1,x,y-1));
                }
                if(y+1<n && board[x][y+1]==0 && board[x+1][y+1]==0 && vis[0][x][y]==inf){
                    vis[0][x][y] = nextCnt;
                    q.offer(new Node(0,x,y));
                }
                if(y+1<n && board[x][y+1]==0 && board[x+1][y+1]==0 && vis[0][x+1][y]==inf){
                    vis[0][x+1][y] = nextCnt;
                    q.offer(new Node(0,x+1,y));
                }
                if(y-1>=0 && board[x][y-1]==0 && board[x+1][y-1]==0 && vis[0][x][y-1]==inf){
                    vis[0][x][y-1] = nextCnt;
                    q.offer(new Node(0,x,y-1));
                }
                if(y-1>=0 && board[x][y-1]==0 && board[x+1][y-1]==0 && vis[0][x+1][y-1]==inf){
                    vis[0][x+1][y-1] = nextCnt;
                    q.offer(new Node(0,x+1,y-1));
                }
            }
        }


        int answer = Math.min(vis[0][n-1][n-1-1],vis[1][n-1-1][n-1]);
        return answer;
    }
}