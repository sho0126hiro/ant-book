#include <iostream>
using namespace std;

const int n = 3;
const int w[n] = {3,4,2};
const int v[n] ={4,5,3};
const int W = 7;
int dp[n+1][W+1];

void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            if(j < w[i]){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = max(dp[i][j], dp[i+1][j-w[i]]+v[i]);
            }
        }
    }
    cout << dp[n][W] << endl; 
}

int main(){
    solve();
}