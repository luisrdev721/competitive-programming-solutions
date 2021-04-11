#include <bits/stdc++.h>
using namespace std;
constexpr auto endline = '\n';

class Package {
public:
    int x, y;
    bool collected;
    Package(): collected {false}, x{0}, y{0} {}
};

auto process() -> void {}
auto solve() -> void {
    auto n = 0;
    cin >> n;

    auto packages = vector<Package>(n);
    for(Package& package: packages) {
        cin >> package.x >> package.y;
    }

    sort(packages.begin(), packages.end(), [](Package& a, Package& b) {
        if(a.x != b.x) {
            return a.x < b.x;
        } else {
            return a.y < b.y;
        }
    });

    auto robot_x = 0, robot_y = 0, next = 0;
    auto path = string{};
    auto fail = false;

    while(next < n) {
        if(robot_x == packages[next].x) {
            if(packages[next].y > robot_y) {
                auto _path = string(packages[next].y - robot_y, 'U');
                path += _path;
            } else if(packages[next].y < robot_y) {
                fail = true;
                break;
            }
            robot_y = packages[next].y;
            packages[next].collected = true;
            next++;
        } else if(robot_x < packages[next].x) {
            robot_x++;
            path.push_back('R');
        } else {
            fail = true;
            break;
        }
    }

    for(Package& package: packages) {
        if(not package.collected) {
            fail = true;
        }
    }

    if(fail) {
        cout << "NO";
    } else {
        cout << "YES" << endline;
        cout << path;
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