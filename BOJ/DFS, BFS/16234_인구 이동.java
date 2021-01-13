import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Position{
    private int x;
    private int y;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Position(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class 16234_인구 이동 {
    public static int n, l , r;
    public static int[][] map;
    public static int[] dx = {0,0,1,-1};
    public static int[] dy = {1,-1,0,0};

    public static boolean posMove(int x1, int y1, int x2, int y2){
        int value = Math.abs(map[x1][y1]-map[x2][y2]);
        if(l<=value && value <= r) return true;
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());

        map = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int cnt = 0;


        while (true) {
            boolean isEnd = true;
            boolean[][] vis = new boolean[n + 1][n + 1];
            ArrayList<ArrayList<Position>> res = new ArrayList<ArrayList<Position>>();
            ArrayList<Integer> sum = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (vis[i][j]) continue;
                    vis[i][j] = true;
                    Queue<Position> q = new LinkedList<>();
                    ArrayList<Position> temp = new ArrayList<>();
                    int tempSum = 0;
                    q.offer(new Position(i, j));
                    temp.add(new Position(i, j));
                    tempSum += map[i][j];
                    while (!q.isEmpty()) {
                        Position position = q.poll();
                        int x = position.getX();
                        int y = position.getY();
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
                            if (vis[nx][ny]) continue;
                            if (!posMove(x, y, nx, ny)) continue;
                            isEnd = false;
                            vis[nx][ny] = true;
                            tempSum += map[nx][ny];
                            Position nextPos = new Position(nx, ny);
                            temp.add(nextPos);
                            q.offer(nextPos);
                        }
                    }
                    if (temp.size() == 1) continue;
                    sum.add(tempSum);
                    res.add(temp);
                }
            }
            if (!isEnd) {
                cnt++;
                for (int k = 0; k < res.size(); k++) {
                    ArrayList<Position> now = res.get(k);
                    for (int t = 0; t < now.size(); t++) {
                        map[now.get(t).getX()][now.get(t).getY()] = sum.get(k) / now.size();
                    }
                }
            }
            else break;
        }
        bw.write(String.valueOf(cnt));
        bw.flush();
        br.close();
        bw.close();
    }
}