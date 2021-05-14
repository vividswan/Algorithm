import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int n, m;
    public static int[] target;
    public static int[] find;
    public static boolean[][] dp;
    public static void recursion(int idx, int val){
        if(idx==n) return;

        if(!dp[idx][val]){
            dp[idx][val] = true;
            recursion(idx+1,val);
        }

        if(!dp[idx][target[idx]+val]){
            dp[idx][target[idx]+val] = true;
            recursion(idx+1,target[idx]+val);
        }

        if(!dp[idx][Math.abs(target[idx]-val)]){
            dp[idx][Math.abs(target[idx]-val)] = true;
            recursion(idx+1,Math.abs(target[idx]-val));
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        target = new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) target[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        find = new int[m];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<m;i++) find[i] = Integer.parseInt(st.nextToken());

        dp = new boolean[n][40001];
        recursion(0,0);

        for(int i=0; i<m; i++) {
            if(dp[n-1][find[i]]) bw.write("Y ");
            else bw.write("N ");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}