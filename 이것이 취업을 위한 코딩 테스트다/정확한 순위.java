import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int n, m;
    public static int[][] map;
    public static final int INF = (int)1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n+1][n+1];
        for(int i=0; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i!=j) map[i][j] = INF;
            }
        }
        for(int i=1; i<=m; i++){
            st= new StringTokenizer(br.readLine());
            int go = Integer.parseInt(st.nextToken());
            int ed = Integer.parseInt(st.nextToken());
            map[go][ed] = 1;
        }
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(map[i][j] > map[i][k]+map[k][j]){
                        map[i][j] = map[i][k]+map[k][j];
                    }
                }
            }
        }
        int cnt = 0;
        for(int i=1; i<=n; i++){
            int flagCnt= 0;
            for(int j=1; j<=n; j++){
                if(map[i][j]==INF && map[j][i]==INF) break;
                flagCnt++;
            }
            if(flagCnt==n) cnt++;
        }
        bw.write(String.valueOf(cnt)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}