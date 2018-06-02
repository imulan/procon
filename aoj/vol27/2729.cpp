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

int main(){
    int n;
    cin >>n;

    vector<char> d(n);
    vector<int> L(n);
    rep(i,n) cin >>d[i] >>L[i];

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    rep(i,n)if(d[i]=='y') pq.push({L[i],i});

    int ans = 0;
    vector<bool> erased(n);
    while(!pq.empty()){
        pi p = pq.top();
        pq.pop();

        int len = p.fi;
        int idx = p.se;
        if(erased[idx]) continue;

        ++ans;
        int l = idx, r = idx;
        while( l>=0 && (d[l]=='y' || (d[l]=='n'&& L[l]<len)) ) --l;
        while( r<n && (d[r]=='y' || (d[r]=='n'&& L[r]<len)) ) ++r;

        for(int i=l+1; i<r; ++i) erased[i] = true;
    }
    cout << ans << endl;
    return 0;
}
