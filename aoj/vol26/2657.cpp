#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct Date
{
    int year,month,day;

    Date(){}
    Date(string s)
    {
        year=atoi(s.substr(0,4).c_str());
        month=atoi(s.substr(5,2).c_str());
        day=atoi(s.substr(8,2).c_str());
    }

    int releasedAfter(Date b)
    {
        if(year>b.year) return 1;
        else if(year==b.year)
        {
            if(month>b.month) return 1;
            else if(month==b.month)
            {
                if(day>=b.day) return 1;
            }
        }
        return 0;
    }

    int releasedBefore(Date b)
    {
        if(year<b.year) return 1;
        else if(year==b.year)
        {
            if(month<b.month) return 1;
            else if(month==b.month)
            {
                if(day<=b.day) return 1;
            }
        }
        return 0;
    }
};

struct Book
{
    string title,author;
    Date date;

    Book(){}
    Book(string a, string b, Date c)
    {
        title=a;
        author=b;
        date=c;
    }

    int searchString(string q, string s)
    {
        int Q=q.size(), S=s.size();

        rep(i,S-Q+1)
        {
            if(s.substr(i,Q)==q) return 1;
        }
        return 0;
    }

    int includeTitle(string q)
    {
        return searchString(q,title);
    }
    int includeAuthor(string q)
    {
        return searchString(q,author);
    }
    int releasedBefore(Date q)
    {
        return date.releasedBefore(q);
    }
    int releasedAfter(Date q)
    {
        return date.releasedAfter(q);
    }
};

int main()
{
    int n;
    cin >>n;

    vector<Book> b(n);
    rep(i,n)
    {
        string x,y,z;
        cin >>x >>y >>z;
        b[i]=Book(x,y,Date(z));
    }

    int Q;
    cin >>Q;
    rep(q,Q)
    {
        string t,a,from,to;
        cin >>t >>a >>from >>to;

        vector<int> ok(n,1);
        rep(i,n)
        {
            if(t!="*") ok[i]&=b[i].includeTitle(t);
            if(a!="*") ok[i]&=b[i].includeAuthor(a);
            if(from!="*") ok[i]&=b[i].releasedAfter(Date(from));
            if(to!="*") ok[i]&=b[i].releasedBefore(Date(to));
        }

        if(q) printf("\n");
        rep(i,n) if(ok[i]) cout << b[i].title << endl;
    }

    return 0;
}
