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

string solve(){
    int h,w;
    cin >>h >>w;

    int a[2],b[2];
    rep(i,2) cin >>a[i] >>b[i];

    rep(i,2){
        rep(j,2){
            if(a[0]+a[1]<=h){
                if(max(b[0],b[1])<=w) return "YES";
            }
            if(b[0]+b[1]<=w){
                if(max(a[0],a[1])<=h) return "YES";
            }

            swap(a[1],b[1]);
        }
        swap(a[0],b[0]);
    }
    return "NO";
}

int main(){
    cout << solve() << "\n";
    return 0;
}
