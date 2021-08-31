import java.io.*;

public class Solution {
    public static int testCase;
    public static int[] arr = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
    public static int[] cnt;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            int num = Integer.parseInt(br.readLine());
            cnt = new int[arr.length];
            for (int i = 0; i < arr.length; i++) {
                cnt[i] = num / arr[i];
                num %= arr[i];
            }
            bw.write("#"+t+"\n");
            for(int i=0; i<arr.length; i++) bw.write(cnt[i]+" ");
            bw.write("\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}