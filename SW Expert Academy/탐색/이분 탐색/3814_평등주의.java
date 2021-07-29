import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair{
    private int x;
    private int y;

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Solution {
    public static int testCase;
    public static int[][] diff;
    public static int[] arr;
    public static int n, k;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());

        for (int t = 1; t <=testCase ; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int left = 0;
            int right = 1000000000;
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            diff = new int[2][n + 1];
            arr = new int[n + 1];
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            for (int i = 1; i <= n; i++) {
                if (i!=1) diff[0][i] = Math.abs(arr[i] - arr[i - 1]);
                if (i!=n) diff[1][i] = Math.abs(arr[i] - arr[i + 1]);
            }
            int ans = 1000000000;
            while (left <= right) {
                int mid = (left + right) / 2;
                int[] tempArr = Arrays.copyOf(arr, arr.length);
                Queue<Pair> q = new LinkedList<>();
                for (int i = 0; i <2 ; i++) {
                    for (int j = 1; j <=n ; j++) {
                        if (i==0 && j==1) continue;
                        if(i==1 && j==n) continue;
                        if (diff[i][j] > mid) {
                            if (i==0) q.add(new Pair(j,j-1));
                            else q.add(new Pair( j,j+1));
                        }
                    }
                }
                int tempK = 0;
                while (!q.isEmpty()) {
                    Pair poll = q.poll();
                    int x = poll.getX();
                    int y = poll.getY();
                    int value = Math.abs(tempArr[x] - tempArr[y]);
                    if (value <= mid) continue;
                    int bigNum;
                    if (tempArr[x] > tempArr[y]) bigNum = x;
                    else bigNum = y;
                    if (tempArr[bigNum] - value ==0) continue;
                    tempK += value-mid;
                    tempArr[bigNum] -= value;
                    tempArr[bigNum] += mid;
                    if (bigNum >1 && Math.abs(tempArr[bigNum]-tempArr[bigNum-1])>mid) {
                        q.add(new Pair(bigNum, bigNum - 1));
                    }
                    if (bigNum <n && Math.abs(tempArr[bigNum]-tempArr[bigNum+1])>mid){
                        q.add(new Pair(bigNum, bigNum + 1));
                    }
                }
                if (tempK <=k){
                    ans = Math.min(ans,mid);
                    right = mid - 1;
                } else left = mid + 1;
            }
            bw.write("#"+t+" "+String.valueOf(ans)+"\n");

        }
        bw.flush();
        br.close();
        bw.close();
    }
}