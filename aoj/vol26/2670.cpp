#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct Period
{
    // start, end
    int s,e;

    Period(){}

    Period(string x)
    {
        string a=x.substr(0,5), b=x.substr(6);
        s = convertToMinite(a);
        e = convertToMinite(b);
    }

    int convertToMinite(string x)
    {
        return 60*atoi(x.substr(0,2).c_str()) + atoi(x.substr(3).c_str());
    }

    bool cover(const Period& p)
    {
        return s<=p.s && p.e<=e;
    }
};

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int CLASS;
    cin >>CLASS;

    vector<Period> cl(CLASS);
    rep(i,CLASS)
    {
        string s;
        cin >>s;
        cl[i] = Period(s);
    }

    vector<int> teacher_available(CLASS,0), student_available(CLASS,0);

    int Q;

    // teacher
    cin >>Q;
    while(Q--)
    {
        int k;
        cin >>k;

        vector<int> a(CLASS,0);
        rep(i,k)
        {
            string s;
            cin >>s;
            Period p(s);

            rep(j,CLASS)
            {
                if(p.cover(cl[j])) a[j]=1;
            }
        }

        rep(i,CLASS) teacher_available[i] += a[i];
    }

    // student
    cin >>Q;
    while(Q--)
    {
        int k;
        cin >>k;

        vector<int> a(CLASS,0);
        rep(i,k)
        {
            string s;
            cin >>s;
            Period p(s);

            rep(j,CLASS)
            {
                if(p.cover(cl[j])) a[j]=1;
            }
        }

        rep(i,CLASS) student_available[i] += a[i];
    }

    int ans=0;
    rep(i,CLASS) ans+=min(teacher_available[i], student_available[i]);
    cout << ans << '\n';
    return 0;
}
