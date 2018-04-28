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

const int B = 450;

// 現在の状態
int s[B][B] = {};

int F[B];
int T[B];
bool bad[B]={};

void push(int bid){
    if(bad[bid]){
        rep(i,B) s[bid][i] = -1;
        return;
    }
    if(F[bid] == -1) return;

    rep(i,B){
        if(s[bid][i] == F[bid]) s[bid][i] = T[bid];
        else s[bid][i] = -1;
    }

    F[bid] = -1;
    T[bid] = -1;
}

void D(int l, int r, int x){
    int lid = l/B, rid = r/B;
    if(lid == rid){
        push(lid);
        for(int i=l; i<=r; ++i){
            if(s[i/B][i%B] == x-1) s[i/B][i%B] = x;
            else s[i/B][i%B] = -1;
        }
    }
    else{
        push(lid);
        push(rid);

        for(int i=l; i<B*(lid+1); ++i){
            if(s[i/B][i%B] == x-1) s[i/B][i%B] = x;
            else s[i/B][i%B] = -1;
        }

        for(int bid=lid+1; bid<rid; ++bid){
            if(F[bid] == -1){
                F[bid] = x-1;
                T[bid] = x;
            }
            else{
                if(T[bid] == x-1) T[bid] = x;
                else bad[bid] = true;
            }
        }

        for(int i=B*rid; i<=r; ++i){
            if(s[i/B][i%B] == x-1) s[i/B][i%B] = x;
            else s[i/B][i%B] = -1;
        }
    }
}

int main(){
    int n,k,t;
    scanf(" %d %d %d", &n, &k, &t);

    fill(F,F+B,-1);
    fill(T,T+B,-1);
    rep(i,t){
        int l,r,x;
        scanf(" %d %d %d", &l, &r, &x);
        --l;
        --r;
        D(l,r,x);
    }

    rep(i,B) push(i);

    int ans = 0;
    rep(i,n) ans += (s[i/B][i%B] == k);
    printf("%d\n", ans);
    return 0;
}
