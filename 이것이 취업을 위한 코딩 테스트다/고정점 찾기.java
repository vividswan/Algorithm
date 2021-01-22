import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class 고정점 찾기 {
    public static int n;
    public static int[] arr;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int le = 0;
        int ri = n-1;
        int ans = -1;
        while(le<=ri){
            int mid = (le+ri)/2;
            if(arr[mid]==mid){
                ans = mid;
                break;
            }
            else if(arr[mid]>mid) ri = mid-1;
            else le = mid+1;
        }
        bw.write(String.valueOf(ans));
        bw.flush();
        br.close();
        bw.close();

    }
}