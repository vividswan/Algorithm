import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static int[] arr = new int[53];
	public static int n;
	public static String ans;
	public static boolean isPossible = true;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++){
			int num = Integer.parseInt(st.nextToken());
			arr[num]++;
		}
		ans = br.readLine();
		for(int i=0; i<ans.length(); i++){
			char c = ans.charAt(i);
			int num;
			if (c==' ') num = 0;
			else if('A' <= c && c <= 'Z') num = c -'A' +1;
			else num = c - 'a' + 27;
			if (arr[num]<1) isPossible = false;
			arr[num]--;
		}
		for(int i=0; i<53; i++){
			if (arr[i]!=0) isPossible = false;
		}
		if (isPossible) bw.write("y\n");
		else bw.write("n\n");
		bw.flush();
		br.close();
		bw.close();
	}
}