import java.io.*;
import java.util.StringTokenizer;

class Pair{
    private int num;
    private int dir;

    public int getNum() {
        return num;
    }

    public int getDir() {
        return dir;
    }

    public Pair(int num, int dir){
        this.num = num;
        this.dir = dir;
    }
}

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

public class 19236_청소년 상어 {
    public static Pair[][] map = new Pair[5][5];
    public static Position[] pos = new Position[17];
    public static int[] dx = {0,-1,-1,0,1,1,1,0,-1};
    public static int[] dy = {0, 0,-1,-1,-1,0,1,1,1};
    public static String[] dstr = {"0","↑","↖" ,"←", "↙", "↓", "↘", "→", "↗" };
    public static int sharkX;
    public static int sharkY;
    public static int sharkDir;
    public static int res;
    public static int maxRes;
    public static void moving(){
        for(int i=1; i<=16;i++){
            int x = pos[i].getX();
            int y = pos[i].getY();
            if(x==0 || y==0) continue;
            int dir = map[x][y].getDir();
            int cnt=0;
            dir--;
            while(true){
                cnt++;
                if(cnt==9) break;
                dir++;
                if(dir>8) dir=1;
                int nx = x+dx[dir];
                int ny = y+dy[dir];
                if(nx<1||ny<1||nx>4||ny>4) continue;
                if(sharkX==nx&&sharkY==ny) continue;
                Pair temp = new Pair(i,dir);
                map[x][y] = new Pair(map[nx][ny].getNum(),map[nx][ny].getDir());
                map[nx][ny]= temp;
                pos[i]=new Position(nx,ny);
                pos[map[x][y].getNum()] = new Position(x,y);
//                if(i==3) System.out.println(map[x][y].getNum());
                break;
            }
        }
    }
    public static void recursion(){
        moving();
        int nx = sharkX;
        int ny = sharkY;
        while (true){
            nx += dx[sharkDir];
            ny += dy[sharkDir];
            if(nx<1||ny<1||nx>4||ny>4) break;
            if(map[nx][ny].getNum()==0) continue;
            Position[] tempPos = new Position[17];
            for(int i=1;i<=16;i++){
                tempPos[i] = pos[i];
            }
            Pair[][] tempMap = new Pair[5][5];
            for(int i=1; i<=4;i++){
                for(int j=1; j<=4; j++){
                    tempMap[i][j] = map[i][j];
                }
            }
            int tempSharkX = sharkX;
            int tempSharkY = sharkY;
            int tempSharkDir = sharkDir;
            res+=map[nx][ny].getNum();
            maxRes = Math.max(maxRes,res);
            sharkX = nx;
            sharkY = ny;
            sharkDir = map[nx][ny].getDir();
            pos[map[nx][ny].getNum()] = new Position(0,0);
            map[nx][ny]= new Pair(0,0);
            recursion();
            for(int i=1; i<=4;i++){
                for(int j=1; j<=4; j++){
                    map[i][j] = tempMap[i][j];
                }
            }
            for(int i=1;i<=16;i++){
                pos[i] = tempPos[i];
            }
            pos[map[nx][ny].getNum()] = new Position(nx,ny);
            sharkDir = tempSharkDir;
            sharkX = tempSharkX;
            sharkY = tempSharkY;
            res -= map[nx][ny].getNum();
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        for(int i=1; i<=4;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=4;j++){
                int num = Integer.parseInt(st.nextToken());
                int dir = Integer.parseInt(st.nextToken());
                map[i][j] = new Pair(num,dir);
                pos[num] = new Position(i,j);
            }
        }

        sharkX = 1;
        sharkY = 1;
        sharkDir = map[1][1].getDir();
        res+=map[1][1].getNum();
        pos[map[1][1].getNum()] = new Position(0,0);
        map[1][1] = new Pair(0,0);
        recursion();
        bw.write(String.valueOf(maxRes));
        bw.flush();
        br.close();
        bw.close();
    }
}