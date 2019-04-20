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

const int INF = 19191919;

void solve(){
    int S;
    cin >>S;

    vector<int> D(S),A(S),B(S);
    rep(i,S) cin >>D[i] >>A[i] >>B[i];

    int y=0,z=0;

    rep(i,S)for(int j=i; j<S; ++j){
        int L = j-i+1;
        if(L<=2){
            if(L>y){
                y = L;
                z = 1;
            }
            else if(L==y) ++z;
            continue;
        }

        // L>=3
        bool valid = false;

        for(int k=i; k<=j; ++k){
            int M = D[k]+A[k];

            bool ok = true;
            int N = INF;
            for(int l=i; l<=j; ++l){
                int mm = D[l]+A[l];
                if(mm != M){
                    int nn = D[l]-B[l];
                    if(N == INF) N = nn;
                    else{
                        if(N != nn){
                            ok = false;
                            break;
                        }
                    }
                }
            }

            if(ok){
                valid = true;
                break;
            }
        }

        if(valid){
            if(L>y){
                y = L;
                z = 1;
            }
            else if(L==y) ++z;
        }
    }

    printf("%d %d\n",y,z);
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
