import java.io.*;

public class Solution {
    public static int dp[][];
    public static final int MOD = 1000000007;
    public static int t;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        t = Integer.parseInt(br.readLine());
        for (int k = 1; k <= t; k++) {
            String mandatory = br.readLine();
            dp = new int[mandatory.length()][16];
            for(int i=1; i<=15;i++){
                if ((i & 1)==1 && (i & 1 << (mandatory.charAt(0)-'A')) >= 1) dp[0][i] = 1;
            }
            for (int i = 1; i < mandatory.length(); i++) {
                int nowMandNum = mandatory.charAt(i) - 'A';
                for (int j = 1; j <= 15; j++) {
                    if ((j & 1 << nowMandNum)==0) continue;
                    for(int l = 1; l<=15; l++){
                        if ((j & l)  > 0){
                            dp[i][j] += dp[i - 1][l];
                            dp[i][j] %= MOD;
                        }
                    }
                }
            }
            int res = 0;
            for(int i=1; i<=15; i++){
                res += dp[mandatory.length() - 1][i];
                res %= MOD;
            }
            bw.write("#"+k+" "+String.valueOf(res)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}