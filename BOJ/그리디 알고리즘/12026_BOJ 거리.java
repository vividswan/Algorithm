import java.io.*;
import java.util.Arrays;
import java.util.PriorityQueue;

class Pair implements Comparable<Pair>{
    private int x;
    private long y;

    public int getX() {
        return x;
    }

    public long getY() {
        return y;
    }

    public Pair(int x, long y){
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pair other){
        return Long.compare(this.y,other.y);
    }

}

public class Main {
    public static int n;
    public static String str = " ";
    public static long[] distTable;
    public static final long INF = (int)1e9;
    public static boolean[] vis;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        distTable = new long[n+1];
        vis = new boolean[n+1];
        Arrays.fill(distTable,INF);
        str += br.readLine();
        PriorityQueue<Pair> q = new PriorityQueue<>();
        distTable[1] = 0;
        q.offer(new Pair(1,0));
        while (!q.isEmpty()){
            int nowIdx = q.poll().getX();
            if (vis[nowIdx]) continue;
            else vis[nowIdx] = true;
            char nowChar = str.charAt(nowIdx);
            for(int i=nowIdx+1; i<=n; i++){
                if (nowChar=='B' && str.charAt(i)!='O') continue;
                if (nowChar=='O' && str.charAt(i)!='J') continue;
                if (nowChar=='J' && str.charAt(i)!='B') continue;
                if (distTable[i] < (long) (i - nowIdx) * (i-nowIdx) + distTable[nowIdx]) continue;
                distTable[i] = (long) (i - nowIdx) * (i-nowIdx) + distTable[nowIdx];
                q.offer(new Pair(i,distTable[i]));
            }
        }
        if (distTable[n]==INF) bw.write("-1\n");
        else bw.write(String.valueOf(distTable[n])+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}