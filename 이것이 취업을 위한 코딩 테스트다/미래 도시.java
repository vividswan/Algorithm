import java.io.*;
import java.util.StringTokenizer;

public class 미래 도시 {

    public static int n,m;
    public static int[][] dist;
    public static final int INF = (int)1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        dist = new int[n+1][n+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i!=j) dist[i][j] = INF;
            }
        }

        for(int i=1; i<=m; i++){
            st = new StringTokenizer(br.readLine());
            int x,y;
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());

            dist[x][y] = 1;
            dist[y][x] = 1;
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    dist[i][j] = Math.min(dist[i][k]+dist[k][j],dist[i][j]);
                }
            }
        }

        st = new StringTokenizer(br.readLine());
        int x,k;
        x = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        int res = 0;

        if(dist[1][k]==INF || dist[k][x] ==INF) res=-1;
        else{
            res = dist[1][k] + dist[k][x];
        }

        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}