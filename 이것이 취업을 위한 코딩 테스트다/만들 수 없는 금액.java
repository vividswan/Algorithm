import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 만들 수 없는 금액 {

    public static int n;
    public static int[] value;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        value = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            value[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(value);
        int now = 1;
        for(int i=0;i<n;i++){
            if(now>=value[i]){
                now+=value[i];
            }
            else break;
        }
        bw.write(String.valueOf(now));
        bw.flush();
        br.close();
        bw.close();
    }
}