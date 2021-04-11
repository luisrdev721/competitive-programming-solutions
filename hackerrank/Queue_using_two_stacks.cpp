#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    auto q = 0, type = 0, x = 0;
    cin >> q;
    auto qq = queue<int>{};
    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            qq.push(x);
        } else if(type == 2) {
            qq.pop();
        } else {
            cout << qq.front() << endl;
        }
    }   
    return 0;
}