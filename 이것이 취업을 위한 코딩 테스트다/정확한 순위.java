import java.io.*;
import java.util.StringTokenizer;

public class 정확한 순위 {
    public static int n,m;
    public static int[][] map;
    public static final int INF = (int)1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n+1][n+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i != j) map[i][j] = INF;
            }
        }

        for(int i=1;i<=m;i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            map[x][y] = 1;
            map[y][x] = -1;
        }
        for(int k=1; k<=n;k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(map[i][j]!=INF) continue;
                    if(map[i][k]==1 && map[k][j]==1) map[i][j]=1;
                    if(map[i][k]==-1 && map[k][j]==-1) map[i][j]=-1;
                }
            }
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            boolean isAns = true;
            for(int j=1; j<=n; j++){
                if(i==j) continue;
                if(map[i][j]==INF) isAns=false;
            }
            if(isAns) cnt++;
        }
        bw.write(String.valueOf(cnt));
        bw.flush();
        br.close();
        bw.close();

    }
}