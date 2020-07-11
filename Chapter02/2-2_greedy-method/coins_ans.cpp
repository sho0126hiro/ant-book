#include <iostream>
int coins[6] = {1,5,10,50,100,500};

int c[6] = {3,2,1,3,0,2};
int a = 620;

int solve(){
    int ans = 0;
    for(int i =5;i>=0; i--){
        int t = std::min(a/coins[i], c[i]);  // a/coins[i]: コインの枚数全部を使わない時, C[i]: コインの枚数全部 
                                        // -> 最小をとることでコイン使用枚数を出力
        a -= t*coins[i];
        ans++;
    }
    return ans;
}

int main(){
    int result = solve();
    std::cout << result << std::endl;
}