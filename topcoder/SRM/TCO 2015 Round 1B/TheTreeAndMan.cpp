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

class TheTreeAndMan {
    public:
    const long mod=1e9+7;

    int sum(int x, int y)
    {
        long ret=x;
        ret+=y;
        while(ret<0) ret+=mod;
        ret%=mod;
        return (int)ret;
    }

    int mul(int x, int y)
    {
        long ret=x;
        ret*=y;
        ret%=mod;
        return (int)ret;
    }

    int solve(vector<int> parent) {
        //頂点数
        int n=parent.size()+1;
        //グラフ
        vector<int> G[2000];

        //グラフ内でのその頂点の深さ
        int depth[2000]={0};
        //その頂点から到達可能な頂点数(自身も含む)
        int reach[2000]={0};
        //その頂点を足の付根とするときの選び方の総数
        int leg[2000]={0};
        //その頂点以下のlegの和
        int body[2000]={0};

        //有向辺を張る
        rep(i,parent.size()) G[parent[i]].pb(i+1);

        //頂点iから到達可能な頂点数を計算
        for(int i=n-1; i>=0; --i)
        {
            //まず自分自身を計上
            reach[i]=1;
            rep(j,G[i].size()) reach[i]=sum(reach[i],reach[G[i][j]]);
        }

        //BFSして深さを計算
        queue<int> que;
        que.push(0);
        int vis[2000]={0};
        vis[0]=1;
        depth[0]=0;
        while(!que.empty())
        {
            int v=que.front();
            que.pop();
            rep(i,G[v].size())
            {
                int nx=G[v][i];
                if(!vis[nx])
                {
                    vis[nx]=1;
                    depth[nx]=depth[v]+1;
                    que.push(nx);
                }
            }
        }

        //legの計算
        rep(i,n)
        {
            int cur=0;
            rep(j,G[i].size()) cur=sum(cur,reach[G[i][j]]);

            rep(j,G[i].size())
            {
                leg[i]=sum(leg[i],mul(reach[G[i][j]],sum(cur,-reach[G[i][j]])));
                cur=sum(cur,-reach[G[i][j]]);
            }

            body[i]=leg[i];
        }

        //bodyの計算
        for(int i=n-1; i>0; --i)
        {
            body[parent[i-1]]=sum(body[parent[i-1]],body[i]);
        }

        int ret=0;
        for(int i=1; i<n; ++i)
        {
            int j=parent[i-1];
            int add=mul(depth[i]-1,mul(body[i],sum(leg[j],-mul(reach[i],reach[j]-1-reach[i]))));

            ret=sum(ret,add);
        }

        return ret;
    }
};

// CUT begin
ifstream data("TheTreeAndMan.sample");

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

bool do_test(vector<int> parent, int __expected) {
    time_t startClock = clock();
    TheTreeAndMan *instance = new TheTreeAndMan();
    int __result = instance->solve(parent);
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
        vector<int> parent;
        from_stream(parent);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(parent, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1461063448;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "TheTreeAndMan (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
