import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int n;
    public static int[] values;
    public static int[] arr = new int[4];
    public static int maxValue = -(int)1e9;
    public static int minValue = +(int)1e9;
    public static void recursion(int value, int cnt){
        if(cnt == n+1){
            maxValue = Math.max(maxValue,value);
            minValue = Math.min(minValue,value);
            return;
        }
        for(int i=0; i<4; i++){
            if(arr[i]>0){
                arr[i]--;
                if(i==0) recursion(value+values[cnt],cnt+1);
                else if(i==1) recursion(value-values[cnt],cnt+1);
                else if(i==2) recursion(value*values[cnt],cnt+1);
                else recursion(value/values[cnt],cnt+1);
                arr[i]++;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        values = new int[n+1];
        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++){
            values[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<4; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        recursion(values[1], 2);

        bw.write(String.valueOf(maxValue)+"\n");
        bw.write(String.valueOf(minValue)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}