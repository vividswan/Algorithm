import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)  throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            long c = Long.parseLong(st.nextToken());
            if (a==0L && b==0 && c==0L) break;
            ArrayList<Long> arrayList = new ArrayList<>();
            arrayList.add(a);
            arrayList.add(b);
            arrayList.add(c);
            Collections.sort(arrayList);
            if(Math.pow(arrayList.get(0),2)+Math.pow(arrayList.get(1),2) == Math.pow(arrayList.get(2),2)){
                bw.write("right\n");
            }
            else bw.write("wrong\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}