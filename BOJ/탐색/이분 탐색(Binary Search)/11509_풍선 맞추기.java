import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n ; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int left = 1;
        int right = n;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cnt = 1;
            int[] arrowCnt = new int[n + 1];
            arrowCnt[arr[1]] =1;
            for (int i = 1; i <=n ; i++) {
                if (arrowCnt[arr[i]] > 0) {
                    arrowCnt[arr[i]]--;
                    arrowCnt[arr[i]-1]++;
                } else {
                    cnt++;
                    arrowCnt[arr[i]-1]++;
                }
            }
            if (cnt > mid) {
                left = mid + 1;
            }
            else{
                ans = mid;
                right = mid - 1;
            }
        }
        bw.write(ans+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}