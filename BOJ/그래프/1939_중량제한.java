import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Pair implements Comparable<Pair>{
    int x;
    long y;

    public Pair(int x, long y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pair other){
        return Long.compare(other.y, this.y);
    }

}

public class Main {
    public static int n, m;
    public static int MAX = 1000000000;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        ArrayList<ArrayList<Pair>> list = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            list.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int go, ed, cost;
            st = new StringTokenizer(br.readLine());
            go = Integer.parseInt(st.nextToken());
            ed = Integer.parseInt(st.nextToken());
            cost = Integer.parseInt(st.nextToken());
            list.get(go).add(new Pair(ed, cost));
            list.get(ed).add(new Pair(go, cost));
        }
        int start, end;
        st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());
        long[] dist = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            if (i == start) dist[i] = MAX + 1;
            else dist[i] = -1;
        }
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        boolean[] vis = new boolean[n + 1];
        pq.add(new Pair(start, MAX+1));
        while (!pq.isEmpty()) {
            Pair pair = pq.poll();
            int now = pair.x;
            if (vis[now]) continue;
            vis[now] = true;
            for (int i = 0; i < list.get(now).size(); i++) {
                int next = list.get(now).get(i).x;
                long nextCost = list.get(now).get(i).y;
                if (Math.min(dist[now], nextCost) > dist[next]) {
                    dist[next] = Math.min(dist[now], nextCost);
                    pq.add(new Pair(next, dist[next]));
                }
            }
        }
        bw.write(dist[end]+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}