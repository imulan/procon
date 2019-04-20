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
    int v,e;
    while(cin >>v >>e){
        vector<int> s(v);
        rep(i,v) scanf(" %d", &s[i]);

        vector<int> a(e),b(e);
        vector<vector<bool>> E(v,vector<bool>(v));
        rep(i,e){
            scanf(" %d %d", &a[i], &b[i]);
            --a[i];
            --b[i];
            E[a[i]][b[i]] = E[b[i]][a[i]] = true;
        }

        int ans = 0;
        rep(i,e) ans = max(ans, s[a[i]]+s[b[i]]);

        vector<bool> use(v);

        rep(i,e)rep(j,i){
            int tmp = 0;
            vector<int> vv;
            for(int x:vector<int>({a[i],b[i],a[j],b[j]})){
                if(!use[x]){
                    vv.pb(x);
                    tmp += s[x];
                    use[x] = true;
                }
            }

            int V = vv.size();
            bool ok = true;
            rep(ii,V)rep(jj,ii){
                ok &= E[vv[ii]][vv[jj]];
            }

            if(ok) ans = max(ans, tmp);
            for(int x:vv) use[x] = false;
        }

        printf("%d\n", ans);
    }
    return 0;
}
