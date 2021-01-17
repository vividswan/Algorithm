import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class 18310_안테나 {
    public static int n;
    public static ArrayList<Integer> arr;
    public static int resultIdx;
    public static int result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        arr = new ArrayList<Integer>();
        int tot = 0;
        for(int i=0;i<n;i++){
            int num = Integer.parseInt(st.nextToken());
            arr.add(num);
            tot+=num;
        }
        Collections.sort(arr);
        bw.write(arr.get((n-1)/2)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}