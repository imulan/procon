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

int query(int n){
    cout << n << endl;
    cout << flush;

    string s;
    cin >>s;

    if(s=="TOO_SMALL") return 0;
    if(s=="TOO_BIG") return 1;
    if(s=="CORRECT") return 2;
    if(s=="WRONG_ANSWER") return 3;
    return -1;
}

void solve(){
    int l,r,n;
    cin >>l >>r >>n;

    while(r-l>1){
        int m = (l+r)/2;

        int res = query(m);
        assert(res != -1);

        if(res == 0) l=m;
        else if(res == 1) r=m;
        else if(res == 2) return;
        else assert(false);
    }

    int f = query(r);
    assert(f==2);
}

int main(){
    int t;
    cin >>t;
    rep(_,t) solve();
    return 0;
}
