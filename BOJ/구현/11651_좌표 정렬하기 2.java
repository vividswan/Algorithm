import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Pair implements Comparable<Pair>{
    private int x;
    private int y;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Pair(int x, int y){
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pair other) {
        if (this.y == other.y) return Integer.compare(this.x, other.x);
        else return Integer.compare(this.y,other.y);
    }
}

public class Main {
    public static int n;
    public static ArrayList<Pair> pairs = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            pairs.add(new Pair(x,y));
        }
        Collections.sort(pairs);
        for(int i=0; i<n; i++){
            bw.write(String.valueOf(pairs.get(i).getX())+" "+String.valueOf(pairs.get(i).getY())+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}