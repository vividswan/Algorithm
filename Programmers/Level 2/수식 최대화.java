import java.util.ArrayList;

class Solution {
    public static ArrayList<Long> numbers = new ArrayList<>();
    public static ArrayList<Character> opers = new ArrayList<>();
    public static Long getMax(){
        Long maxValue = 0L;
        maxValue = Math.max(maxValue,Math.abs(getValue('+','-','*')));
        maxValue = Math.max(maxValue,Math.abs(getValue('+','*','-')));
        maxValue = Math.max(maxValue,Math.abs(getValue('*','-','+')));
        maxValue = Math.max(maxValue,Math.abs(getValue('*','+','-')));
        maxValue = Math.max(maxValue,Math.abs(getValue('-','+','*')));
        maxValue = Math.max(maxValue,Math.abs(getValue('-','*','+')));
        return maxValue;
    }
    public static Long calc(Long a, Long b, char c){
        if(c=='+') return (a+b);
        if(c=='-') return (a-b);
        else return (a*b);
    }
    public static Long getValue(char a, char b, char c){
        ArrayList<Long> nowNumbers = new ArrayList<>(numbers);
        ArrayList<Character> nowOpers = new ArrayList<>(opers);

        for(int k=0; k<3; k++){
            char now;
            if(k==0)now = a;
            else if(k==1) now = b;
            else now =c;
            for(int i=0;i<nowOpers.size();i++){
                if(nowOpers.get(i) == now){
                    nowOpers.remove(i);
                    nowNumbers.set(i,calc(nowNumbers.get(i), nowNumbers.get(i+1), now));
                    nowNumbers.remove(i+1);
                    i--;
                }
            }
        }
        return nowNumbers.get(0);
    }

    public long solution(String expression) {
        int st = 0;
        for(int i=0; i<expression.length();i++){
            if(expression.charAt(i)=='+' || expression.charAt(i)=='-' ||expression.charAt(i)=='*'){
                Long num = Long.parseLong(expression.substring(st,i));
                st = i+1;
                opers.add(expression.charAt(i));
                numbers.add(num);
            }
            else if(i==expression.length()-1){
                Long num = Long.parseLong(expression.substring(st));
                numbers.add(num);
            }
        }
        return getMax();
    }
}