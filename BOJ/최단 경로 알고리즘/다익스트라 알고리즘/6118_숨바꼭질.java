import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Node implements Comparable<Node>{
    private final int idx;
    private final int value;

    public int getIdx() {
        return idx;
    }

    public int getValue() {
        return value;
    }

    public Node(int idx, int value){
        this.idx = idx;
        this.value = value;
    }

    @Override
    public int compareTo(Node other) {
        return Integer.compare(this.value, other.value);
    }
}

public class 6118_숨바꼭질 {
    public static int n,m;
    public static final  int INF = (int) 1e9;
    public static ArrayList<ArrayList<Integer>> arr =  new ArrayList<ArrayList<Integer>>();
    public static int[] distTable;
    public static void dijkstra(){
        distTable[1] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(1,0));
        while(!pq.isEmpty()){
            Node node = pq.poll();
            int idx = node.getIdx();
            int value = node.getValue();
            for(int i=0;i<arr.get(idx).size();i++){
                int next = arr.get(idx).get(i);
                if(value+1 < distTable[next]){
                    distTable[next] = value+1;
                    pq.offer(new Node(next,distTable[next]));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        distTable = new int[n+1];
        Arrays.fill(distTable,INF);

        for(int i=0; i<=n; i++) arr.add(new ArrayList<Integer>());
        for(int i=1; i<=m; i++){
            int x, y;
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            arr.get(x).add(y);
            arr.get(y).add(x);
        }
        dijkstra();
        int maxDist = 0;
        int resIdx = 0;
        int cnt = 0;
        for(int i=2; i<=n; i++){
            int beforeMaxDist = maxDist;
            maxDist = Math.max(distTable[i],maxDist);
            if(beforeMaxDist!=maxDist) {
                resIdx = i;
                cnt = 0;
            }
            if (maxDist==distTable[i]) cnt++;
        }
        bw.write(String.valueOf(resIdx)+" "+String.valueOf(distTable[resIdx])+" "+String.valueOf(cnt)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}