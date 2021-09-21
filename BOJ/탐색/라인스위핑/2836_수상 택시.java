import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Pair implements Comparable<Pair>{
    private long x;
    private long y;

    public Pair(long  x, long y){
        this.x = x;
        this.y = y;
    }

    public long getX() {
        return x;
    }

    public long getY() {
        return y;
    }

    @Override
    public int compareTo(Pair other){
        return Long.compare(other.x , this.x);
    }

}

public class Main {

    public static int n;
    public static long m;
    public static ArrayList<Pair> arrayList = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Long.parseLong(st.nextToken());

        for(int i=0; i<n; i++){
            long a, b;
            st = new StringTokenizer(br.readLine());
            a = Long.parseLong(st.nextToken());
            b = Long.parseLong(st.nextToken());
            if(a>b) arrayList.add(new Pair(a,b));
        }
        Collections.sort(arrayList);

        long maxx = arrayList.get(0).getX();
        long minn = arrayList.get(0).getY();
        long res = m;

        for(int i=0; i<arrayList.size(); i++){
            if (arrayList.get(i).getX()<minn){
                res += 2 * (maxx-minn);
                maxx = arrayList.get(i).getX();
                minn = arrayList.get(i).getY();
            }
            else {
                minn = Math.min(arrayList.get(i).getY(),minn);
            }
        }
        res += 2*(maxx-minn);
        bw.write(String.valueOf(res));
        bw.flush();
        br.close();
        bw.close();

    }
}