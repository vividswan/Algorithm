import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 11438_LCA 2 {

    public static int n;
    public static int m;
    public static int[] depth;
    public static boolean[] chk;
    public static int[][] parent;
    public static int lca(int a, int b){
        if(depth[a]< depth[b]){
            int temp = a;
            a = b;
            b = temp;
        }
        for(int i=20; i>=0;i--){
            if(depth[a]-depth[b] >= (1 << i)) a = parent[a][i];
        }
        if(a==b) return a;
        for(int i=20; i>=0;i--){
            if(parent[a][i] != parent[b][i]){
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        return parent[a][0];
    }
    public static void getDepth(int idx, int value){
        depth[idx] = value;
        chk[idx] = true;
        int len = graph.get(idx).size();
        for(int i=0; i<len;i++){
            if(!chk[graph.get(idx).get(i)]){
                int next = graph.get(idx).get(i);
                parent[next][0] = idx;
                getDepth(next, value+1);
            }
        }
    }
    public static void getParent(){
        for(int j=1; j<21;j++){
            for(int i=1; i<=n; i++){
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }
    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        parent = new int[n+1][21];
        depth = new int[n+1];
        chk = new boolean[n+1];
        for(int i=0;i<=n;i++) graph.add(new ArrayList<>());
        for(int i=1;i<=n-1;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        getDepth(1,1);
        getParent();

        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        for(int i=1; i<=m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            bw.write(String.valueOf(lca(a,b))+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}