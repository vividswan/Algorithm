import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int n,m,maxValue;
    public static ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
    public static int[] distTable;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i=0; i<=n; i++) arr.add(new ArrayList<>());
        distTable = new int[n+1];
        for(int i=1; i<=n; i++) distTable[i] = -1;

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int go = Integer.parseInt(st.nextToken());
            int ed = Integer.parseInt(st.nextToken());

            arr.get(go).add(ed);
            arr.get(ed).add(go);
        }

        distTable[1] = 0;
        Queue<Integer> q = new LinkedList<>();
        q.offer(1);
        while (!q.isEmpty()){
            int now = q.poll();
            for(int i=0; i<arr.get(now).size();i++){
                int next = arr.get(now).get(i);
                if(distTable[next]!=-1) continue;
                distTable[next] = distTable[now]+1;
                maxValue = Math.max(maxValue,distTable[next]);
                q.offer(next);
            }
        }
        int resIdx = 0;
        int resCnt = 0;
        for(int i=1; i<=n; i++){
            if(resIdx ==0 && distTable[i] == maxValue) resIdx = i;
            if(distTable[i] == maxValue) resCnt++;
        }

        bw.write(String.valueOf(resIdx)+" "+String.valueOf(maxValue)+" "+String.valueOf(resCnt));
        bw.flush();
        br.close();
        bw.close();

    }
}