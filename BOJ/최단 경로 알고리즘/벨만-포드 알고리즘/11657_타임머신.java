import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

class Pair{
    private int  idx;
    private  int dist;

    public int getIdx() {
        return idx;
    }

    public int getDist() {
        return dist;
    }

    public Pair(int idx, int dist){
        this.idx = idx;
        this.dist = dist;
    }
}

public class 11657_타임머신 {

    public static int n;
    public static int m;
    public static long[] dist;
    public static final  int INF = (int) 1e9;
    public static ArrayList<ArrayList<Pair>> graph = new ArrayList<ArrayList<Pair>>();
    public static boolean isInfGraph;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        dist = new long[n+1];
        Arrays.fill(dist,INF);
        dist[1]=0L;
        for(int i=0; i<=n;i++) graph.add(new ArrayList<>());
        for(int i=1; i<=m;i++){
            int a,b,c;
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            graph.get(a).add(new Pair(b, c));
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                ArrayList<Pair> arrayList = graph.get(j);
                for(Pair pair:arrayList){
                    int now = j;
                    int next = pair.getIdx();
                    long cost = pair.getDist();
                    if(dist[now]!=INF && dist[next] > dist[now]+cost){
                        dist[next] = dist[now] + cost;
                        if(i==n) isInfGraph = true;
                    }
                }
            }
        }
        if(isInfGraph){
            bw.write("-1\n");
        }
        else {
            for(int i=2; i<=n;i++){
                if(dist[i]==INF) bw.write("-1\n");
                else bw.write(dist[i]+"\n");
            }
        }
        bw.flush();
        br.close();
        bw.close();
    }
}