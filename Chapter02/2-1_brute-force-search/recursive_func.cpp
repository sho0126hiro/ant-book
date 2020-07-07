#include <iostream>

// 階乗
int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}

// フィボナッチ数列を計算する
int fib(int n){
    if(n<=1) return n;
    return fib(n-1) + fib(n-2);
}

int main(){
    std::cout << "Hello world" << std::endl;
    std::cout << fact(3) << std::endl;
    std::cout << fib(3) << std::endl;
    return 0;
}
