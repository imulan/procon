#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int win(int sl, int sr, int el, int er)
{
    if(sl+sr==0) return 0;
    if(el+er==0) return 1;

    int ret=0;

    if(sl!=0)
    {
        if(el!=0)
        {
            int nel=sl+el;
            if(nel>4) nel=0;
            ret|=!win(nel,er,sl,sr);
        }
        if(er!=0)
        {
            int ner=sl+er;
            if(ner>4) ner=0;
            ret|=!win(el,ner,sl,sr);
        }
    }
    if(sr!=0)
    {
        if(el!=0)
        {
            int nel=sr+el;
            if(nel>4) nel=0;
            ret|=!win(nel,er,sl,sr);
        }
        if(er!=0)
        {
            int ner=sr+er;
            if(ner>4) ner=0;
            ret|=!win(el,ner,sl,sr);
        }
    }

    return ret;
}

int main()
{
    int li,ri,ln,rn;
    cin >>li >>ri >>ln >>rn;
    string ans="NAKAJIMA";
    if(win(li,ri,ln,rn)) ans="ISONO";
    cout << ans << endl;
    return 0;
}
