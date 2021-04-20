import java.util.Stack;

class Solution {
    public static boolean isRightStr(String str){
        Stack<Character> s = new Stack<>();
        for(int i=0; i< str.length() ;i++){
            char now = str.charAt(i);
            if(now=='(') s.push(now);
            else {
                if(s.isEmpty()) return false;
                else s.pop();
            }
        }
        if(s.isEmpty()) return true;
        else return false;
    }
    public String recursion(String str){
        if(isRightStr(str)) return str;
        String temp = "";
        String u = "";
        String v = "";
        int left = 0;
        int right = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(') left++;
            else right++;
            if (left == right) {
                u = str.substring(0, i + 1);
                v = str.substring(i + 1);
                break;
            }
        }
        if(isRightStr(u)){
            temp += u;
            if(!v.isEmpty()) {
                temp += recursion(v);
            }
            return temp;
        }
        temp += "(";
        temp += recursion(v);
        temp += ")";
        String lastTemp = "";
        for(int i=1; i<u.length()-1 ; i++){
            if(u.charAt(i)=='(') lastTemp += ')';
            else lastTemp += '(';
        }
        temp += lastTemp;
        return temp;
    }
    public String solution(String p) {
        String answer = "";
        answer += recursion(p);
        return answer;
    }
}