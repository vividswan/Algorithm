import java.util.ArrayList;
import java.util.Collections;

class Solution {

    public static ArrayList<ArrayList<String>> wordList = new ArrayList<ArrayList<String>>();
    public static ArrayList<ArrayList<String>> reverseWordList = new ArrayList<ArrayList<String>>();
    public static int findFunc(String str){
        int rightValue = 0;
        int leftValue = 0;
        if(str.charAt(str.length()-1)=='?'){
            rightValue = getRightValue(wordList.get(str.length()),str.replaceAll("\\?","z"));
            leftValue = getLeftValue(wordList.get(str.length()),str.replaceAll("\\?","a"));
        }
        else {
            String reStr = new StringBuffer(str).reverse().toString();
            rightValue = getRightValue(reverseWordList.get(str.length()),reStr.replaceAll("\\?","z"));
            leftValue = getLeftValue(reverseWordList.get(str.length()),reStr.replaceAll("\\?","a"));
        }

        return rightValue - leftValue;
    }
    public static int getRightValue(ArrayList<String> list, String str){
        int left = 0;
        int right = list.size();
        while(left < right){
            int mid = (left+right)/2;
            if(list.get(mid).compareTo(str) > 0) right = mid;
            else left = mid+1;
        }
        return right;
    }

    public static int getLeftValue(ArrayList<String> list, String str){
        int left = 0;
        int right = list.size();
        while(left < right){
            int mid = (left+right)/2;
            if(list.get(mid).compareTo(str) >= 0) right = mid;
            else left = mid+1;
        }
        return right;
    }

    public int[] solution(String[] words, String[] queries) {

        int[] answer = new int[queries.length];

        for(int i=0; i<= 10000; i++){
            wordList.add(new ArrayList<>());
            reverseWordList.add(new ArrayList<>());
        }

        for(int i=0; i<words.length; i++){
            String str = words[i];
            wordList.get(str.length()).add(str);
            String reverseStr = new StringBuffer(str).reverse().toString();
            reverseWordList.get(str.length()).add(reverseStr);
        }

        for(int i=1; i<=10000; i++){
            Collections.sort(wordList.get(i));
            Collections.sort(reverseWordList.get(i));
        }

        for(int i=0; i<queries.length;i++){
            answer[i] = findFunc(queries[i]);
        }


        return answer;
    }

}