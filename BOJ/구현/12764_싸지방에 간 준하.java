import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Pair implements Comparable<Pair>{
    private int x;
    private int y;

    public Pair(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    @Override
    public int compareTo(Pair o) {
        return Integer.compare(this.x, o.x);
    }
}

class Computer implements Comparable<Computer>{
    private int idx;
    private int endTime;
    public Computer(int idx, int endTime){
        this.idx = idx;
        this.endTime = endTime;
    }

    public int getIdx() {
        return idx;
    }

    public int getEndTime() {
        return endTime;
    }

    @Override
    public int compareTo(Computer o) {
        if(this.endTime == o.endTime) return  Integer.compare(this.idx, o.idx);
        else return Integer.compare(this.endTime, o.endTime);
    }
}

public class Main {
    public static int n;
    public static int[] cnt;
    public static int computerCnt;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        cnt = new int[n+1];

        ArrayList<Pair> pairs = new ArrayList<>();
        for(int i=0; i<n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            pairs.add(new Pair(p,q));
        }
        Collections.sort(pairs);
        PriorityQueue<Computer> pq = new PriorityQueue<>();
        PriorityQueue<Integer> ansQ = new PriorityQueue<>();
        for(int i=0; i<pairs.size(); i++){
            Pair pair = pairs.get(i);
            int p = pair.getX();
            int q = pair.getY();
            while (!pq.isEmpty()){
                if (pq.peek().getEndTime()<p){
                    ansQ.offer(pq.poll().getIdx());
                }
                else break;
            }
            if(ansQ.isEmpty()){
                computerCnt++;
                cnt[computerCnt]++;
                pq.offer(new Computer(computerCnt, q));
            }
            else{
                int idx = ansQ.poll();
                cnt[idx]++;
                pq.offer(new Computer(idx,q));
            }
        }
        bw.write(String.valueOf(computerCnt)+"\n");
        for(int i=1; i<=computerCnt; i++) bw.write(String.valueOf(cnt[i])+" ");
        bw.flush();
        br.close();
        bw.close();

    }
}