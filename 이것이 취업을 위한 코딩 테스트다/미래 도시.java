import java.util.Scanner;

public class Main {

    public static final int INF = (int) 1e9;

    public static int n,m,x,k;
    public static int map[][];

    public static void 미래 도시(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        map = new int[n+1][n+1];

        for(int i=1;i<=n;i++){
            for(int j=1; j<=n;j++){
                if(i==j) map[i][j]=0;
                else map[i][j]=INF;
            }
        }
        for(int i=1;i<=m;i++){
            int x,y;
            x=scanner.nextInt();
            y=scanner.nextInt();
            map[x][y]=1;
            map[y][x]=1;
        }

        x=scanner.nextInt();
        k=scanner.nextInt();

        for(int t=1;t<=n;t++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    int cost = map[i][t]+map[t][j];
                    if(cost<map[i][j]) map[i][j] = cost;
                }
            }
        }

        if(map[1][k]!=INF && map[k][x] != INF) System.out.println(map[1][k]+map[k][x]);
        else System.out.println(-1);
    }
}