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
    int w,h;
    cin >>w >>h;

    vector<int> a(w), b(h);
    rep(i,w) cin >>a[i];
    rep(i,h) cin >>b[i];

    priority_queue<int> pq;
    rep(i,w){
        if(a[i]>0) pq.push(a[i]);
    }

    sort(all(b), greater<int>());
    rep(i,h){
        vector<int> x;
        rep(j,b[i]){
            if(pq.empty()) return 0;
            int v = pq.top();
            pq.pop();
            x.pb(v-1);
        }

        for(int j:x) if(j>0) pq.push(j);
    }
    return 1;
}

int main(){
    cout << solve() << endl;
    return 0;
}
