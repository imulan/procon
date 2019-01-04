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

const int INF = 19191919;

int n,m;
int c[10];

int ans = INF;
string x = "?";

string t;
void dfs(int d, int r){
    if(d == n){
        int v = atoi(t.c_str());
        if(v < ans){
            ans = v;
            x = t;
        }
        return;
    }

    rep(i,10)if(r-c[i]>=0){
        t[d] = '0'+i;
        dfs(d+1, r-c[i]);
        t[d] = '9';
    }
}

int main(){
    cin >>n >>m;
    rep(i,10) cin >>c[i];

    ans = INF;
    t = string(n,'9');
    dfs(0,m);

    if(ans == INF) cout << "NA" << endl;
    else cout << x << endl;
    return 0;
}
