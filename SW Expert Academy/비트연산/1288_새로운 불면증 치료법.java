import java.io.*;

public class Solution {
    public static int t;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        t = Integer.parseInt(br.readLine());
        for (int k = 1; k <= t; k++) {
            int num = Integer.parseInt(br.readLine());
            int nowNum = num;
            int value = 0;
            int comp = (1 << 10) - 1;
            int cnt = 1;
            while (true){
                int modNum = 1;
                while (modNum <= nowNum) {
                    value |= 1 <<  ((nowNum/ modNum) % 10);
                    modNum *= 10;
                }
                if (value == comp) break;
                cnt++;
                nowNum = num * cnt;
            }
            bw.write("#"+k+" "+nowNum + "\n");
        }
        bw.flush();
        br.close();
    }

}
