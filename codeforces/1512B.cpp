#include <bits/stdc++.h>
using namespace std;

class Vertex {
public:
    int col, row;
};

auto solve() -> void {
    auto n = 0;
    cin >> n;
    auto m = vector<string>(n);
    auto a_saved = false;
    Vertex a, b, c, d;
    
    for(auto i = 0; i < n; ++i) {
        cin >> m[i];
        for(auto j = 0; j < n; ++j) {
            if(m[i][j] == '*') {
                if(a_saved) {
                    b.row = i;
                    b.col = j;
                } else {
                    a_saved = true;
                    a.row = i;
                    a.col = j;
                }
            }
        }
    }

    if(a.row == b.row) {
        if(a.row == 0) {
            c.col = a.col;
            c.row = a.row + 1;
            d.col = b.col;
            d.row = b.row + 1;
        } else {
            c.col = a.col;
            c.row = a.row - 1;
            d.col = b.col;
            d.row = b.row - 1;
        }
    }

    else if(a.col == b.col) {
        if(a.col == 0) {
            c.row = a.row;
            c.col = a.col + 1;
            d.row = b.row;
            d.col = b.col + 1;
        } else {
            c.row = a.row;
            c.col = a.col - 1;
            d.row = b.row;
            d.col = b.col - 1;
        }
    }

    else {
        c.row = a.row;
        c.col = b.col;
        d.row = b.row;
        d.col = a.col;
    }

    m[c.row][c.col] = m[d.row][d.col] = '*';

    for(auto i = 0; i < n; ++i) {
        for(auto j = 0; j < n; ++j) {
            cout << m[i][j];
        }
        cout << endl;
    }

}

auto main() -> int {
    auto tests {0};
    cin >> tests;
    while(tests--) solve();
    return 0;
}