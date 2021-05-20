import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static int[] arr;
    public static int[] pre;
    public static int[] dp;
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        dp = new int[n];
        pre = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            dp[i] = 1;
            pre[i] = i;
            arr[i] = Integer.parseInt(st.nextToken());
        }
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(arr[j] > arr[i]){
                    dp[j] = Math.max(dp[j], dp[i]+1);
                    if(dp[j] == dp[i] +1) pre[j] = i;
                }
            }
        }
        int resCnt = 0;
        int resNum = 0;
        for(int i=0; i<n; i++) {
            resCnt = Math.max(resCnt,dp[i]);
            if(resCnt==dp[i]) resNum = i;
        }
        Stack<Integer> s = new Stack<>();
        s   .push(arr[resNum]);
        while (true){
            if(pre[resNum] == resNum) break;
            s.push(arr[pre[resNum]]);
            resNum = pre[resNum];
        }
        bw.write(s.size()+"\n");
        while (!s.isEmpty()){
            bw.write(String.valueOf(s.pop())+" ");
        }
        bw.write("\n");
        bw.flush();
        br.close();
        bw.close();


    }
}