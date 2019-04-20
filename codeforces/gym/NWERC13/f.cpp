#include<bits/stdc++.h>
#define MOD 100000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int uruu_day[12]={31,29,31,30,31,30,31,31,30,31,30,31};

int get_int(string str){
	int ans=0;
	for(int i=0;i<str.size();i++){
		ans*=10;
		ans+=(str[i]-'0');
	}
	return ans;
}

bool is_uruu(int y,int t){
	if(t==0){
		return (y%4==0);
	}else{
		if(y%400==0)return true;
		if(y%100==0)return false;
		if(y%4==0)return true;
		return false;
	}
}

int calc_process(int y,int m,int d,int type){
    cin.tie(0);ios::sync_with_stdio(false);
	int ans=0;
	while(d!=0){
		d--;
		ans++;
	}
	m--;
	while(m!=0){
		if(is_uruu(y,type))ans+=uruu_day[m-1];
		else ans+=day[m-1];
		m--;
	}
	y--;
	while(y!=0){
		if(is_uruu(y,type))ans+=366;
		else ans+=365;
		y--;
	}
	return ans;
}

int main(void){
	string str;
	while(cin >> str){
		int y=get_int(str.substr(0,4));
		int m=get_int(str.substr(5,2));
		int d=get_int(str.substr(8,2));
		int diff=calc_process(y,m,d,0)-calc_process(1582,10,4,0);
		int gy=1582;
		int gm=10;
		int gd=15;
		while(diff>0){
			gd++;
			if(is_uruu(gy,1) && uruu_day[gm-1]==gd-1){
				gd=1;
				gm++;
			}
			if(!is_uruu(gy,1) && day[gm-1]==gd-1){
				gd=1;
				gm++;
			}
			if(gm==13){
				gm=1;
				gy++;
			}
			diff--;
		}
		printf("%04d-%02d-%02d\n",gy,gm,gd);
	}
	return 0;
}
