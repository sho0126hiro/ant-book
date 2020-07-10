#include <iostream>
using namespace std;
const int n = 5;
int l[n] = {3,4,5,1,2};
// const int n = 3;
// int l[n] = {8,5,8};

int sum(){
    int s = 0;
    for(int i=0;i<n;i++){
        s += l[i];
    }
    return s;
}

void solve(){
    int s = sum();
    int ans = 0;
    int c = 0;
    do{
        sort(l,l+n);
        ans += l[c]+l[c+1];
        l[c] = l[c]+l[c+1];
        l[c+1] = 0;
        c++;    
    }while(l[c]+l[c-1] < s);

    cout << ans << endl;
}

int main(){
    sort(l, l+n);
    solve();
}
