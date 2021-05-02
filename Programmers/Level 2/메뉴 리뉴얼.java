import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class Node implements Comparable<Node>{
    private int value;
    private String str;
    public Node(int value, String str){
        this.value = value;
        this.str = str;
    }

    public int getValue() {
        return value;
    }

    public String getStr() {
        return str;
    }

    @Override
    public int compareTo(Node other) {
        return Integer.compare(other.value, this.value);
    }
}

class Solution {

    public static int nowCount;
    public static boolean[] chk;
    public static ArrayList<String> comb;
    public static boolean isRight(String str1, String str2){
        int pointer = 0;
        for(int i=0; i<str2.length(); i++){
            if(str1.charAt(pointer)==str2.charAt(i)){
                pointer++;
                if(pointer==str1.length()){
                    return true;
                }
            }
        }
        return false;
    }
    public static void recursion(int idx, int cnt){
        if(cnt == nowCount){
            String str = "";
            for(int i=0; i<26;i++){
                if(chk[i]) str+=(char)(i+'A');
            }
            comb.add(str);
            return;
        }
        for(int i=idx; i<26;i++){
            if(!chk[i]){
                chk[i] = true;
                recursion(i,cnt+1);
                chk[i] = false;
            }
        }

    }

    public String[] solution(String[] orders, int[] course) {
        ArrayList<String> ans = new ArrayList<>();
        for(int i=0; i<orders.length;i++){
            char[] StringtoChar = orders[i].toCharArray();
            Arrays.sort(StringtoChar);
            orders[i] = new String(StringtoChar);
        }

        for(int k=0; k<course.length;k++){
            nowCount = course[k];
            chk = new boolean[26];
            comb = new ArrayList<>();
            recursion(0,0);
            ArrayList<Node> nodeList = new ArrayList<>();
            for(int i=0;i<comb.size();i++){
                String str = comb.get(i);
                int cnt = 0;
                for(int j=0; j<orders.length;j++){
                    if(isRight(str,orders[j])) cnt++;
                }
                if(cnt >= 2) nodeList.add(new Node(cnt, str));
            }
            Collections.sort(nodeList);
            int maxValue = 0;
            for(int t=0; t<nodeList.size();t++){
                if(t==0) maxValue = nodeList.get(t).getValue();
                if(maxValue!=nodeList.get(t).getValue()) break;
                ans.add(nodeList.get(t).getStr());
            }
        }
        Collections.sort(ans);
        String[] answer = new String[ans.size()];
        for(int i=0; i<ans.size();i++){
            answer[i] = ans.get(i);
        }

        return answer;
    }
}