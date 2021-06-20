import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static int MAX = 2000000;
    public static boolean[] vis = new boolean[MAX+1];
    public static boolean[] isPrime = new boolean[MAX+1];
    public static ArrayList<Integer> arrayList = new ArrayList<>();
    public static int t;
    public static boolean func(long val){
        long now = val - 2;
        if (now<=MAX) return isPrime[(int) now];
        boolean isPrime = true;
        for(int i=0; i<arrayList.size(); i++){
            int modVal = arrayList.get(i);
            if (now%modVal==0){
                isPrime = false;
                break;
            }
        }
        return isPrime;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Arrays.fill(isPrime,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i<= Math.sqrt(MAX); i++){
            if (vis[i]) continue;
            vis[i] = true;
            int cnt = 2;
            while (true){
                int next = i*cnt;
                if (next>MAX) break;
                vis[next] = true;
                isPrime[next] = false;
                cnt++;
            }
        }

        for(int i=2; i<=MAX;i++){
            if (isPrime[i]) arrayList.add(i);
        }

        t = Integer.parseInt(br.readLine());

        for(int i=0; i<t; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            long tot = a+b;
            if (tot!=2 && (tot%2L==0)) bw.write("YES\n");
            else{
                if (func(tot)){
                    bw.write("YES\n");
                }
                else {
                    bw.write("NO\n");
                }
            }
        }

        bw.flush();
        br.close();
        bw.close();
    }
}