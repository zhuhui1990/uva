#include <iostream>
#include <cstdio>

using namespace std;

const int maxm = 55;
const int maxn = 1005;

char array[maxm][maxn];
char res[maxn];
char s[5];

inline int findmax(int a,int b,int c,int d){
	return max(max(max(a,b),c),d);
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int ncase;
	scanf("%d",&ncase);
	int m,n;
	int a,c,g,t;
	int mm;
	int diff;
	for(int icase=0;icase<ncase;++icase){
		scanf("%d %d",&m,&n);
		gets(s);
		for(int i=0;i<m;++i){
			gets(array[i]);
		}
		diff = 0;
		for(int i=0;i<n;++i){
			a = c = g = t = 0;
			mm = 0;
			for(int j=0;j<m;++j){
				switch (array[j][i]){
					case 'A':
						++a;
						break;
					case 'G':
						++g;
						break;
					case 'C':
						++c;
						break;
					case 'T':
						++t;
						break;
					default:
						break;
				}
			}
			mm = findmax(a,c,g,t);
			if(mm == a){
				res[i] = 'A';
			}else if(mm == c){
				res[i] = 'C';
			}else if(mm == g){
				res[i] = 'G';
			}else if(mm == t){
				res[i] = 'T';
			}
			diff += a+c+g+t-mm;		
		}
		res[n] = '\0';
		printf("%s\n",res);
		printf("%d\n",diff);
	}
	
	return 0;
}