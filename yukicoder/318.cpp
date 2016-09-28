#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    map<int,int> most_right;
    for(int i=n-1; i>=0; --i)
    {
        if(most_right.find(a[i]) == most_right.end()) most_right[a[i]]=i;
    }

    set<int> s;

    rep(i,n)
    {
        s.insert(a[i]);

        if(i) printf(" ");
        printf("%d", *s.rbegin());

        if(i == most_right[a[i]]) s.erase(a[i]);
    }
    printf("\n");
    
    return 0;
}
