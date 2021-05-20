import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static int n, res;
    private static ArrayList<Integer> arrayList = new ArrayList<>();
    public static void recursion(int val){
        if (arrayList.size()==2){
            res = Math.max(res,val);
            return;
        }
        for(int i=1; i<arrayList.size()-1; i++){
            int plusVal = arrayList.get(i-1) * arrayList.get(i+1);
            int tempVal = arrayList.get(i);
            arrayList.remove(i);
            recursion(val + plusVal);
            arrayList.add(i,tempVal);
        }
    }
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            arrayList.add(Integer.parseInt(st.nextToken()));
        }

        recursion(0);
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();


    }
}