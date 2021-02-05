import java.io.*;
import java.util.StringTokenizer;

class Shark{
    private int x;
    private int y;
    private int dir;
    private int idx;
    private int[][] dirArr;
    public Shark(int x, int y, int dir, int idx){
        this.x = x;
        this.y = y;
        this.dir = dir;
        this.idx = idx;
        this.dirArr = new int[5][5];
    }

    public void setY(int y) {
        this.y = y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setIdx(int idx) {
        this.idx = idx;
    }

    public void setDir(int dir) {
        this.dir = dir;
    }

    public void setDirArr(int[][] dirArr) {
        this.dirArr = dirArr;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getDir() {
        return dir;
    }

    public int getIdx() {
        return idx;
    }

    public int[][] getDirArr() {
        return dirArr;
    }
}

class Position{
    private int x;
    private int y;
    private int scentLen;
    private int sharkIdx;

    public Position(int x, int y, int scentLen, int sharkIdx){
        this.x = x;
        this.y = y;
        this.scentLen = scentLen;
        this.sharkIdx = sharkIdx;
    }

    public void setSharkIdx(int sharkIdx) {
        this.sharkIdx = sharkIdx;
    }

    public void setScentLen(int scentLen) {
        this.scentLen = scentLen;
    }

    public int getSharkIdx() {
        return sharkIdx;
    }

    public int getScentLen() {
        return scentLen;
    }
}

public class 19237_어른 상어 {
    public static int n,m,k;
    public static Position[][] map;
    public static Shark[] sharkArr;
    public static int[] dx = {0,-1,1,0,0};
    public static int[] dy = {0,0,0,-1,1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        map = new Position[n+1][n+1];
        sharkArr = new Shark[m+1];
        for(int i=1; i<=n;i ++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++){
                int now = Integer.parseInt(st.nextToken());
                if(now==0) map[i][j] = new Position(i,j,0,0);
                else {
                    map[i][j]= new Position(i,j,k,now);
                    sharkArr[now] = new Shark(i,j,0,now);
                }
            }
        }
        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=m; i++){
            sharkArr[i].setDir(Integer.parseInt(st.nextToken()));
        }
        for(int i=1; i<=m; i++){
            int[][] temp = new int[5][5];
            for(int j=1; j<=4;j++){
                st = new StringTokenizer(br.readLine());
                for(int k=1; k<=4; k++){
                    temp[j][k] = Integer.parseInt(st.nextToken());
                }
            }
            sharkArr[i].setDirArr(temp);
        }
        int cnt = 0;
        int deadShark = 0;
        while(true){
            if(deadShark==m-1) break;
            cnt++;
            if(cnt>1000) break;
            for(int i=1;i<=m;i++){
                Shark shark = sharkArr[i];
                if(shark.getIdx()==0) continue;
                int dir = shark.getDir();
                int x = shark.getX();
                int y = shark.getY();
                int[][] dirArr = shark.getDirArr();
                boolean isEnd = false;
                for(int k=1;k<=4;k++){
                    int nx = x+dx[dirArr[dir][k]];
                    int ny = y+dy[dirArr[dir][k]];
                    if(nx<1||ny<1||nx>n||ny>n) continue;
                    if(map[nx][ny].getSharkIdx()!=0) continue;
                    sharkArr[i].setX(nx);
                    sharkArr[i].setY(ny);
                    sharkArr[i].setDir(dirArr[dir][k]);
                    isEnd = true;
                    break;
                }
                if(isEnd) continue;
                for(int k=1;k<=4;k++){
                    int nx = x+dx[dirArr[dir][k]];
                    int ny = y+dy[dirArr[dir][k]];
                    if(nx<1||ny<1||nx>n||ny>n) continue;
                    if(map[nx][ny].getSharkIdx()!=shark.getIdx()) continue;
                    sharkArr[i].setX(nx);
                    sharkArr[i].setY(ny);
                    sharkArr[i].setDir(dirArr[dir][k]);
                    break;
                }
            }
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(map[i][j].getScentLen()!=0){
                        map[i][j].setScentLen(map[i][j].getScentLen()-1);
                        if(map[i][j].getScentLen()==0){
                            map[i][j].setSharkIdx(0);
                        }
                    }
                }
            }
            int[][] tempMap = new int[n+1][n+1];
            for(int i=1; i<=m; i++){
                Shark shark = sharkArr[i];
                if(shark.getIdx()==0) continue;
                int x = shark.getX();
                int y= shark.getY();
                if(tempMap[x][y]==1){
                    deadShark++;
                    shark.setIdx(0);
                    continue;
                }
                tempMap[x][y] = 1;
                map[x][y].setSharkIdx(i);
                map[x][y].setScentLen(k);
            }
        }
        if(cnt>1000) bw.write("-1");
        else bw.write(String.valueOf(cnt));
        bw.flush();
        br.close();
        bw.close();
    }
}