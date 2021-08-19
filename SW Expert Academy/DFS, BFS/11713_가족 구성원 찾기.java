class UserSolution {

    public static final int MAX = 200;
    public static int sum;
    public static char[][] idx;
    public static int[][] child;
    public static int[][] parent;
    public static int[] spouse;
    public static int[] childCnt;
    public static int[] parentCnt;
    public static boolean[] hasSpouse;
    public static int[] gender;

    public static int getIdx(char[] target) {
        int res = 0;
        for (int i = 1; i <=200 ; i++) {
            if (mstrcmp(target,idx[i])==0) res = i;
        }
        return res;
    }


    public static int mstrcmp(char[] a, char[] b) {
        int i;
        for (i = 0; a[i] != '\0'; i++) {
            if (a[i] != b[i])
                return a[i] - b[i];
        }
        return a[i] - b[i];
    }

    public static int mstrlen(char[] a) {
        int len = 0;

        while (a[len] != '\0')
            len++;

        return len;
    }

    public static void mstrcpy(char[] dest, char[] src) {
        int i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = src[i];
    }


    void init(char initialMemberName[], int initialMemberSex) {
        idx = new char[MAX + 1][21];
        child = new int[MAX + 1][MAX + 1];
        parent = new int[MAX + 1][3];
        spouse = new int[MAX + 1];
        childCnt = new int[MAX + 1];
        parentCnt = new int[MAX + 1];
        hasSpouse = new boolean[MAX + 1];
        gender = new int[MAX + 1];
        sum = 1;
        idx[sum] = initialMemberName;
        gender[sum] = initialMemberSex;
    }

    boolean addMember(char newMemberName[], int newMemberSex, int relationship, char existingMemberName[]) {
        int nowIdx = getIdx(existingMemberName);
        if (relationship ==0) {
            if (hasSpouse[nowIdx]) return false;
            if (gender[nowIdx] == newMemberSex) return false;
            sum++;
            idx[sum] = newMemberName;
            gender[sum] = newMemberSex;
            hasSpouse[sum] = true;
            hasSpouse[nowIdx] = true;
            spouse[sum] = nowIdx;
            spouse[nowIdx] = sum;
            childCnt[sum] = childCnt[nowIdx];
            for (int i = 1; i <= childCnt[nowIdx] ; i++) {
                child[sum][i] = child[nowIdx][i];
                int childIdx = child[sum][i];
                parent[childIdx][1] = nowIdx;
                parent[childIdx][2] = sum;
                parentCnt[childIdx] = 2;
            }
        }
        else if (relationship == 1) {
            if (parentCnt[nowIdx]==2) return false;
            for (int i = 1; i <= parentCnt[nowIdx] ; i++) {
                if (gender[parent[nowIdx][i]]== newMemberSex) return false;
            }
            sum++;
            idx[sum] = newMemberName;
            gender[sum] = newMemberSex;
            parentCnt[nowIdx]++;

            parent[nowIdx][parentCnt[nowIdx]] = sum;
            if (parentCnt[nowIdx] == 2) {
                int befParent = parent[nowIdx][1];
                hasSpouse[befParent] = true;
                hasSpouse[sum] = true;
                spouse[sum] = befParent;
                spouse[befParent] = sum;
                childCnt[sum] = childCnt[befParent];
                for (int i = 1; i <= childCnt[befParent] ; i++) {
                    child[sum][i] = child[befParent][i];
                    child[sum][i] = child[befParent][i];
                    int childIdx = child[sum][i];
                    if (childIdx == nowIdx) continue;
                    parentCnt[childIdx] = parentCnt[nowIdx];
                    parent[childIdx][0] = parent[nowIdx][0];
                    parent[childIdx][1] = parent[nowIdx][1];
                }
            }else{
                child[sum][1] = nowIdx;
                childCnt[sum] = 1;
            }
        }
        else {
            sum++;
            idx[sum] = newMemberName;
            gender[sum] = newMemberSex;
            childCnt[nowIdx]++;
            child[nowIdx][childCnt[nowIdx]] = sum;
            if (childCnt[nowIdx] >= 2) {
                parent[sum][1] = parent[child[nowIdx][1]][1];
                parent[sum][2] = parent[child[nowIdx][1]][2];
                parentCnt[sum] = parentCnt[child[nowIdx][1]];
            }
            else{
                parent[sum][1] = nowIdx;
                parentCnt[sum] = 1;
                if (hasSpouse[nowIdx]) {
                    parentCnt[sum] = 2;
                    parent[sum][2] = spouse[nowIdx];
                }
            }
            if (hasSpouse[nowIdx]) {
                childCnt[spouse[nowIdx]]++;
                child[spouse[nowIdx]][childCnt[spouse[nowIdx]]] = sum;
            }
        }
        return true;
    }

    int getDistance(char nameA[], char nameB[]) {
        int nowIdx = getIdx(nameA);
        int target = getIdx(nameB);
        int[] vis = new int[201];
        for (int i = 1; i <= 200; i++) {
            vis[i] = -1;
        }
        int[] arr = new int[201];
        arr[1] = nowIdx;
        int cnt = 1;
        vis[nowIdx] = 0;
        for (int i = 1; i <=200 ; i++) {
            int now = arr[i];
            if (now == target) break;
            if (hasSpouse[now] && vis[spouse[now]] == -1) {
                vis[spouse[now]] = vis[now];
                cnt++;
                arr[cnt] = spouse[now];
            }
            for (int j = 1; j <= parentCnt[now]; j++) {
                int next = parent[now][j];
                if (vis[next] != -1) continue;
                vis[next] = vis[now] + 1;
                cnt++;
                arr[cnt] = next;
            }
            for (int j = 1; j <= childCnt[now]; j++) {
                int next = child[now][j];
                if (vis[next] != -1) continue;
                vis[next] = vis[now] + 1;
                cnt++;
                arr[cnt] = next;
            }

        }
        return vis[target];
    }

    int countMember(char name[], int dist) {
        int nowIdx = getIdx(name);
        int[] vis = new int[201];
        for (int i = 1; i <= 200; i++) {
            vis[i] = -1;
        }
        int[] arr = new int[201];
        arr[1] = nowIdx;
        int cnt = 1;
        vis[nowIdx] = 0;
        for (int i = 1; i <=200 ; i++) {
            int now = arr[i];
            if (hasSpouse[now] && vis[spouse[now]] == -1) {
                vis[spouse[now]] = vis[now];
                cnt++;
                arr[cnt] = spouse[now];
            }
            for (int j = 1; j <= parentCnt[now]; j++) {
                int next = parent[now][j];
                if (vis[next] != -1) continue;
                vis[next] = vis[now] + 1;
                cnt++;
                arr[cnt] = next;
            }
            for (int j = 1; j <= childCnt[now]; j++) {
                int next = child[now][j];
                if (vis[next] != -1) continue;
                vis[next] = vis[now] + 1;
                cnt++;
                arr[cnt] = next;
            }

        }
        int res = 0;
        for (int i = 1; i <= 200 ; i++) {
            if (i==nowIdx) continue;
            if (dist == vis[i]) res++;
        }
        return res;
    }
}
