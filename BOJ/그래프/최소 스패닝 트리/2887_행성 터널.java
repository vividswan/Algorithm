import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Node{
    private int x;
    private int y;
    private int z;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getZ() {
        return z;
    }

    public Node(int x, int  y, int z){
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

class Pair implements Comparable<Pair>{
    private int idx;
    private int value;
    public Pair(int idx, int value){
        this.idx = idx;
        this.value = value;
    }

    public int getIdx() {
        return idx;
    }

    public int getValue() {
        return value;
    }

    @Override
    public int compareTo(Pair other) {
        return Integer.compare(this.value,other.value);
    }
}

class ConnectSpace implements Comparable<ConnectSpace>{
    private int go;
    private int ed;
    private int value;

    public ConnectSpace(int go, int ed, int value){
        this.go = go;
        this.ed = ed;
        this.value = value;
    }

    public int getGo() {
        return go;
    }

    public int getEd() {
        return ed;
    }

    public int getValue() {
        return value;
    }

    @Override
    public int compareTo(ConnectSpace other) {
        return Integer.compare(this.value,other.value);
    }
}

public class 행성 터널 {

    public static ArrayList<Node> nodeArr = new ArrayList<>();
    public static ArrayList<Pair> xArr = new ArrayList<>();
    public static ArrayList<Pair> yArr = new ArrayList<>();
    public static ArrayList<Pair> zArr = new ArrayList<>();
    public static ArrayList<ConnectSpace> searchArr = new ArrayList<>();
    public static int calcDist(Node a, Node b){
        return Math.min(Math.abs(a.getX()-b.getX()) , Math.min(Math.abs(a.getY()-b.getY()) , Math.abs(a.getZ() - b.getZ())));
    }

    public static int n;
    public static int[] parent;
    public static int sum;
    public static int find(int idx){
        if(idx==parent[idx]) return idx;
        else return parent[idx] = find(parent[idx]);
    }
    public static void merge(int x ,int y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        if(x<y) parent[y] = x;
        else parent[x] = y;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        parent = new int[n];
        for(int i=0; i<n; i++) parent[i] = i;
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            nodeArr.add(new Node(x,y,z));
            xArr.add(new Pair(i,x));
            yArr.add(new Pair(i,y));
            zArr.add(new Pair(i,z));
        }

        Collections.sort(xArr);
        Collections.sort(yArr);
        Collections.sort(zArr);

        for(int i=0; i<n-1; i++){
            searchArr.add(new ConnectSpace(xArr.get(i).getIdx(), xArr.get(i+1).getIdx() , calcDist(nodeArr.get(xArr.get(i).getIdx()),nodeArr.get(xArr.get(i+1).getIdx()))));
            searchArr.add(new ConnectSpace(yArr.get(i).getIdx(), yArr.get(i+1).getIdx() , calcDist(nodeArr.get(yArr.get(i).getIdx()),nodeArr.get(yArr.get(i+1).getIdx()))));
            searchArr.add(new ConnectSpace(zArr.get(i).getIdx(), zArr.get(i+1).getIdx() , calcDist(nodeArr.get(zArr.get(i).getIdx()),nodeArr.get(zArr.get(i+1).getIdx()))));
        }

        Collections.sort(searchArr);

        for(int i=0; i<searchArr.size();i++){
            int go = searchArr.get(i).getGo();
            int ed = searchArr.get(i).getEd();
            int value = searchArr.get(i).getValue();

            if(find(go)==find(ed)) continue;
            else {
                merge(go,ed);
                sum += value;
            }
        }
        bw.write(String.valueOf(sum)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}