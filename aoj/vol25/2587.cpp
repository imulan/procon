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

const int PW = 10;
int pw[PW];

const int INF = 19191919;

int n;
int l[6],r[6];
int A,B;

vector<bool> va,vb;
vector<bool> appear;
int END;
void dfs(int idx, int val){
    if(idx == END){
        appear[val] = true;
        return;
    }

    for(int i=l[idx]; i<=r[idx]; ++i){
        if(i<10) dfs(idx+1, val*10 + i);
        else dfs(idx+1, val*100 + i);
    }
}


const int N = 1000000;
int low_a[N][4], high_b[N][4], val_b[N][4];

int main(){
    pw[0] = 1;
    for(int i=1; i<PW; ++i) pw[i] = pw[i-1]*10;

    memset(low_a,-1,sizeof(low_a));
    for(int i=1; i<N; ++i){
        int tv = i;
        int tmp = 0;
        for(int j=1; j<=3; ++j){
            tmp += (tv%10) * pw[j-1];
            low_a[i][j] = tmp;
            tv /= 10;
            if(tv==0) break;
        }
    }

    memset(high_b,-1,sizeof(high_b));
    memset(val_b,-1,sizeof(val_b));
    for(int i=1; i<N; ++i){
        int tv = i;
        vector<int> vv;
        while(tv>0){
            vv.pb(tv%10);
            tv /= 10;
        }
        reverse(all(vv));
        int VV = vv.size();

        int tmp = 0;
        for(int j=1; j<=min(3,VV); ++j){
            tmp = tmp*10 + vv[j-1];
            high_b[i][j] = tmp;

            val_b[i][j] = 0;
            for(int k=j; k<VV; ++k) val_b[i][j] = 10*val_b[i][j] + vv[k];
        }
        val_b[i][0] = i;
    }

    while(scanf(" %d", &n),n){
        rep(i,n) scanf(" %d %d", &l[i], &r[i]);

        A = n/2;
        B = n-A;

        appear = vector<bool>(N,false);
        END = A;
        dfs(0,0);
        va = appear;

        appear = vector<bool>(N,false);
        END = A+B;
        dfs(A,0);
        vb = appear;

        ll ans = 0;
        for(int D=A+B; D<=2*(A+B); ++D){
            // printf(" ---- D  %d ----\n",D);
            int W = min(D-(A+B), 2*(A+B)-D);

            rep(i,pw[W]){
                unordered_map<int,int> ppa,ppb;

                // calc pata,patb
                vector<int> pata(W+1),patb(W+1);
                rep(j,W+1){
                    patb[j] = -1;
                    if(j>0){
                        patb[j] = i%pw[j];

                        // no leading zero
                        int tmp = patb[j];
                        rep(_,j-1) tmp /= 10;
                        if(tmp%10==0) patb[j] = -INF;
                    }

                    pata[j] = -1;
                    if(j<W) pata[j] = i/pw[j];
                }

                int DB = B-1;
                int DA = D-DB;
                while(DA>2*A+1){
                    ++DB;
                    --DA;
                }

                rep(j,W+1){
                    ++DB;
                    --DA;
                    if(patb[j] == -INF) continue;
                    // printf("CHECK (%d %d)  DA DB ( %d %d )  pat ( %d %d )\n",i,j,DA,DB,pata[j],patb[j]);
                    // printf(" ?? %d digits,  %d digits \n", DA-(W-j), DB - j);

                    for(int k=pw[DA-(W-j)-1]; k<pw[DA-(W-j)]; ++k){
                        int num =  k*pw[W-j];
                        if(pata[j]>=0) num += pata[j];
                        if(!va[num]) continue;

                        // 下から W-j 桁
                        if(pata[j]<0 || (pata[j] == low_a[num][W-j])){
                            int val = num;
                            if(j<W) val /= pw[W-j];
                            // printf(" ! MATCH  A ! %d ,  val %d\n", num,val);
                            ppa[val] |= (1<<j);
                        }
                    }

                    int st = pw[DB-j-1];
                    if(st==1 || patb[j]>=0) st = 0;
                    for(int k=st; k<pw[DB-j]; ++k){
                        int num = k;
                        if(patb[j]>=0) num += patb[j]*pw[DB-j];
                        if(!vb[num]) continue;

                        // 上から j 桁
                        if(patb[j]<0 || (patb[j] == high_b[num][j])){
                            // printf(" ! MATCH  B ! %d ,  val %d\n", num,val_b[num][j]);
                            ppb[val_b[num][j]] |= (1<<j);
                        }
                    }
                }

                if(!ppa.empty() && !ppb.empty()){
                    vector<ll> cta(1<<(W+1)), ctb(1<<(W+1));
                    for(const auto &p:ppa) ++cta[p.se];
                    for(const auto &p:ppb) ++ctb[p.se];

                    // 高速ゼータ変換
                    rep(ii,W+1){
                        rep(jj,1<<(W+1)){
                            if((jj>>ii&1) == 0){
                                cta[jj] += cta[jj|(1<<ii)];
                                ctb[jj] += ctb[jj|(1<<ii)];
                            }
                        }
                    }

                    // 包除原理で数える
                    for(int j=1; j<(1<<(W+1)); ++j){
                        if(__builtin_popcount(j)%2==1) ans += cta[j]*ctb[j];
                        else ans -= cta[j]*ctb[j];
                    }
                }
            }
            // dbg(ans);
        }

        printf("%lld\n", ans);
    }
    return 0;
}
