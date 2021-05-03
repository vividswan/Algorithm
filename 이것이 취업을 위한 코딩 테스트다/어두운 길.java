import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Connection implements Comparable<Connection>{
    private int x;
    private int y;
    private int value;

    public Connection(int x, int y, int value){
        this.x = x;
        this.y = y;
        this.value = value;
    }

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public int getValue() {
        return value;
    }

    @Override
    public int compareTo(Connection other) {
        return Integer.compare(this.value,other.value);
    }
}

public class Main {

    public static int n,m,tot;
    public static int[] parent;

    public static int find(int idx){
        if(parent[idx]==idx) return idx;
        else return parent[idx] =find(parent[idx]);
    }

    public static void merge(int a, int b){
        a = find(a);
        b = find(b);

        if(a==b) return;
        if(a>b){
            int temp = a;
            a = b;
            b = temp;
        }

        parent[b] = a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());

        parent = new int[n];

        for(int i=0; i<n; i++) parent[i] = i;

        PriorityQueue<Connection> pq = new PriorityQueue<>();

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(st.nextToken());
            int y =Integer.parseInt(st.nextToken());
            int value = Integer.parseInt(st.nextToken());

            pq.offer(new Connection(x,y,value));
        }
        while(!pq.isEmpty()){
            Connection connection = pq.poll();
            int x = connection.getX();
            int y = connection.getY();
            int value = connection.getValue();
            if(find(x)==find(y)){
                tot += value;
                continue;
            }
            else merge(x,y);
        }
        bw.write(String.valueOf(tot)+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}