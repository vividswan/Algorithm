import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void dfs(int idx){
        if(idx>n) return;
        if (idx<1) return;
        if (chk[idx]) return;
        chk[idx] = true;
        res++;
        dfs(idx+map[idx]);
        dfs(idx-map[idx]);
    }
    public static int n, first, res;
    public static int[] map;
    public static boolean[] chk;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        map = new int[n+1];
        chk = new boolean[n+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++){
            map[i] = Integer.parseInt(st.nextToken());
        }
        first = Integer.parseInt(br.readLine());
        dfs(first);
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}