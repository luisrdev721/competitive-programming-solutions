#include <bits/stdc++.h>
using namespace std;
constexpr auto endline = '\n';

auto solve() -> void {
    auto n = 0;
    cin >> n;
    auto b = vector<int>(n+2);
    auto sum = 0LL;

    for(auto& el: b)
        cin >> el, sum += el;

    sort(b.begin(), b.end());

    sum -= b[n];
    sum -= b[n+1];

    if(sum == b[n]) {
        for(auto i = 0; i < n; ++i) {
            cout << b[i] << " ";
        } 
    } else {
        sum += b[n];
        auto id = -1;

        for(auto i = 0; i < n + 1; ++i) {
            if(sum - b[i] == b[n+1]) {
                id = i;
            }
        }

        if(id < 0) {
            cout << id;

        } else {
            for(auto i = 0; i < n + 1; ++i) {
                if(i != id) {
                    cout << b[i] << " ";
                }
            }
        }
    } cout << endline;
}

auto main() -> int {
    auto tests {0};
    cin >> tests;
    while(tests--) solve();
    return 0;
}