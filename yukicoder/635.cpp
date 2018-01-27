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

const double LIM = 20000;

int x[3],y[3];
bool solve(){
    if(x[0]==x[2] && y[0]==y[2]) return false;

    double l=0, r=LIM;
    bool ok = true;
    for(int i:{0,2}){
        if(y[i]==y[1]) ok &= (x[1]-x[i]>0);
        else{
            double dy = y[i]-y[1];
            if(dy>0) r = min(r,(x[1]-x[i])/dy);
            else l = max(l,(x[1]-x[i])/dy);
        }
    }
    if(ok && l<r) return true;

    l=0;
    r=LIM;
    ok = true;
    for(int i:{0,2}){
        if(y[i]==y[1]) ok &= (x[1]-x[i]<0);
        else{
            double dy = y[i]-y[1];
            if(dy>0) l = max(l,(x[1]-x[i])/dy);
            else r = min(r,(x[1]-x[i])/dy);
        }
    }
    if(ok && l<r) return true;
    return false;
}

int main(){
    int n;
    scanf(" %d", &n);
    while(n--){
        rep(i,3) scanf(" %d", &x[i]);
        rep(i,3) scanf(" %d", &y[i]);

        if(solve()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
