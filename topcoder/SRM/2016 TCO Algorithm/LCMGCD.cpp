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

typedef pair<int,int> pi;

class LCMGCD {
    public:
    pi gcd(pi x, pi y)
    {
        pi ret;
        ret.fi=min(x.fi,y.fi);
        ret.se=min(x.se,y.se);
        return ret;
    }

    pi lcm(pi x, pi y)
    {
        pi ret;
        ret.fi=max(x.fi,y.fi);
        ret.se=max(x.se,y.se);
        return ret;
    }

    string isPossible(vector<int> x, int t) {
        int n=x.size();
        if(n==1)
        {
            if(x[0]==t) return "Possible";
            else return "Impossible";
        }

        vector<pi> a(n,pi(0,0));
        pi b;

        rep(i,n)
        {
            int tmp=x[i];
            while(tmp%2==0){
                ++a[i].fi;
                tmp/=2;
            }
            while(tmp%3==0){
                ++a[i].se;
                tmp/=3;
            }
        }

        int tmp=t;
        while(tmp%2==0){
            ++b.fi;
            tmp/=2;
        }
        while(tmp%3==0){
            ++b.se;
            tmp/=3;
        }

        bool ok=false;
        rep(i,n)
        {
            if(a[i].fi==b.fi) ok=true;
        }
        if(!ok) return "Impossible";

        ok=false;
        rep(i,n)
        {
            if(a[i].se==b.se) ok=true;
        }
        if(!ok) return "Impossible";

        bool found=false;
        int idx=-1;
        rep(i,n)
        {
            if(x[i]==t)
            {
                found=true;
                idx=i;
            }
        }

        if(found)
        {
            vector<pi> y(a);
            y.erase(y.begin()+idx);

            pi g=y[0], l=y[0];
            for(int i=1; i<y.size(); ++i)
            {
                g=gcd(g,y[i]);
                l=lcm(l,y[i]);
            }

            if((g.fi<=b.fi&&g.se<=b.se) || (b.fi<=l.fi&&b.se<=l.se)) return "Possible";
            else return "Impossible";
        }
        else
        {
            int ida=-1,idb=-1;
            rep(i,n)
            {
                if(a[i].fi==b.fi) ida=i;
            }

            rep(i,n)
            {
                if(a[i].se==b.se) idb=i;
            }

            vector<pi> y;
            rep(i,n)
            {
                if(i!=ida && i!=idb) y.pb(a[i]);
            }

            pi p=a[ida], q=a[idb];

            rep(i,y.size())
            {
                if(y[i].fi>=b.fi) p=gcd(p,y[i]);
                else
                {
                    if(y[i].se>=b.se) q=gcd(q,y[i]);
                    else p=lcm(p,y[i]);
                }
            }

            pi X=gcd(p,q);
            pi Y=lcm(p,q);

            if(X==b || Y==b) return "Possible";
            else return "Impossible";
        }

        return "Impossible";
    }
};

// CUT begin
ifstream data("LCMGCD.sample");

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

bool do_test(vector<int> x, int t, string __expected) {
    time_t startClock = clock();
    LCMGCD *instance = new LCMGCD();
    string __result = instance->isPossible(x, t);
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
        vector<int> x;
        from_stream(x);
        int t;
        from_stream(t);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(x, t, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1463065211;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 400 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "LCMGCD (400 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
