import java.io.*;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

class Pair{
    private int x;
    private int y;
    public Pair(int x, int y){
        this.x = x;
        this.y =y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}

public class Main {
    public static int n,m,q;
    public static int[] parent;
    public static boolean[] cutEdge;
    public static int find(int idx){
        if (parent[idx] < 0) return idx;
        else return parent[idx] =  find(parent[idx]);
    }
    public static void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return;
        if(a>b){
            parent[b] += parent[a];
            parent[a] = b;
        }
        else {
            parent[a] += parent[b];
            parent[b] = a;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());

        parent = new int[n+1];
        for(int i=1; i<=n; i++) parent[i] = -1;

        ArrayList<Pair> pairs = new ArrayList<>();
        pairs.add(new Pair(0,0));
        for(int i=1; i<=m; i++){
            st = new StringTokenizer(br.readLine());
            int a= Integer.parseInt(st.nextToken());
            int b= Integer.parseInt(st.nextToken());
            pairs.add(new Pair(a,b));
        }
        cutEdge = new boolean[m+1];
        Stack<Integer> cutEdgeIdx = new Stack<>();
        for(int i =1; i<=q; i++){
            int now = Integer.parseInt(br.readLine());
            cutEdgeIdx.push(now);
            cutEdge[now] = true;
        }
        for(int i=1; i<=m; i++){
            if (!cutEdge[i]) merge(pairs.get(i).getX(),pairs.get(i).getY());
        }
        long sum = 0;
        while (!cutEdgeIdx.empty()){
            int now = cutEdgeIdx.pop();
            int a = pairs.get(now).getX();
            int b = pairs.get(now).getY();
            int aParent = find(a);
            int bParent = find(b);
            if (aParent == bParent) {
                merge(a,b);
            }
            else{
                sum += (long) parent[aParent] * parent[bParent];
                merge(a,b);
            }
        }
        bw.write(String.valueOf(sum)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}