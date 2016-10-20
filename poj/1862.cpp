#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <iomanip>
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

    priority_queue<double> pq;
    rep(i,n)
    {
        double w;
        scanf(" %lf", &w);
        pq.push(w);
    }

    while(pq.size()>1)
    {
        double a=pq.top();
        pq.pop();
        double b=pq.top();
        pq.pop();
        pq.push(2*sqrt(a)*sqrt(b));
    }

    cout << fixed;
    cout << setprecision(3) << pq.top() << endl;
    return 0;
}
