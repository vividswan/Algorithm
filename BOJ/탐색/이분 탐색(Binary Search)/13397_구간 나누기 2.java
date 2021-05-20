import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n,m, le, ri;
    public static int[] arr;
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
            ri = Math.max(ri,arr[i]);
        }
        int res = 0;
        while (le<=ri){
            int mid = (le+ri)/2;
            int cnt = 0;
            int minn = arr[0];
            int maxx = arr[0];
            for(int i=1; i<n; i++){
                minn = Math.min(arr[i],minn);
                maxx = Math.max(arr[i],maxx);
                if(maxx-minn > mid){
                    cnt++;
                    minn = arr[i];
                    maxx = arr[i];
                }
            }
            if(cnt+1<=m){
                res = mid;
                ri = mid-1;
            }
            else le = mid+1;
        }
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();


    }
}