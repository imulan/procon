#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; assert(cin >> T);
    assert(1 <= T && T <= 10000);

    int sum_M = 0;
    while (T--) {
        int N, M; assert(cin >> N >> M);
        assert(2 <= N && N <= 100 * 1000);
        assert(1 <= M && M <= 200 * 1000);
        sum_M += M;
        assert(sum_M <= 200 * 1000);

        vector< pair<int, int> > wishes;
        vector< vector<int> > edges(N);
        for (int i = 0; i < M; ++i) {
            int x, y; assert(cin >> x >> y);
            assert(1 <= x && x <= N);
            assert(1 <= y && y <= N);
            assert(x != y);

            wishes.emplace_back(x - 1, y - 1);
            edges[x - 1].push_back(y - 1);
            edges[y - 1].push_back(x - 1);
        }

        vector<bool> white(N, false);
        for (int i = 0; i < N; ++i) {
            int white_neighbours = 0, black_neighbours = 0;
            for (auto &x : edges[i])
                if (x < i) {
                    if (white[x])
                        ++white_neighbours;
                    else
                        ++black_neighbours;
                }
            if (white_neighbours > black_neighbours)
                white[i] = false;
            else
                white[i] = true;
        }

        int white_to_black = 0, black_to_white = 0;
        for (auto &wish : wishes) {
            if (white[wish.first] && !white[wish.second])
                ++white_to_black;
            if (!white[wish.first] && white[wish.second])
                ++black_to_white;
        }

        bool first_white;
        if (white_to_black > black_to_white) {
            first_white = true;
            cout << white_to_black << "\n";
        } else {
            first_white = false;
            cout << black_to_white << "\n";
        }
        for (int i = 0; i < M; ++i) {
            auto& wish = wishes[i];
            if (white[wish.first] != white[wish.second] && white[wish.first] == first_white)
                cout << i + 1 << " ";
        }
        cout << "\n";
    }
}
