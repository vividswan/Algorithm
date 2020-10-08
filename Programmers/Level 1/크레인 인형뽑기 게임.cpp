#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> s;
    int answer = 0;
    for(int i=0; i<moves.size();i++){
        int now = moves[i]-1;
        for(int j=0;j<board.size();j++){
            if(board[j][now]!=0){
                if(s.empty()){
                    s.push(board[j][now]);
                }
                else {
                    if(s.top()==board[j][now]){
                        answer+=2;
                        s.pop();
                    }
                    else s.push(board[j][now]);
                }
                board[j][now]=0;
                break;
            }
        }
    }
    return answer;
}