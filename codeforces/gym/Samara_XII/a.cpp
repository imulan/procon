#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<int> invalid(n+1);
    auto ok = [&](int idx){
        if(a[idx]>0){
            if(invalid[a[idx]]) return false;
        }
        else{
            ++invalid[-a[idx]];
        }
        return true;
    };

    int idx = 0;
    rep(i,n){
        while(idx<n && ok(idx)) ++idx;

        if(a[i]<0) --invalid[-a[i]];
        printf("%d%c", idx-i, " \n"[i==n-1]);
    }
    return 0;
}
