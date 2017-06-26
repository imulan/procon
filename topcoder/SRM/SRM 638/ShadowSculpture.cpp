#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const string OK="Possible", NG="Impossible";

struct Point{ int x,y,z; };

class ShadowSculpture {
    public:
    string possible(vector<string> XY, vector<string> YZ, vector<string> ZX) {
        int n = XY.size();

        int f[10][10][10]={};
        rep(i,n)rep(j,n)rep(k,n) f[i][j][k]=1;

        rep(i,n)rep(j,n)
        {
            if(XY[i][j]=='N') rep(k,n) f[i][j][k]=0;
            if(YZ[i][j]=='N') rep(k,n) f[k][i][j]=0;
            if(ZX[i][j]=='N') rep(k,n) f[j][k][i]=0;
        }

        rep(i,n)rep(j,n)
        {
            int ct;
            if(XY[i][j]=='Y')
            {
                ct=0;
                rep(k,n) ct+=f[i][j][k];
                if(!ct) return NG;
            }
            if(YZ[i][j]=='Y')
            {
                ct=0;
                rep(k,n) ct+=f[k][i][j];
                if(!ct) return NG;
            }
            if(ZX[i][j]=='Y')
            {
                ct=0;
                rep(k,n) ct+=f[j][k][i];
                if(!ct) return NG;
            }
        }

        bool all_zero=true;
        rep(i,n)rep(j,n)rep(k,n) all_zero&=(f[i][j][k]==0);
        if(all_zero) return OK;

        #define IN(x,y,z) (0<=x && x<n && 0<=y && y<n && 0<=z && z<n)
        int dx[6]={1,-1,0,0,0,0};
        int dy[6]={0,0,1,-1,0,0};
        int dz[6]={0,0,0,0,1,-1};
        int vis[10][10][10]={};

        rep(ii,n)rep(jj,n)rep(kk,n)
        {
            if(vis[ii][jj][kk]==1 || f[ii][jj][kk]==0) continue;

            vis[ii][jj][kk]=2;
            queue<Point> que;
            que.push({ii,jj,kk});
            while(!que.empty())
            {
                Point p = que.front();
                que.pop();
                rep(d,6)
                {
                    int nx=p.x+dx[d], ny=p.y+dy[d], nz=p.z+dz[d];
                    if(IN(nx,ny,nz) && f[nx][ny][nz] && !vis[nx][ny][nz])
                    {
                        vis[nx][ny][nz]=2;
                        que.push({nx,ny,nz});
                    }
                }
            }

            // check
            bool ok = true;
            rep(i,n)rep(j,n)
            {
                int ct;
                if(XY[i][j]=='Y')
                {
                    ct=0;
                    rep(k,n) ct+=(vis[i][j][k]==2);
                    if(!ct) ok=false;
                }
                if(YZ[i][j]=='Y')
                {
                    ct=0;
                    rep(k,n) ct+=(vis[k][i][j]==2);
                    if(!ct) ok=false;
                }
                if(ZX[i][j]=='Y')
                {
                    ct=0;
                    rep(k,n) ct+=(vis[j][k][i]==2);
                    if(!ct) ok=false;
                }
            }
            if(ok) return OK;
            
            // uodate
            rep(i,n)rep(j,n)rep(k,n)if(vis[i][j][k]==2) vis[i][j][k]=1;
        }

        return NG;
    }
};

// CUT begin
ifstream data("ShadowSculpture.sample");

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

bool do_test(vector<string> XY, vector<string> YZ, vector<string> ZX, string __expected) {
    time_t startClock = clock();
    ShadowSculpture *instance = new ShadowSculpture();
    string __result = instance->possible(XY, YZ, ZX);
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
        vector<string> XY;
        from_stream(XY);
        vector<string> YZ;
        from_stream(YZ);
        vector<string> ZX;
        from_stream(ZX);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(XY, YZ, ZX, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1498484766;
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
        cout << "ShadowSculpture (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
