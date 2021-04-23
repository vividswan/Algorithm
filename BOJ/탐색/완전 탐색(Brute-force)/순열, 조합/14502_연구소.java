import java.io.*;
import java.util.*;

class Node{
    private int x;
    private int y;
    public Node(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}

public class Main {

    public static int n,m,res;
    public static int[] dx = {0,0,1,-1};
    public static int[] dy = {-1,1,0,0};
    public static int[][] map;
    public static ArrayList<Node> arr = new ArrayList<>();
    public static ArrayList<ArrayList<Integer>> combArray = new ArrayList<ArrayList<Integer>>();
    public static int emptySize;
    public static boolean[] chk;

    public static void bfsFunc(ArrayList<Integer> array){
        int[][] nowMap = new int[n+1][m+1];
        int nowRes = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                nowMap[i][j] = map[i][j];
            }
        }
        for(int i=0;i<array.size();i++){
            nowMap[arr.get(array.get(i)).getX()][arr.get(array.get(i)).getY()] = 1;
        }
        Queue<Node> q = new LinkedList<>();
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (nowMap[i][j]==2) q.offer(new Node(i,j));
            }
        }
        while (!q.isEmpty()){
            Node node = q.poll();
            int x = node.getX();
            int y = node.getY();
            for(int i=0; i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<1 || ny <1 || nx>n || ny >m) continue;
                if(nowMap[nx][ny]!=0) continue;
                nowMap[nx][ny] = 2;
                q.offer(new Node(nx,ny));
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (nowMap[i][j]==0) nowRes++;
            }
        }
        res = Math.max(res,nowRes);
    }

    public static void  recursion(int idx, int cnt){
        if(cnt == 3){
            ArrayList<Integer> temp =  new ArrayList<Integer>();
            for(int i=0; i<emptySize; i++){
                if(chk[i]) temp.add(i);
            }
            combArray.add(temp);
            return;
        }

        for(int i=idx; i<emptySize; i++){
            if(!chk[i]){
                chk[i] = true;
                recursion(i,cnt+1);
                chk[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n+1][m+1];

        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=m; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j]==0) arr.add(new Node(i,j));
            }
        }
        emptySize = arr.size();
        chk = new boolean[emptySize];

        recursion(0,0);

        for(int i=0; i<combArray.size(); i++){
            ArrayList<Integer> nowComb = combArray.get(i);
            bfsFunc(nowComb);
        }
        bw.write(String.valueOf(res)+"\n");
        bw.flush();
        br.close();
        bw.close();
    }
}