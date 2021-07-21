import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static int k,v,e;
    public static ArrayList<ArrayList<Integer>> graph;
    public static int[] vis;
    public static boolean isAns;
    public static boolean dfs(int idx, int val){
        vis[idx] = val;
        for(int i =0; i<graph.get(idx).size(); i++){
            int next = graph.get(idx).get(i);
            if (vis[next]==val) return false;
            if (vis[next]== -1 * val) continue;
            else if (!dfs(next,-1*val)) return false;
        }
        return true;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        k = Integer.parseInt(br.readLine());
        for(int l=1; l<=k; l++){
            isAns = true;
            StringTokenizer st = new StringTokenizer(br.readLine());
            v = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            vis = new int[v+1];
            graph = new ArrayList<ArrayList<Integer>>();
            for(int i=0; i<=v; i++) graph.add(new ArrayList<>());
            for(int i =1; i<=e; i++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                graph.get(a).add(b);
                graph.get(b).add(a);
            }
            for(int i=1; i<=v; i++){
                if (vis[i]==0){
                    if (!dfs(i,1)) {
                        isAns = false;
                        break;
                    }
                }
            }
            if (isAns) bw.write("YES\n");
            else bw.write("NO\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}