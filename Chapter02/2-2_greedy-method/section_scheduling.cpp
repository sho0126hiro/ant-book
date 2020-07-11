#include <iostream>

// const int n = 5;
const int n = 3;
// int s[n] = {1,2,4,6,8};
// int t[n] = {3,5,7,9,10};
int s[n] = {1,2,4};
int t[n] = {6,3,5};

int solve(){
    int ans = 0;
    int now_end = 0;
    std::pair<int, int> sec[n];
    for(int i=0;i<n;i++){
        sec[i] = std::make_pair(t[i],s[i]);
    }
    std::sort(sec, sec+n);
    for(int i=0;i<n;i++){
        int next_end = std::max(sec[i].first, now_end);
        if(now_end < sec[i].second && next_end == sec[i].first){
            now_end = next_end;
            ans++;
        }
    }
    return ans;
}

int main(){
    int s = solve();
    std::cout << s << std::endl;
}