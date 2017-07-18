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
    string s,t;
    cin >>s >>t;
    int S = s.size(), T = t.size();

    int cs[26]={}, ct[26]={};
    int q=0;
    rep(i,S)
    {
        if(s[i]=='?') ++q;
        else ++cs[s[i]-'a'];
    }
    rep(i,T) ++ct[t[i]-'a'];

    while(1)
    {
        bool ok = true;
        rep(i,26)if(cs[i]<ct[i]) ok=false;
        if(!ok) break;
        rep(i,26) cs[i]-=ct[i];
    }

    int cq[26]={};
    while(q>0)
    {
        int need[26];
        int sn = 0;
        rep(i,26)
        {
            need[i] = max(0,ct[i]-cs[i]);
            sn += need[i];
        }

        if(q>=sn)
        {
            rep(i,26)
            {
                if(need[i]>0)
                {
                    cq[i] += need[i];
                    cs[i] = 0;
                }
                else cs[i] -= ct[i];
            }
            q -= sn;
        }
        else
        {
            cq[0] += q;
            break;
        }
    }

    int qidx = 0;
    rep(i,S)
    {
        while(qidx<26 && cq[qidx]==0) ++qidx;
        if(s[i]=='?')
        {
            s[i] = 'a'+qidx;
            --cq[qidx];
        }
    }
    cout << s << endl;
    return 0;
}
