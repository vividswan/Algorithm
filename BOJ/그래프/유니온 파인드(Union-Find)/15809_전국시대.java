import java.io.*;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    public static int n,m;
    public static int[] val;
    public static int[] parent;
    public static int find(int idx){
        if (parent[idx]==idx) return idx;
        else return parent[idx] = find(parent[idx]);
    }
    public static void merge(int a, int b){
        a = find(a);
        b = find(b);
        if (a==b) return;
        if (val[a] > val[b]){
            val[a] += val[b];
            parent[b] = a;
        }
        else {
            val[b] += val[a];
            parent[a] = b;
        }
    }
    public static void battle(int a, int b){
        a = find(a);
        b = find(b);
        if (val[a] == val[b]){
            val[a] = 0;
            val[b] = 0;
            parent[a] = -1;
            parent[b] = -1;
            return;
        }
        else if(val[a] > val[b]){
            val[a] -= val[b];
            parent[b] = a;
            return;
        }
        else{
            val[b] -= val[a];
            parent[a] = b;
            return;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        val = new int[n+1];
        parent = new int[n+1];
        for(int i=1; i<=n; i++) parent[i] = i;
        for(int i=1; i<=n; i++){
            val[i] = Integer.parseInt(br.readLine());
        }
        for(int i=1; i<=m; i++){
            st = new StringTokenizer(br.readLine());
            int mod = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (mod==1) merge(a,b);
            else battle(a,b);
        }
        ArrayList<Integer> res = new ArrayList<>();
        for(int i=1; i<=n; i++){
            if (parent[i] != i) continue;
            else res.add(val[i]);
        }
        bw.write(res.size()+"\n");
        Collections.sort(res);
        for(int i=0; i<res.size(); i++  ) bw.write(res.get(i)+" ");
        bw.write("\n");
        bw.flush();
        br.close();
        bw.close();
    }
}