import java.io.*;
import java.util.StringTokenizer;

public class 집합의 표현{
    public static int n,m;
    public static int[] parent;

    public static int find(int idx){
        if(parent[idx]==idx) return idx;
        else return parent[idx] = find(parent[idx]);
    }

    public static void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a>b) parent[a] = b;
        else parent[b] = a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());


        parent = new int[n+1];
        for(int i=1;i<=n;i++) parent[i] = i;
        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if(x==0){
                if(find(a) != find(b)){
                    merge(a,b);
                }
            }
            else if (x==1){
                if(find(a)==find(b)) bw.write("YES\n");
                else bw.write("NO\n");
            }
        }
        bw.flush();
        br.close();
        bw.close();
    }
}