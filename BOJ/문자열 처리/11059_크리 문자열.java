import java.io.*;

public class Main {
	public static String str;
	public static int cnt;
	public static boolean isValid(String now){
		int bef = 0;
		int aft = 0;
		for(int i=0; i<now.length()/2; i++){
			bef += now.charAt(i) - '0';
		}
		for(int i=now.length()/2; i<now.length(); i++){
			aft += now.charAt(i) - '0';
		}
		if (bef == aft) return true;
		else return false;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		str = br.readLine();
		for(int i=0; i<str.length();i++){
			for(int j=i+1; j<str.length();j++){
				if((j-i+1)%2==1) continue;
				if (isValid(str.substring(i,j+1))){
					cnt = Math.max(cnt, j-i+1);
				}
			}
		}
		bw.write(String.valueOf(cnt)+"\n");
		bw.flush();
		br.close();
		bw.close();
	}
}