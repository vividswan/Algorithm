import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    public static int t;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        t = Integer.parseInt(br.readLine());
        for (int k = 1; k <= t; k++) {
            int n, m;
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            boolean isOn = true;
            for (int i = n - 1; i >= 0; i--) {
                int val = m & (1 << i);
                if (val==0){
                    isOn = false;
                    break;
                }
            }
            bw.write("#"+k+" ");
            if (isOn) bw.write("ON\n");
            else bw.write("OFF\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}