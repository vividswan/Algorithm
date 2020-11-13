
import java.util.Scanner;

public class 음료수 얼려 먹기{

    public static int map[][] = new int[1001][1001];
    public static int dx[] = {0,0,-1,1};
    public static int dy[] = {1,-1,0,0};
    public static int vis[][] = new int[1001][1001];
    public static int n,m;

    public static void dfs(int x, int y){
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(map[nx][ny]==1) continue;;
            if(vis[nx][ny]==1) continue;
            vis[nx][ny] = 1;
            dfs(nx,ny);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        scanner.nextLine();

        for(int i=0;i<n;i++){
            String str = scanner.nextLine();
            for(int j=0;j<m;j++){
                map[i][j] = str.charAt(j)-'0';
            }
        }

        int result = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1 || map[i][j]==1) continue;
                result++;
                dfs(i,j);
            }
        }
        System.out.println(result);

    }
}