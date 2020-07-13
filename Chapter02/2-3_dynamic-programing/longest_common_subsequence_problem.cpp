#include <iostream>

using namespace std;

const int n = 4;
const int m = 4;
string s = "abcd";
string t = "becd";

int dp[n+1][m+1]; // dp[i][j]: s1 ~ siとt1~tiの共通部分列

void solve(){
    // s_1.. s_i+1,, t_1...t_j+1 のLCSは次のどれか
    // 1. s_i+1 = t_j+1 ->  ~s_i, ~t_iの最長部分列 + s_i 
    // 2. ~s_i+1, ~t_j の最長部分列
    // 3. ~s_i, ~t_j+1 の最長部分列

    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(s[i+1]==t[j+1]) dp[i+1][j+1] = dp[i][j] + 1;
            else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            } 
        }
    }

    cout << dp[n][m] << endl; // s1-sn, t1-tnのLCSと定義
}

int main(){
    solve();
}