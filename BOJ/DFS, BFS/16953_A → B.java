import java.io.*;
import java.util.*;

public class Main {
    public static long a,b;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Long.parseLong(st.nextToken());
        b = Long.parseLong(st.nextToken());
        Map<Long, Long> m = new HashMap<>();
        Queue<Long> q = new LinkedList<>();
        m.put(a,1L);
        q.offer(a);
        while (!q.isEmpty()){
            long now = q.poll();
            for(int i=0; i<2; i++){
                long next = 0;
                if(i==0) next = now*10 + 1;
                else next = now*2;
                if (next > b) continue;
                if (m.containsKey(next)) continue;
                m.put(next, m.get(now)+1);
                q.offer(next);
            }
        }
        if (!m.containsKey(b)) bw.write("-1\n");
        else bw.write(String.valueOf(m.get(b))+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}