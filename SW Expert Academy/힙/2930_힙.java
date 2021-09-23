import java.io.*;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
    public static int testCase, n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            n = Integer.parseInt(br.readLine());
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            Queue<Integer> integers = new LinkedList<>();
            for (int i = 1; i <= n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int oper = Integer.parseInt(st.nextToken());
                if (oper == 1) pq.add(-1 * Integer.parseInt(st.nextToken()));
                else {
                    if (pq.isEmpty()) integers.add(-1);
                    else integers.add(-1 * pq.poll());
                }
            }
            bw.write("#"+t);
            while (!integers.isEmpty()) bw.write(" " + integers.poll());
            bw.write("\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}