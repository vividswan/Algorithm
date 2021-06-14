import java.io.*;
import java.util.ArrayList;

public class Main {
    public static long num;
    public static ArrayList<Long> list = new ArrayList<>();
    public static boolean isValid;
    public static void recur(int cnt, long val){
        if (val == 0){
            isValid = true;
            return;
        }
        if (cnt==list.size() || val < 0) return;
        recur(cnt+1, val-list.get(cnt));
        recur(cnt+1, val);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        num = Long.parseLong(br.readLine());
        long now = 1;
        for(int i=0; i<=21; i++){
            list.add(now);
            now *= 3L;
        }
        recur(0,num);
        if (isValid && num != 0) bw.write("YES\n");
        else bw.write("NO\n");
        bw.flush();
        br.close();
        bw.close();
    }
}