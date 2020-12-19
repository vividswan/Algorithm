import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

class Node implements Comparable<com.company.Node>{
    private int index;
    private int dist;

    public Node(int index, int dist){
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
    public int compareTo(com.company.Node o) {
        if (this.dist < o.dist ) return -1;
        else return 1;
    }
}

public class 다익스트라 구현 {

    public static final int INF = (int) 1e9;
    public static int[] distTable;
    public static int n,m,first;

    public static ArrayList<ArrayList<com.company.Node>> adj = new ArrayList<ArrayList<com.company.Node>>();

    public static void dijkstra(int firstNum){
        PriorityQueue<com.company.Node> pq = new PriorityQueue<>();

        pq.offer(new com.company.Node(firstNum,0));
        distTable[firstNum] = 0;

        while (!pq.isEmpty()){
            com.company.Node node = pq.poll();
            int index = node.getIndex();
            int dist = node.getDist();

            if(distTable[index] < dist) continue;

            for(int i=0;i<adj.get(index).size();i++){
                int cost = distTable[index]  + adj.get(index).get(i).getDist();
                int next = adj.get(index).get(i).getIndex();
                if(cost < distTable[next]){
                    distTable[next] = cost;
                    pq.offer(new com.company.Node(next,cost));
                }
            }

        }

    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        m= scanner.nextInt();
        first = scanner.nextInt();

        distTable = new int[n+1];
        Arrays.fill(distTable,INF);

        for(int i=0; i<=n;i++) adj.add(new ArrayList<com.company.Node>());
        for(int i=0;i<m;i++){
            int st,ed,val;
            st = scanner.nextInt();
            ed = scanner.nextInt();
            val = scanner.nextInt();

            adj.get(st).add(new com.company.Node(ed,val));
        }

        dijkstra(first);

        for(int i=1;i<=n;i++){
            if(distTable[i]==INF) System.out.println("도달 불가능");
            else System.out.println(distTable[i]);
        }

    }

}