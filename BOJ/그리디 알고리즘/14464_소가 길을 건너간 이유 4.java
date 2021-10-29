import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Pair implements Comparable<Pair>{
    int x;
    int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pair other) {
        if (this.y == other.y) return Integer.compare(this.x, other.x);
        else return Integer.compare(this.y , other.y);
    }
}

public class Main {
    static int c, n, res;
    static ArrayList<Pair> cows;
    static ArrayList<Integer> chickens;
    static boolean[] vis;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        c = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        cows = new ArrayList<>();
        chickens = new ArrayList<>();
        vis = new boolean[n];
        for (int i = 0; i < c; i++) {
            chickens.add(Integer.parseInt(br.readLine()));
        }
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            cows.add(new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        Collections.sort(cows);
        Collections.sort(chickens);
        for (Integer chicken : chickens) {
            for (int i = 0; i < n; i++) {
                if (vis[i]) continue;
                Pair cow = cows.get(i);
                if (chicken >= cow.x && chicken <= cow.y) {
                    res++;
                    vis[i] = true;
                    break;
                }
            }
        }

        bw.write(res+"\n");
        bw.flush();
        br.close();
        bw.close();

    }
}