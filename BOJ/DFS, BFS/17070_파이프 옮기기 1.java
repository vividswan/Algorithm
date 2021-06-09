import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int n, res;
    public static int[][] map;
    public static void dfs(int dir, int x, int y){
        if (dir==0 && x==n && y == n-1){
            res++;
            return;
        }

        if (dir==1 && x==n-1 && y == n-1){
            res++;
            return;
        }

        if (dir==2 && x==n-1 && y == n){
            res++;
            return;
        }

        if (dir==0){
            int nx = x;
            int ny = y+1;
            if (nx<=n && ny+1<=n){
                if (map[nx][ny+1]==0) dfs(dir,nx,ny);
            }
            if (nx+1<=n && ny+1<=n){
                if (map[nx+1][ny+1]==0 && map[nx][ny+1]==0 && map[nx+1][ny]==0) dfs(1,nx,ny);
            }
        }
        else if(dir == 1){
            int nx = x+1;
            int ny = y+1;
            if (nx<=n && ny+1<=n){
                if (map[nx][ny+1] == 0) dfs(0,nx,ny);
            }
            if (nx+1<=n && ny<=n){
                if (map[nx+1][ny]==0) dfs(2,nx,ny);
            }
            if (nx+1<=n && ny+1<=n){
                if (map[nx+1][ny+1]==0 && map[nx][ny+1]==0 && map[nx+1][ny]==0) dfs(dir,nx,ny);
            }
        }
        else {
            int nx = x+1;
            int ny = y;
            if (nx+1<=n && ny<=n){
                if (map[nx+1][ny]==0) dfs(dir,nx,ny);
            }
            if (nx+1<=n && ny+1<=n){
                if (map[nx+1][ny+1]==0 && map[nx][ny+1]==0 && map[nx+1][ny]==0) dfs(1,nx,ny);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        map = new int[n+1][n+1];
        for(int i=1; i<=n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dfs(0,1,1);
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        bw.close();
        br.close();
    }
}