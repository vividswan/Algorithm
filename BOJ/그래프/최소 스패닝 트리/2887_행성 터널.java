import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Dist implements Comparable<Dist>{
    private int x;
    private int y;
    private int val;

    public Dist(int x, int y, int val){
        this.x = x;
        this.y = y;
        this.val = val;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getVal() {
        return val;
    }

    @Override
    public int compareTo(Dist other) {
        return Integer.compare(this.val, other.val);
    }
}

class DotDist implements Comparable<DotDist>{
    private int idx;
    private int val;
    public DotDist(int idx, int val){
        this.idx = idx;
        this.val =val;
    }

    public int getVal() {
        return val;
    }

    public int getIdx() {
        return idx;
    }

    @Override
    public int compareTo(DotDist other) {
        return Integer.compare(this.val,other.val);
    }
}

public class Main {

    public static int[] parent;
    public static int find(int idx){
        if(idx==parent[idx]) return idx;
        else return  parent[idx] = find(parent[idx]);
    }

    public static void merge(int a, int b){
        a = find(a);
        b= find(b);

        if(a==b) return;

        if(a>b) parent[a] = b;
        else parent[b] = a;
    }

    public static int n;
    public static ArrayList<DotDist> dotX = new ArrayList<>();
    public static ArrayList<DotDist> dotY = new ArrayList<>();
    public static ArrayList<DotDist> dotZ = new ArrayList<>();
    public static ArrayList<Dist> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n =Integer.parseInt(st.nextToken());
        parent = new int[n];
        for(int i = 0; i<n; i++) parent[i] = i;

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            int a,b,c;
            a = Integer.parseInt(st.nextToken());
            b =Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            dotX.add(new DotDist(i, a));
            dotY.add(new DotDist(i, b));
            dotZ.add(new DotDist(i, c));
        }

        Collections.sort(dotX);
        Collections.sort(dotY);
        Collections.sort(dotZ);

        for(int i=0; i<n-1; i++){
            list.add(new Dist(dotX.get(i).getIdx(),dotX.get(i+1).getIdx(), Math.abs(dotX.get(i).getVal()-dotX.get(i+1).getVal())));
            list.add(new Dist(dotY.get(i).getIdx(),dotY.get(i+1).getIdx(), Math.abs(dotY.get(i).getVal()-dotY.get(i+1).getVal())));
            list.add(new Dist(dotZ.get(i).getIdx(),dotZ.get(i+1).getIdx(), Math.abs(dotZ.get(i).getVal()-dotZ.get(i+1).getVal())));
        }

        Collections.sort(list);

        int tot = 0;
        for(int i=0; i<list.size(); i++){
            Dist dist = list.get(i);
            int x = dist.getX();
            int y = dist.getY();
            int val = dist.getVal();
            if(find(x)==find(y)) continue;
            else {
                merge(x,y);
                tot+=val;
            }
        }
        bw.write(String.valueOf(tot)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}