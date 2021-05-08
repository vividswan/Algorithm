class Solution {

    public static final int MAX_NUM = 45;

    public int[] solution(int[] lottos, int[] win_nums) {
        int zeroCnt = 0;
        int sameCnt = 0;
        boolean[] vis = new boolean[MAX_NUM+1];
        for(int i=0; i<lottos.length; i++){
            int now = lottos[i];
            if(now==0){
                zeroCnt++;
                continue;
            }
            vis[now] = true;
        }
        for(int i=0; i<win_nums.length; i++){
            int now = win_nums[i];
            if (vis[now]) sameCnt++;
        }
        int maxValue = sameCnt+zeroCnt;
        int minValue = sameCnt;

        int[] answer = new int[2];
        int minRes = 7 - minValue;
        if (minRes > 6) minRes = 6;
        if (minRes < 1) minRes = 1;
        int maxRes = 7 - maxValue;
        if(maxRes<1) maxRes = 1;
        if(maxRes>6) maxRes = 6;
        answer[0] = maxRes;
        answer[1] = minRes;
        return answer;
    }
}