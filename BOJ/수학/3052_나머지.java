import java.io.*;
import java.util.HashSet;
import java.util.Set;

public class Main {

    public static Set<Integer> s = new HashSet<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i=0;i<10; i++){
            int now = Integer.parseInt(br.readLine());
            s.add(now%42);
        }
        bw.write(String.valueOf(s.size())+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}