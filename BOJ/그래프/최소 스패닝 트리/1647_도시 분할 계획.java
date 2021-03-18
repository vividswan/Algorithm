import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Edge implements Comparable<Edge>{
    private int x;
    private int y;
    private int dist;

    public Edge(int x, int y, int dist){
        this.x = x;
        this. y = y;
        this.dist = dist;
    }

    @Override
    public int compareTo(Edge other) {
        return Integer.compare(this.dist, other.dist);
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getDist() {
        return dist;
    }
}

public class 1647_도시 분할 계획 {

    public static ArrayList<Edge> arr = new ArrayList<>();
    public static int n,m;
    public static int[] parent;
    public static int find(int idx){
        if(parent[idx]==idx) return idx;
        return parent[idx] = find(parent[idx]);
    }
    public static void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return;;
        if(a>b){
            int temp = b;
            b = a;
            a = temp;
        }
        parent[b] = a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        parent = new int[n+1];
        for(int i=1; i<=n; i++) parent[i] = i;

        for(int i=1; i<=m; i++){
            st = new StringTokenizer(br.readLine());
            int a,b,c;
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            arr.add(new Edge(a,b,c));
        }

        Collections.sort(arr);
        int res = 0;
        int maxVal = 0;

        for(int i=0; i<arr.size();i++){
            Edge edge = arr.get(i);
            int x = edge.getX();
            int y = edge.getY();
            int dist = edge.getDist();

            if(find(x)==find(y)) continue;
            maxVal = Math.max(maxVal, dist);
            res += dist;
            merge(x,y);
        }

        bw.write(String.valueOf(res - maxVal)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}