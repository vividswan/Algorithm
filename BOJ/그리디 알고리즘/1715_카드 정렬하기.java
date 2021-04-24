import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static  int n;
    public static PriorityQueue<Integer> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n=Integer.parseInt(st.nextToken());
        for(int i=0; i<n;i++){
            st = new StringTokenizer(br.readLine());
            pq.offer(Integer.parseInt(st.nextToken()));
        }

        int sum = 0;

        while (pq.size()>=2){
            int num1= pq.poll();
            int num2= pq.poll();
            sum+=num1+num2;
            pq.offer(num1+num2);
        }

        bw.write(String.valueOf(sum)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}