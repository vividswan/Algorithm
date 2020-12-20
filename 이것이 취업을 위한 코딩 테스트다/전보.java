import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

class Node implements Comparable<Node>{
    private int index;
    private int cost;

    public Node(int index, int cost){
        this.index = index;
        this.cost = cost;
    }

    public int getIndex() {
        return index;
    }

    public int getCost() {
        return cost;
    }

    @Override
    public int compareTo(Node obj) {
        if(this.cost < obj.cost){
            return -1;
        }
        else return 1;
    }
}

public class 전보 {

    public static int n,m,c;
    public static ArrayList<ArrayList<Node>> adj = new ArrayList<ArrayList<Node>>();
    public static int[] distTable;
    public static final int INF = (int) 1e9;

    public static void dijkstra(int c) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        distTable[c] = 0;
        pq.offer(new Node(c,0));
        while(!pq.isEmpty()){
            Node node = pq.poll();
            int index = node.getIndex();
            int dist = node.getCost();
            if(distTable[index] < dist) continue;
            for(int i=0;i<adj.get(index).size();i++){
                int cost  = adj.get(index).get(i).getCost();
                int next = adj.get(index).get(i).getIndex();
                if(distTable[index]+cost < distTable[next]){
                    distTable[next] = distTable[index] + cost;
                    pq.offer(new Node(next,cost));
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        c = scanner.nextInt();
        for(int i=0; i<=n; i++) adj.add(new ArrayList<Node>());
        distTable = new int[n+1];
        Arrays.fill(distTable,INF);
        for(int i=0; i<m; i++){
            int x,y,z;
            x = scanner.nextInt();
            y = scanner.nextInt();
            z = scanner.nextInt();
            adj.get(x).add(new Node(y,z));
        }

        dijkstra(c);

        int cnt = 0;
        int val = 0;

        for(int i=1;i<=n;i++){
            if(i==c) continue;
            if(distTable[i]!=INF){
                cnt++;
                val = Math.max(val, distTable[i]);
            }
        }
        System.out.println(cnt + " " + val);
    }
}
