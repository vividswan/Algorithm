import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class 부품 찾기{
    public static void main(String[] args) {
        int n,m;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        List<Integer> value = new ArrayList<>();
        for(int i=0;i<n;i++){
            Integer now = scanner.nextInt();
            value.add(now);
        }
        Collections.sort(value);
        m = scanner.nextInt();
        for(int i=0;i<m;i++){
            Integer now = scanner.nextInt();
            int le = 0, ri =n-1;
            String ans = "no ";
            while(le <= ri){
                int mid = (le+ri)/2;
                if(value.get(mid) == now){
                    ans="yes ";
                    break;
                }
                else if(value.get(mid)>now){
                    ri = mid-1;
                    continue;
                }
                else {
                    le = mid+1;
                }
            }
            System.out.print(ans);
        }
        System.out.println();
    }
}