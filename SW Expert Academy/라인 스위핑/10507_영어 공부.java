import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    public static int testCase;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            boolean[] vis = new boolean[1200001];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                vis[Integer.parseInt(st.nextToken())] = true;
            }
            int start = 1;
            int res = p+1;
            for (int i = 1; i <= 1200000 ; i++) {
                if (vis[i]){
                    res = Math.max(i-start+1, res);
                }
                else {
                    if (p > 0) {
                        p--;
                        res = Math.max(i-start+1, res);
                        continue;
                    }
                    else{
                        while (vis[start]) start++;
                        start++;
                        res = Math.max(i - start+1, res);
                    }
                }
            }
            bw.write("#"+t+" "+String.valueOf(res)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}