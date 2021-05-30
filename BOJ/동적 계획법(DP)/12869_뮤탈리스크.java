import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int dp[][][] = new int[61][61][61];
    public static int n, a, b, c;
    public static final int INF = (int)1e9;
    public static int recursion(int a, int b, int c){
        if (a<0) return recursion(0,b,c);
        if (b<0) return recursion(a,0,c);
        if (c<0) return recursion(a,b,0);
        if (dp[a][b][c] != -1) return dp[a][b][c];
        if (a==0 && b==0 && c==0) return 0;
        dp[a][b][c] = INF;
        dp[a][b][c] = Math.min(dp[a][b][c], recursion(a-9, b-3, c-1)+1);
        dp[a][b][c] = Math.min(dp[a][b][c], recursion(a-9, b-1, c-3)+1);
        dp[a][b][c] = Math.min(dp[a][b][c], recursion(a-3, b-9, c-1)+1);
        dp[a][b][c] = Math.min(dp[a][b][c], recursion(a-1, b-9, c-3)+1);
        dp[a][b][c] = Math.min(dp[a][b][c], recursion(a-3, b-1, c-9)+1);
        dp[a][b][c] = Math.min(dp[a][b][c], recursion(a-1, b-3, c-9)+1);
        return dp[a][b][c];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for(int i =0; i<= 60; i++){
            for(int j=0; j<=60; j++){
                for(int k=0; k<=60; k++){
                    dp[i][j][k] = -1;
                }
            }
        }

        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++){
            if (i==1) a = Integer.parseInt(st.nextToken());
            if (i==2) b = Integer.parseInt(st.nextToken());
            if (i==3) c = Integer.parseInt(st.nextToken());
        }
        bw.write(String.valueOf(recursion(a,b,c))+"\n");
        bw.flush();
        br.close();
        bw.close();


    }
}