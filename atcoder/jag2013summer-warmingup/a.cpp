#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int i=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x<<"="<<x<<endl
#define fi first
#define se second


typedef pair<int,int> P;

int N,M;
vector<P> ps;
int nxt[1000010][21];
int l[100010],r[100010];
vector<int> ds;

int main(){
    memset(nxt,-1,sizeof(nxt));
    cin>>N>>M;
    rep(i,N){
        cin>>l[i]>>r[i];
        ds.push_back(l[i]);
        ds.push_back(r[i]);
    }
    ds.push_back(M);
    sort(all(ds));
    ds.erase(unique(all(ds)), ds.end());
    M=lower_bound(all(ds),M)-ds.begin();
    rep(i,N){
        l[i]=lower_bound(all(ds),l[i])-ds.begin();
        r[i]=lower_bound(all(ds),r[i])-ds.begin();
        if(l[i]>r[i]){
            r[i]+=M;
        }
        ps.push_back(P(l[i],r[i]));
        ps.push_back(P(l[i]+M,r[i]+M));
    }
    sort(all(ps),[=](const P& a,const P& b){ return a.fi > b.fi; });

    {
        set<int> st;
        int i = 0;
        for (int j = M * 2 - 1; j >= 0; j--) {
            while (i<(int)ps.size()&&ps[i].fi == j) {
                st.insert(ps[i].se);
                i++;
            }
            if (st.size() == 0) nxt[j][0] = -1;
            else nxt[j][0] = *st.begin();
        }
    }

    rep(k,20){
        rep(i,M*2){
            if(nxt[i][k]==-1)nxt[i][k+1]=-1;
            else nxt[i][k+1]=nxt[nxt[i][k]][k];
        }
    }

    int res=1;
    rep(i,N*2){
        int a=ps[i].fi,b=ps[i].se;
        if(b>=2*M)continue;
        int lb=0,ub=N;
        while(ub-lb>1){
            int X=(ub+lb)/2;
            int idx=b;
            rep(k,21){
                if((X>>k)&1){
                    idx=nxt[idx][k];
                    if(idx==-1)break;
                }
            }
            if(idx!=-1&&idx<=a+M) lb=X;
            else ub=X;
        }
        res=max(res,lb+1);
    }
    cout<<res<<endl;

    return 0;
}
