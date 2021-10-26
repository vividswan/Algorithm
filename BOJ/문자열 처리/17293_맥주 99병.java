import java.io.*;

public class Main {
	public static int n;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		n = Integer.parseInt(br.readLine());
		for(int i=n; i>=0; i--){
			if (i==1){
				bw.write(i+ " bottle of beer on the wall, "+i +" bottle of beer.\n");
				bw.write("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
			}
			else if (i==2){
				bw.write(i+ " bottles of beer on the wall, "+i +" bottles of beer.\n");
				bw.write("Take one down and pass it around, "+(i-1)+" bottle of beer on the wall.\n\n");
			}
			else if(i==0){
				if (n==1){
					bw.write("No more bottles of beer on the wall, no more bottles of beer.\n");
					bw.write("Go to the store and buy some more, "+ n +" bottle of beer on the wall.");
				}
				else {
					bw.write("No more bottles of beer on the wall, no more bottles of beer.\n");
					bw.write("Go to the store and buy some more, "+ n +" bottles of beer on the wall.");
				}
			}
			else {
				bw.write(i+ " bottles of beer on the wall, "+i +" bottles of beer.\n");
				bw.write("Take one down and pass it around, "+(i-1)+" bottles of beer on the wall.\n\n");
			}
		}
		bw.flush();
		br.close();
		bw.close();
	}
}