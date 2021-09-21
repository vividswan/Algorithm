import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

class Pair{
    private int x;
    private int y;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Solution {
    public static int getBombCnt(Pair pair) {
        int x = pair.getX();
        int y = pair.getY();
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || ny <1 || nx >n || ny > n) continue;
            if (arr[nx][ny]==1) cnt++;
        }
        return cnt;
    }
    public static int testCase, n;
    public static int[][] arr;
    public static int[] dx = {-1, -1, -1, 0 , 0, 1, 1, 1};
    public static int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());

        for (int t = 1; t <=testCase ; t++) {
            int res = 0;
            Queue<Pair> q = new LinkedList<>();
            n = Integer.parseInt(br.readLine());
            arr = new int[n + 1][n + 1];
            int[][] vis = new int[n + 1][n + 1];
            for (int i = 1; i <= n; i++) {
                String str = br.readLine();
                for (int j = 1; j <= n; j++) {
                    if(str.charAt(j - 1) == '.') arr[i][j] = 0;
                    else arr[i][j] = 1;
                    vis[i][j] = -1;
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (vis[i][j] != -1 || arr[i][j] == 1) continue;
                    if (getBombCnt(new Pair(i,j))==0) {
                        res++;
                        vis[i][j] = 0;
                        q.add(new Pair(i, j));
                        while (!q.isEmpty()) {
                            Pair poll = q.poll();
                            int x = poll.getX();
                            int y = poll.getY();
                            for (int k= 0; k < 8; k++) {
                                int nx = x + dx[k];
                                int ny = y + dy[k];
                                if(nx < 1 || ny <1 || nx >n || ny > n) continue;
                                if (vis[nx][ny]!=-1) continue;
                                if (arr[nx][ny]==1) vis[nx][ny] = -2;
                                else{
                                    vis[nx][ny] = getBombCnt(new Pair(nx, ny));
                                    if(vis[nx][ny] == 0) q.add(new Pair(nx, ny));
                                }
                            }
                        }
                    }
                }
            }

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (vis[i][j]==-1 && arr[i][j]== 0) res++;
                }
            }
            bw.write("#"+t+" "+String.valueOf(res)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}