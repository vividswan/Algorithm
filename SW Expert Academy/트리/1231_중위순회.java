import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    public static void func(int idx) {
        if (child[idx][0]!=-1) func(child[idx][0]);
        sb.append(val[idx]);
        if (child[idx][1]!=-1) func(child[idx][1]);
    }
    public static int n;
    public static int[][] child;
    public static char[] val;
    public static StringBuilder sb;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int t = 1; t <= 10; t++) {
            n = Integer.parseInt(br.readLine());
            val = new char[n + 1];
            child = new int[n + 1][2];
            for (int i = 1; i <= n ; i++) {
                for (int j = 0; j <2 ; j++) {
                    child[i][j] = -1;
                }
            }
            for (int i = 1; i <=n ; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int idx = Integer.parseInt(st.nextToken());
                char c = st.nextToken().charAt(0);
                val[idx] = c;
                if(st.hasMoreTokens()) child[idx][0] = Integer.parseInt(st.nextToken());
                if(st.hasMoreTokens()) child[idx][1] = Integer.parseInt(st.nextToken());
            }
            sb = new StringBuilder();
            func(1);
            bw.write("#"+t+" "+sb.toString()+"\n");
        }
        bw.flush();
        br.close();
        bw.close();

    }
}