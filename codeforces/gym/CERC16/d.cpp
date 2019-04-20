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

const int INF = 123456;

struct State{
    int r,c;

    stack<int> st;
    // [mn,mx]の値を管理している
    int mn,mx;

    State(){
        mn = INF;
        mx = 0;
    }

    void PUSH(int v){
        st.push(v);
        mn = min(mn, v);
        mx = max(mx, v);
    }
};

int main(){
    vector<vector<int>> f(7,vector<int>(7));
    f[1][1] = 1;
    f[1][2] = f[2][1] = 2;
    for(int i=1; i<=6; ++i)for(int j=1; j<=6; ++j){
        if(f[i][j] != 0) continue;

        for(int r=1; r<=i; ++r)for(int c=1; c<=j; ++c){
            if(r==i && c==j) continue;
            f[i][j] += f[r][c];
        }
    }

    int n;
    scanf(" %d", &n);

    State ini;
    ini.r = ini.c = 6;
    rep(i,n){
        int d;
        scanf(" %d", &d);
        ini.PUSH(d);
    }

    vector<pi> mv(n+1);

    stack<State> st_st;
    st_st.push(ini);
    while(!st_st.empty()){
        State now = st_st.top();
        st_st.pop();

        int R = now.r, C = now.c;
        stack<int> s = now.st;
        int l = now.mn, r = now.mx;

        if(R==1 && C==1) continue;

        int posr = 7-R, posc = 7-C;

        if( (R==1&&C==2) || (R==2&&C==1) ){
            char dir = 'D';
            if(R==1) dir = 'R';

            int rem = r-l+1;

            if(rem == 2){ // 2個の場合は特殊な処理
                if(s.top() == l){ // 上が小さい方なので、2個一気に移動
                    printf("%d %d %c 2\n", posr, posc, dir);
                }
                else{ // 上が大きい方なので、1個ずつ移動
                    rep(i,2) printf("%d %d %c 1\n", posr, posc, dir);
                }
            }
            else{
                assert(rem == 1);
                printf("%d %d %c 1\n", posr, posc, dir);
            }
            continue;
        }

        // 各値の行き先を決定
        // ゴールに近い方から、大きい値を割り当てていく
        vector<vector<int>> cap(f);
        int nr = 1, nc = 1;
        for(int i=r; i>=l; --i){
            mv[i] = {nr,nc};
            --cap[nr][nc];

            if(cap[nr][nc] == 0){
                ++nc;
                if(nc==C+1){
                    nc = 1;
                    ++nr;
                }
            }
        }

        State nx[7][7];
        while(!s.empty()){
            int val = s.top();
            s.pop();

            // 実際に val を目的地へ移動させる
            int rr = mv[val].fi, cc = mv[val].se;
            nr = 7-rr;
            nc = 7-cc;

            for(int i=posr; i<nr; ++i) printf("%d %d D 1\n", i, posc);
            for(int i=posc; i<nc; ++i) printf("%d %d R 1\n", nr, i);

            nx[rr][cc].PUSH(val);
        }

        // 大きい値を先に処理したいので、stackには後でpushするようにする
        for(int i=R; i>=1; --i)for(int j=C; j>=1; --j){
            if(!nx[i][j].st.empty()){
                nx[i][j].r = i;
                nx[i][j].c = j;
                st_st.push(nx[i][j]);
            }
        }
    }

    return 0;
}
