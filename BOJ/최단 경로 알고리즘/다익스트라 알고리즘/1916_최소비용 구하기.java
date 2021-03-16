import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Node implements Comparable<Node>{
    private int index;
    private int dist;

    public int getIndex() {
        return index;
    }

    public int getDist() {
        return dist;
    }

    public Node(int index, int dist){
        this.index = index;
        this.dist = dist;
    }

    @Override
    public int compareTo(Node other) {
        return Integer.compare(this.dist,other.dist);
    }
}

public class 1916_최소비용 구하기{
    public static int n,m,c,d;
    public static int[] distTable;
    public static boolean[] vis;
    public static ArrayList<ArrayList<Node>> graph = new ArrayList<ArrayList<Node>>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());

        for(int i=0; i<=n; i++) graph.add(new ArrayList<Node>());
        distTable = new int[n+1];
        Arrays.fill(distTable,(int)1e9);
        vis = new boolean[n+1];

        for(int i=1; i<=m; i++){
            st = new StringTokenizer(br.readLine());
            int x,y,z;
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            z = Integer.parseInt(st.nextToken());
            graph.get(x).add(new Node(y,z));
        }

        st = new StringTokenizer(br.readLine());

        c = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());

        distTable[c] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(c,0));

        while (!pq.isEmpty()){
            Node node = pq.poll();
            int index = node.getIndex();
            int dist = node.getDist();
            if(vis[index]) continue;
            vis[index] = true;

            for(int i=0; i<graph.get(index).size();i++){
                int nextIdx = graph.get(index).get(i).getIndex();
                int nextDist = graph.get(index).get(i).getDist();

                int nowDist = dist+nextDist;
                if(nowDist<distTable[nextIdx]){
                    distTable[nextIdx] = nowDist;
                    pq.offer(new Node(nextIdx,nowDist));
                }
            }
        }

        bw.write(String.valueOf(distTable[d])+ "\n");
        bw.flush();
        br.close();
        bw.close();

    }
}