import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

class Pair {
    private int x;
    private int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

}

public class Solution {
    public static int testCase, n , k;
    public static int[][] dp;
    public static Pair[] pairs;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            dp = new int[n+1][k + 1];
            pairs = new Pair[n+1];
            for (int i = 1; i <=n ; i++) {
                st = new StringTokenizer(br.readLine());
                int v = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                pairs[i] = new Pair(v, c);
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= k ; j++) {
                    if (j-pairs[i].getX() < 0 ) dp[i][j] = dp[i - 1][j];
                    else dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - pairs[i].getX()] + pairs[i].getY());
                }
            }

            bw.write("#"+t+" "+dp[n][k]+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}