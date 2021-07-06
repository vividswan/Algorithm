import java.io.*;
import java.util.ArrayList;

public class Main {
    public static int n;
    public static ArrayList<String> strings = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        int cnt = 2*n - 3;
        for(int i=0; i<n; i++){
            String str = "";
            for(int j=0; j<i; j++) str += " ";
            if (i==n-1) {
                str += "*";
                strings.add(str);
            }
            else{
                str += "*";
                for(int j=0; j<cnt; j++) str +=" ";
                str += "*";
                cnt -= 2;
                strings.add(str);
            }
        }
        for(int i=n-1; i>=0; i--){
            bw.write(strings.get(i)+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}