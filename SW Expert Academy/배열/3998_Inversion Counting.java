import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    public static void mergeSort(int start, int end) {
        if (start < end) {
            int mid = (start + end)/2;
            mergeSort(start,mid);
            mergeSort(mid+1,end);
            int idx = start;
            int left = start;
            int right = mid + 1;
            while (left <= mid || right <= end) {
                if (right > end || (left <= mid && (arr[left] < arr[right]))) {
                    temp[idx++] = arr[left++];
                }
                else {
                    cnt += mid - left + 1;
                    temp[idx++] = arr[right++];
                }
            }
            for (int i = start; i <= end; i++) {
                arr[i] = temp[i];
            }
        }
    }
    public static int testCase;
    public static int[] temp;
    public static int[] arr;
    public static long cnt;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        testCase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= testCase ; t++) {
            int n = Integer.parseInt(br.readLine());
            arr = new int[n];
            temp = new int[n];
            cnt = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            mergeSort(0,n-1);
            bw.write("#"+t+" "+cnt+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}