import java.util.*;

class Pair implements Comparable<Pair>{
    private int idx;
    private long val;

    public Pair(int idx, long  val){
        this.idx = idx;
        this.val = val;
    }

    public int getIdx() {
        return idx;
    }

    public long getVal() {
        return val;
    }

    @Override
    public int compareTo(Pair other) {
        return Long.compare(this.val, other.val);
    }
}

class Solution {
    public int solution(int[] food_times, long k) {

        long tot = 0;
        for(int i=0;i<food_times.length;i++){
            tot += food_times[i];
        }

        if(tot<=k) return -1;

        PriorityQueue<Pair> pq = new PriorityQueue<>();
        for(int i=0;i<food_times.length;i++){
            pq.offer(new Pair(i+1, (long)food_times[i]));
        }

        long befTot = 0;
        long befVal = 0;
        long cnt =food_times.length;

        while(befTot+((pq.peek().getVal()-befVal)*cnt) <= k){
            Pair pair = pq.poll();
            befTot += (pair.getVal()-befVal) * cnt;
            cnt--;
            befVal = pair.getVal();
        }


        List<Integer> list = new ArrayList<>();

        while(!pq.isEmpty()){
            Pair pair = pq.poll();
            int idx = pair.getIdx();
            list.add(idx);
        }

        Collections.sort(list);

        int answer = list.get((int) ((k-befTot) % cnt));
        return answer;
    }
}