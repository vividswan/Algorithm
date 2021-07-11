import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        ArrayList<Integer> arrayList = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int bef = -1000000;
        boolean isBad = false;
        while (st.hasMoreTokens()){
            int now = Integer.parseInt(st.nextToken());
            if(now<bef){
                isBad = true;
                break;
            }
            bef = now;
        }
        if (isBad) bw.write("Bad\n");
        else bw.write("Good\n");
        bw.flush();
        br.close();
        bw.close();
    }
}