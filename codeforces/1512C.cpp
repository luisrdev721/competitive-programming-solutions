#include <bits/stdc++.h>
using namespace std;
constexpr auto endline = '\n';

auto is_palindrome(string& s) -> bool {
    for(auto i = 0; i < s.size()/2; ++i)
        if(s[i] != s[s.size()-i-1])
            return false;
    return true;
}

auto solve() -> void {
    
    auto hash = vector<int>(2);
    auto s = string{};

    cin >> hash[0] >> hash[1] >> s;

    auto n = hash[0] + hash[1];
    auto fail = false;

    // 1. Check only pairs type [0,?], [?,0], [1,?], [?,1] and [1,0], [0,1]
    
    for(auto left = 0; left < n - left - 1; ++left) {
        auto right = n - left - 1;

        if(s[left] == '?' and s[right] == '?')  {
            continue;
        }

        if(s[left] == '?') {
            s[left] = s[right];

        } else if(s[right] == '?') {
            s[right] = s[left];

        } else if(s[left] != s[right]) {
            fail = true;
        }

        hash[s[right] - '0'] -= 2;
    }

    // 2. Check pairs type [?,?]

    for(auto left = 0; left < n - left - 1; ++left) {
        if(s[left] == '?') {
            auto right = n - left - 1;
            
            if(hash[0] >= 2) {
                s[left] = s[right] = '0';

            } else if(hash[1] >= 2) {
                s[left] = s[right] = '1';

            } else {
                fail = true;
            }

            hash[s[left] - '0'] -= 2;
        }
    }

    // 3. Check if the string length is odd and have a valid center

    if(n & 1) {
        auto center = n >> 1;

        if(s[center] == '?') {
            if(hash[0] >= 1) {
                s[center] = '0';

            } else if(hash[1] >= 1) {
                s[center] = '1';

            } else {
                fail = true;
            }
        }

        hash[s[center] - '0']--;
    }

    if(hash[0] < 0 or hash[1] < 0) {
        fail = true;
    }

    cout << (fail ? "-1" : s) << endline;
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto tests = 0;
    cin >> tests;
    while(tests--) {
        solve();
    }
    return 0;
}