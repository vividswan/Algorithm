import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n, x;
        int[] arr;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        arr = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <=n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int left = 1;
        int right = n;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            for (int i = 1; i <= n ; i++) {
                if (pq.size()<mid) pq.add(arr[i]);
                else {
                    int now = pq.poll();
                    pq.add(now + arr[i]);
                }
            }
            boolean isPossible = true;
            while (!pq.isEmpty()) {
                if (pq.poll()> x) isPossible = false;
            }
            if(isPossible){
                right = mid - 1;
                ans = mid;
            }
            else{
                left = mid + 1;
            }
        }
        bw.write(ans+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}