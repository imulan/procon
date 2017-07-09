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

const int N = 100000;
bool use[N+5];
char s[N+5];
int n,m;

int take(char c){
    int last = -1;
    int crnt = 0;
    int ret = 0;
    rep(i,n){
        crnt++;
        if(use[i]) crnt=0;
        if(s[i]==c) last = i;
        if(crnt==m){
            if(i-last >= m) return -1;
            else {
                use[last] = true;
                ret++;
                crnt = i-last;
            }
        }
    }
    return ret;
}


int main()
{
    scanf("%d %s", &m, s);
    n = strlen(s);
    fill(use, use+n, false);

    rep(i,26){
        char c = i + 'a';
        int r = take(c);
        if(r==-1){
            r = 0;
            rep(k,n) if(s[k]==c){
                r++;
                use[k]=true;
            }
        }
        else {
            i = 30; // break loop
        }
        rep(_,r) printf("%c", c);
    }
    printf("\n");

    return 0;
}
