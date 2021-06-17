import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

class Node{
    private int x;
    private int y;
    private int cnt;

    public Node(int x, int y, int cnt){
        this.x = x;
        this.y = y;
        this.cnt = cnt;
    }

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public int getCnt() {
        return cnt;
    }
}

public class Main {
    public static int n;
    public static int map[][];
    public static int vis[][][];
    public static int[] dx = {0,0,-1,1};
    public static int[] dy = {1,-1,0,0};
    public static int blackCnt;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        map = new int[n+1][n+1];
        for(int i=1; i<=n; i++){
            String str = br.readLine();
            for(int j=1; j<=n; j++){
                map[i][j] = str.charAt(j-1) - '0';
                if (map[i][j]==0) blackCnt++;
            }
        }
        vis = new int[blackCnt+1][n+1][n+1];
        for(int k=0; k<=blackCnt; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    vis[k][i][j] = -1;
                }
            }
        }

        vis[0][1][1] = 0;
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(1,1,0));
        while (!q.isEmpty()){
            Node node = q.poll();
            int x = node.getX();
            int y = node.getY();
            int cnt =node.getCnt();
            if(cnt==0 && map[x][y]==0){
                System.out.println(x);
                System.out.println(y);
                System.out.println();
            }
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nextCnt = cnt + 1;
                if(nx<1 || ny < 1 || nx > n || ny >n) continue;
                if (map[nx][ny]==0){
                    if(nextCnt <= blackCnt){
                        if(vis[nextCnt][nx][ny]==-1) {
                            vis[nextCnt][nx][ny] = vis[cnt][x][y] + 1;
                            q.offer(new Node(nx,ny,nextCnt));
                        }
                    }
                }
                else {
                    if(vis[cnt][nx][ny]==-1){
                        vis[cnt][nx][ny] = vis[cnt][x][y] + 1;
                        q.offer(new Node(nx,ny,cnt));
                    }
                }
            }
        }

        int res = (int)1e9;
        for(int i=0; i<=blackCnt; i++){
            if(vis[i][n][n]!=-1){
                res = i;
                break;
            }
        }
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();



    }
}