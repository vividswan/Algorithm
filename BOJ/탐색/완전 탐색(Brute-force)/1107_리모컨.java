import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static int n, m;
    public static ArrayList<Integer> arrayList = new ArrayList<>();
    public static void recursion(String value){
        if (value.length() == 7) return;
        if (value.length()!=0) arrayList.add(Integer.parseInt(value));
        for(int i=0; i<10; i++){
            if(notWorking[i]) continue;
            value += String.valueOf(i);
            recursion(value);
            value = value.substring(0,value.length()-1);
        }
    }
    public static boolean[] notWorking = new boolean[10];
    public static int cnt;
    public static int res = (int)1e9;
    public static int res_100;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        cnt = String.valueOf(n).length();

        if(m!=0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i=0; i<m; i++) notWorking[Integer.parseInt(st.nextToken())] = true;
        }

        recursion("");
        int totRes = (int)1e9;
        for(int i=0; i<arrayList.size(); i++){
            int now = arrayList.get(i);
            res = Math.min(res,Math.abs(n-now));
            if (res==Math.abs(n-now)) totRes = Math.min(res+String.valueOf(now).length(),totRes);
        }
        res_100 = Math.abs(100-n);
        bw.write(String.valueOf(Math.min(res_100,totRes))+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}