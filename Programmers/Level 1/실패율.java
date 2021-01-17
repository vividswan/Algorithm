import java.util.ArrayList;
import java.util.Collections;

class Stage implements Comparable<Stage>{
    private int idx;
    private float proccess;

    public Stage(int idx, float proccess){
        this.idx = idx;
        this.proccess = proccess;
    }

    public int getIdx() {
        return idx;
    }

    @Override
    public int compareTo(Stage other) {
        if(this.proccess != other.proccess)return Float.compare(other.proccess, this.proccess);
        else return Integer.compare(this.idx, other.idx);
    }
}

class Solution {

    public static int[] cnt;
    public static int[] notSuccess;
    public static float[] res;

    public int[] solution(int N, int[] stages) {

        cnt = new int[N+2];
        notSuccess = new int[N+2];
        res = new float[N+2];

        ArrayList<Stage> list = new ArrayList<>();

        for(int i=0; i<stages.length;i++){
            int stage = stages[i];
            for(int j=1; j<=stage;j++){
                cnt[j]++;
            }
            notSuccess[stage]++;
        }

        for(int i=1;i<=N;i++){
            if(cnt[i]==0) list.add(new Stage(i,0));
            else list.add(new Stage(i, ((float)notSuccess[i]/cnt[i])));
        }

        Collections.sort(list);

        int[] answer = new int[N];

        for(int i=0;i<list.size();i++){
            answer[i] = list.get(i).getIdx();
        }

        return answer;
    }
}