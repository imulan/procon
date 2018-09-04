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
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;

struct edge{ int to,cost; };

const ll INF = LLONG_MAX/3;
const int N = 50;
ll d[N][N];
vector<edge> ug[N], rg[N];

int main(){
    int n,m;
    while(cin >>n >>m,n){
        rep(i,N){
            ug[i].clear();
            rg[i].clear();
        }

        vector<int> fee(n),h(n);
        for(int i=1; i<n-1; ++i) cin >>fee[i] >>h[i];
        h[0] = 1;
        h[n-1] = 1000;

        vector<int> a(m),b(m),c(m);
        rep(i,m){
            cin >>a[i] >>b[i] >>c[i];
            --a[i];
            --b[i];
            if(h[a[i]]<=h[b[i]]) ug[a[i]].pb({b[i],c[i]});
            if(h[a[i]]>=h[b[i]]) rg[b[i]].pb({a[i],c[i]});
        }

        vector<int> height;
        rep(i,n) height.pb(h[i]);
        sort(all(height));
        height.erase(unique(all(height)), height.end());

        int H = height.size();
        rep(i,n) h[i] = lower_bound(all(height), h[i]) - height.begin();

        vvi town(H);
        rep(i,n) town[h[i]].pb(i);

        vector<int> idx(n);
        vector<vvi> UD(H),RD(H);
        vector<vvvvi> MD(H);

        rep(hh,H){
            vi t = town[hh];
            int T = t.size();
            rep(j,T) idx[t[j]] = j;

            const int inf = 19191919;
            vvi uu(T,vi(T,inf)), rr(T,vi(T,inf));
            vvvvi mm(T,vvvi(T,vvi(T,vi(T,inf))));

            rep(mask,1<<T){
                int FEE = 0;
                rep(i,T)if(mask>>i&1) FEE += fee[t[i]];

                vvi tu(T,vi(T,inf)), tr(T,vi(T,inf));
                rep(i,T)if(mask>>i&1){
                    tu[i][i] = 0;
                    tr[i][i] = 0;

                    for(const auto &e:ug[t[i]]){
                        if(hh==h[e.to] && (mask>>idx[e.to]&1)) tu[i][idx[e.to]] = e.cost;
                    }
                    for(const auto &e:rg[t[i]]){
                        if(hh==h[e.to] && (mask>>idx[e.to]&1)) tr[i][idx[e.to]] = e.cost;
                    }
                }

                rep(k,T)rep(i,T)rep(j,T){
                    tu[i][j] = min(tu[i][j], tu[i][k]+tu[k][j]);
                    tr[i][j] = min(tr[i][j], tr[i][k]+tr[k][j]);
                }

                rep(i,T)rep(j,T){
                    uu[i][j] = min(uu[i][j], tu[i][j]+FEE);
                    rr[i][j] = min(rr[i][j], tr[i][j]+FEE);
                }
                rep(i,T)rep(ii,T)rep(j,T)rep(jj,T){
                    mm[i][ii][j][jj] = min(mm[i][ii][j][jj], tu[i][ii]+tr[j][jj]+FEE);
                }
            }

            UD[hh] = uu;
            RD[hh] = rr;
            MD[hh] = mm;
        }

        fill(d[0],d[N],INF);
        d[0][0] = 0;
        queue<pi> que;
        que.push({0,0});
        while(!que.empty()){
            pi now = que.front();
            que.pop();
            int go = now.fi, ret = now.se;
            ll D = d[go][ret];
            int eg = h[go], er = h[ret];
            if(eg<er){
                for(int ng:town[eg])for(const auto &e:ug[ng]){
                    if(eg<h[e.to] && d[e.to][ret] > D+e.cost+UD[eg][idx[go]][idx[ng]]){
                        d[e.to][ret] = D+e.cost+UD[eg][idx[go]][idx[ng]];
                        que.push({e.to,ret});
                    }
                }
            }
            else if(eg>er){
                for(int nr:town[er])for(const auto &e:rg[nr]){
                    if(er<h[e.to] && d[go][e.to] > D+e.cost+RD[er][idx[ret]][idx[nr]]){
                        d[go][e.to] = D+e.cost+RD[er][idx[ret]][idx[nr]];
                        que.push({go,e.to});
                    }
                }
            }
            else{
                for(int ng:town[eg])for(const auto &ue:ug[ng]){
                    for(int nr:town[er])for(const auto &re:rg[nr]){
                        if(eg<h[ue.to] && er<h[re.to] && d[ue.to][re.to] > D+ue.cost+re.cost+MD[eg][idx[go]][idx[ng]][idx[ret]][idx[nr]]){
                            d[ue.to][re.to] = D+ue.cost+re.cost+MD[eg][idx[go]][idx[ng]][idx[ret]][idx[nr]];
                            que.push({ue.to,re.to});
                        }
                    }
                }
            }
        }

        ll ans = d[n-1][n-1];
        if(ans==INF) ans = -1;
        cout << ans << endl;
    }
    return 0;
}
