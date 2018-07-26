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

int ct[10]={};

const int N = 20;
map<vector<int>,ll> dp[N];

ll dfs(int d, const vector<int> &v){
    if(dp[d].count(v)) return dp[d][v];

    ll ret = 1;
    rep(i,10){
        if(ct[i]>0 && v[i]==0) ret = 0;
    }

    int l=0;
    if(d==0) l=1;
    for(int i=l; i<10; ++i)if(v[i]<ct[i]){
        vector<int> nv(v);
        ++nv[i];
        ret += dfs(d+1,nv);
    }

    return dp[d][v] = ret;
}

int main(){
    string s;
    cin >>s;
    rep(i,s.size()) ++ct[s[i]-'0'];

    vector<int> x(10);
    cout << dfs(0,x) << endl;
    return 0;
}
