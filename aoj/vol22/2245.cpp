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

const int INF = 393939;

using pi = pair<int,int>;

const int ura[7]={0,3,4,1,2,6,5};

struct Dice{
    int F,R,BK,L,T,BT;
    Dice(){}
    Dice(int f, int t, int r){
        F = f;
        T = t;
        R = r;
        BK = ura[f];
        BT = ura[t];
        L = ura[r];
    }

    void rot(int dir){
        if(dir==0){
            // 前
            int tmp = F;
            F = T;
            T = BK;
            BK = BT;
            BT = tmp;
        }
        else if(dir==1){
            // 後ろ
            int tmp = F;
            F = BT;
            BT = BK;
            BK = T;
            T = tmp;
        }
        else if(dir==2){
            // 左
            int tmp = T;
            T = R;
            R = BT;
            BT = L;
            L = tmp;
        }
        else{
            // 右
            int tmp = T;
            T = L;
            L = BT;
            BT = R;
            R = tmp;
        }
    }
};

vector<string> rotate_ccw(const vector<string> &v){
    vector<string> ret(3,string(3,' '));
    rep(i,3)rep(j,3) ret[2-j][i] = v[i][j];
    return ret;
}

vector<string> rotate_cw(const vector<string> &v){
    vector<string> ret(v);
    rep(i,3) ret = rotate_ccw(ret);
    return ret;
}

int d[7][4]={
    {0,0,0,0},
    {5,2,6,4},
    {5,3,6,1},
    {5,4,6,2},
    {5,1,6,3},
    {3,2,1,4},
    {1,2,3,4}
};

int main(){
    string s;
    while(cin >>s,(s!="#")){
        vector<vector<string>> surface(7,vector<string>(3));
        for(int i=1; i<=6; ++i){
            rep(j,3){
                if(i==1 && j==0){
                    surface[i][j] = s;
                    continue;
                }
                cin >>surface[i][j];
            }
        }

        auto check = [&](int f, int t){
            vector<string> front = surface[f], back = surface[ura[f]];
            if(f==5 || f==6){
                rep(_,2) back = rotate_ccw(back);
            }

            rep(i,4){
                if(d[f][i] == t) break;
                front = rotate_ccw(front);
                back = rotate_cw(back);
            }


            int fv=0, bv=0;
            rep(i,3){
                fv |= (front[2][i]=='*');
                bv |= (back[2][i]=='*');
            }
            return fv&bv;
        };

        int ans = INF;

        vector<vector<int>> dp(7,vector<int>(7,INF));
        queue<pi> que;
        dp[1][5] = 0;
        que.push({1,5});
        while(!que.empty()){
            pi now = que.front();
            que.pop();

            int f=now.fi, t=now.se;
            // dbg(now);
            // dbg(dp[f][t]);
            if(check(f,t)){
                ans = dp[f][t];
                break;
            }

            int r = 0;
            rep(i,4){
                if(d[f][i]==t){
                    r = d[f][(i+1)%4];
                    break;
                }
            }
            assert(r>0);

            rep(dir,4){
                Dice dd(f,t,r);
                dd.rot(dir);
                if(dp[dd.F][dd.T] > dp[f][t]+1){
                    dp[dd.F][dd.T] = dp[f][t]+1;
                    que.push({dd.F,dd.T});
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
