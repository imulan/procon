#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

void func()
{
    cin >> N >> Q;
cin >> R >> key;

for (i = 0; i < N - 1; i++)
{
    cin >> u >> v >> k;
}

int last_answer = 0;

for (i = 0; i < Q; i++)
{
    cin >> t;

    // find real value of t
    t ^= last_answer;

    if (t == 0)
    {
        cin >> v >> u >> k;

        // find real values for u, v, and k
        u ^= last_answer;
        v ^= last_answer;
        k ^= last_answer;
    }
    else
    {
        cin >> v >> k;

        // find real values for v, and k
        v ^= last_answer;
        k ^= last_answer;

        // compute the requested values
        int min_answer = ...
        int max_answer = ...

        // update last_answer
        last_answer = min_answer ^ max_answer;
    }
}
}

int main()
{

    return 0;
}
