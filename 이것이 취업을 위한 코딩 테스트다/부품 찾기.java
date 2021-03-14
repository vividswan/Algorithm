import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 부품 찾기 {
    public static int[] arr;
    public static int[] search;
    public static int n, m;
    public static boolean isExist(int val){
        int st = 0;
        int ed = n-1;
        while(st<=ed){
            int mid = (st+ed)/2;
            if(arr[mid]==val) return true;
            else if(mid<val) st = mid+1;
            else ed = mid-1;
        }
        return false;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        search = new int[m];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<m; i++){
            search[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        for(int i=0; i<m; i++){
            if(isExist(search[i])) bw.write("yes ");
            else bw.write("no ");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}