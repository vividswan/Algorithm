import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 떡볶이 떡 만들기 {

    public static int n,m;
    public static int[] arr;
    public static int cutFunc(int val){
        int res = 0;
        for(int i=0; i<n; i++){
            if(arr[i]>val) res+= arr[i]-val;
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);
        int le = 0;
        int ri = arr[n-1];
        int res = 0;
        while(le<=ri){
            int mid = (le+ri)/2;
            int val = cutFunc(mid);
            if(val>=m) {
                res = mid;
                le = mid+1;
            }
            else {
                ri = mid-1;
            }
        }
        bw.write(String.valueOf(res));
        bw.flush();
        br.close();
        bw.close();
    }
}