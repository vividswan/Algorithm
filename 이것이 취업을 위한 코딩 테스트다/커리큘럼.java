import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 커리큘럼 {

    public static ArrayList<ArrayList<Integer>> outDegree = new ArrayList<ArrayList<Integer>>();
    public static int[] inDegreeCnt;
    public static int[] value;
    public static int[] result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        for(int i=0;i<=n;i++) outDegree.add(new ArrayList<Integer>());
        inDegreeCnt = new int[n+1];
        value = new int[n+1];
        result = new int[n+1];

        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            int val = Integer.parseInt(st.nextToken());
            value[i] = val;
            while(true){
                int cnt = Integer.parseInt(st.nextToken());
                if(cnt == -1) break;
                outDegree.get(cnt).add(i);
                inDegreeCnt[i]++;
            }
        }

        Queue<Integer> q = new LinkedList<>();
        for(int i=1;i<=n;i++){
            if(inDegreeCnt[i]==0) {
                q.offer(i);
                result[i]=value[i];
            }
        }
        while(!q.isEmpty()){
            int now = q.poll();
            for(int i=0;i<outDegree.get(now).size();i++){
                int out = outDegree.get(now).get(i);
                inDegreeCnt[out]--;
                result[out] = Math.max(result[out],result[now]);
                if(inDegreeCnt[out]==0){
                    q.offer(out);
                    result[out] += value[out];
                }
            }
        }
        for(int i=1;i<=n;i++){
            bw.write(String.valueOf(result[i])+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}