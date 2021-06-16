import java.io.*;
import java.util.*;

public class Main {
    public static int n;
    public static ArrayList<Long> arrayList = new ArrayList<>();
    public static PriorityQueue<Long> pq = new PriorityQueue<>();
    public static Map<Long, Integer> map = new HashMap<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            long now = Long.parseLong(st.nextToken());
            pq.offer(now);
            arrayList.add(now);
        }
        long bef = -1;
        int cnt = 0;
        while (!pq.isEmpty()){
            long peekLong = pq.poll();
            if (bef == peekLong) continue;
            map.put(peekLong,cnt);
            cnt++;
            bef = peekLong;
        }
        for(long num : arrayList){
            bw.write(map.get(num)+" ");
        }
        bw.write("\n");
        bw.flush();
        br.close();
        bw.close();
    }
}