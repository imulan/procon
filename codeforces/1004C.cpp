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

using pi = pair<int,int>;

const int N = 100010;
int l[N],r[N];

int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    rep(i,N){
        l[i]=N;
        r[i]=-1;
    }

    rep(i,n){
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }

    priority_queue<int,vector<int>,greater<int>> L,R;
    rep(i,N){
        L.push(l[i]);
        R.push(r[i]);
    }

    ll ans = 0;
    while(!L.empty()){
        int v = L.top();
        L.pop();
        while(!R.empty() && v>=R.top()) R.pop();
        ans += R.size();
    }

    cout << ans << endl;
    return 0;
}
