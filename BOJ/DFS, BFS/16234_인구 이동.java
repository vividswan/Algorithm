import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node {
    private int x;
    private int y;

    public Node(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}

public class Main {

    public static int n, l, r;
    public static int[][] map;
    public static boolean[][] chk;
    public static int[] dx = {0, 0, -1, 1};
    public static int[] dy = {1, -1, 0, 0};
    public static boolean re = true;
    public static int res = 0;

    public static void recursion(int i, int j) {
        Queue<Node> q = new LinkedList<>();
        Queue<Node> resQ = new LinkedList<>();
        q.offer(new Node(i, j));
        resQ.offer(new Node(i, j));
        int sum = map[i][j];
        int cnt = 1;
        chk[i][j] = true;
        while (!q.isEmpty()) {
            Node node = q.poll();
            int x = node.getX();
            int y = node.getY();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
                if (chk[nx][ny]) continue;
                int dif = Math.abs(map[x][y] - map[nx][ny]);
                if (dif >= l && dif <= r) {
                    chk[nx][ny] = true;
                    sum += map[nx][ny];
                    cnt++;
                    q.offer(new Node(nx, ny));
                    resQ.offer(new Node(nx, ny));
                    if(!re) res++;
                    re = true;
                }
            }
        }
        while (!resQ.isEmpty()){
            Node node = resQ.poll();
            map[node.getX()][node.getY()] = sum/cnt;
        }
    }


    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());

        map = new int[n + 1][n + 1];
        chk = new boolean[n+1][n+1];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        while (re) {
            re = false;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (!chk[i][j]) recursion(i, j);
                }
            }
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    chk[i][j] = false;
                }
            }
        }

        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}