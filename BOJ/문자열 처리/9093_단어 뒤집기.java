import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static int n;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		n = Integer.parseInt(br.readLine());
		for(int i=0;i<n; i++){
			String str = br.readLine();
			String[] strArr = str.split(" ");
			String ans = "";
			for(int j=0; j<strArr.length; j++){
				StringBuffer sb = new StringBuffer(strArr[j]);
				ans += sb.reverse().toString();
				if (j!=strArr.length-1) ans+=" ";
			}
			bw.write(ans+"\n");
		}
		bw.flush();
		br.close();
		bw.close();
	}
}