import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Node implements Comparable<Node>{
    private int x;
    private int y;
    private int val;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getVal() {
        return val;
    }

    public Node(int x, int y, int val){
        this.x = x;
        this.y = y;
        this.val = val;
    }

    @Override
    public int compareTo(Node other) {
        return Integer.compare(this.val, other.val);
    }
}

public class Main {
    public static int[][] map;
    public static ArrayList<Node> list = new ArrayList<>();
    public static int n,k, s, x, y;
    public static int[] dx = {0,0,-1,1};
    public static int[] dy = {1,-1,0,0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        map = new int[n+1][n+1];

        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] != 0) list.add(new Node(i,j,map[i][j]));
            }
        }

        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());
        int sec = 0;
        boolean printAns = false;
        while (!list.isEmpty()){
            if(sec == s) {
                bw.write(String.valueOf(map[x][y])+"\n");
                printAns = true;
            }
            int size = list.size();
            Collections.sort(list);
            ArrayList<Node> temp = new ArrayList<>();
            for(int i=0; i<size; i++){
                Node node = list.get(i);
                int x = node.getX();
                int y = node. getY();

                for(int j=0; j<4; j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(nx<1 || ny < 1 || nx > n || ny > n) continue;
                    if(map[nx][ny]!=0) continue;
                    map[nx][ny] = node.getVal();
                    temp.add(new Node(nx,ny,node.getVal()));
                }
            }
            sec++;
            list = temp;
        }
        if(!printAns) bw.write(String.valueOf(map[x][y])+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}