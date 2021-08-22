import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class MaxNode implements Comparable<MaxNode>{
    private int idx;
    private long value;

    public int getIdx() {
        return idx;
    }

    public long getValue() {
        return value;
    }

    public MaxNode(int idx ,long value){
        this.idx = idx;
        this.value = value;
    }

    @Override
    public int compareTo(MaxNode other){
        return Long.compare(other.value, this.value);
    }
}

class MinNode implements Comparable<MinNode>{
    private int idx;
    private long value;

    public int getIdx() {
        return idx;
    }

    public long getValue() {
        return value;
    }

    public MinNode(int idx ,long value){
        this.idx = idx;
        this.value = value;
    }

    @Override
    public int compareTo(MinNode other){
        return Long.compare(this.value, other.value);
    }
}

public class Main {
    public static int t;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        t = Integer.parseInt(br.readLine());
        for(int l=0; l<t; l++){
            int k = Integer.parseInt(br.readLine());
            int cnt = 0;
            boolean[] isDel = new boolean[k+1];
            PriorityQueue<MaxNode> maxPq = new PriorityQueue<>();
            PriorityQueue<MinNode> minPq = new PriorityQueue<>();
            for(int i=0; i<k; i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                String mod = st.nextToken();
                long num = Long.parseLong(st.nextToken());
                while (!maxPq.isEmpty()){
                    MaxNode maxNode = maxPq.peek();
                    if (isDel[maxNode.getIdx()]) maxPq.poll();
                    else break;
                }
                while (!minPq.isEmpty()){
                    MinNode minNode = minPq.peek();
                    if (isDel[minNode.getIdx()]) minPq.poll();
                    else break;
                }
                if(mod.equals("I")){
                    MaxNode maxNode = new MaxNode(cnt, num);
                    MinNode minNode = new MinNode(cnt, num);
                    maxPq.add(maxNode);
                    minPq.add(minNode);
                    cnt++;
                }
                else {
                    if (num==1){
                        if (maxPq.isEmpty()) continue;
                        MaxNode maxNode = maxPq.poll();
                        isDel[maxNode.getIdx()] = true;
                        if (!minPq.isEmpty()){
                            if (minPq.peek().getIdx() == maxNode.getIdx()) minPq.poll();
                        }
                    }
                    else {
                        if (minPq.isEmpty()) continue;
                        MinNode minNode = minPq.poll();
                        isDel[minNode.getIdx()] = true;
                        if (!maxPq.isEmpty()){
                            if (maxPq.peek().getIdx() == minNode.getIdx()) maxPq.poll();
                        }
                    }
                }
            }
            while (!maxPq.isEmpty()){
                MaxNode maxNode = maxPq.peek();
                if (isDel[maxNode.getIdx()]) maxPq.poll();
                else break;
            }
            while (!minPq.isEmpty()){
                MinNode minNode = minPq.peek();
                if (isDel[minNode.getIdx()]) minPq.poll();
                else break;
            }
            if (minPq.isEmpty() && maxPq.isEmpty()) bw.write("EMPTY\n");
            else bw.write(maxPq.peek().getValue()+" "+minPq.peek().getValue()+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}