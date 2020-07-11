#include <iostream>
#include <string>
const int n =  6;
const std::string s = "ACDBCB";

void solve(){
    using namespace std;
    string t = "";
    int l = 0;
    int r = n-1;
    while(l<=r){
        if(s[l]<s[r]){
            t += s[l];
            l++;
        }else{
            t += s[r];
            r--;
        }
    }
    cout << t << endl;
}

int main(){
    solve();
    return 0;
}