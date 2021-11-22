import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static int n,k;
    public static Queue<Integer> q = new LinkedList<>();
    public static ArrayList<Integer> ans = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for(int i=1; i<=n; i++) q.offer(i);
        while (!q.isEmpty()){
            for(int i=1; i<=k; i++){
                int now = q.poll();
                if (i!=k) q.offer(now);
                else ans.add(now);
            }
        }
        bw.write("<");
        for(int i=0; i<ans.size()-1;i++) bw.write(String.valueOf(ans.get(i))+", ");
        bw.write(String.valueOf(ans.get(ans.size()-1)+">\n"));
        bw.flush();
        br.close();
        bw.close();
    }
}