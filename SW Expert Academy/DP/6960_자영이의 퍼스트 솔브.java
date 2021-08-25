import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

class Pair implements Comparable<Pair>{
    private int x;
    private int y;

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pair other) {
        if(this.y == other.y) return Integer.compare(this.x, other.x);
        else return Integer.compare(this.y, other.y);
    }
}

public class Solution {
    public static int testCase;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            int n = Integer.parseInt(br.readLine());
            ArrayList<Pair> pairs = new ArrayList<>();
            pairs.add(new Pair(-1, -1));
            for (int i = 1; i <= n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int f = Integer.parseInt(st.nextToken());
                if (s > f) continue;
                pairs.add(new Pair(s, f));
            }
            Collections.sort(pairs);
            int size = pairs.size()-1;
            int[][] dp = new int[size + 1][size + 1];
            for (int i = 0; i <= size ; i++) {
                Arrays.fill(dp[i],-1);
            }
            for (int i = 1; i <=size ; i++) {
                dp[i][0] = 0;
                dp[i][1] = pairs.get(i).getX();
            }
            for (int i = 2; i <=size ; i++) {
                for (int j = 1; j <= i ; j++) {
                    if (dp[i - 1][j - 1] != -1) {
                        if (dp[i - 1][j - 1] + pairs.get(i).getX() <= pairs.get(i).getY()) {
                            if (dp[i - 1][j] != -1) {
                                dp[i][j] = Math.min(dp[i - 1][j], dp[i - 1][j - 1] + pairs.get(i).getX());
                            }
                            else dp[i][j] = dp[i - 1][j - 1] + pairs.get(i).getX();
                        }
                        else dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            int res = 0;
            for (int i = 1; i <= size; i++) {
                if (dp[size][i]!=-1) res = i;
            }
            bw.write("#"+t+" "+String.valueOf(res)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}