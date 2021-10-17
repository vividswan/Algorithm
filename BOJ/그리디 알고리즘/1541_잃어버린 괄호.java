import java.io.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        ArrayList<Character> characters = new ArrayList<>();
        ArrayList<Integer> arrayList = new ArrayList<>();
        String str = br.readLine();
        int idx = 0;
        int result = 0;
        while (true) {
            if (idx == str.length() || str.charAt(idx) == '+' || str.charAt(idx) == '-') break;
            idx++;
        }
        result += Integer.parseInt(str.substring(0, idx));
        if (idx != str.length()){
            characters.add(str.charAt(idx));
            idx++;
            int beforeIdx = idx;
            while (true) {
                if (idx == str.length()) {
                    arrayList.add(Integer.parseInt(str.substring(beforeIdx, idx)));
                    break;
                }
                if (str.charAt(idx) == '+' || str.charAt(idx) == '-') {
                    characters.add(str.charAt(idx));
                    arrayList.add(Integer.parseInt(str.substring(beforeIdx, idx)));
                    beforeIdx = idx+1;
                }
                idx++;
            }
            idx = -1;
            while (true) {
                idx++;
                if (idx == characters.size()) break;
                if (characters.get(idx) == '-') break;
                else result += arrayList.get(idx);
            }
            int sum =0;
            idx--;
            while (true) {
                idx++;
                if (idx == arrayList.size()) {
                    result -= sum;
                    break;
                } else if (characters.get(idx) == '-') {
                    result -= sum;
                    sum = arrayList.get(idx);
                } else sum += arrayList.get(idx);
            }
        }
        bw.write(String.valueOf(result) + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}