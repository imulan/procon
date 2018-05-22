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

vector<string> split(const string &str, char sep){
    vector<string> v;
    stringstream ss(str + sep);
    string buffer;
    while( getline(ss,buffer,sep ) ) v.pb(buffer);
    return v;
}

int Na,Nt,Ng,Nc;
int m;

const int N = 52;
const ll mod = 1e9+7;

vector<string> x;
int X;

ll dp[N][N][N][N];
ll dfs(int a, int t, int g, int c){
    if(a>Na || t>Nt || g>Ng || c>Nc) return 0;

    int idx = a+t+g+c;
    if(idx == X){
        return (a==Na && t==Nt && g==Ng && c==Nc);
    }

    if(dp[a][t][g][c]>=0) return dp[a][t][g][c];

    string f = x[idx];
    ll ret = 0;
    rep(i,f.size()){
        if(f[i]=='A') ret += dfs(a+1,t,g,c);
        else if(f[i]=='T') ret += dfs(a,t+1,g,c);
        else if(f[i]=='G') ret += dfs(a,t,g+1,c);
        else if(f[i]=='C') ret += dfs(a,t,g,c+1);
        ret %= mod;
    }
    return dp[a][t][g][c] = ret;
}

int main(){
    cin >>Na >>Nt >>Ng >>Nc >>m;
    cin.ignore();

    map<string,int> t2id;
    vector<vector<string>> v(m);
    rep(i,m){
        string s;
        getline(cin,s);
        vector<string> vs = split(s, ' ');

        string t = vs[0];
        t = t.substr(0,t.size()-1);
        t2id[t] = i;

        for(int j=1; j<vs.size(); ++j) v[i].pb(vs[j]);
    }

    // precalc for length
    vector<ll> L(m);
    for(int i=m-1; i>=0; --i){
        rep(j,v[i].size()){
            if(v[i][j][0]=='[') ++L[i];
            else{
                int idx = t2id[v[i][j]];
                L[i] += L[idx];
            }
        }
    }

    // Over Length
    if(L[0] > Na+Nt+Ng+Nc){
        cout << 0 << endl;
        return 0;
    }

    // calc DP
    for(int i=m-1; i>=0; --i){
        vector<string> new_v;
        rep(j,v[i].size()){
            if(v[i][j][0]=='[') new_v.pb(v[i][j].substr());
            else{
                int idx = t2id[v[i][j]];
                for(string a:v[idx]) new_v.pb(a);
            }
        }
        v[i] = new_v;
    }

    x = v[0];
    X = x.size();
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0,0,0) << endl;
    return 0;
}
