import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String str = br.readLine();
		String resStr = br.readLine();

		boolean isPossible = false;
		while (true){
			if (resStr.charAt(resStr.length()-1)=='A'){
				resStr = resStr.substring(0,resStr.length()-1);
			}
			else{
				resStr = resStr.substring(0,resStr.length()-1);
				StringBuffer sb = new StringBuffer(resStr);
				resStr = sb.reverse().toString();
			}
			if (resStr.equals(str)) isPossible = true;
			if (resStr.equals("")) break;
		}
		if (isPossible) bw.write("1\n");
		if (!isPossible) bw.write("0\n");
		bw.flush();
		bw.close();
	}
}

