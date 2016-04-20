#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

bool uru(int y){
  bool ret=false;
  if(y%4==0){
    if(y%100==0){
      if(y%400==0) ret=true;
      else ret=false;
    }
    else ret=true;
  }
  return ret;
}

int main(int argc, char const *argv[]) {
  while(1){
    int i;

    int y,m,d,a,b,c;
    scanf(" %d/",&y);
    if(y==0) break;
    scanf(" %d/%d %d:%d:%d",&m,&d,&a,&b,&c);
    string st;
    cin >>st;

    ll t=0;
    ll now=1;
    rep(i,(int)st.size()){
      t+=now;
      now*=2;
    }

    ll sec=3600*a+60*b+c;
    ll remain=3600*24-sec;

    if(t>=remain){
      int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
      if(uru(y)) days[2]=29;
      else days[2]=28;

      //とりあえず次の日の始めに移す
      sec=0;
      t-=remain;
      ++d;
      if(days[m]<d){
        ++m;
        d=1;
      }
      if(m==13){
        m=1;
        ++y;
      }

      if(uru(y)) days[2]=29;
      else days[2]=28;

      //printf("pre1 %d,%d,%d,%lld\n", y,m,d,t);

      //次に年末まで移動できるか
      while(m<13 && 3600*24<=t){
        ++d;
        t-=3600*24;
        if(days[m]<d){
          ++m;
          d=1;
        }
      }

      if(m==13){
        m=1;
        ++y;

        //printf("pre2 %d,%d,%d,%lld\n", y,m,d,t);

        //年を増加させていく
        while(1){
          ll dd=365;
          if(uru(y)) ++dd;
          ll tmp=dd*24*3600;

          if(t<tmp) break;
          else{
            t-=tmp;
            ++y;
          }
        }

        //printf("pre3 %d,%d,%d,%lld\n", y,m,d,t);

        if(uru(y)) days[2]=29;
        else days[2]=28;

        //余った分は年内で処理
        while(3600*24<=t){
          ++d;
          t-=3600*24;
          if(days[m]<d){
            ++m;
            d=1;
          }
        }
      }

    }
    //最後に秒数を処理
    sec+=t;

    //結果
    printf("%d/", y);
    if(m<10) printf("0");
    printf("%d/", m);
    if(d<10) printf("0");
    printf("%d ", d);

    a=sec/3600;
    sec-=a*3600;
    b=sec/60;
    sec-=b*60;
    c=sec;
    if(a<10) printf("0");
    printf("%d:", a);
    if(b<10) printf("0");
    printf("%d:", b);
    if(c<10) printf("0");
    printf("%d\n", c);
  }
  return 0;
}
