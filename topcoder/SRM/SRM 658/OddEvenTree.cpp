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

class OddEvenTree {
    public:
    vector<int> getTree(vector<string> x) {
        int n=x.size();

        bool valid=true;
        rep(i,n) if(x[i][i]=='O') valid=false;
        rep(i,n)rep(j,i) if(x[i][j]!=x[j][i]) valid=false;

        vector<int> fail;
        fail.pb(-1);

        if(!valid) return fail;

        vector<int> ret;

        vector<int> G[50];
        int ct=0;
        int f=-1;
        for(int i=1; i<n; ++i)
        {
            if(x[0][i]=='O')
            {
                if(ct==0) f=i;
                ++ct;

                G[0].pb(i);
                G[i].pb(0);

                ret.pb(0);
                ret.pb(i);
            }
        }

        if(ct==0) return fail;

        for(int i=1; i<n; ++i)
        {
            if(x[0][i]=='E')
            {
                G[f].pb(i);
                G[i].pb(f);

                ret.pb(f);
                ret.pb(i);
            }
        }

        const int INF=1234567;
        int dist[50][50];
        rep(i,n)rep(j,n) dist[i][j]=INF;
        rep(i,n)
        {
            dist[i][i]=0;
            queue<int> que;
            que.push(i);
            while(!que.empty())
            {
                int v=que.front();
                que.pop();
                rep(j,G[v].size())
                {
                    int nx=G[v][j];
                    if(dist[i][nx]>dist[i][v]+1)
                    {
                        dist[i][nx]=dist[i][v]+1;
                        que.push(nx);
                    }
                }
            }
        }

        bool ok=true;
        rep(i,n)rep(j,n)
        {
            int t=dist[i][j]%2;
            if(t==0 && x[i][j]=='O') ok=false;
            if(t==1 && x[i][j]=='E') ok=false;
        }

        if(ok) return ret;
        else return fail;
    }
};

// CUT begin
ifstream data("OddEvenTree.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<string> x, vector<int> __expected) {
    time_t startClock = clock();
    OddEvenTree *instance = new OddEvenTree();
    vector<int> __result = instance->getTree(x);
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
        vector<string> x;
        from_stream(x);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(x, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1464432412;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "OddEvenTree (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
