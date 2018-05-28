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

const int N = 10000001;
const int M = 12;

short m[N];
bool ava[M][M]={};

int s[M];

// M個の結果をマージ
int R[N];

inline void READ_M(int n){
    char s[4];
    rep(i,n){
        scanf("%s", s);
        if(s[0]=='D'){
            if(s[2]=='#') m[i] = 1;
            else m[i] = 0;
        }
        else if(s[0]=='R'){
            if(s[2]=='#') m[i] = 3;
            else m[i] = 2;
        }
        else if(s[0]=='M'){
            m[i] = 4;
        }
        else if(s[0]=='F'){
            if(s[2]=='#') m[i] = 6;
            else m[i] = 5;
        }
        else if(s[0]=='S'){
            if(s[1]=='o'){
                if(s[3]=='#') m[i] = 8;
                else m[i] = 7;
            }
            else{
                m[i] = 11;
            }
        }
        else if(s[0]=='L'){
            if(s[2]=='#') m[i] = 10;
            else m[i] = 9;
        }
    }
}

int main(){
    int code[7]={0,2,4,5,7,9,11};
    rep(i,M)rep(j,7) ava[i][(i+code[j])%M] = true;

    int n;
    scanf(" %d", &n);
    READ_M(n);

    R[n] = n;
    rep(i,M){
        int r = n;
        for(int j=n-1; j>=0; --j){
            if(!ava[i][m[j]]) r = j;
            if(R[j]<r) R[j] = r;
        }
        s[i] = r;
    }

    int ans = n;
    rep(i,M){
        int x=s[i];
        if(x==0) continue;

        if(x==n){
            ans = 1;
            break;
        }

        int y = n-1;
        while(ava[i][m[y]]) --y;

        int ct = 1;
        int now = x;
        while(1){
            // unroll
            int nx = R[R[R[R[now]]]];
            if(nx>y) break;

            now = nx;
            ct+=4;
            if(ct>=ans) break;
        }
        if(ct>=ans) continue;

        while(now<=y){
            now = R[now];
            ++ct;
        }

        ans = min(ans, ct);
    }
    printf("%d\n", ans);
    return 0;
}
