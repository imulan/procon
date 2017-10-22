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

bool pal(string s)
{
    int S = s.size();
    rep(i,S)if(s[i]!=s[S-1-i]) return false;
    return true;
}

int solve()
{
    string s;
    cin >>s;
    int S = s.size();

    string t = "";
    vector<int> idx;
    rep(i,S)if(s[i]!='x')
    {
        t+=s[i];
        idx.pb(i);
    }

    if(t.size()==0) return 0;
    if(!pal(t)) return -1;

    int T = t.size();
    int ct = 0;
    int l = idx[(T-1)/2], r = idx[T/2];
    // dbg(l);dbg(r);
    while(l>=0 || r<S)
    {
        // printf(" N %d %d\n", l,r);
        if(l==-1)
        {
            ++ct;
            ++r;
        }
        else if(r==S)
        {
            --l;
            ++ct;
        }
        else
        {
            if(s[l]==s[r])
            {
                --l;
                ++r;
            }
            else
            {
                if(s[l]=='x')
                {
                    --l;
                    ++ct;
                }
                else if(s[r]=='x')
                {
                    ++r;
                    ++ct;
                }
                else assert(false);
            }
        }
    }

    return ct;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
