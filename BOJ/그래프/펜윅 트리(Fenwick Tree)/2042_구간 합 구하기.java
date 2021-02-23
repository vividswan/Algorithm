import java.io.*;
import java.util.StringTokenizer;

public class 2042_구간 합 구하기 {

    public static int n;
    public static int m;
    public static int k;
    public static long[] arr;
    public static long[] tree;

    public static void update(int idx, long value){
        while(idx<=n){
            tree[idx] += value;
            idx +=( idx&(-idx));
        }
    }

    public static long sum(int idx){
        long res = 0;
        while(idx > 0){
            res +=  tree[idx];
            idx -= (idx&(-idx));
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        arr = new long[n+1];
        tree = new long[n+1];
        for(int i=1; i<=n;i++){
            st = new StringTokenizer(br.readLine());
            long value = Long.parseLong(st.nextToken());
            update(i,value);
            arr[i] = value;
        }
        for(int i=1; i<=m+k;i++){
            int a,b;
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            if(a==1){
                long c = Long.parseLong(st.nextToken());
                long diff = c - arr[b];
                update(b, diff);
                arr[b] = c;
            }
            else {
                int c = Integer.parseInt(st.nextToken());
                long res = sum(c) -sum(b-1);
                bw.write(String.valueOf(res)+"\n");
            }
        }
        bw.flush();
        br.close();
        bw.close();
    }
}