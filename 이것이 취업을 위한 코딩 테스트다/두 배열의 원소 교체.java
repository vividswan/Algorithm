import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class MyInt implements Comparable<com.company.MyInt>{

    private int num;

    MyInt(int num){
        this.num = num;
    }

    public int getNum() { return  num; }

    @Override
    public int compareTo(com.company.MyInt other) {
        if(this.num < other.num) return 1;
        return -1;
    }
}

public class 두 배열의 원소 교체{
    public static void main(String[] args) {
        int n, k;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();;
        k = scanner.nextInt();
        List<com.company.MyInt> list1 = new ArrayList<>();
        List<com.company.MyInt> list2 = new ArrayList<>();
        for(int i=0;i<n;i++){
            int num;
            num = scanner.nextInt();
            list1.add(new com.company.MyInt(num));
        }
        for(int i=0;i<n;i++){
            int num;
            num = scanner.nextInt();
            list2.add(new com.company.MyInt(num));
        }
        Collections.sort(list2);
        int result = 0;
        for(int i=0;i<k;i++) list1.add(new com.company.MyInt(list2.get(i).getNum()));
        Collections.sort(list1);
        for(int i=0;i<n;i++) result += list1.get(i).getNum();
        System.out.println(result);
    }
}