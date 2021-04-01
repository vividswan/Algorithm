import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node{
    private int x;
    private int y;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Node(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class 3190_뱀 {
    public static int n,k,l;
    public static int[][] map;
    public static int[] rot = new int[10001];
    public static int x, y, dirVal;
    public static int[] dx = {0,-1,0,1};
    public static int[] dy = {1,0,-1,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        map = new int[n+1][n+1];

        st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());
        for(int i=0; i<k; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            map[x][y] = 1;
        }

        st = new StringTokenizer(br.readLine());
        l = Integer.parseInt(st.nextToken());

        for(int i=0; i<l; i++){
            st = new StringTokenizer(br.readLine());
            int sec = Integer.parseInt(st.nextToken());
            char dir = st.nextToken().charAt(0);
            if(dir=='L') rot[sec] = -1;
            else rot[sec] = 1;
        }

        Queue<Node> q = new LinkedList<>();

        int sec = 0;
        x = 1;
        y = 1;
        map[x][y] = 2;
        q.offer(new Node(x,y));
        dirVal = 0;
        while(true) {
            sec++;
            int nx = x + dx[dirVal];
            int ny = y + dy[dirVal];
            if (nx < 1 || ny < 1 || nx > n || ny > n) break;
            if (map[nx][ny] == 2) break;
            q.offer(new Node(nx, ny));
            x = nx;
            y = ny;
            if(map[nx][ny] != 1) {
                Node node = q.poll();
                map[node.getX()][node.getY()] = 0;
            }
            map[nx][ny] = 2;
            if (rot[sec] != 0) {
                if (rot[sec] == 1) {
                    dirVal--;
                    if (dirVal == -1) dirVal = 3;
                } else {
                    dirVal++;
                    if (dirVal == 4) dirVal = 0;
                }
            }
        }

        bw.write(String.valueOf(sec));
        bw.flush();
        br.close();
        bw.close();

    }
}