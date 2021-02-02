import java.io.*;
import java.util.StringTokenizer;

public class 여행 계획 {
    public static int n,m;
    public static int[] parent;
    public static int find(int idx){
        if(parent[idx]==idx) return idx;
        else return parent[idx]= find(parent[idx]);
    }
    public static void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        if(x < y) parent[y] = x;
        else parent[x] = y;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        parent = new int[n+1];
        for(int i=1;i<=n;i++) parent[i] = i;

        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=n;j++){
                int now = Integer.parseInt(st.nextToken());
                if(now==0) continue;
                merge(i,j);
            }
        }
        boolean isPossible = true;
        st = new StringTokenizer(br.readLine());
        int resIdx = find(Integer.parseInt(st.nextToken()));
        for(int i=2; i<=m;i++){
            if(resIdx!=find(Integer.parseInt(st.nextToken()))) isPossible = false;
        }
        if(isPossible) bw.write("YES\n");
        else bw.write("NO\n");
        bw.flush();
        br.close();
        bw.close();
    }
}