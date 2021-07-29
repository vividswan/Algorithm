import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n, maxx;
    public static int[] arr;
    public static boolean[] chk;
    public static void dfs(int cnt, int sum){
        if (cnt==n){
            chk[sum] = true;
            return;
        }
        dfs(cnt+1, sum);
        dfs(cnt+1, sum+arr[cnt]);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
            maxx += arr[i];
        }
        maxx++;
        chk = new boolean[maxx+1];
        dfs(0,0);
        for(int i=1; i<=maxx; i++){
            if(!chk[i]){
                bw.write(String.valueOf(i)+"\n");
                break;
            }
        }
        bw.flush();
        br.close();
        bw.close();
    }
}