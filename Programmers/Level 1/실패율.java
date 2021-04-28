import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class Node implements Comparable<Node>{
    private int idx;
    private double val;

    public int getIdx() {
        return idx;
    }

    public double getVal() {
        return val;
    }

    public Node(int idx, double val){
        this.idx = idx;
        this.val = val;
    }

    @Override
    public int compareTo(Node other) {
        return Double.compare(other.val,this.val);
    }
}

class Solution {
    public static double[] clear;
    public static double[] notClear;

    public int[] solution(int N, int[] stages) {
        clear = new double[N+2];
        notClear = new double[N+2];
        for(int i=0; i<stages.length; i++){
            int now = stages[i];
            notClear[now]++;
            for(int j=1; j<=now; j++) clear[j]++;
        }
        ArrayList<Node> list = new ArrayList<>();
        for(int i=1; i<=N; i++){
            if(clear[i]==0) list.add(new Node(i,  0));
            else list.add(new Node(i,  (notClear[i]/clear[i])));
        }
        Collections.sort(list);
        int[] answer = new int[N];
        for(int i=0; i<N;i++){
            answer[i] = list.get(i).getIdx();
        }
        return answer;
    }
}