class Solution {
	public int solution(String string) {
		int answer = string.length();
		for (int i = 1; i < string.length(); i++) {
			int count = 0;
			String nowString = "";
			int nowValue = 1;
			StringBuilder sb = new StringBuilder();
			while (true) {
				String targetString = string.substring(i * count, Math.min(i * (count + 1), string.length()));
				if (targetString.equals(nowString)) {
					nowValue++;
				} else {
					if (nowValue != 1) {
						sb.append(nowValue);
					}
					sb.append(nowString);
					nowString = targetString;
					nowValue = 1;
				}
				count++;
				if (i * count > string.length()) {
					if (nowValue != 1) {
						sb.append(nowValue);
					}
					sb.append(nowString);
					break;
				}
			}
			answer = Math.min(sb.length(), answer);
		}
		return answer;
	}
}
