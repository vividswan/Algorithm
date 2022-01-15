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
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int[] dx = {0, 0, 1, - 1};
        int[] dy = {1, -1, 0, 0};
        int r, c;
        int[][] map;
        Queue<Pair> fireQ = new LinkedList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        int vis[][] = new int[r + 1][c + 1];
        map = new int[r + 1][c + 1];
        Pair start = null;
        for (int i = 1; i <= r; i++) {
            String str = br.readLine();
            for (int j = 1; j <=c ; j++) {
                vis[i][j] = -1;
                char now = str.charAt(j - 1);
                if (now=='J') start = new Pair(i, j);
                else if (now == '#') map[i][j] = 2;
                else if(now=='F'){
                    map[i][j] = 1;
                    fireQ.add(new Pair(i, j));
                }
            }
        }
        Queue<Pair> q = new LinkedList<>();
        q.add(start);
        vis[start.x][start.y] = 0;
        int res = -1;
        while (res == -1 && !q.isEmpty() ){
            int cnt = fireQ.size();
            for (int i = 0; i < cnt; i++) {
                Pair now = fireQ.poll();
                int x = now.x;
                int y = now.y;
                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx < 1  || ny <1 || nx > r || ny >c) continue;
                    if (map[nx][ny]== 1 || map[nx][ny] == 2) continue;
                    map[nx][ny] = 1;
                    fireQ.add(new Pair(nx, ny));
                }
            }
            cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                Pair now = q.poll();
                int x = now.x;
                int y = now.y;
                for (int j = 0; j < 4; j++) {
                    int nx = now.x + dx[j];
                    int ny = now.y + dy[j];
                    if (nx < 1  || ny <1 || nx > r || ny >c){
                        res = vis[x][y] + 1;
                        break;
                    }
                    if (map[nx][ny]== 1 || map[nx][ny] == 2) continue;
                    map[nx][ny] = 1;
                    vis[nx][ny] = vis[x][y] + 1;
                    q.add(new Pair(nx, ny));
                }
            }
        }
        if (res==-1) bw.write("IMPOSSIBLE\n");
        else bw.write(res+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}