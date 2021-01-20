import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 2110_공유기 설치 {
    public static int n,c;
    public static int[] arr;
    public static int ans;
    public static void getAns(){
        int le = 0;
        int ri = arr[n-1] - arr[0];
        while(le <= ri){
            int mid = (ri+le)/2;
            int count =1;
            int now =  0;
            for(int i=1; i<n;i++){
                if(arr[i]-arr[now]>=mid){
                    now = i;
                    count++;
                }
            }
            if(count>=c) ans = mid;
            if(count < c) ri = mid-1;
            else le = mid+1;
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        arr = new int[n];

        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        getAns();
        bw.write(String.valueOf(ans));
        bw.flush();
        br.close();
        bw.close();
    }
}