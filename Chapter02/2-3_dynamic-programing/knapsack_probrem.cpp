#include <iostream>

using namespace std;
const int n = 4;
const int w[n] = {2,1,3,2};
const int v[n] = {3,2,4,2};
const int W = 5;
int dp[n+1][W+1]; // n番目までの商品を入れた時の価値dp(w: その時の残りの容量（残り入れられる重さ）)

void solve(){
    for(int j=0;j<W;j++){ // 0番目までの商品を入れている（全く商品を入れていない）時の価値を0とする
        dp[0][j] = 0;
    }
    for(int i=0;i<n;i++){ // 入れようとするもの
        for(int j=0;j<=W;j++){ // 残りの鞄の容量
            // 入れる荷物の重さw[i]が鞄の残りの容量jを超える時（もう入らない）
            if(j < w[i]) dp[i+1][j] = dp[i][j]; // i+1番目までの商品を入れた時の最大価値は足さない状態(dp[i][j]と等しい)
            else {
            // 超えていない時（入れない時, 入れた時（j-w[i]: iを入れた時の残りの鞄の容量, dp[i][j-w[i]]+v[i]: i番目の商品までを入れた時の最大価値にiの価値を加える）
            dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
            }
        }
    }
    cout << dp[n][W] << endl; // n番目の商品を入れた時の価値dp　ただし、残りの容量はw　-> n個の商品をw以下の重さ（容量）で得られる最大の価値

}

int main(){
    solve();
}
