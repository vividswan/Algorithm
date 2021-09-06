import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Solution {
    public static int testCase, n, m;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            int res = 0;
            HashMap<String, Boolean> map = new HashMap<String, Boolean>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                String str = st.nextToken();
                map.put(str, true);
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < m; i++) {
                String str = st.nextToken();
                if(map.containsKey(str)) res++;
            }
            bw.write("#"+t+" "+res+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}