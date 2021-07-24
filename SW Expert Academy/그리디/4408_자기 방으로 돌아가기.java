import java.io.*;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;

class Pair implements Comparable<Pair> {
    private int x;
    private int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
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
        for (int t = 1; t <= testCase; t++) {
            int n = sc.nextInt();
            PriorityQueue<Pair> pq = new PriorityQueue<>();
            for (int i = 1; i <= n; i++) {
                int num1 = sc.nextInt();
                int num2 = sc.nextInt();
                if (num1 > num2) {
                    int temp = num1;
                    num1 = num2;
                    num2 = temp;
                }
                if ((num1%2)==0) num1 -= 1;
                if ((num2%2)==0) num2 -= 1;
                pq.offer(new Pair(num1, num2));
            }
            int res = 0;
            while (!pq.isEmpty()) {
                PriorityQueue<Pair> tempPq = new PriorityQueue<>();
                int lastIdx = -1;
                while (!pq.isEmpty()){
                    Pair pair = pq.poll();
                    if (pair.getX()<=lastIdx) tempPq.add(pair);
                    else{
                        lastIdx = pair.getY();
                    }
                }
                pq = tempPq;
                res++;
            }
            bw.write("#"+t+" "+res+"\n");
        }
        bw.flush();
        sc.close();
        bw.close();

    }
}