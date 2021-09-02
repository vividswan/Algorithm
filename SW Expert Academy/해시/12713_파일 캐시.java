import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

class Pair implements Comparable<Pair>{
    int x;
    int y;

    public Pair(int x, int y) {
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        this.x = x;
        this.y = y;
    }

    public int getSpace() {
        return y - x + 1;
    }

    @Override
    public int compareTo(Pair other) {
        return Integer.compare(this.x, other.x);
    }
}

class File {
    int idx;
    Pair space;
    int updatedAt;
    public File(int idx, Pair space, int updatedAt) {
        this.idx = idx;
        this.space = space;
        this.updatedAt = updatedAt;
    }
}

class UserSolution {
    ArrayList<Pair> spaceList;
    Map<Integer, File> m;
    int updateCnt;
    int searchUpdate;
    int[] updateArr;
    int sum;

    public void init(int N) {
        spaceList = new ArrayList<>();
        spaceList.add(new Pair(0, N - 1));
        m = new HashMap<>();
        updateCnt = 0;
        searchUpdate = 1;
        updateArr = new int[20001];
        sum = 0;
        return;
    }

    public int access(int fileId, int fileSize) {
        updateCnt++;
        File file = m.get(fileId);
        if (file != null) {
            file.updatedAt = updateCnt;
            updateArr[updateCnt] = fileId;
            return file.space.x;
        }
        for (int i = 0; i < spaceList.size(); i++) {
            if (spaceList.get(i).getSpace() >= fileSize) {
                File newFile = new File(fileId, new Pair(spaceList.get(i).x, spaceList.get(i).x + fileSize - 1), updateCnt);
                m.put(fileId, newFile);
                sum += newFile.space.getSpace();
                updateArr[updateCnt] = fileId;
                spaceList.get(i).x = spaceList.get(i).x + fileSize;
                if (spaceList.get(i).getSpace() == 0) spaceList.remove(i);
                return newFile.space.x;
            }
        }
        for (; searchUpdate < updateCnt; searchUpdate++) {
            int idx = updateArr[searchUpdate];
            if (!m.containsKey(idx)) continue;
            File nowFile = m.get(idx);
            if (nowFile == null) continue;
            if (nowFile.updatedAt != searchUpdate) continue;
            int left = -1;
            int right = -1;
            for (int i = 0; i < spaceList.size(); i++) {
                if (spaceList.get(i).y+1 == nowFile.space.x) left = i;
                if(spaceList.get(i).x == nowFile.space.y +1) right = i;
            }
            int target = -1;
            if (left != -1 && right != -1) {
                spaceList.get(left).y = spaceList.get(right).y;
                spaceList.remove(right);
                target = left;
            }
            else if (left != -1) {
                spaceList.get(left).y = nowFile.space.y;
                target = left;
            }
            else if (right != -1) {
                spaceList.get(right).x = nowFile.space.x;
                target = right;
            }
            else {
                spaceList.add(new Pair(nowFile.space.x, nowFile.space.y));
                Collections.sort(spaceList);
                for (int i = 0; i < spaceList.size(); i++) {
                    if (spaceList.get(i).x == nowFile.space.x) {
                        target = i;
                        break;
                    }
                }
            }
            sum -= nowFile.space.getSpace();
            m.put(nowFile.idx, null);
            if (spaceList.get(target).getSpace() < fileSize) continue;
            File newFile = new File(fileId, new Pair(spaceList.get(target).x, spaceList.get(target).x + fileSize - 1), updateCnt);
            m.put(fileId, newFile);
            updateArr[updateCnt] = fileId;
            sum += newFile.space.getSpace();
            spaceList.get(target).x += fileSize;
            if (spaceList.get(target).getSpace() == 0) spaceList.remove(target);
            return newFile.space.x;
        }
        return 0;
    }

    public int usage() {
        return sum;
    }
}