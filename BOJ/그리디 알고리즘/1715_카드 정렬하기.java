import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 1715_카드 정렬하기 {
    public static int n, tot;
    public static PriorityQueue<Integer> pq;

    public static void main(String[] args) throws Exception{
        pq = new PriorityQueue<>();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        for(int i=1; i<=n;i++){
            st = new StringTokenizer(br.readLine());
            int value = Integer.parseInt(st.nextToken());
            pq.offer(value);
        }

        while(pq.size()>=2){
            int x = pq.poll();
            int y= pq.poll();
            tot+= x+y;
            pq.offer(x+y);
        }

        bw.write(String.valueOf(tot));
        bw.flush();
        br.close();
        bw.close();
    }
}