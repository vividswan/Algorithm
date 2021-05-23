import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static final int MAX =  100*100+1;
    public static int[] dp = new int[MAX];
    public static int n,m;
    public static int[] val;
    public static int[] cost;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());


        val = new int[n];
        cost = new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) val[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) cost[i] = Integer.parseInt(st.nextToken());

        for(int i=0; i<n; i++){
            int nowCost = cost[i];
            for(int j=MAX-1;j>=nowCost; j--){
                dp[j] = Math.max(dp[j],dp[j-nowCost]+val[i]);
            }
        }
        for(int i=0; i<MAX; i++){
            if(dp[i]>=m) {
                bw.write(String.valueOf(i)+"\n");
                break;
            }
        }
        bw.flush();
        br.close();
        bw.close();
    }
}