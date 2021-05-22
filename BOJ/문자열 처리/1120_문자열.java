import java.io.*;
import java.util.StringTokenizer;

public class Main {

	public static int res = (int)1e9;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		String str1 = st.nextToken();
		String str2 = st.nextToken();

		for(int i=0; i<=str2.length()-str1.length(); i++){
			int cnt = 0;
			for(int j=0; j<str1.length();j++){
				if (str1.charAt(j) != str2.charAt(i+j)) cnt++;
			}
			res = Math.min(res,cnt);
		}
		bw.write(String.valueOf(res)+"\n");
		bw.flush();
		br.close();
		bw.close();

	}

}