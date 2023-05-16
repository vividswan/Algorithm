import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

class Solution {
	public String[] solution(int[][] line) {
		List<Pair> dotList = getDotList(line);
		Pair maxPair = getMaxPair(dotList);
		Pair minPair = getMinPair(dotList);
		if (!(minPair.getX() == 0 && minPair.getY() == 0)) {
			maxPair.setX(maxPair.getX() - minPair.getX());
			maxPair.setY(maxPair.getY() - minPair.getY());
			dotList = correctValue(dotList, minPair);
		}
		boolean[][] array = makeArray(maxPair, dotList);
		String[] answer = printFunc(array);
		return answer;
	}

	private static String[] printFunc(boolean[][] array) {
		String[] strings = new String[array[0].length];
		for (int i = 0; i < array[0].length; i++) {
			StringBuffer sb = new StringBuffer();
			for (int j =0; j< array.length; j++) {
				if (array[j][i]) {
					sb.append('*');
				} else {
					sb.append('.');
				}
			}
			strings[array[0].length - i - 1] = sb.toString();
		}
		return strings;
	}

	public static boolean[][] makeArray(Pair maxPair, List<Pair> dotList) {
		boolean[][] array = new boolean[(int)maxPair.getX() + 1][(int)maxPair.getY() + 1];
		for (Pair pair : dotList) {
			array[(int)pair.getX()][(int)pair.getY()] = true;
		}
		return array;
	}

	public static Pair getMaxPair(List<Pair> dotList)  {
		double maxX = dotList.get(0).getX();
		double maxY = dotList.get(0).getY();
		for (Pair dot : dotList) {
			maxX = Math.max(maxX, dot.getX());
			maxY = Math.max(maxY, dot.getY());
		}
		return new Pair(maxX, maxY);
	}

	public static Pair getMinPair(List<Pair> dotList)  {
		double minX = dotList.get(0).getX();
		double minY = dotList.get(0).getY();
		for (Pair dot : dotList) {
			minX = Math.min(minX, dot.getX());
			minY = Math.min(minY, dot.getY());
		}
		return new Pair(minX, minY);
	}

	public static List<Pair> correctValue(List<Pair> dotList, Pair minPair) {
		for (Pair dot : dotList) {
			dot.setX(dot.getX() - minPair.getX());
			dot.setY(dot.getY() - minPair.getY());
		}
		return dotList;
	}

	public static List<Pair> getDotList(int[][] line) {
		ArrayList<Pair> pairs = new ArrayList<>();
		for (int i =0; i< line.length; i ++) {
			for (int j = i+1; j < line.length; j++) {
				Optional<Pair> dotByLines = getDotByLines(line[i], line[j]);
				dotByLines.ifPresent(pairs::add);
			}
		}
		return pairs;
	}

	public static Optional<Pair> getDotByLines(int[] firstLine, int[] secondLine) {
		int firstX = firstLine[0];
		int secondX = secondLine[0];
		int firstY = firstLine[1];
		int secondY = secondLine[1];
		int firstZ = firstLine[2];
		int secondZ = secondLine[2];
		double denominatorValue = (double)firstX * secondY - (double)secondX * firstY;
		if (denominatorValue == 0L) {
			return Optional.empty();
		}
		double xNumeratorValue = (double)firstY * secondZ - (double)firstZ * secondY;
		if (xNumeratorValue % denominatorValue != 0L) {
			return Optional.empty();
		}
		double yNumeratorValue = (double)firstZ * secondX - (double)firstX * secondZ;
		if (yNumeratorValue % denominatorValue != 0L) {
			return Optional.empty();
		}
		return Optional.of(new Pair((xNumeratorValue / denominatorValue), (yNumeratorValue / denominatorValue)));
	}
}

class Pair {
	private double x;
	private double y;

	public Pair(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public double getX() {
		return this.x;
	}

	public double getY() {
		return this.y;
	}

	public void setX(double value) {
		this.x = value;
	}

	public void setY(double value) {
		this.y = value;
	}
}
