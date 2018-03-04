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

inline int dist(int y, int r){
    int ret = 191919;
    for(int R:vector<int>({0,r/2+1,r+2})){
        ret = min(ret, abs(y-R));
    }
    return ret;
}

inline int select(const string &s, int L, int R){
    if(s[4]=='-' || s[6]=='-'){
        if(s[4]=='-' && s[6]=='-'){
            if(L>=R) return 4;
            return 6;
        }

        if(s[4]=='-') return 4;
        return 6;
    }

    if(s[2]=='-' || s[8]=='-'){
        if(s[2]=='-' && s[8]=='-'){
            if(L>=R) return 2;
            return 8;
        }

        if(s[2]=='-') return 2;
        return 8;
    }

    if(s[0]=='-' || s[10]=='-'){
        if(s[0]=='-' && s[10]=='-'){
            if(L>=R) return 0;
            return 10;
        }

        if(s[0]=='-') return 0;
        return 10;
    }

    if(s[5]=='-') return 5;

    if(s[1]=='-' || s[9]=='-'){
        if(s[1]=='-' && s[9]=='-'){
            if(L>=R) return 1;
            return 9;
        }

        if(s[1]=='-') return 1;
        return 9;
    }
    assert(false);
}

int main(){
    int r,n;
    cin >>r >>n;

    vector<string> s(r+3);
    rep(i,r+3) cin >>s[i];

    rep(num,n){
        char c = 'a'+num;

        vector<int> e(r+3);
        rep(i,r+3){
            rep(j,11) e[i] += (s[i][j]=='-');
        }

        int L = 0, R = 0;
        rep(i,r+3){
            rep(j,5) L += (s[i][j]=='-');
            for(int j=6; j<=10; ++j) R += (s[i][j]=='-');
        }
        // printf(" L R %d %d\n", L, R);

        bool flg = false;
        if(e[1]>0 || e[r/2+2]>0) flg = true;

        // dbg(flg);
        // rep(j,r+3) cout << s[j] << " " << e[j] << endl;

        int y = -1;
        int me = 0;
        rep(i,r+3){
            if(flg){
                if(i!=1 && i!=r/2+2) continue;
            }

            if(e[i]>me){
                y = i;
                me = e[i];
            }
            else if(e[i]==me){
                if(dist(i,r)<dist(y,r)){
                    y = i;
                    me = e[i];
                }
            }
        }

        // printf(" %c  : y = %d ",c,y);
        assert(y>0);
        int x = select(s[y], L, R);
        // printf("  x = %d\n", x);
        s[y][x] = c;
    }

    rep(i,r+3) cout << s[i] << endl;
    return 0;
}
