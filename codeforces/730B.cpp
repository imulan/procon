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

int ask(int i, int j){
    printf("? %d %d\n",i,j);
    fflush(stdout);

    char c;
    scanf(" %c", &c);
    if(c=='=') return 0;
    else if(c=='<') return 1;
    else return -1;
}

void ans(int MIN, int MAX){
    printf("! %d %d\n",MIN,MAX);
    fflush(stdout);
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(cases,T){
        int n;
        scanf(" %d", &n);

        if(n==1){
            ans(1,1);
            continue;
        }

        vector<int> win,lose;
        for(int i=1; i+1<=n; i+=2){
            int res = ask(i,i+1);
            if(res == 1){
                win.pb(i+1);
                lose.pb(i);
            }
            else{
                win.pb(i);
                lose.pb(i+1);
            }
        }
        if(n%2==1){
            int res = ask(n-1,n);
            if(res == 1) win.pb(n);
            else if(res == -1) lose.pb(n);
        }

        while(win.size()>1){
            int sz = win.size();
            vector<int> t;
            for(int i=0; i+1<sz; i+=2){
                if(ask(win[i],win[i+1])==1) t.pb(win[i+1]);
                else t.pb(win[i]);
            }
            if(sz%2==1) t.pb(win.back());

            win = t;
        }
        while(lose.size()>1){
            int sz = lose.size();
            vector<int> t;
            for(int i=0; i+1<sz; i+=2){
                if(ask(lose[i],lose[i+1])==1) t.pb(lose[i]);
                else t.pb(lose[i+1]);
            }
            if(sz%2==1) t.pb(lose.back());

            lose = t;
        }

        ans(lose[0], win[0]);

    }
    return 0;
}
