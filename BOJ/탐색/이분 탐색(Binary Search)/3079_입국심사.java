import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static long m;
    public static ArrayList<Long> arrayList = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st. nextToken());
        m = Long.parseLong(st.nextToken());
        for(int i=0; i<n; i++){
            long num = Long.parseLong(br.readLine());
            arrayList.add(num);
        }
        Collections.sort(arrayList);
        long le = 1;
        long ri = m * arrayList.get(arrayList.size()-1);
        long res = -1;
        while (le<=ri){
            long mid = (le+ri)/2;
            long cnt = 0;
            for(int i=0; i<arrayList.size();i++){
                cnt += mid/arrayList.get(i);
            }
            if (cnt>=m){
                res = mid;
                ri = mid-1;
            }
            else le = mid+1;
        }
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}