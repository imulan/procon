#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

class JoinedString {
    public:
    const int INF=12345678;
    int dp[15][1<<15];
    string a[15][1<<15];
    // i,jの順に繋ぐ時の共通部分列の長さ
    int com[15][15];

    string joinWords(vector<string> s) {
        sort(all(s));
        s.erase(unique(all(s)),s.end());

        int n=s.size();
        vector<bool> use(n,true);
        rep(i,n)rep(j,n)
        {
            if(i==j) continue;

            int I=s[i].size(), J=s[j].size();
            if(I>J) continue;
            rep(k,J-I+1) if(s[i]==s[j].substr(k,I)) use[i]=false;
        }

        vector<string> t;
        rep(i,n) if(use[i]) t.pb(s[i]);
        int T=t.size();

        memset(com,0,sizeof(com));
        rep(i,T)rep(j,T)
        {
            if(i==j) continue;
            int I=t[i].size(), J=t[j].size();

            rep(k,min(I,J))
            {
                int len=k+1;
                if(t[i].substr(I-len)==t[j].substr(0,len)) com[i][j]=len;
            }
        }

        fill(dp[0],dp[15],INF);
        fill(a[0],a[15],"#");

        // 最初
        rep(i,T)
        {
           dp[i][1<<i]=t[i].size();
           a[i][1<<i]=t[i];
        }

        for(int mask=1; mask<(1<<T); ++mask)
        {
           rep(before,T)if(mask>>before&1)
           {
               rep(i,T)if(!(mask>>i&1))
               {
                   int add=t[i].size()-com[before][i];
                   if(dp[i][mask+(1<<i)]>dp[before][mask]+add)
                   {
                       dp[i][mask+(1<<i)]=dp[before][mask]+add;
                       a[i][mask+(1<<i)]=a[before][mask]+t[i].substr(com[before][i]);
                   }
                   else if(dp[i][mask+(1<<i)]==dp[before][mask]+add)
                   {
                       string tmp=a[before][mask]+t[i].substr(com[before][i]);
                       a[i][mask+(1<<i)] = min(a[i][mask+(1<<i)],tmp);
                   }
               }
           }
        }

        int min_len=INF;
        rep(i,T) min_len=min(min_len, dp[i][(1<<T)-1]);

        string ans="#";
        rep(i,T)
        {
           if(dp[i][(1<<T)-1]==min_len)
           {
               if(ans=="#") ans=a[i][(1<<T)-1];
               else ans=min(ans,a[i][(1<<T)-1]);
           }
        }

        return ans;
    }
};

// CUT begin
ifstream data("JoinedString.sample");

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

bool do_test(vector<string> words, string __expected) {
    time_t startClock = clock();
    JoinedString *instance = new JoinedString();
    string __result = instance->joinWords(words);
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
        vector<string> words;
        from_stream(words);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(words, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1479731695;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "JoinedString (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
