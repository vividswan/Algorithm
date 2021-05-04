import java.util.ArrayList;

class Solution {
    public static boolean[] vis;

    public int[] solution(String s) {
        s =  s.substring(1,s.length()-1);
        String[] array = s.split("},");
        for(int i=0; i<array.length;i++){
            if(i==array.length-1) array[i] = array[i].substring(1,array[i].length()-1);
            else array[i] = array[i].substring(1);
        }
        int n = array.length;
        ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i<=n; i++) arr.add(new ArrayList<>());
        for(int i=0; i<n; i++){
            String[] nowArr = array[i].split(",");
            int size = nowArr.length;
            for(int j=0;j<size;j++){
                arr.get(size).add(Integer.parseInt(nowArr[j]));
            }
        }
        ArrayList<Integer> res = new ArrayList<>();
        vis = new boolean[100001];
        for(int i=1; i<=n; i++){
            ArrayList<Integer> list = arr.get(i);
            for(int j=0; j<list.size(); j++){
                int now = list.get(j);
                if(!vis[now]){
                    res.add(now);
                    vis[now] = true;
                    break;
                }
            }
        }
        int[] answer = new int[res.size()];
        for(int i=0; i<res.size();i++){
            answer[i] = res.get(i);
        }
        return answer;
    }
}