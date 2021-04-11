#include <bits/stdc++.h>
using namespace std;

auto solve() -> void {
    auto n {0};
    cin >> n;

    auto nums = vector<int>(n);
    auto hash = vector<int>(105);

    for(auto& num: nums)
        cin >> num, hash[num]++;

    auto spy {-1};

    for(auto i = 0; i < 101; ++i) {
        if(hash[i] == 1) {
            spy = i; break;
        }
    }

    for(auto i = 0; i < n; ++i)
        if(nums[i] == spy)
            cout << i + 1 << endl;

}

auto main() -> int {
    auto tests {0};
    cin >> tests;
    while(tests--) solve();
    return 0;
}