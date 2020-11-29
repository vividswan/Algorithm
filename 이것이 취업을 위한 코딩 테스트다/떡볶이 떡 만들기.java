import java.util.Arrays;
import java.util.Scanner;

public class 떡볶이 떡 만들기{
    public static Long binarySearch(Long value){
        Long result = 0L;
        while(minn <= maxx){
            Long mid = (minn+maxx)/2L;
            Long sum = 0L;
            for(int i=0;i<n;i++){
                if(mid>=arr[i])  continue;
                sum += arr[i]-mid;
            }
            if(sum>=value) {
                result = minn;
                minn = mid+1;
            }
            else maxx = mid-1;
        }
        return result;
    }

    public static int n;
    public static Long m, minn, maxx=0L;
    public static Long[] arr;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextLong();
        arr = new Long[n];
        minn = 2000000000L;
        for(int i=0;i<n;i++){
            arr[i]=scanner.nextLong();
            maxx = Math.max(maxx,arr[i]);
            minn = Math.min(minn,arr[i]);
        }
        Arrays.sort(arr);
        System.out.println(binarySearch(m));
    }
}