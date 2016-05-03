#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n, t, m=0;
	int st[10], ar[10];
	string ans[10];
	int anst[10];
	
	scanf(" %d %d", &n, &t);
	for(int i=0; i<n; ++i){
		int a, b, c, d;
		string p, q;
		
		scanf(" %d:%d", &a, &b);
		cin >> p;
		scanf(" %d:%d", &c, &d);
		cin >> q;
		st[i]=a*60+b;
		ar[i]=c*60+d;
		
		//printf("st[%d]=%d, ar[%d]=%d\n", i, st[i], i, ar[i]);
	
		if(i==0) continue;
		else{
			int tt=st[i]-ar[i-1];
			if(tt>=t){
				ans[m]=p;
				anst[m]=tt;
				m++;		
			}
		}
		
	}
	
	printf("%d\n", m);
	for(int i=0; i<m; ++i) cout << ans[i] << " " << anst[i] << endl;
}