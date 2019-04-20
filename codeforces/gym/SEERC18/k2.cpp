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

#define X first
#define Y second

using P = pair<int,int>;
using R = pair<P,P>;

int main(){
    int q;
    scanf(" %d", &q);

    vector<int> t(q);
    vector<R> a(q);
    vector<int> ux;
    rep(i,q){
        scanf(" %d", &t[i]);

        scanf(" %d %d", &a[i].fi.X, &a[i].fi.Y);
        ux.pb(a[i].fi.X);
        if(t[i]==2){
            scanf(" %d %d", &a[i].se.X, &a[i].se.Y);
            ux.pb(a[i].se.X);
        }
    }




    return 0;
}
