import javax.management.StringValueExp;
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public  class Main  {

    public static int n,c;
    public static int[] arr;

    public static boolean isPossible(int dist){
        int nowIdx = 0;
        int nextDist = arr[nowIdx] + dist;
        int cnt = c-1;
        for(int i=1; i<n; i++){
            if(cnt == 0) break;
            if(arr[i] < nextDist) continue;
            else {
                cnt--;
                nowIdx = i;
                nextDist = arr[nowIdx] + dist;
            }
        }
        if(cnt==0) return true;
        else return false;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        arr = new int[n];

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        int left = 0;
        int right = arr[n-1];
        int ans = 0;
        while(left <= right){
            int mid = (left+right)/2;
            if(isPossible(mid)) {
                ans = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        bw.write(String.valueOf(ans)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}