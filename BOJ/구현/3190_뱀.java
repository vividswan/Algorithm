import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair{
    private int cnt;
    private String direction;

    Pair(int cnt, String direction){
        this.cnt = cnt;
        this.direction = direction;
    }

    public int getCnt() {
        return cnt;
    }

    public String getDirection() {
        return direction;
    }
}

public class 3190_뱀 {

    public static int[][] map;
    public static int[][] lastMove;
    public static int[] dx = {0,1,0,-1};
    public static int[] dy = {1,0,-1,0};
    public static int dir = 0;

    public static int changeDir(int dir, String command){
        if(command.equals("L")){
            if(dir==0) return 3;
            else return dir-1;
        }
        else {
            if(dir==3) return 0;
            else return dir+1;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        map = new int[n+1][n+1];
        lastMove = new int[n+1][n+1];
        st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken());
        for(int i=0;i<k;i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            map[x][y] = 2;
        }

        Queue<Pair> q = new LinkedList<>();

        st = new StringTokenizer(br.readLine());
        int l = Integer.parseInt(st.nextToken());
        for(int i=0;i<l;i++){
            st = new StringTokenizer(br.readLine());
            int cnt = Integer.parseInt(st.nextToken());
            String direction = st.nextToken();
            q.offer(new Pair(cnt,direction));
        }

        dir = 0;
        int result = 0;
        map[1][1] = 1;
        lastMove[1][1] = dir;
        int nowX = 1;
        int nowY = 1;
        int endX = 1;
        int endY = 1;
        int moveCnt = 0;
        String moveDir = "";
        if(!q.isEmpty()) {
            moveCnt = q.peek().getCnt();
            moveDir = q.peek().getDirection();
        }
        while(true){
            result++;
            if(result==moveCnt+1){
                q.poll();
                dir = changeDir(dir,moveDir);
                if(!q.isEmpty()) {
                    moveCnt = q.peek().getCnt();
                    moveDir = q.peek().getDirection();
                }
            }
            int nextX = nowX + dx[dir];
            int nextY = nowY + dy[dir];
            if(nextX<=0 || nextY<=0 || nextX > n || nextY > n) break;
            if(map[nextX][nextY]==1) break;
            lastMove[nowX][nowY] = dir;
            nowX = nextX;
            nowY = nextY;
            if(map[nextX][nextY]==2){
                map[nextX][nextY] = 1;
                continue;
            }
            else {
                map[nextX][nextY] = 1;
                map[endX][endY] = 0;
                int nowDir= lastMove[endX][endY];
                endX += dx[nowDir];
                endY += dy[nowDir];
            }
        }
        bw.write(String.valueOf(result));
        bw.flush();
        br.close();
        bw.close();
    }

}