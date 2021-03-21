import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int n;
    public static int[] inDegree;
    public static int[] value;
    public static int[] res;
    public static ArrayList<ArrayList<Integer>> outDegree = new ArrayList<ArrayList<Integer>>();
    public static void topologySorting(){
        Queue<Integer> q = new LinkedList<Integer>();
        for(int i=1; i<=n; i++) {
            if(inDegree[i]==0) {
                res[i]=value[i];
                q.add(i);
            }
        }
        while(!q.isEmpty()){
            int now = q.poll();
            for(int i=0; i<outDegree.get(now).size();i++){
                int next = outDegree.get(now).get(i);
                inDegree[next]--;
                res[next] = Math.max(res[next],res[now]);
                if(inDegree[next]==0) {
                    q.add(next);
                    res[next]+=value[next];
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        inDegree = new int[n+1];
        value  = new int[n+1];
        res  = new int[n+1];
        for(int i=0; i<=n; i++) outDegree.add(new ArrayList<>());

        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            value[i] = Integer.parseInt(st.nextToken());
            while(true){
                int idx = Integer.parseInt(st.nextToken());
                if(idx==-1) break;
                inDegree[i]++;
                outDegree.get(idx).add(i);
            }
        }

        topologySorting();

        for(int i=1; i<=n; i++){
            bw.write(String.valueOf(res[i])+"\n");
        }
        bw.flush();
        br.close();
        bw.close();

    }
}