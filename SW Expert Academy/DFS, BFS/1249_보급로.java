import java.io.*;
import java.util.PriorityQueue;

class Pair implements Comparable<Pair>{
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

    @Override
    public int compareTo(Pair other) {
        return Integer.compare(this.value, other.value);
    }

    public Pair(int x, int y, int value) {
        this.x = x;
        this.y = y;
        this.value = value;
    }
}

public class Solution {
    public static int testCase, n;
    public static int[][] arr;
    public static int[][] vis;
    public static int[] dx = {0, 0, 1, -1};
    public static int[] dy = {1, -1, 0, 0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            n = Integer.parseInt(br.readLine());
            int res = 0;
            arr = new int[n + 1][n + 1];
            vis = new int[n + 1][n + 1];
            for (int i = 1; i <= n; i++) {
                String str = br.readLine();
                for (int j = 1; j <= n; j++) {
                    arr[i][j] = str.charAt(j - 1) - '0';
                    vis[i][j] = -1;
                }
            }
            PriorityQueue<Pair> pq = new PriorityQueue<>();
            pq.add(new Pair(1, 1, 0));
            while (!pq.isEmpty()) {
                Pair poll = pq.poll();
                int x = poll.getX();
                int y = poll.getY();
                int value = poll.getValue();
                for (int i = 0; i <4 ; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx <1 || ny <1 || nx > n || ny > n ) continue;
                    if(vis[nx][ny] != -1) continue;
                    int cost = arr[nx][ny] + value;
                    vis[nx][ny] = cost;
                    pq.add(new Pair(nx, ny, cost));
                    if (nx == n && ny == n) res = cost;
                }
            }
            bw.write("#"+t+" "+res+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}