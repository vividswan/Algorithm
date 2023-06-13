import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {

	public static List<Node> getPlaceNodeList(String[] place) {
		ArrayList<Node> nodes = new ArrayList<>();
		for (int i = 0; i < place.length; i++) {
			for (int j = 0; j < place[0].length(); j++) {
				if (place[i].charAt(j) == 'P') {
					Node node = new Node(i, j);
					nodes.add(node);
				}
			}
		}
		return nodes;
	}

	public static boolean isProperManhattanDistance(Node firstNode, Node secondNode) {
		int xDistance = Math.abs(firstNode.getX() - secondNode.getX());
		int yDistance = Math.abs(firstNode.getY() - secondNode.getY());
		int totalDistance = xDistance + yDistance;
		return 2 < totalDistance;
	}

	public static int[] dx = {0, 0, 1, -1};
	public static int[] dy = {1, -1, 0, 0};

	public static boolean canNotMeetInTwoManhattanDistance(String[] place, Node firstNode, Node secondNode) {
		int x = firstNode.getX();
		int y = firstNode.getY();
		int[][] visit = new int[5][5];
		visit[x][y] = 0;
		Queue<Node> nodes = new LinkedList<>();
		nodes.add(new Node(x, y));
		while (!nodes.isEmpty()) {
			Node nowNode = nodes.poll();
			int nowX = nowNode.getX();
			int nowY = nowNode.getY();
			for (int i = 0; i < 4; i++) {
				int nx = nowX + dx[i];
				int ny = nowY + dy[i];
				if (nx < 0 || nx > 4 || ny < 0 || ny > 4 || (nx == firstNode.getX() && ny == firstNode.getY())) {
					continue;
				}
				if (place[nx].charAt(ny) == 'X' || visit[nx][ny] > 0) {
					continue;
				}
				if (nx == secondNode.getX() && ny == secondNode.getY()) {
					return false;
				}
				visit[nx][ny] = visit[nowX][nowY] + 1;
				if (visit[nx][ny] < 3) {
					nodes.add(new Node(nx, ny));
				}
			}
		}
		return true;
	}

	public static boolean isValidRelation(String[] place, Node firstNode, Node secondNode) {
		if (isProperManhattanDistance(firstNode, secondNode)) {
			return true;
		}
		return canNotMeetInTwoManhattanDistance(place, firstNode, secondNode);
	}

	public static boolean isValidatePlace(String[] place, List<Node> placeNodeList) {
		for (int i = 0; i < placeNodeList.size() - 1; i++) {
			for (int j = i + 1; j < placeNodeList.size(); j++) {
				if (!isValidRelation(place, placeNodeList.get(i), placeNodeList.get(j))) {
					return false;
				}
			}
		}
		return true;
	}

	public int[] solution(String[][] places) {
		ArrayList<Integer> integerList = new ArrayList<>();
		for (int i = 0; i < places.length; i++) {
			String[] place = places[i];
			List<Node> placeNodeList = getPlaceNodeList(place);
			if (isValidatePlace(place, placeNodeList)) {
				integerList.add(1);
			} else {
				integerList.add(0);
			}
		}
		int[] answer = new int[integerList.size()];
		for (int i = 0; i < answer.length; i++) {
			answer[i] = integerList.get(i);
		}
		return answer;
	}

}

class Node {
	private int x;
	private int y;

	public Node(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}
}
