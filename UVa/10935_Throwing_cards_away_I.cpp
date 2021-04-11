#include <bits/stdc++.h>
using namespace std;
constexpr auto endline = '\n';

auto process() -> void {}
auto solve(int& n) -> void {
    auto q = queue<int>{};
    for(auto i = 1; i <= n; ++i) {
        q.push(i);
    }

    auto discarted_cards = vector<int>{};

    while(q.size() > 1) {
        auto discarted_card = q.front();
        q.pop();
        discarted_cards.push_back(discarted_card);

        auto remaning_card = q.front();
        q.pop();
        q.push(remaning_card);
    }

    auto discarted = string{"Discarded cards:"};

    if(discarted_cards.size() > 0) {
        discarted += " ";
    }

    for(auto i = 0; i < discarted_cards.size(); ++i) {
        discarted += to_string(discarted_cards[i]);
        if(i < discarted_cards.size() - 1) {
            discarted += ", ";
        }
    }
    auto remaining = string{"Remaining card: "};
    remaining += to_string(q.front());

    cout << discarted << endl << remaining << endl;
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(0);
    process();
    auto tests = 0;
    while(cin >> tests) {
        if(tests == 0) {
            break;
        }
        solve(tests);
    }
    return 0;
}