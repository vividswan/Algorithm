class Solution {
	boolean solution(String s) {
		int pCount = 0;
		int yCount = 0;
		char[] chars = s.toLowerCase().toCharArray();
		for (char target : chars) {
			if (target == 'p') {
				pCount++;
			} else if (target == 'y') {
				yCount++;
			}
		}
		return pCount == yCount;
	}
}
