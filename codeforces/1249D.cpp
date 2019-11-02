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

const int N = 200000;

using pi = pair<int,int>;

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<int> s(N+1);
    vector<vector<pi>> L(N);
    rep(i,n){
        int l,r;
        scanf(" %d %d", &l, &r);
        --l;
        --r;

        ++s[l];
        --s[r+1];
        L[l].pb({r,i});
    }

    rep(i,N) s[i+1] += s[i];

    int m = 0;
    priority_queue<pi> pq;
    vector<int> ans;
    vector<int> R(N);
    rep(i,N){
        for(const auto &p:L[i]) pq.push(p);

        while(s[i]-m > k){
            pi p = pq.top();
            pq.pop();

            ans.pb(p.se+1);
            ++R[p.fi];
            ++m;
        }

        m -= R[i];
    }

    int A = ans.size();
    printf("%d\n", A);
    rep(i,A) printf("%d%c", ans[i], " \n"[i==A-1]);
    return 0;
}
