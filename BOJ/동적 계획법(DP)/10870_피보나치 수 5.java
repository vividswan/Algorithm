import java.io.*;
import java.util.Arrays;

public class Main {
    public static int n;
    public static long[] dp;
    public static long recursion(int idx){
        if (dp[idx]!=-1) return dp[idx];
        return dp[idx] = recursion(idx-1) + recursion(idx-2);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        if (n==0) bw.write("0\n");
        else{
            dp = new long[n+1];
            Arrays.fill(dp,-1);
            dp[0] = 0;
            dp[1] = 1;
            bw.write(String.valueOf(recursion(n))+"\n");
        }
        bw.flush();
        br.close();
        bw.close();

    }
}