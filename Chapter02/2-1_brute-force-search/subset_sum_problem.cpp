#include <cstdio>
#include <iostream>

const int n = 4;
int a[n] = {1,2,4,7};
int k = 11;

bool solve(int idx, int sum){
    if(idx == n) return sum == k;
    // 加えた方向のノードをチェック
    if(solve(idx+1, sum+a[idx])){
        return true;
    }
    // 加えない方向のノードをチェック
    if(solve(idx+1, sum)){
        return true;
    }
    return false;
}

int main(){
    if(solve(0,0)){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
}

