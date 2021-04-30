import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int n,m;
    public static int[][] map;
    public static  int[] parent;
    public static int find(int idx){
        if(parent[idx] == idx) return idx;
        else return parent[idx] = find(parent[idx]);
    }
    public static void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return;
        if(a>b) {
            int temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n+1][n+1];
        parent = new int[n+1];
        for(int i=1; i<=n; i++) parent[i] = i;
        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j]==1) merge(i,j);
            }
        }
        st = new StringTokenizer(br.readLine());
        int resParent = 0;
        boolean isRight = true;
        for(int i=0; i<m; i++){
            int idx = Integer.parseInt(st.nextToken());
            if(resParent==0) resParent = find(idx);
            else {
                if(resParent != find(idx)){
                    isRight = false;
                    break;
                }
            }
        }
        if(isRight) bw.write("YES\n");
        else bw.write("NO\n");
        bw.flush();
        br.close();
        bw.close();

    }
}