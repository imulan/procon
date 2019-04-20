#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int a[2020]={};
int suma[2020];

int main()
{
    int n,u;
    scanf(" %d %d", &n, &u);

    string s(n,'0');
    string t(n,' ');

    rep(i,u)
    {
        int l,r;
        scanf(" %d %d", &l, &r);

        ++a[l];
        --a[r+1];

        for(int j=1; j<=n; ++j)
        {
            suma[j] = suma[j-1]+a[j];
            if(suma[j]%2==0) t[j-1]='0';
            else t[j-1]='1';
        }

        s=max(s,t);
        // cout << " "<<t<<endl;
    }
    cout << s << endl;
    return 0;
}
