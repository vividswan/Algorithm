import java.io.*;
import java.util.*;

class Virus implements Comparable<Virus> {
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

    public Virus(int x, int y, int value){
        this.x = x;
        this.y = y;
        this.value = value;
    }

    @Override
    public int compareTo(Virus other) {
        if(this.value < other.value) return -1;
        else return 1;
    }
}

public class 18405_경쟁적 전염 {

    public static int n;
    public static int k;
    public static int s;
    public static int x;
    public static int y;
    public static int[][] map;
    public static ArrayList<Virus> list = new ArrayList<>();
    public static int[] dx = {1,-1,0,0};
    public static int[] dy = {0,0,1,-1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        map = new int[n+1][n+1];

        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=n;j++){
                map[i][j] =Integer.parseInt(st.nextToken());
                if(map[i][j]!=0) {
                    list.add(new Virus(i,j,map[i][j]));
                }
            }
        }

        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());

        Collections.sort(list);

        Queue<Virus> q = new LinkedList<>();
        for(int i=0;i<list.size();i++) q.offer(list.get(i));

        int t = 0;
        int qSize = q.size();

        while(!q.isEmpty()){
            if(t==s) break;
            qSize--;
            if(qSize==0){
                t++;
                qSize = q.size();
            }
            if(t==s) break;
            Virus virus = q.poll();
            for(int j=0;j<4;j++){
                int nx = virus.getX() + dx[j];
                int ny = virus.getY() + dy[j];
                if(nx<1||ny<1||nx>n||ny>n) continue;
                if(map[nx][ny]!=0) continue;
                map[nx][ny] = virus.getValue();
                q.offer(new Virus(nx,ny,virus.getValue()));
            }
        }

        bw.write(String.valueOf(map[x][y]));
        bw.flush();
        br.close();
        bw.close();
    }

}