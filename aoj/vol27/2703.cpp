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

const int INF = 19191919;

struct Dice{
    int x,y;
    int l,r,f,b,d,u;

    void read(){
        cin >>x >>y >>l >>r >>f >>b >>d >>u;
    }

    void rot(char c){
        int tmp;
        if(c=='L'){
            --x;
            tmp = u;
            u = r;
            r = d;
            d = l;
            l = tmp;
        }
        else if(c=='R'){
            ++x;
            tmp = u;
            u = l;
            l = d;
            d = r;
            r = tmp;
        }
        else if(c=='F'){
            --y;
            tmp = u;
            u = b;
            b = d;
            d = f;
            f = tmp;
        }
        else if(c=='B'){
            ++y;
            tmp = u;
            u = f;
            f = d;
            d = b;
            b = tmp;
        }
    }

    pi pos(){
        return {x,y};
    }

    int val(){
        return d;
    }
};


int main(){
    int n;
    while(cin >>n,n){
        map<pi,int> cov;
        vector<map<pi,int>> D(n);
        rep(i,n){
            Dice a;
            a.read();
            string rot;
            cin >>rot;

            map<pi,int> m;
            m[a.pos()] = a.val();
            for(char c:rot){
                a.rot(c);
                m[a.pos()] = a.val();
            }

            for(const auto &p:m){
                cov[p.fi] |= (1<<i);
            }
            D[i] = m;
        }

        vector<int> dp(1<<n, -INF);
        dp[0] = 0;
        rep(mask,1<<n){
            rep(i,n)if(!(mask>>i&1)){
                int nmask = mask|(1<<i);

                int add = 0;
                for(const auto &p:D[i]){
                    if((nmask|cov[p.fi]) == nmask) add += p.se;
                }
                dp[nmask] = max(dp[nmask], dp[mask]+add);
            }
        }
        cout << dp[(1<<n)-1] << endl;
    }
    return 0;
}
