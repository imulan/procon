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

using vi = vector<int>;

void solve(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<vi> student(n);
    vi correct(n);
    rep(i,n){
        vi v(m);
        rep(j,m){
            char c;
            scanf(" %c", &c);
            v[j] = c-'0';
        }
        student[i] = v;

        scanf(" %d", &correct[i]);
    }

    if(m==1){
        vector<int> cand;
        rep(i,2){
            bool ok = true;
            rep(j,n){
                if(student[j][0] == i){
                    if(correct[j] == 0) ok = false;
                }
                else{
                    if(correct[j] == 1) ok = false;
                }
            }
            if(ok) cand.pb(i);
        }

        int C = cand.size();
        if(C==1) printf("%d\n", cand[0]);
        else printf("%d solutions\n", C);
        return;
    }

    int B = m/2, A = m-B;
    map<vi,vi> f;
    rep(mask,1<<A){
        vi v(A);
        rep(i,A) v[i] = (mask>>i&1);

        vector<int> num_correct(n);
        rep(i,n){
            rep(j,A) num_correct[i] += (student[i][j] == v[j]);
        }

        f[num_correct].pb(mask);
    }

    int ans = 0;
    vi sol(m);

    rep(mask,1<<B){
        vi v(B);
        rep(i,B) v[i] = (mask>>i&1);

        vector<int> num_correct(n);
        rep(i,n){
            rep(j,B) num_correct[i] += (student[i][A+j] == v[j]);
        }

        vector<int> key(n);
        rep(i,n) key[i] = correct[i] - num_correct[i];
        if(f.count(key)){
            ans += f[key].size();

            if(ans == 1){
                int mask_A = f[key][0];
                rep(i,A) sol[i] = (mask_A>>i&1);
                rep(i,B) sol[A+i] = v[i];
            }
        }
    }

    if(ans == 1){
        rep(i,m) printf("%d", sol[i]);
        printf("\n");
    }
    else{
        printf("%d solutions\n", ans);
    }
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
