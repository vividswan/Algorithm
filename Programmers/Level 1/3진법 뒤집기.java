class Solution {
	public int solution(int n) {
		String stringByThreeOption = Integer.toString(n, 3);
		StringBuilder stringBuilder = new StringBuilder(stringByThreeOption);
		String reverseStringByThreeOption = stringBuilder.reverse().toString();
		return  Integer.parseInt(reverseStringByThreeOption, 3);
	}
}
