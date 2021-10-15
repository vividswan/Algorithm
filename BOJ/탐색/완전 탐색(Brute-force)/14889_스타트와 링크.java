import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int[][] map;
    static boolean[] chk;
    static int res = -1;

    static void recursion(int idx, int cnt) {
        if(cnt ==n/2){
            int tot1 = 0;
            int tot2 = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if(i==j) continue;
                    if(chk[i] && chk[j]) tot1 += map[i][j];
                    else if(!chk[i] && !chk[j]) tot2 += map[i][j];
                }
            }
            int tempRes = Math.abs(tot1 - tot2);
            if(res == -1) res = tempRes;
            else res = Math.min(res, tempRes);
            return;
        }

        for (int i = idx; i <=n ; i++) {
            if (!chk[i]) {
                chk[i] = true;
                recursion(i,cnt+1);
                chk[i] = false;
            }
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        map = new int[n + 1][n + 1];
        chk = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <=n ; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        recursion(1, 0);
        bw.write(res+"\n");
        bw.flush();
        br.close();
        bw.close();


    }
}