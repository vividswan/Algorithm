import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Node implements Comparable<Node>{
    private int idx;
    private int val;

    public Node(int idx, int val){
        this.idx = idx;
        this.val = val;
    }

    public int getVal() {
        return val;
    }

    public int getIdx() {
        return idx;
    }

    @Override
    public int compareTo(Node o) {
        return Integer.compare(this.val, o.val);
    }
}

public class Main {

    public static int n,p,k, le, ri;
    public static final int INF =(int)1e9;
    public static int[] cntTable;
    public static boolean[] vis;
    public static ArrayList<ArrayList<Node>> graph = new ArrayList<ArrayList<Node>>();
    public static boolean isPossible(int val){
        cntTable = new int[n+1];
        vis = new boolean[n+1];
        for(int i=0; i<=n; i++) cntTable[i] = INF;
        cntTable[1] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(1,0));
        while (!pq.isEmpty()){
            Node node = pq.poll();
            int nowIdx = node.getIdx();
            if(vis[nowIdx]) continue;
            vis[nowIdx] = true;
            for(int i =0; i<graph.get(nowIdx).size(); i++){
                int nextIdx = graph.get(nowIdx).get(i).getIdx();
                int nextVal = graph.get(nowIdx).get(i).getVal();
                int tempNext = cntTable[nowIdx];
                if(nextVal> val) tempNext++;
                if(tempNext >= cntTable[nextIdx]) continue;
                cntTable[nextIdx] = tempNext;
                pq.offer(new Node(nextIdx,  cntTable[nextIdx]));
            }
        }
        if(cntTable[n]==INF) return false;
        else return cntTable[n] <= k;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());


        for (int i=0; i<=n; i++) graph.add(new ArrayList<>());

        for(int i=0; i<p; i++){
            int start, end, val;
            st = new StringTokenizer(br.readLine());
            start = Integer.parseInt(st.nextToken());
            end = Integer.parseInt(st.nextToken());
            val = Integer.parseInt(st.nextToken());
            ri = Math.max(ri,val);

            graph.get(start).add(new Node(end,val));
            graph.get(end).add(new Node(start,val));
        }

        int res = INF;
        while (le<=ri){
            int mid = (le+ri)/2;
            if(isPossible(mid)) {
                res = mid;
                ri = mid-1;
            }
            else le = mid+1;
        }
        if(res==INF) bw.write("-1\n");
        else bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}