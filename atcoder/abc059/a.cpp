#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    rep(i,3)
    {
        string s;
        cin >>s;
        printf("%c", s[0]-'a'+'A');
    }
    printf("\n");
    return 0;
}
