import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Bridge implements Comparable<Bridge>{
    public Bridge(int x, int y, long cost) {
        this.x = x;
        this.y = y;
        this.cost = cost;
    }

    private int x;
    private int y;
    private long cost;

    @Override
    public int compareTo(Bridge other) {
        return Long.compare(this.cost, other.cost);
    }

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public long getCost() {
        return cost;
    }


}

class Pair{
    int idx;
    long x;
    long y;

    public int getIdx() {
        return idx;
    }

    public long getX() {
        return x;
    }

    public long getY() {
        return y;
    }

    public Pair(int idx, long x, long y) {
        this.idx = idx;
        this.x = x;
        this.y = y;
    }
}

public class Solution {

    public static int testCase, n;
    private static double e;
    public static int[] parent;
    public static int find(int idx) {
        if (parent[idx] == idx) return idx;
        else return parent[idx] = find(parent[idx]);
    }

    public static void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a==b) return;
        if (a<b) parent[b] = a;
        else parent[a] = b;
    }
    public static long getDist(Pair a, Pair b) {
        long first = a.getX() - b.getX();
        first *= first;
        long second = a.getY() - b.getY();
        second *= second;
        return first + second;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            n = Integer.parseInt(br.readLine());
            parent = new int[n + 1];
            for (int i =1; i <=n ; i++) {
                parent[i] = i;
            }
            ArrayList<Pair> pairs = new ArrayList<>();
            StringTokenizer st1 = new StringTokenizer(br.readLine());
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for(int i=1; i<=n;i++){
                long x = Integer.parseInt(st1.nextToken());
                long y = Integer.parseInt(st2.nextToken());
                pairs.add(new Pair(i, x, y));
            }
            e = Double.parseDouble(br.readLine());
            PriorityQueue<Bridge> pq = new PriorityQueue<>();
            for (int i=0; i<pairs.size()-1;i++) {
                for (int j = i + 1; j < pairs.size(); j++) {
                    pq.offer(new Bridge(pairs.get(i).getIdx(), pairs.get(j).getIdx(), getDist(pairs.get(i), pairs.get(j))));
                }
            }
            long sum = 0;
            while (!pq.isEmpty()) {
                Bridge bridge = pq.poll();
                if (find(bridge.getX()) != find(bridge.getY())){
                    merge(bridge.getX(), bridge.getY());
                    sum += bridge.getCost();
                }
            }
            double res = e * sum;
            if (res - (long)res >= 0.5) res = (long) res + 1;
            else res = (long) res;
            bw.write("#"+t+" "+String.valueOf((long) res   +"\n"));
        }
        bw.flush();
        br.close();
        bw.close();
    }
}