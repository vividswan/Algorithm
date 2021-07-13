import java.io.*;

public class Main {
	public static int[] getPi(String pattern) {
		int m = pattern.length();
		int[] pi = new int[m];

		int j = 0;
		for (int i = 1; i < m; i++) {
			while (j > 0 && pattern.charAt(i) != pattern.charAt(j))
				j = pi[j - 1];

			if (pattern.charAt(i) == pattern.charAt(j))
				pi[i] = ++j;
		}

		return pi;
	}
	public static int kmpIndexOf(String parent, String pattern) {
		int[] pi = getPi(pattern);

		int n = parent.length(), m = pattern.length();

		int j = 0;
		for (int i = 0; i < n; i++) {
			while (j > 0 && parent.charAt(i) != pattern.charAt(j))
				j = pi[j - 1];

			if (parent.charAt(i) == pattern.charAt(j)) {
				if (j == m - 1) {

					return (i - m + 1);

				} else j++;
			}
		}

		return -1;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String str1 = br.readLine();
		String str2 = br.readLine();
		if (kmpIndexOf(str1, str2)==-1) bw.write(0+"\n");
		else bw.write(1+"\n");
		bw.flush();
		br.close();
		bw.close();
	}
}