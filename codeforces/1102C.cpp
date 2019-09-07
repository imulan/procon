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
    int n,x,y;
    scanf(" %d %d %d", &n, &x, &y);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int ans = n;
    if(x <= y){
        int ct = 0;
        for(int i:a) ct += (i<=x);
        ans = (ct+1)/2;
    }
    printf("%d\n", ans);
    return 0;
}
