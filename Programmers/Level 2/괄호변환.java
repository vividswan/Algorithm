import java.util.Stack;

class Solution {

    public static String recursionV(String str){
        if(str.isEmpty()) return "";
        int cnt1 = 0;
        int cnt2 = 0;
        int maxIdx = 0;
        boolean isRight = true;
        for(int i=0;i<str.length();i++){
            char nowC = str.charAt(i);
            if(nowC=='(') cnt1 ++;
            else cnt2++;
            if(cnt1==cnt2 && maxIdx==0) maxIdx = i;
        }
        Stack<Character> s = new Stack<>();
        for(int i=0; i<=maxIdx;i++){
            if(str.charAt(i)=='(') s.push('(');
            else{
                if(!s.isEmpty()) s.pop();
                else {
                    isRight = false;
                    break;
                }
            }
        }
        if(!s.isEmpty()) isRight = false;
        if(isRight) {
            return (str.substring(0,maxIdx+1) + recursionV(str.substring(maxIdx+1)));
        }
        else {
            String now = "";
            for(int i=1;i<maxIdx;i++){
                if(str.charAt(i)=='(') now += ")";
                else now += "(";
            }
            return ("("+recursionV(str.substring(maxIdx+1))+")" + now);
        }
    }

    public String solution(String p) {
        String answer = "";
        answer += recursionV(p);
        return answer;
    }
}