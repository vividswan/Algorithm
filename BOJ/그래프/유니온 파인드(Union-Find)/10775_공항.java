import java.io.*;
import java.util.StringTokenizer;

public class 10775_공항 {
    public static int g,p;
    public static int[] parent;
    public static int find(int idx){
        if(parent[idx]==idx) return idx;
        else return parent[idx] = find(parent[idx]);
    }
    public static void merge(int x, int y){
        x = find(x);
        y= find(y);
        if(x==y) return;
        if(x < y) parent[y] = x;
        else parent[x] = y;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        g = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        p = Integer.parseInt(st.nextToken());

        parent = new int[g+1];
        for(int i=1;i<=g;i++) parent[i] = i;
        int res = 0;
        for(int i=1; i<=p;i++){
            st = new StringTokenizer(br.readLine());
            int val = Integer.parseInt(st.nextToken());
            int nowParent = find(val);
            if(nowParent==0) break;
            merge(nowParent,nowParent-1);
            res = i;
        }
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}