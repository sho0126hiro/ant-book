#include <stack>
#include <cstdio>

using namespace std;

// 1,2,3 -> 3,2,1
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    printf("%d\n", s.top());
    s.pop();
    printf("%d\n", s.top());
    s.pop();
    printf("%d\n", s.top());
    s.pop();
    return 0;
}