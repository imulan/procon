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
    int T;
    cin >>T;
    while(T--)
    {
        int n;
        scanf(" %d", &n);

        vector<int> s(n);
        rep(i,n)
        {
            int c;
            scanf(" %d", &c);

            s[i]=c;

            vector<int> types(6,0);
            rep(j,c)
            {
                int t;
                scanf(" %d", &t);
                types[t-1]++;
            }
            sort(all(types));

            int sub;

            //6個組
            s[i]+=types[0]*4;
            sub=types[0];
            rep(j,6) types[j]-=sub;

            //5個組
            s[i]+=types[1]*2;
            sub=types[1];
            for(int j=1; j<6; ++j) types[j]-=sub;

            //4個組
            s[i]+=types[2];
            sub=types[2];
            for(int j=2; j<6; ++j) types[j]-=sub;
        }

        int max_score=0;
        rep(i,n) max_score = max(max_score, s[i]);

        int num=0;
        int idx=-1;
        rep(i,n)
        {
            if(s[i] == max_score)
            {
                num++;
                idx=i;
            }
        }

        if(num>1) printf("tie\n");
        else
        {
            if(idx==0) printf("chef\n");
            else printf("%d\n", idx+1);
        }
    }
    return 0;
}
