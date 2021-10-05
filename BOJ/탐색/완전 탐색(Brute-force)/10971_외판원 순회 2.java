import java.awt.print.Pageable;
import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static int[][] map;
    public static boolean[] chk;
    public static int res = (int)1e9;
    public static void recursion(int cnt, int now,int val){
        if (cnt==n && now == 1){
            res = Math.min(val,res);
            return;
        }
        for(int i=1; i<=n; i++){
            if (chk[i] || map[now][i] == 0) continue;
            chk[i] = true;
            recursion(cnt+1,i,val+map[now][i]);
            chk[i] = false;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        map = new int[n+1][n+1];
        chk = new boolean[n+1];
        for(int i=1; i<=n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        recursion(0,1,0);
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}