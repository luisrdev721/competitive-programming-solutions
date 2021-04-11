#include <bits/stdc++.h>
using namespace std;
constexpr auto endline = '\n';

auto mx = 1e7+1;
auto divs = vector<int> (mx);
auto ans = vector<int> (mx, -1);

auto process() -> void {
    for(auto i = 1; i < mx; ++i) {
        for(auto j = i; j < mx; j += i) {
            divs[j] += i;
        }
    }
    
    for(auto i = 1; i < ans.size(); ++i) {
        if(divs[i] > mx) {
            continue;
        }

        if(ans[divs[i]] < 0) {
            ans[divs[i]] = i;
        }
    }
}
auto solve() -> void {
    auto n = 0;
    cin >> n;
    cout << ans[n] << endline;
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(0);
    process();
    auto tests = 0;
    cin >> tests;
    while(tests--) {
        solve();
    }
    return 0;
}