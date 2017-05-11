#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char array[5][7];
char c;
char s[6];
int bx,by;
bool flag;

void process(char c){
		switch (c){
			case 'A':{
				if(bx == 0){
					flag = false;
					return;
				}
				array[bx][by] = array[bx-1][by];
				array[bx-1][by] = ' ';
				--bx;
				break;
			}
			case 'B':{
				if(bx == 4){
					flag = false;
					return;
				}
				array[bx][by] = array[bx+1][by];
				array[bx+1][by] = ' ';
				++bx;
				break;
			}
			case 'L':{
				if(by == 0){
					flag = false;
					return;
				}
				array[bx][by] = array[bx][by-1];
				array[bx][by-1] = ' ';
				--by;
				break;
			}
			case 'R' :{
				if(by == 4){
					flag = false;
					return;
				}
				array[bx][by] = array[bx][by+1];
				array[bx][by+1] = ' ';
				++by;
				break;
			}
			default:{
				flag = false;
				return;
				break;
			}
		}
	
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif 
	int x,y;
	int ncase = 0;
	while(gets(array[0]) && array[0][0] !='Z'){
		if(ncase > 0){
			printf("\n");
		}
		++ncase;
		flag = true;
		for(int i=1; i<5; ++i){
			gets(array[i]);
		}
		for(int i=0; i<5; ++i){
			for(int j=0; j<5; ++j){
				if(array[i][j] < 'A' || array[i][j] > 'Z'){
					bx = i;
					by = j;
					break;
				}
			}
		}
		//cout<<int(array[2][1])<<endl;
		//cout<<"bx="<<bx<<" by="<<by<<endl;
		while(cin>>c && c != '0'){
			//cout<<"c="<<c<<endl;
			//cout<<"bx="<<bx<<" by="<<by<<endl;
			process(c);
		}
		gets(s);
		printf("Puzzle #%d:\n",ncase);
		if(flag){
			for(int i=0;i<5;++i){
				printf("%c",array[i][0]);
				for(int j=1;j<5;++j){
					printf(" %c",array[i][j]);
				}
				printf("\n");
			}
		}else{
			printf("This puzzle has no final configuration.\n");
		}
	}
	return 0;
}		