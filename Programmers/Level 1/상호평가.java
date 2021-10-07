import java.util.*;

class Solution {
    public static String getGrade(double grade){
        if(grade >= 90) return "A";
        else if(grade >= 80) return "B";
        else if(grade >= 70) return "C";
        else if(grade >= 50) return "D";
        else return "F";
    }
    public String solution(int[][] scores) {
        StringBuilder sb = new StringBuilder();
        for(int j=0; j<scores[0].length; j++){
            int minCnt = 1;
            int maxCnt = 1;
            int minn = 101;
            int maxx = -1;
            int targetValue = -1;
            for(int i=0; i<scores.length; i++){
                int now = scores[i][j];
                if(i==j) targetValue = now;
                if(minn > now){
                    minn = now;
                    minCnt = 1;
                }
                else if(minn == now) minCnt++;

                if(maxx < now){
                    maxx = now;
                    maxCnt = 1;
                }
                else if(maxx == now) maxCnt++;
            }
            if(minn == targetValue && minCnt == 1){
                scores[j][j] = -1;
            }
            else if(maxx == targetValue && maxCnt == 1){
                scores[j][j] = -1;
            }
        }
        for(int j=0; j<scores[0].length; j++){
            int size = 0;
            int tot = 0;
            for(int i=0; i<scores.length; i++){
                if(scores[i][j] == -1) continue;
                size++;
                tot += scores[i][j];
            }
            sb.append(getGrade((double)tot/(double)size));
        }
        return sb.toString();
    }
}