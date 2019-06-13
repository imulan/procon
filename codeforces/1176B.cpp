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

int solve(){
    int n;
    scanf(" %d", &n);

    int ct[3]={};
    rep(i,n){
        int a;
        scanf(" %d",&a);
        ++ct[a%3];
    }

    while(ct[1]>0 && ct[2]>0){
        --ct[1];
        --ct[2];
        ++ct[0];
    }

    return ct[0] + ct[1]/3 + ct[2]/3;
}

int main(){
    int t;
    scanf(" %d", &t);
    while(t--) printf("%d\n", solve());
    return 0;
}
