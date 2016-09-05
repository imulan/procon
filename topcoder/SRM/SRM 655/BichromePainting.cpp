#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

class BichromePainting {
    public:
    string isThatPossible(vector<string> board, int k) {
        // k=1なら絶対できるのでその場合はこれ以降は考慮しない
        if(k==1) return "Possible";

        int n = board.size();

        while(1)
        {
            int Y=-1,X=-1;
            // ?変換を出来る場所を探す
            rep(i,n+1-k)rep(j,n+1-k)
            {
                int q=0,b=0,w=0;
                for(int y=i; y<i+k; ++y)for(int x=j; x<j+k; ++x)
                {
                    if(board[y][x]=='W') ++w;
                    else if(board[y][x]=='B') ++b;
                    else ++q;
                }

                // 全てのセルが?なのでここは対象外
                if(q==k*k) continue;

                // どちらかの色しか含まれていない時、そこを?変換の対象とできる
                if(b==0 || w==0)
                {
                    Y=i;
                    X=j;
                    break;
                }
            }

            // 見つからなかった
            if(Y==-1) break;

            // 変換
            for(int y=Y; y<Y+k; ++y)for(int x=X; x<X+k; ++x) board[y][x]='?';
        }

        // 最後に初期状態に戻せるかを判定
        bool valid=true;
        rep(i,n)rep(j,n)
        {
            if(board[i][j]!='?') valid=false;
        }
        string ret="Impossible";
        if(valid) ret="Possible";
        return ret;
    }
};

// CUT begin
ifstream data("BichromePainting.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<string> board, int k, string __expected) {
    time_t startClock = clock();
    BichromePainting *instance = new BichromePainting();
    string __result = instance->isThatPossible(board, k);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<string> board;
        from_stream(board);
        int k;
        from_stream(k);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(board, k, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1473069680;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "BichromePainting (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
