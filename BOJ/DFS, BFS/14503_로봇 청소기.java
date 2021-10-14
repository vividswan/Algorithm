import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair{
    int x;
    int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {
    static int n, m, res;
    static int[][] map;
    static boolean[][] vis;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    public static void main(String[] args) throws IOException {
        res++;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int nowX, nowY, nowDir;
        st = new StringTokenizer(br.readLine());
        nowX = Integer.parseInt(st.nextToken());
        nowY = Integer.parseInt(st.nextToken());
        nowDir = Integer.parseInt(st.nextToken());
        nowX++;
        nowY++;
        map = new int[n + 1][m + 1];
        vis = new boolean[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        vis[nowX][nowY] = true;

        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(nowX, nowY));
        while (!q.isEmpty()) {
            Pair poll = q.poll();
            int x = poll.x;
            int y = poll.y;
            int cnt = 0;
            while (true) {
                cnt++;
                nowDir--;
                if (nowDir ==-1) nowDir = 3;
                boolean isValid = false;
                int nx = x + dx[nowDir];
                int ny = y + dy[nowDir];
                if(!(nx<1 || ny <1 || nx >n || ny > m) && !(map[nx][ny] == 1 || vis[nx][ny])) isValid = true;
                if(!isValid && (cnt==4)) break;
                else if(isValid){
                    res++;
                    q.add(new Pair(nx, ny));
                    vis[nx][ny] = true;
                    break;
                }
            }
            if(q.isEmpty()){
                int tempDir = nowDir;
                nowDir+=2;
                nowDir %= 4;
                int nx = x + dx[nowDir];
                int ny = y + dy[nowDir];
                nowDir = tempDir;
                if(!(nx<1 || ny <1 || nx >n || ny > m)) {
                    if (map[nx][ny] == 0) {
                        q.add(new Pair(nx, ny));
                    }
                }
            }
        }
        bw.write(res+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}