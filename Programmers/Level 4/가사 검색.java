import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public static ArrayList<ArrayList<String>> list = new ArrayList<ArrayList<String>>();
    public static ArrayList<ArrayList<String>> reverseList = new ArrayList<ArrayList<String>>();
    public static ArrayList<Integer> ans;

    public static int leftIdx(ArrayList<String> nowList, String target){
        int left = 0;
        int right = nowList.size();
        while(left < right){
            int mid = (right+left)/2;
            if(nowList.get(mid).compareTo(target)>=0) right = mid;
            else left = mid+1;
        }
        return right;
    }

    public static int rightIdx(ArrayList<String> nowList, String target){
        int left = 0;
        int right = nowList.size();
        while (left < right){
            int mid = (right+left)/2;
            if(nowList.get(mid).compareTo(target)>0) right = mid;
            else left = mid + 1;
        }
        return right;
    }


    public static int getCnt(ArrayList<String> list, String target){
        String lTaget = target.replaceAll("\\?", "a");
        String rTaget = target.replaceAll("\\?", "z");
        int left = leftIdx(list, lTaget);
        int right = rightIdx(list, rTaget);
        return right - left;
    }

    public int[] solution(String[] words, String[] queries) {

        for(int i=0;i<=10000;i++){
            list.add(new ArrayList<String>());
            reverseList.add(new ArrayList<String>());
        }

        for(int i=0; i< words.length;i++){
            list.get(words[i].length()).add(words[i]);
            String reverseString = (new StringBuffer(words[i])).reverse().toString();
            reverseList.get(words[i].length()).add(reverseString);
        }

        for(int i=0;i<=10000;i++){
            Collections.sort(list.get(i));
            Collections.sort(reverseList.get(i));
        }

        ans = new ArrayList<>();

        for(int i=0; i<queries.length;i++){
            int cnt ;
            String word = queries[i];
            if(queries[i].charAt(0)!='?') cnt = getCnt(list.get(word.length()),word);
            else cnt = getCnt(reverseList.get(word.length()), (new StringBuffer(word)).reverse().toString());
            ans.add(cnt);
        }



        int[] answer = new int[ans.size()];
        for(int i=0; i< ans.size();i++){
            answer[i]  = ans.get(i);
        }
        return answer;
    }
}