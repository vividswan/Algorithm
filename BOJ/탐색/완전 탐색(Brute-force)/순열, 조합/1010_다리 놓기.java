import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int t,n,m,res;
    public static boolean[] chk;
    public static int[][] dp = new int[31][31];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 31; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i < 31; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        t= Integer.parseInt(st.nextToken());
        for(int i=0; i<t; i++){
            res = 0;
            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            chk = new boolean[m];
            bw.write(String.valueOf(dp[n][m])+"\n");
        }
        bw.flush();
        br.close();
        bw.close();

    }
}