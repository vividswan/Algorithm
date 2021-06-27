import java.io.*;

public  class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw= new BufferedWriter(new OutputStreamWriter(System.out));

		while (true){
			String str = br.readLine();
			if (str.equals("END")) break;
			String reverse = new StringBuffer(str).reverse().toString();
			bw.write(reverse);
			bw.write("\n");
		}

		bw.flush();
		br.close();
		bw.close();
	}
}