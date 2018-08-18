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
    int n,k;
    cin >>n >>k;
    vector<int> p(n);
    rep(i,n) cin >>p[i];

    const int N = 256;
    vector<int> g(N,-1);

    rep(i,n){
        if(g[p[i]]==-1){
            for(int j=k-1; j>=0; --j){
                int idx = p[i]-j;
                if(idx<0) continue;

                int start = idx;
                for(int x=idx; x<=p[i]; ++x){
                    if(g[x]!=-1) start = min(start, g[x]);
                }

                if(p[i] - start + 1 <=k){
                    for(int x=idx; x<=p[i]; ++x) g[x] = start;
                    break;
                }
            }
        }
    }

    rep(i,n) cout << g[p[i]] << " \n"[i==n-1];
    return 0;
}
