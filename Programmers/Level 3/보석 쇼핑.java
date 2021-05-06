import java.util.*;

class Node implements Comparable<Node>{
    private int x;
    private int y;
    private int value;
    public Node(int x, int y, int value){
        this.x = x;
        this.y = y;
        this.value = value;
    }

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public int getValue() {
        return value;
    }

    @Override
    public int compareTo(Node o) {
        if(this.value != o.value) return Integer.compare(this.value, o.value);
        else return Integer.compare(this.x, o.x);
    }
}

class Solution {

    public static Map<String,Integer> m = new HashMap<>();
    public static Set<String > s = new HashSet<>();
    public static Queue<String> q = new LinkedList<>();
    public static int idx;
    ArrayList<Node> arr = new ArrayList<>();

    public int[] solution(String[] gems) {
        for(int i=0; i<gems.length; i++){
            s.add(gems[i]);
        }
        for(int i=0; i<gems.length;i++){
            String now = gems[i];
            if(!m.containsKey(now)) m.put(now,1);
            else m.replace(now, m.get(now)+1);
            q.offer(now);
            while(!q.isEmpty()){
                if (m.get(q.peek())>=2){
                    m.replace(q.peek(), m.get(q .peek())-1);
                    q.poll();
                    idx++;
                    continue;
                }
                break;
            }
            if(m.size()==s.size()) arr.add(new Node(idx+1,i+1,q.size()));
        }
        Collections.sort(arr);
        int[] answer = {arr.get(0).getX(), arr.get(0).getY()};
        return answer;
    }
}