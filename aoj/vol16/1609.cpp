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

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<char> c(n);
        rep(i,n) cin >>c[i];

        int v[26]={};
        bool determined = false;
        char x;
        int y;
        rep(i,n)
        {
            ++v[c[i]-'A'];
            int r = n-1-i;

            int win[26]={};
            rep(j,26)
            {
                v[j] += r;

                int m = 0;
                rep(k,26) m = max(m,v[k]);

                int ct = 0, idx = 0;
                rep(k,26)
                {
                    if(v[k]==m)
                    {
                        ++ct;
                        idx=k;
                    }
                }
                if(ct==1) ++win[idx];

                v[j] -= r;
            }

            rep(j,26)
            {
                if(win[j]==26)
                {
                    determined = true;
                    x = 'A'+j;
                    y = i+1;
                }
            }
            if(determined) break;
        }

        if(determined) printf("%c %d\n",x,y);
        else printf("TIE\n");
    }
    return 0;
}
