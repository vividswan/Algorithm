class Solution {
	public String solution(String s) {
		char[] chars = s.toCharArray();
		StringBuilder stringBuilder = new StringBuilder();
		boolean toggle = true;
		for (char c : chars) {
			if (c == ' ') {
				toggle = true;
				stringBuilder.append(c);
			} else {
				if (toggle) {
					stringBuilder.append(Character.toUpperCase(c));
				} else {
					stringBuilder.append(Character.toLowerCase(c));
				}
				toggle = !toggle;
			}
		}
		return stringBuilder.toString();
	}
}
