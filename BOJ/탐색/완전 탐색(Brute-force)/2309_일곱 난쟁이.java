import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	public static boolean success;
	public static List<Integer> valueList = new ArrayList<>();
	public static List<Boolean> checkArray = new ArrayList<>();
	public static List<Integer> ansList = new ArrayList<>();
	public static void recursion(int idx, int cnt) {
		if (success) return;
		if (cnt == 7) {
			int tempSum = 0;
			for (int i = 1; i < checkArray.size(); i++) {
				if (checkArray.get(i))
					tempSum += valueList.get(i);
			}
			if (tempSum == 100) {
				for (int i = 1; i < checkArray.size(); i++) {
					if (checkArray.get(i))
						ansList.add(valueList.get(i));
				}
				success = true;
			}
		}
		else {
			for (int i = idx; i <= 9; i++) {
				if (checkArray.get(i)) continue;
				checkArray.set(i, true);
				recursion(idx+1, cnt+1);
				checkArray.set(i, false);
			}
		}
	}

	public static void main(String[] args) throws IOException {
		success = false;
		for (int i = 0; i <= 9; i++) {
			checkArray.add(false);
		}
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		valueList = new ArrayList<>();
		valueList.add(0);
		for (int i = 1; i <= 9; i++) {
			st = new StringTokenizer(br.readLine());
			valueList.add(Integer.parseInt(st.nextToken()));
		}
		recursion(1,0);
		Collections.sort(ansList);
		for (Integer number : ansList) {
			bw.write(number+"\n");
		}
		bw.flush();
		br.close();
		bw.close();
	}
}
