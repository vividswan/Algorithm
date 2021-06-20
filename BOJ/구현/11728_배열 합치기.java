import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    public static int n,m;
    public static ArrayList<Integer> res = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++) res.add(Integer.parseInt(st.nextToken()));

        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=m; i++) res.add(Integer.parseInt(st.nextToken()));

        Collections.sort(res);

        for(int i=0; i<n+m; i++) bw.write(String.valueOf(res.get(i))+" ");
        bw.flush();
        br.close();
        bw.close();
    }
}