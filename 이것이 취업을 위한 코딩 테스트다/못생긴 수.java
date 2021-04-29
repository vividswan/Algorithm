import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int twoIdx, threeIdx, fiveIdx, n;
    public static int idx = 1;
    public  static int[] dp = new int[1001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        dp[1] = 1;
        twoIdx = 1;
        threeIdx = 1;
        fiveIdx = 1;
        while(idx<1000){
            idx++;
            int minVal = Math.min(dp[twoIdx]*2, dp[threeIdx]*3);
            minVal = Math.min(minVal,dp[fiveIdx]*5);
            if(minVal == dp[twoIdx]*2){
                dp[idx] = dp[twoIdx]*2;
                twoIdx++;
            }
            if(minVal == dp[threeIdx]*3){
                dp[idx] = dp[threeIdx]*3;
                threeIdx++;
            }
            if(minVal == dp[fiveIdx]*5) {
                dp[idx] = dp[fiveIdx]*5;
                fiveIdx++;
            }
        }
        bw.write(String.valueOf(dp[n])+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}