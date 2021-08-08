import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution {
    public static int testCase, n, a;
    public static final int MOD = 20171109;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            int sum = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            PriorityQueue<Integer> minQ = new PriorityQueue<>();
            PriorityQueue<Integer> maxQ = new PriorityQueue<>();
            for (int i = 1; i <= n; i++) {
                st = new StringTokenizer(br.readLine());
                int[] arr = new int[2];
                arr[0] = Integer.parseInt(st.nextToken());
                arr[1] = Integer.parseInt(st.nextToken());
                for (int j = 0; j < 2; j++) {
                    int num = arr[j];
                    if (num < a) minQ.add(-1 * num);
                    else maxQ.add(num);
                }
                if (minQ.size() > maxQ.size()) {
                    maxQ.add(a);
                    a = -1 * minQ.poll();
                }
                else if (minQ.size() < maxQ.size()) {
                    minQ.add(-1 * a);
                    a = maxQ.poll();
                }
                sum += a;
                sum %= MOD;
            }
            bw.write("#"+t+" "+sum+"\n");
        }
        bw.flush();
        br.close();
        bw.close();

    }
}