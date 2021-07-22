import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Bridge implements Comparable<Bridge>{
    private int destination;
    private int cost;

    public int getDestination() {
        return destination;
    }

    public int getCost() {
        return cost;
    }

    public Bridge(int destination, int cost) {
        this.destination = destination;
        this.cost = cost;
    }

    @Override
    public int compareTo(Bridge other) {
        return Integer.compare(this.cost, other.cost);
    }
}

public class Solution {
    public static int testCase;
    public static final int INF = 100000000;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int[] distTable = new int[n + 1];
            int[] reverseDistTable = new int[n + 1];
            Arrays.fill(distTable,INF);
            Arrays.fill(reverseDistTable,INF);
            distTable[end] = 0;
            reverseDistTable[end] = 0;
            ArrayList<ArrayList<Bridge>> graph = new ArrayList<>();
            ArrayList<ArrayList<Bridge>> reverseGraph = new ArrayList<>();
            for(int i=0; i<=n; i++) graph.add(new ArrayList<>());
            for(int i=0; i<=n; i++) reverseGraph.add(new ArrayList<>());
            for (int i = 1; i <= m; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int cost = Integer.parseInt(st.nextToken());
                graph.get(x).add(new Bridge(y,cost));
                reverseGraph.get(y).add(new Bridge(x,cost));
            }
            PriorityQueue<Bridge> pq = new PriorityQueue<>();
            pq.add(new Bridge(end, 0));
            while (!pq.isEmpty()) {
                Bridge bridge = pq.poll();
                int now = bridge.getDestination();
                int cost = bridge.getCost();
                if (distTable[now] < cost) continue;
                for (int i = 0; i < graph.get(now).size(); i++) {
                    int next = graph.get(now).get(i).getDestination();
                    int nextCost = cost + graph.get(now).get(i).getCost();
                    if (distTable[next] > nextCost) {
                        distTable[next] = nextCost;
                        pq.offer(new Bridge(next, nextCost));
                    }
                }
            }
            pq.add(new Bridge(end, 0));
            while (!pq.isEmpty()) {
                Bridge bridge = pq.poll();
                int now = bridge.getDestination();
                int cost = bridge.getCost();
                if (reverseDistTable[now] < cost) continue;
                for (int i = 0; i < reverseGraph.get(now).size(); i++) {
                    int next = reverseGraph.get(now).get(i).getDestination();
                    int nextCost = cost + reverseGraph.get(now).get(i).getCost();
                    if (reverseDistTable[next] > nextCost) {
                        reverseDistTable[next] = nextCost;
                        pq.offer(new Bridge(next, nextCost));
                    }
                }
            }
            int res = 0;
            for (int i = 1; i <= n; i++) res = Math.max(res, distTable[i] + reverseDistTable[i]);
            bw.write("#"+t+" "+String.valueOf(res)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}