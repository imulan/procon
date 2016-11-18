#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int score(int l,int ac)
{
    return 50*l + (int)(floor(0.000001+50*l/(0.8+0.2*ac)));
}

int main()
{
    int a,b;
    cin >>a >>b;
    cout << score(a,b) << endl;
    return 0;
}
