#include <iostream>
int coins[6] = {1,5,10,50,100,500};

int c[6] = {3,2,1,3,0,2};
int a = 620;

int solve(){
    int result = 0;
    for(int i=5;i>0; i--){
        for(int j=0;j<c[i];j++){
            if(a-coins[i] >= 0){
                a-=coins[i];
                // std::printf("%d %d\n",coins[i], a);
                result++;
            }else{
                // std::printf("%d %d*\n",coins[i], a);
                break;
            }
        }
        if(a == 0) return result;
        if(a < 0) return -1;
    }
    return -1;
}

int main(){
    int result = solve();
    std::cout << result << std::endl;
}