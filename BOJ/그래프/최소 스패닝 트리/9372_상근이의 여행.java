import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static int t;
    public static int[] parent;
    public static int find(int idx){
        if(parent[idx] == idx) return idx;
        return parent[idx] = find(parent[idx]);
    }
    public static void merge(int a, int b){
        a = find(a);
        b = find(b);
        if (a==b) return;
        if (a<b) parent[b] = a;
        else parent[a] = b;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        t = Integer.parseInt(br.readLine());
        for(int k=0; k<t; k++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            parent = new int[n+1];
            for(int i=0; i<=n; i++) {
                parent[i] = i;
            }
            int cnt = 0;
            for(int i=1; i<=m; i++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                if (find(a)!=find(b)){
                    cnt++;
                    merge(a,b);
                }
            }
            bw.write(String.valueOf(cnt)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}