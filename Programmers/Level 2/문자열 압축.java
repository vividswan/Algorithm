class Solution {
    public int solution(String s) {
        int answer = s.length();
        for(int i=1;i<s.length()/2+1;i++){
            int step = i;
            String prev = s.substring(0,step);
            String resultString = "";
            int cnt = 1;
            for(int j=i;j<s.length();j+=step){
                String nowPrev = "";
                for(int k=j;k<j+step;k++){
                    if(k<s.length())nowPrev += s.charAt(k);
                }
                if(prev.equals(nowPrev)) cnt++;
                else {
                    if(cnt>1) resultString += cnt+prev;
                    else resultString += prev;
                    cnt = 1;
                    prev=nowPrev;
                }
            }
            if(cnt>1) resultString += cnt+prev;
            else resultString += prev;
            answer= Math.min(answer,resultString.length());
        }

        return answer;
    }
}