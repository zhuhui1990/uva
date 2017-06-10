#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dir[6][6] = { {0,1,2,3,4,5},
									{1,5,2,3,0,4},
									{2,1,5,0,4,3},
									{3,1,0,5,4,2},
									{4,0,2,3,5,1},
									{5,4,2,3,1,0},
								};
char s[20]={0},s1[10]={0},s2[10]={0};

bool same(){
	char ss[10]={0};
	for(int i=0;i<6;++i){
		for(int j=0;j<6;++j){
			ss[j] = s1[dir[i][j]];
		}
		for(int j=0;j<4;++j){
			char c = ss[1];
			ss[1] = ss[2];
			ss[2] = ss[4];
			ss[4] = ss[3];
			ss[3] = c;
			if(strcmp(ss,s2) == 0){
				return true;
			}
		}
	}
	return false;
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	//string s,s1(6,' '),s2(6,' ');
	
	while(scanf("%s",s) != EOF){
		//s1 = s.substr(0,6);
		//s2 = s.substr(6,12);
		for(int i=0;i<6;++i){
			s1[i] = s[i];
			s2[i] = s[i+6];
		}
		if(same()){
			cout<<"TRUE"<<endl;
		}else{
			cout<<"FALSE"<<endl;
		}
	}
	
	return 0;
}