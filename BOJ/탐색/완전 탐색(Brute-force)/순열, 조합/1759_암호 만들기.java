import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

class Combination{
    private int n;
    private int m;
    private int[] arr;
    private ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();

    public Combination(int n, int m){
        this.n = n;
        this.m = m;
        this.arr = new int[n];
    }

    public void goComb(int index, int target){
        if(index == m){
            ArrayList<Integer> temp = new ArrayList<>();
            for(int i=0;i<m;i++){
                temp.add(arr[i]);
            }
            result.add(temp);
            return;
        }
        if(target == n) return;
        arr[index] = target;
        goComb(index+1, target+1);
        goComb(index, target+1);
    }

    public ArrayList<ArrayList<Integer>> getResult(){
        return result;
    }

}

public class 1759_암호 만들기 {

    public static int l;
    public static int c;
    public static char[] charList;
    public static boolean isAns(String str){
        int vowel = 0;
        for(int i=0; i<str.length();i++){
            char ch = str.charAt(i);
            if(ch=='a' || ch=='e' || ch== 'i' || ch == 'o' || ch=='u') vowel++;
        }
        if(vowel>=1 && l-vowel >= 2) return true;
        else return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        l = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        charList = new char[c];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<c;i++) charList[i] = st.nextToken().charAt(0);
        Arrays.sort(charList);

        Combination combination = new Combination(c,l);
        combination.goComb(0,0);
        ArrayList<ArrayList<Integer>> combiList = combination.getResult();
        for(int i=0; i<combiList.size();i++){
            ArrayList<Integer> list = combiList.get(i);
            String str = "";
            for(int num:list){
                str+=charList[num];
            }
            if(isAns(str)) bw.write(str+"\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}