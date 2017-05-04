#include <iostream>
#include <cstdio>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	char ch;
	bool in = false;
	while(scanf("%c",&ch)!=EOF){
		if(ch == '"'){
			if(in){
				printf("\'\'");
			}else{
				printf("``");
			}
			in = !in;
		}else{
			printf("%c",ch);
		}
	}
}