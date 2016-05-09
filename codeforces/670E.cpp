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

typedef pair<int,int> pi;

int main()
{
    int n,m,p;
    string cbs,op;

    cin >>n >>m >>p;
    cin >>cbs;
    cin >>op;

    --p;

    stack<int> st;
    //対応付け
    vector<int> pos(n);

    rep(i,n)
    {
        if(cbs[i]=='(') st.push(i);
        else
        {
            int v=st.top();
            st.pop();
            pos[v]=i;
            pos[i]=v;
        }
    }

    int left[500000],right[500000];
    rep(i,n) left[i]=i-1;
    rep(i,n) right[i]=i+1;
    right[n-1]=-1;

    rep(i,m)
    {
        if(op[i]=='L') p=left[p];
        else if(op[i]=='R') p=right[p];
        else
        {
            int lf=p;
            int rg=pos[p];
            if(lf>rg) swap(lf,rg);

            if(right[rg]==-1) p=left[lf];
            else p=right[rg];

            //括弧の結合の更新
            right[left[lf]]=right[rg];
            left[right[rg]]=left[lf];
        }
    }

    //rep(i,n) printf("%d: left: %d, right: %d\n",i,left[i],right[i]);

    int idx=n-1;
    while(left[idx]!=-1) --idx;
    while(idx!=-1)
    {
        printf("%c",cbs[idx]);
        idx=right[idx];
    }
    printf("\n");

    return 0;
}
