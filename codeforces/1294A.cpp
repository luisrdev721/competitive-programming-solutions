#include <bits/stdc++.h>
using namespace std;
constexpr auto endline = '\n';

auto process() -> void {}
auto solve() -> void {
    auto a = 0, b = 0, c = 0, coins = 0;
    auto fail = false;
    
    cin >> a >> b >> c >> coins;

    auto min_coins = max(a, max(b, c));
    auto min_coins_needed = (min_coins - a) + (min_coins - b) + (min_coins - c);

    coins -= min_coins_needed;

    if(coins < 0 or coins % 3 != 0) {
        fail = true;
    }

    if(fail) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    
    cout << endline;
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