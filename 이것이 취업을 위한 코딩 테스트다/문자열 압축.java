import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public static int cntFunc(int val){
        int res = 0;
        while(true){
            if(val>=Math.pow(10,res)){
                res++;
            }
            else break;
        }
        return res;
    }

    public static int func(String s, int len){
        int res = 0;
        int isNotOne = 1;
        Queue<String> q = new LinkedList<>();
        int idx = 0;
        while(true){
            if(idx>s.length()) break;
            if(idx+len>s.length()) {
                q.offer(s.substring(idx,s.length()));
                break;
            }
            q.offer(s.substring(idx,idx+len));
            idx+=len;
        }
        String now = "";
        if(!q.isEmpty()) now = q.poll();
        while(!q.isEmpty()){
            String qString = q.poll();
            if(now.equals(qString)){
                isNotOne++;
                continue;
            }
            else{
                if(isNotOne>1) res+=(cntFunc(isNotOne)+len);
                else res+=len;
                now = qString;
                isNotOne = 1;
            }
        }
        if(isNotOne>1) res+=(cntFunc(isNotOne)+now.length());
        else res += now.length();
        return res;
    }

    public int solution(String s) {

        int len = s.length();
        int res = len;

        for(int i=1; i<= len/2; i++){
            res = Math.min(res,func(s,i));
        }

        return res;
    }
}
