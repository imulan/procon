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

class ApplesAndOrangesEasy {
    public:
    int maximumApples(int N, int K, vector<int> info) {
        //食べたフルーツ(0:orange,1:apple)
        vector<int> f(N+1,-1);
        rep(i,info.size()) f[info[i]]=1;
        //リスト内のapple許容量
        int lim=K/2;

        //iを終端とする区間に含まれているapple
        vector<int> num(N+1,0);
        rep(i,info.size())
        {
            int now=info[i];
            for(int j=now; j<=min(N,now+K-1); ++j) ++num[j];
        }

        for(int i=1; i<=N; ++i)
        {
            if(f[i]!=-1) continue;

            //この位置でappleを食べても問題ないか調べる
            int ct=0;
            for(int j=i; j<=min(N,i+K-1); ++j) ct=max(ct,num[j]+1);

            if(ct<=lim)
            {
                f[i]=1;
                for(int j=i; j<=min(N,i+K-1); ++j) ++num[j];
            }
            else f[i]=0;
        }

        int ans=0;
        for(int i=1; i<=N; ++i) ans+=f[i];

        return ans;
    }
};

// CUT begin
ifstream data("ApplesAndOrangesEasy.sample");

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

bool do_test(int N, int K, vector<int> info, int __expected) {
    time_t startClock = clock();
    ApplesAndOrangesEasy *instance = new ApplesAndOrangesEasy();
    int __result = instance->maximumApples(N, K, info);
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
        int N;
        from_stream(N);
        int K;
        from_stream(K);
        vector<int> info;
        from_stream(info);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, K, info, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1464345269;
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
        cout << "ApplesAndOrangesEasy (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
