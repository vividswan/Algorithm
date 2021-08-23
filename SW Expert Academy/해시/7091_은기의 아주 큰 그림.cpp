#include <iostream>
using namespace std;

int testCase ,n, m, h, w;
int tareget[2000][2000], map[2000][2000];
unsigned int hashMap[2000][2000], randNum[4000000], value[2000];

int findHash(unsigned int hashValue) {
    int i, j;
    int cnt = 0;

    for (i = w - 1; i < m; i++) {
        value[i] = 0;
        for (j = 0; j < h; j++) {
            value[i] += hashMap[j][i] * randNum[w * (h - j - 1)];
        }
        if (hashValue == value[i]) cnt++;
    }

    for (i = 1; i < n - h + 1; i++) {
        for (j = w - 1; j < m; j++) {

            value[j] = (value[j] - hashMap[i - 1][j] * randNum[w * (h - 1)]) * randNum[w] + hashMap[i + h - 1][j];
            if (hashValue == value[j])               cnt++;
        }
    }
    return cnt;
}

unsigned int getHash() {
    unsigned int hash = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            hash += tareget[i][j] * randNum[w * (h - i) - j - 1];
        }
    }
    return hash;
}

void initHash() {
    unsigned int temp;

    for (int i = 0; i < n; i++) {
        temp = 0;
        for (int j = 0; j < w; j++) {
            temp += map[i][j] * randNum[w - j - 1];
        }
        hashMap[i][w - 1] = temp;

        for (int j = w; j < m; j++) {
            hashMap[i][j] = hashMap[i][j - 1] - randNum[w - 1] * map[i][j - w];
            hashMap[i][j] = hashMap[i][j] * 3 + map[i][j];
        }
    }
}


int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> testCase;

    randNum[0] = 1;
    for (int i = 1; i < 4000000; i++) randNum[i] = randNum[i - 1] * 3;

    for (int t = 1; t <= testCase; t++) {
        cin >> h >> w >> n >> m;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                char c;
                cin >> c;
                if(c=='o') tareget[i][j] = 1;
                else tareget[i][j] = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                if(c=='o') map[i][j] = 1;
                else map[i][j] = 0;
            }
        }

        initHash();
        cout << "#" << t << " " << findHash(getHash()) << "\n";

    }

    return 0;
}