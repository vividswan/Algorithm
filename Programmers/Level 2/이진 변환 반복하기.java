class Solution {
	public int[] solution(String s) {
		int deletedZeroCount = 0;
		int operateCount = 0;
		while (!s.equals("1")) {
			operateCount++;
			char[] chars = s.toCharArray();
			int oneCount = 0;
			for (char target : chars) {
				if (target == '0') {
					deletedZeroCount++;
				} else {
					oneCount++;
				}
			}
			s = Integer.toString(oneCount, 2);
		}
		int[] answer = {operateCount, deletedZeroCount};
		return answer;
	}
}
