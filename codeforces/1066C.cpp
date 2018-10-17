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

const int N = 500000;
int b[N];
int pos[N];
int l = 250000, r=l+1;

int main(){
    int q;
    scanf(" %d", &q);

    while(q--){
        char t;
        int x;
        scanf(" %c %d", &t, &x);

        if(t=='L'){
            pos[x] = l;
            --l;
        }
        else if(t=='R'){
            pos[x] = r;
            ++r;
        }
        else{
            int p = pos[x];
            printf("%d\n", min((r-1)-p, p-(l+1)));
        }
    }

    return 0;
}
