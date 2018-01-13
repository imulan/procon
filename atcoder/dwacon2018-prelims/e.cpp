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

const int N = 2020;
vector<int> G[N];

int query(int u, int v){
    printf("? %d %d\n",u,v);
    cout << flush;
    int ret;
    cin >> ret;
    return ret;
}

int main(){
    int n,q;
    cin >>n >>q;

    rep(i,n-1){
        int a,b;
        cin >>a >>b;
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    int start = 0;
    while(G[start].size()!=1) ++start;

    int now = start;
    vector<int> v;
    vector<bool> vis(n);
    while(v.size()!=n){
        v.pb(now);
        vis[now] = true;
        for(int e:G[now])if(!vis[e]) now = e;
    }

    int x=0, y=n-1;
    int ans = -1;
    while(y-x>1){
        int mid = (x+y)/2;

        int a = query(v[x]+1,v[y]+1);
        if(a==0){
            ans = v[mid]+1;
            break;
        }
        else if(a==v[x]+1){
            y = mid;
            if((y-x)%2==1) ++y;
        }
        else x = mid;
    }

    if(ans<0){
        int a = query(v[x]+1,v[y]+1);
        if(a==v[x]+1) ans = v[x]+1;
        else ans = v[y]+1;
    }

    printf("! %d\n",ans);
    cout << flush;
    return 0;
}
