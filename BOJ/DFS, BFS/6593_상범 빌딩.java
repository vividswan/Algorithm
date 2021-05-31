import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair{
    private int x;
    private int y;
    private int z;

    public int getZ() {
        return z;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Pair(int z, int x, int y){
        this.z = z;
        this.x = x;
        this.y = y;
    }
}

public class Main {
    public static int l,r,c;
    public static char[][][] map;
    public static int[][][] vis;
    public static int[] dz = {0,0,0,0,-1, 1};
    public static int[] dx = {1,-1,0,0,0,0,};
    public static int[] dy = {0,0,1,-1,0,0,};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            l = Integer.parseInt(st.nextToken());
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            if(l==0 && r==0 && c==0)  break;
            Pair startPair = null;
            Pair endPair = null;
            map = new char[l+1][r+1][c+1];
            vis = new int[l+1][r+1][c+1];
            for(int k=1; k<=l; k++){
                for(int i=1; i<=r; i++){
                    String str = br.readLine();
                    for(int j=1; j<=c; j++){
                        map[k][i][j]= str.charAt(j-1);
                        if(map[k][i][j] == 'S'){
                            startPair = new Pair(k,i,j);
                        }
                        else if(map[k][i][j]=='E'){
                            endPair = new Pair(k,i,j);
                        }
                        vis[k][i][j] = -1;
                    }
                }
                br.readLine();
            }
            vis[startPair.getZ()][startPair.getX()][startPair.getY()] = 0;
            Queue<Pair>q = new LinkedList<>();
            q.offer(startPair);
            while (!q.isEmpty()){
                Pair pair = q.poll();
                int x = pair.getX();
                int y = pair.getY();
                int z = pair.getZ();
                for(int i=0; i<6;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    int nz= z + dz[i];
                    if(nx<1||ny<1||nz<1||nx>r||ny>c||nz>l) continue;
                    if (map[nz][nx][ny]=='#') continue;
                    if (vis[nz][nx][ny]!=-1) continue;
                    vis[nz][nx][ny] = vis[z][x][y] + 1;
                    q.offer(new Pair(nz,nx,ny));
                }
            }
            if(vis[endPair.getZ()][endPair.getX()][endPair.getY()]==-1) bw.write("Trapped!\n");
            else bw.write("Escaped in "+vis[endPair.getZ()][endPair.getX()][endPair.getY()]+" minute(s).\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}