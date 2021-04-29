import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int g, p;
    public static int[] parent;

    public static int find(int idx){
        if(idx==parent[idx]) return idx;
        else return parent[idx] = find(parent[idx]);
    }

    public static void merge(int a, int b){
        a= find(a);
        b = find(b);
        if(a==b) return;

        if(a > b){
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
        g = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        p = Integer.parseInt(st.nextToken());

        parent = new int[g+1];
        for(int i=0; i<=g; i++) parent[i] = i;

        int cnt = 0;
        boolean isEnd = false;
        for(int i=1; i<=p; i++){
            st = new StringTokenizer(br.readLine());
            int now = Integer.parseInt(st.nextToken());
            int rootNode = find(now);
            if(rootNode==0) isEnd = true;
            if(!isEnd){
                cnt++;
                merge(rootNode-1, rootNode);
            }
        }
        bw.write(String.valueOf(cnt)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}