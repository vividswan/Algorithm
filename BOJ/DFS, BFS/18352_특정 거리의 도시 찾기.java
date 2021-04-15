import java.io.*;
import java.util.*;

public class Main {

    public static int n,m,k,x;
    public static ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
    public static int[] vis;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n= Integer.parseInt(st.nextToken());
        m= Integer.parseInt(st.nextToken());
        k= Integer.parseInt(st.nextToken());
        x= Integer.parseInt(st.nextToken());

        for(int i=0; i<=n; i++){
            arr.add(new ArrayList<Integer>());
        }
        vis = new int[n+1];
        Arrays.fill(vis,-1);

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int a,b;
            a  = Integer.parseInt(st.nextToken());
            b  = Integer.parseInt(st.nextToken());
            arr.get(a).add(b);
        }

        Queue<Integer> q = new LinkedList<>();
        q.offer(x);
        vis[x]=0;
        while (!q.isEmpty()){
            int now = q.poll();
            for(int i=0; i<arr.get(now).size();i++){
                int next = arr.get(now).get(i);
                if(vis[next]==-1){
                    q.offer(next);
                    vis[next] = vis[now]+1;
                }
            }
        }
        boolean ansExist = false;
        for(int i=1; i<=n; i++){
            if(vis[i]==k){
                ansExist = true;
                bw.write(String.valueOf(i)+"\n");
            }
        }
        if(!ansExist) bw.write(String.valueOf(-1)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}