#include <iostream>
#include <queue>
#include <string>
#include <array>

using namespace std;

const int N = 10;
const int M = 10;

string MAZE[N][M] =
{
    {"#", "S", "#", "#", "#", "#", "#", "#", ".", "#"},
    {".", ".", ".", ".", ".", ".", "#", ".", ".", "#"},
    {".", "#", ".", "#", "#", ".", "#", "#", ".", "#"},
    {".", "#", ".", ".", ".", ".", ".", ".", ".", "."},
    {"#", "#", ".", "#", "#", ".", "#", "#", "#", "#"},
    {".", ".", ".", ".", "#", ".", ".", ".", ".", "#"},
    {".", "#", "#", "#", "#", "#", "#", "#", ".", "#"},
    {".", ".", ".", ".", "#", ".", ".", ".", ".", "."},
    {".", "#", "#", "#", "#", ".", "#", "#", "#", "."},
    {".", ".", ".", ".", "#", ".", ".", ".", "G", "#"}
};

struct Position{
    int x;
    int y;
    Position(int x, int y): x(x), y(y){};
};

int solve(){
    // 現在地（複数格納, queueに入れる）
    queue<Position> q;
    Position p(0,1);
    q.push(p);
    int step = 0;
    while(true){
        int size = q.size();
        step+=1;
        for(int i=0;i<size;i++){
            Position now = q.front();
            MAZE[now.x][now.y] = "v"; // is visited
            q.pop();
            // get moveable
            string down = MAZE[now.x+1][now.y];
            string right =  MAZE[now.x][now.y+1];
            string up = MAZE[now.x-1][now.y];
            string left = MAZE[now.x][now.y-1];
            
            // check goal
            if(down == "G" || right == "G" || up == "G" || left == "G"){
                return step;
            }
            
            // check moveable
            if(now.x!=N-1 && down == "."){
                q.push(Position(now.x+1, now.y));
            }
            if(now.y!=M-1 && right == "."){
                q.push(Position(now.x, now.y+1));
            }
            if(now.x!=0 && up == "."){
                q.push(Position(now.x-1, now.y));
            }
            if(now.y!=0 && left == "."){
                q.push(Position(now.x, now.y-1));
            }
        }
    }
}

int main(){
    int x = solve();
    cout << "迷路までの最小ターン数: " << x << endl;
}