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

const string ok = "Yes", ng = "No";

string solve()
{
    int h,w;
    cin >>h >>w;

    int ct[26]={};
    rep(i,h)
    {
        string s;
        cin >>s;
        rep(j,w) ++ct[s[j]-'a'];
    }

    vector<vector<bool>> done(h,vector<bool>(w));

    int c[5]={};
    rep(i,h)rep(j,w)if(!done[i][j])
    {
        set<pi> s;
        s.insert(pi(i,j));
        s.insert(pi(i,w-1-j));
        s.insert(pi(h-1-i,w-1-j));
        s.insert(pi(h-1-i,j));

        int S = s.size();
        ++c[S];
        for(const auto &p:s) done[p.fi][p.se]=true;
    }

    while(c[1]>0)
    {
        bool found = false;
        rep(j,26)
        {
            if(ct[j]>0&&ct[j]%2==1)
            {
                --ct[j];
                --c[1];
                found = true;
                break;
            }
        }
        if(!found) break;
    }

    while(c[2]>0)
    {
        bool found = false;
        rep(j,26)
        {
            if(ct[j]>0&&ct[j]%4!=0 && ct[j]%2==0)
            {
                ct[j]-=2;
                --c[2];
                found = true;
                break;
            }
        }
        if(!found)
        {
            rep(j,26)
            {
                if(ct[j]>0&&ct[j]%2==0)
                {
                    ct[j]-=2;
                    --c[2];
                    found = true;
                    break;
                }
            }
        }

        if(!found) break;
    }

    while(c[4]>0)
    {
        bool found = false;
        rep(j,26)
        {
            if(ct[j]>0&&ct[j]%4==0)
            {
                ct[j]-=4;
                --c[4];
                found = true;
                break;
            }
        }
        if(!found) break;
    }

    // printf("%d %d %d\n", c[1],c[2],c[4]);
    // rep(i,5) printf("ct[%d] %d\n", i,ct[i]);
    rep(i,5)if(c[i]>0) return ng;
    rep(i,26)if(ct[i]>0) return ng;
    return ok;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
