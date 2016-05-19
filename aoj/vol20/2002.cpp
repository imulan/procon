#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int h,w;
int top[7];
int under[7];
int lf[7];
int rg[7];

bool dfs(const vector<int> &a, const vector<string> &b)
{
    bool ret=false;
    int A=a.size();

    int ct=0;
    rep(i,A) ct+=a[i];
    if(ct==A) return true;

    //iが今あるものの中で一番手前にあると仮定
    rep(i,A)
    {
        //既に使った
        if(a[i]==1) continue;

        bool ok=true;
        char focus='0'+i;
        for(int y=top[i]; y<=under[i]; ++y)
        {
            for(int x=lf[i]; x<=rg[i]; ++x)
            {
                if(b[y][x]!=focus && b[y][x]!='S')
                {
                    ok=false;
                    break;
                }
            }
            if(!ok) break;
        }

        if(ok)
        {
            vector<int> na(a);
            vector<string> nb(b);
            na[i]=1;

            for(int y=top[i]; y<=under[i]; ++y)
            for(int x=lf[i]; x<=rg[i]; ++x)
            {
                if(nb[y][x]==focus) nb[y][x]='S';
            }

            ret|=dfs(na,nb);
        }
    }

    return ret;
}

int main()
{
    int n;
    cin >>n;
    rep(T,n)
    {
        cin >>h >>w;

        vector<string> f(h);
        rep(i,h) cin >>f[i];

        int im[26];
        fill(im,im+26,-1);

        int ct=0;
        rep(i,h)rep(j,w)
        {
            if(f[i][j]!='.')
            {
                int idx=f[i][j]-'A';
                if(im[idx]==-1) im[idx]=ct++;
            }
        }

        rep(i,h)rep(j,w)
        {
            if(f[i][j]!='.') f[i][j]=im[f[i][j]-'A']+'0';
        }

        fill(top,top+7,h);
        fill(under,under+7,0);
        fill(lf,lf+7,w);
        fill(rg,rg+7,0);
        rep(i,h)rep(j,w)
        {
            if(f[i][j]!='.')
            {
                int idx=f[i][j]-'0';

                top[idx]=min(top[idx],i);
                under[idx]=max(under[idx],i);
                lf[idx]=min(lf[idx],j);
                rg[idx]=max(rg[idx],j);
            }
        }

        vector<int> use(ct,0);
        bool valid=dfs(use,f);

        string ans="SUSPICIOUS";
        if(valid) ans="SAFE";
        std::cout << ans << std::endl;
    }
    return 0;
}
