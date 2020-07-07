#include <cstdio>
#include <iostream>

const int N = 10;
const int M = 12;


// 水溜り: 1. 水溜りではない場所: 0
const int LAKE[N][M] =
{
    {1,0,0,0,0,0,0,0,0,1,1,0},
    {0,1,1,1,0,0,0,0,0,1,1,1},
    {0,0,0,0,1,1,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,1,0,0,0,0,0,0,1,0,0},
    {0,1,0,1,0,0,0,0,0,1,1,0},
    {1,0,1,0,1,0,0,0,0,0,1,0},
    {0,1,0,1,0,0,0,0,0,0,1,0},
    {0,0,1,0,0,0,0,0,0,0,1,0},   
};

int mask[N][M] = {0};

int update(int i, int j, int c){
    if(mask[i-1][j-1] || mask[i-1][j] || mask[i-1][j+1] || mask[i][j-1] || mask[i][j+1] || mask[i+1][j-1] || mask[i+1][j] || mask[i+1][j+1]){
        // どれか一つがc
        mask[i][j] = c;
    }else{//全部0
        c+=1;
        mask[i][j] = c;
    }
    return c;
}

int solve(){
    int c = 1;
    for(int i=0;i<N; i++){
        for(int j=0;j<M;j++){
            if(LAKE[i][j]){
                c = update(i,j,c);
            } 
        }
    }
    return c;
}

int main(){
    std::printf("水溜りの個数: %d\n", solve());
}