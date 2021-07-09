import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Key implements Comparable<Key>{
    private int idx;
    private int time;
    private char val;
    public Key(int idx, int time, char val){
        this.idx = idx;
        this.time = time;
        this.val = val;
    }

    public int getIdx() {
        return idx;
    }

    public int getTime() {
        return time;
    }

    public char getVal() {
        return val;
    }

    @Override
    public int compareTo(Key other){
        if (this.time == other.time) return Integer.compare(this.idx, other.idx);
        else return Integer.compare(this.time, other.time);
    }

}

public class Main {
    public static int n,m;
    public static ArrayList<Key> arrayList = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());


        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            arrayList.add(new Key(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),st.nextToken().charAt(0)));
        }

        Collections.sort(arrayList);

        for(int i=0; i<arrayList.size();i++){
            bw.write(arrayList.get(i).getVal());
        }
        bw.write("\n");
        bw.flush();
        br.close();
        bw.close();

    }
}