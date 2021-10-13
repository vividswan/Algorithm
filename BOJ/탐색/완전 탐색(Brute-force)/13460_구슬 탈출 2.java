import java.io.*;
import java.util.StringTokenizer;

class Pair {
    int x;
    int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {
    static int n, m;
    static char[][] map;
    static Pair blue;
    static Pair red;
    static int res = -1;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    static void recursion(int cnt) {
        if (cnt > 10) return;
        Pair tempRed = new Pair(red.x, red.y);
        Pair tempBlue = new Pair(blue.x, blue.y);
        for (int i = 0; i < 4; i++) {
            int redCnt = 0;
            int blueCnt = 0;
            boolean isIn = false;
            boolean isValid = false;
            while (true) {
                int nx = red.x + dx[i];
                int ny = red.y + dy[i];
                if (nx < 1 || ny < 1 || nx > n || ny > m) break;
                else if (map[nx][ny] == '#') break;
                else if (map[nx][ny] == 'O') {
                    isIn = true;
                    isValid = true;
                    break;
                }
                redCnt++;
                red.x = nx;
                red.y = ny;
            }
            while (true) {
                int nx = blue.x + dx[i];
                int ny = blue.y + dy[i];
                if (nx < 1 || ny < 1 || nx > n || ny > m) break;
                else if (map[nx][ny] == '#') break;
                else if (map[nx][ny] == 'O') {
                    isIn = true;
                    isValid = false;
                    break;
                }
                blueCnt++;
                blue.x = nx;
                blue.y = ny;
            }
            if (isValid) {
                if(res == -1) res = cnt;
                else res = Math.min(res, cnt);
            }
            if (red.x == blue.x && red.y == blue.y) {
                if (redCnt > blueCnt) {
                    red.x -= dx[i];
                    red.y -= dy[i];
                } else if(redCnt < blueCnt) {
                    blue.x -= dx[i];
                    blue.y -= dy[i];
                }
            }
            if(!isIn && !(redCnt ==0 && blueCnt ==0) ) recursion(cnt+1);
            red.x = tempRed.x;
            red.y = tempRed.y;
            blue.x = tempBlue.x;
            blue.y = tempBlue.y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new char[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            String str = br.readLine();
            for (int j = 1; j <= m; j++) {
                map[i][j] = str.charAt(j - 1);
                if (map[i][j] == 'B') blue = new Pair(i, j);
                else if (map[i][j] == 'R') red = new Pair(i, j);
            }
        }
        recursion(1);
        bw.write(res + "\n");
        bw.flush();
        br.close();

    }
}