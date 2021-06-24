import java.io.*;

public class Main {
    public static final int MAX = 123456*2;
    public static boolean[] isNotPrime = new boolean[MAX+1];
    public static boolean[] vis = new boolean[MAX+1];
    public static int[] sum = new int[MAX+1];
    public static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        isNotPrime[0] = true;
        isNotPrime[1] = true;
        for(int i=2; i<=Math.sqrt(MAX); i++){
            if (vis[i]) continue;
            vis[i] = true;
            int j = 2;
            while (j*i<=MAX){
                isNotPrime[j*i] = true;
                vis[j*i] = true;
                j++;
            }
        }
        for(int i=2; i<=MAX; i++){
            if (!isNotPrime[i]) sum[i] = sum[i-1] +1;
            else sum[i] = sum[i-1];
        }
        while (true){
            n = Integer.parseInt(br.readLine());
            if (n==0) break;
            int res = sum[2*n] - sum[n];
            bw.write(String.valueOf(res)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}