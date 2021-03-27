import java.util.Arrays;
import java.util.PriorityQueue;

class Node implements Comparable<Node>{
    private  int val;
    private  int idx;

    public Node(int val, int idx){
        this.val = val;
        this.idx = idx;
    }

    public int getIdx() {
        return idx;
    }

    public int getVal() {
        return val;
    }

    @Override
    public int compareTo(Node other) {
        return Integer.compare(this.val, other.val);
    }
}

class Solution {

    public int solution(int[] food_times, long k) {

        PriorityQueue<Node> pq = new PriorityQueue<>();
        long sum = 0;

        for (int i = 0; i < food_times.length; i++) {
            pq.offer(new Node(food_times[i], i + 1));
            sum += food_times[i];
        }

        if (sum <= k) return -1;
        sum = 0;
        long foodLength = pq.size();
        long bef = 0;
        long now = 0;


        while (sum + (pq.peek().getVal() - bef) * foodLength <= k) {
            Node node = pq.poll();
            now = node.getVal();
            sum += (now - bef) * foodLength;
            foodLength--;
            bef = now;
        }

        k -= sum;
        int[] arr = new int[pq.size()];
        int cnt = 0;
        while(!pq.isEmpty()){
            int idx = pq.poll().getIdx();
            arr[cnt]  = idx;
            cnt++;
        }
        Arrays.sort(arr);

        return arr[(int)(k%cnt)];

    }
}