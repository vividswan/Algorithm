import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    public static double recur(int idx) {
        if (node[idx] == '0') {
            return value[idx];
        } else {
            double num1 = recur(child[idx][0]);
            double num2 = recur(child[idx][1]);
            double res = 0;
            if (node[idx] == '+') res = num1 + num2;
            else if(node[idx] == '-') res = num1 - num2;
            else if(node[idx] == '*') res = num1 * num2;
            else res = num1 / num2;
            node[idx] = '0';
            return value[idx] = res;
        }
    }
    public static int  n;
    public static int[][] child;
    public static double[] value;
    public static char[] node;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int t = 1; t <= 10; t++) {
            n = Integer.parseInt(br.readLine());
            child = new int[n + 1][2];
            value = new double[n + 1];
            node = new char[n+1];
            for (int i = 1; i <= n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int idx = Integer.parseInt(st.nextToken());
                String next = st.nextToken();
                char temp = next.charAt(0);
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
                    node[idx] = temp;
                    child[idx][0] = Integer.parseInt(st.nextToken());
                    child[idx][1] = Integer.parseInt(st.nextToken());
                }
                else {
                    node[idx] = '0';
                    value[idx] = Double.parseDouble(next);
                }
            }
            recur(1);
            bw.write("#"+t+" "+String.valueOf((int)value[1])+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}