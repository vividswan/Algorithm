import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    public static boolean isValid(int mid) {
        int kIdx = 1;
        int nowCnt = 0;
        for (int i = 1; i <=n ; i++) {
            if (nArr[i] <= mid) nowCnt++;
            else nowCnt = 0;
            if(nowCnt == kArr[kIdx]){
                kIdx++;
                nowCnt = 0;
                if (kIdx == k+1) break;
            }
        }
        if (kIdx == k+1) return true;
        return false;
    }
    public static int testCase, n, k, left, right;
    public static int[] nArr;
    public static int[] kArr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase; t++) {
            left = 0;
            right = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            nArr = new int[n + 1];
            kArr = new int[k + 1];
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) {
                nArr[i] = Integer.parseInt(st.nextToken());
                right = Math.max(right, nArr[i]);
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= k; i++) {
                kArr[i] = Integer.parseInt(st.nextToken());
            }
            int res = -1;
            while (left <= right) {
                int mid = (left + right) / 2;
                boolean isPossible = isValid(mid);
                if(isPossible) {
                    res = mid;
                    right = mid - 1;
                }
                else left = mid + 1;
            }
            bw.write("#"+t+" "+res+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}