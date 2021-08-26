import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Pair {
    int x;
    int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class UserSolution {
    Pair head;
    boolean isConnected;
    Map<Integer, Integer> map;
    ArrayList<Pair> front;
    ArrayList<Pair> back;
    Pair nextFront;
    Pair nextBefore;
    int n;
    int frontDir;
    int backDir;

    void init(int N) {
        n = N;
        head = new Pair(N, N);
        map = new HashMap<>();
        front = new ArrayList<>();
        front.add(new Pair(N, N));
        back = new ArrayList<>();
        back.add(new Pair(N, N));
        isConnected = false;
        nextFront = new Pair(N, N + 1);
        nextBefore = new Pair(N, N - 1);
        frontDir = 1;
        backDir = 3;
    }

    void addRail(int mFront, int mDirection) {
        if (mFront == 0) {
            int x = nextBefore.x;
            int y = nextBefore.y;
            Pair pair = new Pair(x, y);
            back.add(pair);
            map.put(x * 100000 + y, (back.size() - 1) * -1);
            int nextX;
            int nextY;
            if (mDirection == 2) {
                if (backDir == 0) {
                    nextX = x;
                    nextY = y + 1;
                    backDir = 1;
                } else if (backDir == 1) {
                    nextX = x + 1;
                    nextY = y;
                    backDir = 2;
                } else if (backDir == 2) {
                    nextX = x;
                    nextY = y - 1;
                    backDir = 3;
                } else {
                    nextX = x - 1;
                    nextY = y;
                    backDir = 0;
                }
            } else if (mDirection == 1) {
                if (backDir == 0) {
                    nextX = x - 1;
                    nextY = y;
                } else if (backDir == 1) {
                    nextX = x;
                    nextY = y + 1;
                } else if (backDir == 2) {
                    nextX = x + 1;
                    nextY = y;
                } else {
                    nextX = x;
                    nextY = y - 1;
                }
            } else {
                if (backDir == 0) {
                    nextX = x;
                    nextY = y - 1;
                    backDir = 3;
                } else if (backDir == 1) {
                    nextX = x - 1;
                    nextY = y;
                    backDir = 0;
                } else if (backDir == 2) {
                    nextX = x;
                    nextY = y + 1;
                    backDir = 1;
                } else {
                    nextX = x + 1;
                    nextY = y;
                    backDir = 2;
                }
            }
            nextBefore = new Pair(nextX, nextY);
            if (x == nextFront.x && y == nextFront.y) {
                if ((nextBefore.x == front.get(front.size() - 1).x && nextBefore.y == front.get(front.size() - 1).y))
                    isConnected = true;
            }
        } else {
            int x = nextFront.x;
            int y = nextFront.y;
            Pair pair = new Pair(x, y);
            front.add(pair);
            map.put(x * 100000 + y, (front.size() - 1));

            int nextX;
            int nextY;
            if (mDirection == 2) {
                if (frontDir == 0) {
                    nextX = x;
                    nextY = y + 1;
                    frontDir = 1;
                } else if (frontDir == 1) {
                    nextX = x + 1;
                    nextY = y;
                    frontDir = 2;
                } else if (frontDir == 2) {
                    nextX = x;
                    nextY = y - 1;
                    frontDir = 3;
                } else {
                    nextX = x - 1;
                    nextY = y;
                    frontDir = 0;
                }
            } else if (mDirection == 1) {
                if (frontDir == 0) {
                    nextX = x - 1;
                    nextY = y;
                } else if (frontDir == 1) {
                    nextX = x;
                    nextY = y + 1;
                } else if (frontDir == 2) {
                    nextX = x + 1;
                    nextY = y;
                } else {
                    nextX = x;
                    nextY = y - 1;
                }
            } else {
                if (frontDir == 0) {
                    nextX = x;
                    nextY = y - 1;
                    frontDir = 3;
                } else if (frontDir == 1) {
                    nextX = x - 1;
                    nextY = y;
                    frontDir = 0;
                } else if (frontDir == 2) {
                    nextX = x;
                    nextY = y + 1;
                    frontDir = 1;
                } else {
                    nextX = x + 1;
                    nextY = y;
                    frontDir = 2;
                }
            }
            nextFront = new Pair(nextX, nextY);
            if (x == nextBefore.x && y == nextBefore.y) {
                if ((nextFront.x == back.get(back.size() - 1).x) && (nextFront.y == back.get(back.size() - 1).y))
                    isConnected = true;
            }
        }
    }

    int delRail(int mRow, int mCol) {
        Integer num = map.get(mRow * 100000 + mCol);
        if (num == null) return 0;
        if (num > 0) {
            if (isConnected) {
                isConnected = false;
                for (int i = front.size() - 1; i >= num; i--) {
                    if (i == num) {
                        map.put(100000 * front.get(i).x + front.get(i).y, null);
                        nextFront.x = front.get(i).x;
                        nextFront.y = front.get(i).y;
                    } else {
                        back.add(front.get(i));
                        map.put(100000 * front.get(i).x + front.get(i).y, (back.size() - 1) * -1);
                    }
                    front.remove(i);
                }
                int x = nextFront.x - front.get(front.size() - 1).x;
                int y = nextFront.y - front.get(front.size() - 1).y;
                if (x == 1) frontDir = 2;
                if (x == -1) frontDir = 0;
                if (y == 1) frontDir = 1;
                if (y == -1) frontDir = 3;
                nextBefore = new Pair(nextFront.x, nextFront.y);
                x = nextBefore.x - back.get(back.size() - 1).x;
                y = nextBefore.y - back.get(back.size() - 1).y;
                if (x == 1) backDir = 2;
                if (x == -1) backDir = 0;
                if (y == 1) backDir = 1;
                if (y == -1) backDir = 3;

                return 1;
            } else {
                int cnt = 0;
                for (int i = front.size() - 1; i >= num; i--) {
                    cnt++;
                    map.put(100000 * front.get(i).x + front.get(i).y, null);
                    nextFront.x = front.get(i).x;
                    nextFront.y = front.get(i).y;

                    front.remove(i);

                }
                int x = nextFront.x - front.get(front.size() - 1).x;
                int y = nextFront.y - front.get(front.size() - 1).y;
                if (x == 1) frontDir = 2;
                if (x == -1) frontDir = 0;
                if (y == 1) frontDir = 1;
                if (y == -1) frontDir = 3;
                return cnt;
            }
        } else {
            num *= -1;
            if (isConnected) {
                isConnected = false;
                for (int i = back.size() - 1; i >= num; i--) {
                    if (i == num) {
                        map.put(100000 * back.get(i).x + back.get(i).y, null);
                        nextBefore.x = back.get(i).x;
                        nextBefore.y = back.get(i).y;
                    } else {
                        front.add(back.get(i));
                        map.put(100000 * back.get(i).x + back.get(i).y, front.size() - 1);
                    }
                    back.remove(back.size() - 1);
                }
                if (back.size() == 0) {
                    backDir = -1;
                } else {
                    int x = nextBefore.x - back.get(back.size() - 1).x;
                    int y = nextBefore.y - back.get(back.size() - 1).y;
                    if (x == 1) backDir = 2;
                    if (x == -1) backDir = 0;
                    if (y == 1) backDir = 1;
                    if (y == -1) backDir = 3;
                    nextFront = new Pair(nextBefore.x, nextBefore.y);
                    x = nextFront.x - front.get(front.size() - 1).x;
                    y = nextFront.y - front.get(front.size() - 1).y;
                    if (x == 1) frontDir = 2;
                    if (x == -1) frontDir = 0;
                    if (y == 1) frontDir = 1;
                    if (y == -1) frontDir = 3;
                }
                return 1;
            } else {
                int cnt = 0;
                for (int i = back.size() - 1; i >= num; i--) {
                    cnt++;
                    map.put(100000 * back.get(i).x + back.get(i).y, null);
                    nextBefore.x = back.get(i).x;
                    nextBefore.y = back.get(i).y;
                    back.remove(i);
                }
                int x = nextBefore.x - back.get(back.size() - 1).x;
                int y = nextBefore.y - back.get(back.size() - 1).y;
                if (x == 1) backDir = 2;
                if (x == -1) backDir = 0;
                if (y == 1) backDir = 1;
                if (y == -1) backDir = 3;

                return cnt;
            }
        }
    }
}