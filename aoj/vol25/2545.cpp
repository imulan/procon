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

int n,x,m;
int l[10],r[10],s[10];

bool valid = false;
int ans[6];

void dfs(int d){
    if(d==n){
        bool ok = true;
        rep(i,m){
            int t = 0;
            for(int j=l[i]; j<=r[i]; ++j) t += ans[j];
            if(s[i] != t) ok = false;
        }
        if(ok) valid = true;
        return;
    }

    rep(i,x+1){
        ans[d] = i;
        dfs(d+1);
        if(valid) return;
    }
}

int main(){
    cin >>n >>x >>m;
    rep(i,m){
        cin >>l[i] >>r[i] >>s[i];
        --l[i];
        --r[i];
    }

    dfs(0);

    if(valid) rep(i,n) printf("%d%c", ans[i], " \n"[i==n-1]);
    else printf("-1\n");
    return 0;
}
