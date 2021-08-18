import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    public static int n;
    public static char[] oper;
    public static boolean ans;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int t = 1; t <= 10; t++) {
            ans = true;
            n = Integer.parseInt(br.readLine());
            oper = new char[n + 1];
            for (int i = 1; i <= n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int idx = Integer.parseInt(st.nextToken());
                String now = st.nextToken();
                char c = now.charAt(0);
                if (c == '-' || c == '+' || c == '*' || c == '/') {
                    oper[idx] = c;
                }
                else {
                    oper[idx] = '0';
                }
            }
            for (int i = 1; i <=n/2 ; i++) {
                if (oper[i] == '0') ans = false;
            }
            for (int i = n/2+1; i <=n ; i++) {
                if (oper[i] != '0') ans = false;
            }
            if (ans) bw.write("#"+t+" "+"1\n");
            else bw.write("#"+t+" "+"0\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}