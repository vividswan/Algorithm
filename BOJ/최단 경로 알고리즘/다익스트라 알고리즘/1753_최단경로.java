import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

class Node implements Comparable<Node> {
    private int index;
    private int dist;

    Node(int index, int dist) {
        this.index = index;
        this.dist = dist;
    }

    public int getIndex() {
        return index;
    }

    public int getDist() {
        return dist;
    }

    @Override
    public int compareTo(Node n) {
        if (this.dist < n.dist) return -1;
        return 1;
    }
}
public class 1573_최단경로 {

    public static final int INF = (int) 1e9;
    public static int v,e,k;
    public static int[] distTable;
    public static ArrayList<ArrayList<Node>> adj = new ArrayList<ArrayList<Node>>();

    public static   void dijkstra(int first){
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(first,0));
        distTable[first] = 0;
        while(!pq.isEmpty()){
            Node node = pq.poll();
            int index = node.getIndex();
            int dist = node.getDist();

            if(distTable[index]<dist) continue;;

            for(int i=0;i<adj.get(index).size();i++){
                int next = adj.get(index).get(i).getIndex();
                int cost = distTable[index] + adj.get(index).get(i).getDist();
                if(distTable[next] > cost ){
                    distTable[next] = cost;
                    pq.offer(new Node(next,cost));
                }
            }

        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        v = scanner.nextInt();
        e = scanner.nextInt();
        k = scanner.nextInt();

        distTable = new int[v+1];
        Arrays.fill(distTable,INF);
        for(int i=0;i<=v;i++) adj.add(new ArrayList<Node>());

        for(int i=0; i <e; i++){
            int u,v,w;
            u = scanner.nextInt();
            v = scanner.nextInt();
            w = scanner.nextInt();

            adj.get(u).add(new Node(v,w));
        }

        dijkstra(k);

        for(int i=1;i<=v;i++){
            if(distTable[i]==INF) System.out.println("INF");
            else System.out.println(distTable[i]);
        }

    }
}