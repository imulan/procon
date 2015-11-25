#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int y, m, d;
	
	while(scanf(" %d %d %d", &y, &m ,&d) != EOF){
		string ans;
		int year;
		bool flag=false;
		
		if(y<1868 || (y==1868 && m<9) || (y==1868 && m==9 && d<=7) ) { 
			ans = "pre-meiji";
			flag=true;
		}
		else if(y<1912 || (y==1912 && m<7) || (y==1912 && m==7 && d<=29) ) {
			ans = "meiji";
			year = y - 1868 + 1;
		}
		else if(y<1926 || (y==1926 && m<12) || (y==1926 && m==12 && d<=24) ) {
			ans = "taisho";
			year = y - 1912 + 1;
		}
		else if(y<1989 || (y==1989 && m<1) || (y==1989 && m==1 && d<=7) ) {
			ans = "showa";
			year = y - 1926 + 1;
		}
		else {
			ans = "heisei";
			year = y - 1989 + 1;
		}
	
		if(flag) cout << ans << endl;
		else cout << ans << " " << year << " " << m << " " << d <<endl;
	}

	return 0;
}