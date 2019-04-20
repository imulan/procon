#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const vector<string> NG = vector<string>();

using pi = pair<int,int>;

class DistanceZeroAndOne {
    public:
    vector<string> construct(vector<int> dist0, vector<int> dist1) {
        int n = dist0.size();

        if(dist0[0]!=0) return NG;
        if(dist1[1]!=0) return NG;
        if(dist0[1]!=dist1[0]) return NG;
        rep(i,n)
        {
            if(i!=0 && dist0[i]==0) return NG;
            if(i!=1 && dist1[i]==0) return NG;
        }

        vector<string> G(n,string(n,'N'));

        vector<bool> use(n,false);
        use[0]=use[1]=true;
        int D = dist0[1];
        vector<int> x(D+1);
        x[0]=0;
        x[D]=1;
        for(int i=1; i<D; ++i)
        {
            bool found=false;
            rep(j,n)if(!use[j])
            {
                if(dist0[j]==i && dist1[j]==D-i)
                {
                    x[i]=j;
                    use[j]=true;
                    found=true;
                    break;
                }
            }

            if(!found) return NG;
        }

        // rep(i,D+1) printf("x[%d]=%d\n", i,x[i]);

        rep(i,D)
        {
            G[x[i]][x[i+1]]='Y';
            G[x[i+1]][x[i]]='Y';
        }

        vector<pi> p;
        rep(i,n)if(!use[i])
        {
            int sum = dist0[i] + dist1[i];
            if(sum<D) return NG;

            p.pb(pi(sum,i));
        }

        sort(all(p));
        for(const auto &v:p)
        {
            int s=v.fi;
            int num=v.se;

            // printf("num %d\n", num);

            if(s==D)
            {
                int id=dist0[num];
                G[num][x[id-1]]='Y';
                G[x[id-1]][num]='Y';
                G[num][x[id+1]]='Y';
                G[x[id+1]][num]='Y';
            }
            else if(s==D+1)
            {
                int d0=dist0[num];
                G[num][x[d0-1]]='Y';
                G[x[d0-1]][num]='Y';
                G[num][x[d0]]='Y';
                G[x[d0]][num]='Y';
            }
            else
            {
                int d0=dist0[num];
                int d1=s-d0;

                bool found=false;

                int x=-1,y=-1;

                rep(i,n)
                {
                    if(d0-1==dist0[i] && d1-1<=dist1[i])
                    {
                        x=i;
                        break;
                    }
                }
                rep(i,n)
                {
                    if(d0-1<=dist0[i] && d1-1==dist1[i])
                    {
                        y=i;
                        break;
                    }
                }

                if(x==-1 || y==-1) return NG;
                G[num][x]='Y';
                G[x][num]='Y';
                G[num][y]='Y';
                G[y][num]='Y';
            }
        }

        return G;
    }
};

// CUT begin
ifstream data("DistanceZeroAndOne.sample");

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

bool do_test(vector<int> dist0, vector<int> dist1, vector<string> __expected) {
    time_t startClock = clock();
    DistanceZeroAndOne *instance = new DistanceZeroAndOne();
    vector<string> __result = instance->construct(dist0, dist1);
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
        vector<int> dist0;
        from_stream(dist0);
        vector<int> dist1;
        from_stream(dist1);
        next_line();
        vector<string> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(dist0, dist1, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1495297461;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "DistanceZeroAndOne (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
