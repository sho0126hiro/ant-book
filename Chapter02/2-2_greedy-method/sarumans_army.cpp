#include <iostream>
using namespace std;

const int n = 6;
const int r = 10;
int x[n] = {1,7,15,20,30,50};

void solve(){
    int now = 0;
    int t = 0;
    int ans = 0;
    while(now<n){
        // 印をつける
        for(int i=now;i<n;i++){
            if(x[i] - x[now] <= r && now < n) t = i;
            else break;
        }
        now = t; // 印をつけたところ
        // 印をつけたところからさらにR
        for(int i=now;i<n;i++){
            if(x[i] - x[now] <= r && now < n) t = i;
            else break;
        }
        now = t+1; // 範囲外で一番手前の座標
        ans++;
    }
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}
