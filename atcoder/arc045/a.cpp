#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	char c;
	bool f=true;
	while(~scanf(" %c", &c)){
		bool pr=false;
		char u;
		if(c=='L'){u='<'; pr=true;}
		else if(c=='R'){u='>'; pr=true;}
		else if(c=='A'){u='A'; pr=true;}
		
		if(pr){
			if(!f) printf(" ");
			printf("%c", u);
			f=false;
		}
	}
	printf("\n");
}
		