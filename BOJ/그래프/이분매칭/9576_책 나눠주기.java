import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int t,n,m;
    public static boolean[][] adj;
    public static int[] aMatch;
    public static int[] bMatch;
    public static boolean[] vis;

    public static boolean dfs(int idx){
        if(vis[idx]) return false;
        vis[idx] = true;
        for(int i=1; i<=n; i++){
            if(adj[idx][i]){
                if(bMatch[i]==-1 || dfs(bMatch[i])){
                    aMatch[idx] = i;
                    bMatch[i] = idx;
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        t = Integer.parseInt(br.readLine());
        for(int k=0; k<t; k++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            aMatch = new int[m+1];
            bMatch = new int[n+1];
            for(int i=1; i<=m; i++) aMatch[i] = -1;
            for(int i=1; i<=n; i++) bMatch[i] = -1;
            adj = new boolean[m+1][n+1];

            for(int i=1; i<=m; i++){
                st = new StringTokenizer(br.readLine());
                int a, b;
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                for(int j=a; j<=b; j++){
                    adj[i][j] = true;
                }
            }
            int res = 0;
            for(int i=1; i<=m; i++){
                vis = new boolean[m+1];
                if(dfs(i)) res++;
            }
            bw.write(String.valueOf(res)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}