import java.io.*;
import java.util.*;

class Pair implements Comparable<Pair>{
    private int x;
    private int y;

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pair other) {
        return Integer.compare(this.x, other.x);
    }
}

public class Solution {
    public static int testCase;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testCase = sc.nextInt();

        for (int t = 1; t <=testCase ; t++) {
            ArrayList<Pair> pairs = new ArrayList<>();

            int l = sc.nextInt();
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                pairs.add(new Pair(x, y));
            }
            Collections.sort(pairs);
            int[] getVal = new int[n];
            int res = 0;
            int start;
            int end;
            int bef = 0;
            int finalNum =0;
            for (int i = 0; i <n ; i++) {
                Pair pair = pairs.get(i);
                end = pair.getY();
                start = end - l;
                if (pair.getX() >= start) getVal[i] = pair.getY() - pair.getX();
                else getVal[i] = pair.getY() - start;
                res += getVal[i];
                while (true) {
                    if (bef == i) break;
                    Pair befPair = pairs.get(bef);
                    if (befPair.getX() >= start) break;
                    if (befPair.getY() <= start) {
                        res -= getVal[bef];
                        bef++;
                    }
                    else if (start < befPair.getY() ){
                        res -= getVal[bef];
                        getVal[bef] = befPair.getY() - start;
                        res += getVal[bef];
                        break;
                    }
                }
                finalNum = Math.max(finalNum, res);
            }
            bw.write("#"+t+" "+String.valueOf(finalNum)+"\n");
            bw.flush();
        }
        bw.close();
        sc.close();
    }
}