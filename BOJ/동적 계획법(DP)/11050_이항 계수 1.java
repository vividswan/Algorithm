import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static final int MAX = 10;
    public static int n;
    public static int m;
    public static int[][] dp = new int[MAX + 1][MAX + 1];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i=0; i<=MAX; i++) dp[i][0] = 1;
        for(int i=1; i<=MAX; i++){
            for(int j=1; j<=MAX; j++){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        bw.write(String.valueOf(dp[n][m])+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}