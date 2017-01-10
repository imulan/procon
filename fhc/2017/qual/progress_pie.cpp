#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const double pi = acos(-1);

bool in_circle(int x, int y)
{
    return sqrt((x-50)*(x-50)+(y-50)*(y-50))<=50;
}

double percentile(int x, int y)
{
    if(x==50)
    {
        if(y>=50) return 0;
        else return 50;
    }

    double cos_v = (x-50)/sqrt((x-50)*(x-50)+(y-50)*(y-50));

    double theta = acos(cos_v);
    if(y<50) theta = 2*pi-theta;

    if(theta <= pi/2) return 25.0 * (pi/2 - theta) / (pi/2);
    else return -50.0/pi * theta + 125;
}

int main()
{
    int T;
    cin >>T;
    rep(cases,T)
    {
        // input
        int p,x,y;
        cin >>p >>x >>y;

        // solve
        bool inner = false;
        if(in_circle(x,y) && p>0)
        {
            // printf(" percentile = %.2f\n", percentile(x,y));
            if(percentile(x,y)<=p) inner = true;
        }

        // output
        string ans="white";
        if(inner) ans="black";
        printf("Case #%d: ", cases+1);
        cout << ans << endl;
    }
    return 0;
}
