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
    int n;
    cin >>n;

    vector<int> q[33];
    rep(i,n){
        int a,b;
        cin >>a >>b;
        q[a].pb(b);
    }

    priority_queue<int,vector<int>,greater<int>> pq;
    int ans = 0;
    for(int i=1; i<=31; ++i){
        for(int e:q[i]) pq.push(e);

        while(!pq.empty() && pq.top()<i) pq.pop();

        if(!pq.empty()){

            ans += 2;
            pq.pop();
        }
        else ++ans;
    }

    cout << ans*50 << endl;
    return 0;
}
