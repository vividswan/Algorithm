import java.util.ArrayList;
import java.util.Collections;

class Solution {

    public static ArrayList<ArrayList<Integer>> permuList = new ArrayList<ArrayList<Integer>>();
    public static ArrayList<Integer> nowPermu = new ArrayList<>();
    public static ArrayList<Integer> weakLocations = new ArrayList<>();
    public static ArrayList<Integer>distList = new ArrayList<>();
    public static boolean[] chk;
    public static int weakSize;
    public static int distSize;

    public static void recursion(int cnt){
        if(cnt == distSize){
            ArrayList<Integer> temp = new ArrayList<>(nowPermu);
            permuList.add(temp);
            return;
        }
        for(int i=0; i<distSize;i++){
            if(!chk[i]){
                chk[i] = true;
                nowPermu.add(distList.get(i));
                recursion(cnt+1);
                nowPermu.remove(nowPermu.size()-1);
                chk[i] = false;
            }
        }
    }

    public int solution(int n, int[] weak, int[] dist) {

        weakSize = weak.length;
        distSize = dist.length;
        chk = new boolean[distSize];
        int answer = dist.length+1;

        for(int i=0; i<dist.length; i++){
            distList.add(dist[i]);
        }

        for(int i=0; i<weakSize; i++){
            weakLocations.add(weak[i]);
            weakLocations.add(weak[i] + n);
        }

        Collections.sort(weakLocations);

        recursion(0);

        for(int i=0; i<weakSize;i++){
            for(int j=0; j<permuList.size();j++){
                ArrayList<Integer> permu = permuList.get(j);
                int cnt = 1;
                boolean isCorrect = true;
                int nowDist = weakLocations.get(i) + permu.get(0);
                for(int idx=i;idx<i+weakSize; idx++){
                    if (nowDist < weakLocations.get(idx)){
                        cnt++;
                        if(cnt > permu.size()){
                            isCorrect = false;
                            break;
                        }
                        nowDist = weakLocations.get(idx) + permu.get(cnt-1);
                    }
                }
                if(isCorrect) answer = Math.min(answer,cnt);
            }
        }
        if(answer == dist.length+1) return -1;
        else return answer;
    }
}