import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Edge implements Comparable<Edge>{
    private int st, ed, value;
    public Edge(int st, int ed, int value){
        this.st = st;
        this.ed = ed;
        this.value = value;
    }

    public int getSt() {
        return st;
    }

    public int getEd() {
        return ed;
    }

    public int getValue() {
        return value;
    }

    @Override
    public int compareTo(Edge obg) {
        if(this.value < obg.value) return -1;
        else return 1;
    }
}

public class 도시 분할 계획 {

    public static int[] parent;

    public static int find(int idx){
        if(idx==parent[idx]) return idx;
        else return parent[idx] = find(parent[idx]);
    }

    public static void merge(int a, int b){
        a = find(a);
        b= find(b);
        if(a>b) parent[a] = b;
        else parent[b] = a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n, m;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m= Integer.parseInt(st.nextToken());

        parent = new int[n+1];
        for(int i=1;i<=n;i++) parent[i] = i;

        PriorityQueue<Edge> pq = new PriorityQueue<>();

        for(int i=0;i<m;i++){
            int a,b,c;
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            Edge edge = new Edge(a,b,c);
            pq.offer(edge);
        }

        int tot = 0;
        int maxVal = 0;

        while(!pq.isEmpty()){
            Edge edge = pq.poll();
            int fr = edge.getSt();
            int ed = edge.getEd();
            int value = edge.getValue();

            if(find(fr) == find(ed)) continue;
            else merge(fr,ed);
            tot += value;
            maxVal = Math.max(maxVal,value);
        }

        bw.write(String.valueOf(tot-maxVal));
        bw.write("\n");

        bw.flush();
        br.close();
        bw.close();
    }
}