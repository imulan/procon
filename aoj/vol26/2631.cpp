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

int n;
int a[5];
ll ans;

int s[5][4];
bool t[20][20]={};

void dfs(int d, int idx, int row, int v){
    if(d==n){
        // ok
        ll mx = 0;
        rep(i,n)rep(j,min(4,a[i])) mx = max(mx,(ll)s[i][j]);
        ++mx;
        rep(i,n){
            if(a[i]>4) mx += a[i]-4;
        }

        // if(mx == 11){
        //     rep(i,n){
        //         rep(j,min(4,a[i]))printf(" %d", s[i][j]);
        //         printf("\n");
        //     }
        // }
        ans = min(ans, mx);
        return;
    }

    int sz = min(4,a[d]);

    int nd = d;
    int nidx = idx+1;
    int nrow = row;
    if(idx == sz-1){
        nd = d+1;
        nidx = 0;
        nrow = 0;
    }

    if(row<d){
        rep(i,min(4,a[row])){
            s[d][idx] = s[row][i];

            bool ok = true;
            rep(j,idx){
                if(s[d][j] == s[d][idx] || t[s[d][j]][s[d][idx]]){
                    ok = false;
                }
            }

            if(ok){
                rep(j,idx){
                    t[s[d][j]][s[d][idx]] = t[s[d][idx]][s[d][j]] = true;
                }

                nrow = row+1;
                if(nidx == 0) nrow = 0;
                dfs(nd,nidx,nrow,v);

                rep(j,idx){
                    t[s[d][j]][s[d][idx]] = t[s[d][idx]][s[d][j]] = false;
                }
            }
            s[d][idx] = -1;
        }

        dfs(d,idx,row+1,v);
    }

    s[d][idx] = v;
    rep(i,idx) t[s[d][i]][s[d][idx]] = t[s[d][idx]][s[d][i]] = true;
    if(idx != sz-1) nrow = nd;
    dfs(nd,nidx,nrow,v+1);
    rep(i,idx) t[s[d][i]][s[d][idx]] = t[s[d][idx]][s[d][i]] = false;
    s[d][idx] = -1;
}

int main(){
    cin >>n;

    ans = 0;
    rep(i,n){
        cin >>a[i];
        ans += a[i];
    }
    sort(a,a+n);

    memset(s,-1,sizeof(s));
    dfs(0,0,0,0);

    cout << ans << endl;
    return 0;
}
