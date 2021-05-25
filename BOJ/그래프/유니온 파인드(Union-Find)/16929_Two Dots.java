import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair{
    private int x;
    private int y;
    public Pair(int x, int y){
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

    public static int n,m;
    public static char[][] map;
    public static int[] parent;
    public static boolean[][] vis;
    public static int[][] mapNum;
    public static boolean isPossible;
    public static int[] dx = {1,-1, 0, 0};
    public static int[] dy = {0 ,0, 1, -1};
    public static boolean[][] visPair;
    public static int find(int idx){
        if(parent[idx]==idx) return idx;
        else return parent[idx] = find(parent[idx]);
    }
    public static void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return;
        if(a>b) parent[a] = b;
        else parent[b] = a;
    }

    public static void bfs(int bx, int by){
        Queue<Pair> q = new LinkedList<>();
        ArrayList<Pair> arrayList = new ArrayList<>();
        q.offer(new Pair(bx,by));
        while (!q.isEmpty()){
            Pair pair = q.poll();
            int x = pair.getX();
            int y = pair.getY();
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<1||ny<1||nx>n||ny>m) continue;
                if(map[x][y]!= map[nx][ny]) continue;
                int le = Math.min(mapNum[x][y],mapNum[nx][ny]);
                int ri = Math.max(mapNum[x][y],mapNum[nx][ny]);
                if(!visPair[le][ri]){
                    visPair[le][ri] = true;
                    arrayList.add(new Pair(le,ri));
                }
                if(vis[nx][ny]) continue;
                vis[nx][ny] = true;
                q.offer(new Pair(nx,ny));
            }
        }
        for(int i=0; i<arrayList.size();i++){
            Pair pair = arrayList.get(i);
            int x = pair.getX();
            int y= pair.getY();
            if(find(x)==find(y)) isPossible = true;
            else merge(x,y);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new char[n+1][m+1];
        mapNum = new int[n+1][m+1];
        parent = new int[n*m+1];
        vis = new boolean[n+1][m+1];
        visPair = new boolean[n*m+1][n*m+1];
        for(int i =1; i<=n*m; i++)parent[i] = i;
        int cnt = 1;
        for(int i=1; i<=n; i++){
            String str= br.readLine();
            for(int j=1; j<=m; j++){
                map[i][j] = str.charAt(j-1);
                mapNum[i][j] = cnt;
                cnt++;
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(!vis[i][j]){
                    vis[i][j] = true;
                    bfs(i,j);
                }
            }
        }
        if(isPossible) bw.write("Yes\n");
        else bw.write("No\n");
        bw.flush();
        br.close();
        bw.close();

    }
}