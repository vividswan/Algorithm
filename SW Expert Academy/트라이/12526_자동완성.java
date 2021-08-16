class Node{
    int count;
    int updatedAt;
    boolean isBan;
    Node[] child;
    char[] str;
    int maxCount;
    int maxUpdatedAt;
    char[] maxStr;

    public Node() {
        this.count = 0;
        this.updatedAt = 0;
        this.child = new Node[26];
        this.maxCount = 0;
        this.maxUpdatedAt = 0;
        isBan = false;
    }
}

class UserSolution {
    Node head;
    int updatedCount;

    void mstrcpy(char dst[], char src[])
    {
        int c = 0;
        while((dst[c] = src[c]) != 0)
            ++c;
    }

    int mstrlen(char[] str)
    {
        int len = 0;
        while (str[len] != 0)
            ++len;
        return len;
    }

    int mstrcmp(char str1[], char str2[])
    {
        int c = 0;
        while(str1[c] != 0 && str1[c] == str2[c])
            ++c;
        return str1[c] - str2[c];
    }

    boolean isBetter(Node node1, Node node2) {
        if (node1.maxCount < node2.maxCount) return true;
        else if (node1.maxCount == node2.maxCount) {
            return node1.maxUpdatedAt < node2.maxUpdatedAt;
        }
        return false;
    }

    void addNode(Node node, int idx, char[] str, boolean isBan) {
        if (str[idx] == '\0') {
            if (node.str == null) {
                node.str = new char[26];
                mstrcpy(node.str, str);
            }
            if (isBan || node.isBan) {
                node.count = 0;
                node.updatedAt = 0;
                node.isBan = true;
            } else {
                node.count++;
                node.updatedAt = ++updatedCount;
            }
        }
        else {
            int next = str[idx] - 'a';
            if (node.child[next] == null) {
                node.child[next] = new Node();
            }
            addNode(node.child[next], idx + 1, str, isBan);
        }
        node.maxCount = node.count;
        node.maxUpdatedAt = node.updatedAt;
        if (node.str != null) {
            node.maxStr = new char[20];
            mstrcpy(node.maxStr, node.str);
        }
        for (int i = 0; i < 26; i++) {
            if (node.child[i] != null) {
                if (isBetter(node, node.child[i])) {
                    node.maxCount = node.child[i].maxCount;
                    node.maxUpdatedAt = node.child[i].maxUpdatedAt;
                    node.maxStr = new char[20];
                    mstrcpy(node.maxStr, node.child[i].maxStr);
                }
            }
        }
    }

    void init()
    {
        head = new Node();
        updatedCount = 0;
    }

    void inputWord(char[] mWord)
    {
        addNode(head,0,mWord,false);
    }

    int recommend(char[] mUser, char[] mAnswer)
    {
        boolean have = true;
        Node node = head;
        for (int i = 0; mUser[i] != '\0' ; i++) {
            int next = mUser[i] - 'a';
            if (node.child[next] == null) {
                have = false;
                break;
            }
            node = node.child[next];
        }
        if (node.maxCount == 0) have = false;
        if (have) mstrcpy(mAnswer, node.maxStr);
        else mstrcpy(mAnswer, mUser);
//        System.out.println(mAnswer);

        return mstrlen(mAnswer);
    }

    void banWord(char[] mWord)
    {
        addNode(head,0,mWord,true);
    }
}