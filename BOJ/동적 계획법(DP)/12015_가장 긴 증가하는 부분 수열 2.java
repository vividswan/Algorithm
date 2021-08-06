import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static int[] arr;
    public static ArrayList<Integer> arrayList = new ArrayList<>();
    public static int lowerBound(int val){
        int le = 0;
        int ri = arrayList.size()-1;
        while (le < ri){
            int mid = (le+ri)/2;
            if(arrayList.get(mid) < val) le = mid+1;
            else ri = mid;
        }
        return ri;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        arrayList.add(arr[0]);
        for(int i=1; i<n; i++){
            int now = arr[i];
            if(arrayList.get(arrayList.size()-1)<now) arrayList.add(now);
            else arrayList.set(lowerBound(now),now);
        }
        bw.write(String.valueOf(arrayList.size())+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}