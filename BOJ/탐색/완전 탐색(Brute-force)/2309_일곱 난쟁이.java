import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static final int STATIC_TOTAL_INT = 9;
	static final int STATIC_SELECTED_INT = 7;
	static boolean recurEnd = false;
	static ArrayList<Integer> intArr = new ArrayList<>();
	static boolean[] checkArr = new boolean[STATIC_TOTAL_INT];
	static void recurFunc(int idx, int cnt, int sum) throws IOException {
		if (recurEnd) {
			return;
		}
		if (cnt == STATIC_SELECTED_INT && sum == 100) {
			recurEnd = true;
			for (int i =0; i < STATIC_TOTAL_INT; i++){
				if (checkArr[i]) {
					bw.write(intArr.get(i)+"\n");
				}
			}
			bw.flush();
			bw.close();
			br.close();
			return;
		}
		for (int i =idx; i < STATIC_TOTAL_INT; i++){
			if (!checkArr[i]) {
				checkArr[i] = true;
				recurFunc(i, cnt+1, sum + intArr.get(i));
				checkArr[i] = false;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		for (int i = 0; i < STATIC_TOTAL_INT; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			intArr.add(Integer.parseInt(st.nextToken()));
		}
		Collections.sort(intArr);
		recurFunc(0, 0, 0);
	}
}
