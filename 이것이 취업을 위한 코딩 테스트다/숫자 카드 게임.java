import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 숫자 카드 게임 {

    public static int[][] map;
    public static int[] cost;
    public static int n;
    public static int m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n+1][m+1];
        cost = new int[n+1];
        Arrays.fill(cost, (int)1e9);

        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=m; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                cost[i] = Math.min(cost[i],map[i][j]);
            }
        }

        int result = 0;
        for(int i=1; i<=n; i++) result = Math.max(cost[i],result);

        bw.write(String.valueOf(result)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}