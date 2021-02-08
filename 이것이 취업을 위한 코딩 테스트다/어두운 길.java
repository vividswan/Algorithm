import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Node implements Comparable<Node>{
    private int x;
    private int y;
    private int value;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getValue() {
        return value;
    }

    public Node(int x, int y, int value){
        this.x = x;
        this.y = y;
        this.value = value;
    }

    @Override
    public int compareTo(Node other) {
        return Integer.compare(this.value, other.value);
    }
}

public class 어두운 길 {

    public static int n,m,sum,minSum;
    public static int[] parent;
    public static int find(int idx){
        if(idx==parent[idx]) return idx;
        else return parent[idx]= find(parent[idx]);
    }
    public static void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        if(x<y) parent[y] = x;
        else parent[x] = y;
    }
    public static ArrayList<Node> arr = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        parent = new int[n];
        for(int i=0; i<n; i++) parent[i] = i;
        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int x,y,val;
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            val = Integer.parseInt(st.nextToken());
            sum+=val;
            arr.add(new Node(x,y,val));
        }
        Collections.sort(arr);
        for(int i=0;i<m;i++){
            Node node = arr.get(i);
            int x = node.getX();
            int y = node.getY();
            int value = node.getValue();

            if(find(x)==find(y)) continue;
            else {
                merge(x,y);
                minSum += value;
            }
        }
        bw.write(String.valueOf(sum-minSum));
        bw.flush();
        br.close();
        bw.close();
    }
}