class Solution {
	public String solution(String s, int n) {
		char[] charArray = s.toCharArray();
		char[] result = new char[charArray.length];
		int index = 0;
		for (char c : charArray) {
			if ('a' <= c && c <= 'z') {
				c += n;
				if (c > 'z') {
					c -= 26;
				}
			} else if ('A' <= c && c <= 'Z') {
				c += n;
				if (c > 'Z') {
					c -= 26;
				}
			}
			result[index++] = c;
		}
		StringBuffer sb = new StringBuffer();
		for (char c : result) {
			sb.append(c);
		}
		return sb.toString();
	}
}
