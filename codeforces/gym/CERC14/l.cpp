#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define minch(x,y) x=min(x,y)

#define dbg(x) cout<<#x<<"="<<x<<endl
#define INF 1e16

typedef long long ll;

int main(){
    ll Te;
    cin>>Te;
    while(Te--){
        int N;
        cin>>N;
        vector<ll> a(N),b(N),d(N);
        vector<ll> ts,ds;
        rep(i,N){
            cin>>a[i]>>b[i]>>d[i];
            ts.push_back(a[i]-1); ts.push_back(b[i]+1);
            ts.push_back(a[i]); ts.push_back(b[i]); 
            ds.push_back(d[i]);
        }
        sort(all(ts)); unique(all(ts));
        sort(all(ds)); unique(all(ds));
        rep(i,N){
            a[i]=lower_bound(all(ts),a[i])-ts.begin();
            b[i]=lower_bound(all(ts),b[i])-ts.begin();
            d[i]=lower_bound(all(ds),d[i])-ds.begin();
        }
        int T=ts.size();
        int D=ds.size();
        vector<vector<ll> > dp(T+1,vector<ll>(T+1,INF));
        rep(l,T)dp[l][l]=0;
        repl(len,1,T)rep(l,T){
            int r=l+len;
            int idx=-1;
            rep(i,N){
                if(l<=a[i]&&b[i]<=r){
                    if(idx==-1||d[i]>d[idx]){
                        idx=i;
                    }
                }
            }
            if(idx==-1){
                dp[l][r]=0;
                continue;
            }
            repl(i,a[i],b[i]+1){
                dp[l][r]=
            }
        }
        cout<<dp[0][T-1]<<endl;
    }
    return 0;
}

