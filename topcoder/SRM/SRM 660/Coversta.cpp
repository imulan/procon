#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vi> vvi;

class Coversta {
    public:
    int X,Y;
    inline bool in(int x, int y)
    {
        return(0<=x&&x<X && 0<=y&&y<Y);
    }

    int place(vector<string> a, vector<int> x, vector<int> y) {
        X=a.size();
        Y=a[0].size();

        int z=x.size();

        //1つ目のstation設置によって得られるpoint
        vvi sum1(X,vi(Y,0));
        rep(i,X)rep(j,Y)rep(k,z)
        {
            int nx=i+x[k], ny=j+y[k];
            if(in(nx,ny)) sum1[i][j]+=(a[nx][ny]-'0');
        }

        int ret=0;
        //1つ目のstationの位置を固定
        rep(i,X)rep(j,Y)
        {
            //2つ目のstation設置によって得られるpoint
            vvi sum2=sum1;

            //1つ目のstationのp個目のグリッドと
            //2つ目のstationのq個目のグリッドが
            //重なっていると仮定した時
            rep(p,z)
            {
                int nx=i+x[p], ny=j+y[p];
                if(in(nx,ny))
                {
                    rep(q,z)
                    {
                        int nnx=nx-x[q], nny=ny-y[q];
                        if(in(nnx,nny)) sum2[nnx][nny]-=(a[nx][ny]-'0');
                    }
                }
            }

            //1つ目のstationの固定に対してベストな位置を選択
            rep(k,X)rep(l,Y) ret=max(ret,sum1[i][j]+sum2[k][l]);
        }

        return ret;
    }
};

// CUT begin
ifstream data("Coversta.sample");

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

bool do_test(vector<string> a, vector<int> x, vector<int> y, int __expected) {
    time_t startClock = clock();
    Coversta *instance = new Coversta();
    int __result = instance->place(a, x, y);
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
        vector<string> a;
        from_stream(a);
        vector<int> x;
        from_stream(x);
        vector<int> y;
        from_stream(y);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, x, y, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1464067917;
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
        cout << "Coversta (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
