import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n,k;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            if(n==0 && k==0) break;
            int cnt = -1;
            int res = 0;
            int kIdx = -1;
            int[] value = new int[1001];
            int[] number = new int[1001];
            for(int i=0; i<=1000; i++){
                value[i] = -1;
                number[i] = -1;
            }
            st = new StringTokenizer(br.readLine());
            for(int i=1; i<=n; i++){
                value[i] = Integer.parseInt(st.nextToken());
                if (value[i]==k) kIdx = i;
                if(value[i] != value[i-1]+1) cnt++;
                number[i] = cnt;
            }
            for(int i=1; i<=n; i++){
                if(number[i] != number[kIdx] && number[number[i]] == number[number[kIdx]]) res++;
            }
            bw.write(String.valueOf(res)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}