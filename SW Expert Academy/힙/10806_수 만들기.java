import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Pair implements Comparable<Pair>{
    private int x;
    private int y;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    @Override
    public int compareTo(Pair other) {
        return Integer.compare(this.x, other.x);
    }

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Solution {
    public static int testCase, n, k;
    public static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr = new int[n + 1];
            for (int i = 1; i <= n ; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            k = Integer.parseInt(br.readLine());
            PriorityQueue<Pair> pq = new PriorityQueue<>();
            pq.add(new Pair(0, k));
            while (!pq.isEmpty()) {
                if (pq.peek().getY() == 0) break;
                Pair poll = pq.poll();
                int x = poll.getX();
                int y = poll.getY();
                pq.add(new Pair(x + y, 0));
                for (int i = 1; i <= n; i++) {
                    pq.add(new Pair(x + y % arr[i], y / arr[i]));
                }
            }
            bw.write("#"+t+" "+pq.peek().getX()+"\n");
        }
        bw.flush();
        br.close();
        bw.close();

    }
}