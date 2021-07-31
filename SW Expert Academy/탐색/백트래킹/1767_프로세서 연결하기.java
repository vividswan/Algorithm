import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Pair {
    private int x;
    private int y;

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Solution {
    public static final int MAX = 100000000;
    public static void recur(int idx, int cnt, int val) {
        if (processorCnt == idx) {
            int tempRes = res;
            res = Math.max(res, cnt);
            if (tempRes < res) resVal = MAX;
            if (res == cnt) resVal = Math.min(resVal, val);
            return;
        }
        recur(idx + 1, cnt, val);
        Pair pair = processors.get(idx);
        boolean possible = true;
        int x = pair.getX();
        int y = pair.getY();

        for (int i = 1; i <x ; i++) {
            if (arr[i][y]!=0) {
                possible = false;
                break;
            }
        }
        if (possible) {
            for (int i = 1; i <x ; i++) {
                arr[i][y] = 2;
            }
            recur(idx+1, cnt+1, val+x-1);
            for (int i = 1; i <x ; i++) {
                arr[i][y] = 0;
            }
        }
        possible = true;
        for (int i = n;i >x ; i--) {
            if (arr[i][y]!=0) {
                possible = false;
                break;
            }
        }
        if (possible) {
            for (int i = n;i >x ; i--) {
                arr[i][y] = 2;
            }
            recur(idx+1, cnt+1, val+n-x);
            for (int i = n;i >x ; i--) {
                arr[i][y] = 0;
            }
        }
        possible = true;
        for (int i = 1; i <y ; i++) {
            if (arr[x][i]!=0) {
                possible = false;
                break;
            }
        }
        if (possible) {
            for (int i = 1; i <y ; i++) {
                arr[x][i] = 2;
            }
            recur(idx+1, cnt+1, val+y-1);
            for (int i = 1; i <y ; i++) {
                arr[x][i] = 0;
            }
        }
        possible = true;
        for (int i = n;i >y ; i--) {
            if (arr[x][i]!=0) {
                possible = false;
                break;
            }
        }
        if (possible) {
            for (int i = n;i >y ; i--) {
                arr[x][i] = 2;
            }
            recur(idx+1, cnt+1, val+n-y);
            for (int i = n;i >y ; i--) {
                arr[x][i] = 0;
            }
        }
    }
    public static int testCase, n, processorCnt, res, resVal;
    public static ArrayList<Pair> processors;
    public static int[][] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = Integer.parseInt(br.readLine());

        for (int t = 1; t <=testCase ; t++) {
            res = 0;
            resVal = MAX;
            n = Integer.parseInt(br.readLine());
            arr = new int[n + 1][n + 1];
            processors = new ArrayList<>();
            for (int i = 1; i <= n ; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 1; j <= n ; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                    if (arr[i][j] == 1 && i != 1 && i!=n && j!=1 && j!= n) processors.add(new Pair(i, j));
                }
            }
            processorCnt = processors.size();
            recur(0,0,0);
            bw.write("#"+t+" "+resVal+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}