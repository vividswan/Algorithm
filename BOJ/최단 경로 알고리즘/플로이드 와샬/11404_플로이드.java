import java.io.*;
import java.util.StringTokenizer;

public class 11404_플로이드 {
    public static int[][] map;
    public static int n,m;
    public static final int INF = (int) 1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        map = new int[n+1][n+1];

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i!=j) map[i][j] = INF;
            }
        }

        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());

        for(int i=0;i<m;i++){
            int x,y,cost;
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            cost = Integer.parseInt(st.nextToken());
            map[x][y] = Math.min(map[x][y],cost);
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n;j++){
                    int cost = map[i][k]+map[k][j];
                    if(cost<map[i][j]) map[i][j] = cost;
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1; j<=n;j++){
                if(map[i][j] == INF) bw.write("0 ");
                else bw.write(String.valueOf(map[i][j]+" "));
            }
            bw.write("\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }
}