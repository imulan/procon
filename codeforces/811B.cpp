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

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> p(n);
    rep(i,n) cin >>p[i];

    while(m--){
        int l,r,x;
        scanf(" %d %d %d", &l ,&r, &x);
        --l; --r; --x;

        int val = p[x];
        int ct = 0;
        for(int i=l; i<=r; ++i) ct += (p[i]<=val);
        printf("%s\n", (ct==x-l+1?"Yes":"No"));
    }
    return 0;
}
