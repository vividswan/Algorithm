import java.util.ArrayList;

class Permutation{
    private int n;
    private int m;
    private int[] now;
    private ArrayList<ArrayList<Integer>> result;

    public Permutation(int n, int m){
        this.n = n;
        this.m = m;
        this.now = new int[m];
        this.result = new ArrayList<ArrayList<Integer>>();
    }

    public ArrayList<ArrayList<Integer>> getResult(){
        return result;
    }

    public void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public void getPermutation(int[] arr,int depth){
        if(depth==m){
            ArrayList<Integer> temp = new ArrayList<>();
            for(int i=0;i<now.length;i++){
                temp.add(now[i]);
            }
            result.add(temp);
            return;
        }
        else {
            for(int i=depth;i<n;i++){
                swap(arr,depth,i);
                now[depth] = arr[depth];
                getPermutation(arr,depth+1);
                swap(arr,depth,i);
            }
        }
    }

}

class Solution {
    public int solution(int n, int[] weak, int[] dist) {
        ArrayList<Integer> circleList = new ArrayList<>();
        for(int i=0;i<weak.length;i++){
            circleList.add(weak[i]);
        }
        for(int i=0;i<weak.length;i++){
            circleList.add(weak[i]+n);
        }
        int ans = dist.length+1;
        Permutation permutation = new Permutation(dist.length, dist.length);
        permutation.getPermutation(dist ,0);
        ArrayList<ArrayList<Integer>> perList = permutation.getResult();

        for(int i=0;i<weak.length;i++){
            for(int j=0;j<perList.size();j++){
                int cnt = 0;
                int position = circleList.get(i) + perList.get(j).get(cnt);
                for(int k=i;k<i+weak.length;k++){
                    if(position < circleList.get(k)){
                        cnt+=1;
                        if(cnt >= dist.length) break;
                        position = circleList.get(k) + perList.get(j).get(cnt);
                    }
                }
                ans = Math.min(ans,cnt+1);
            }
        }
        if(ans>dist.length) ans = -1;
        return  ans;
    }
}