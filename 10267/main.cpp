#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

const int maxn = 255;
char array[maxn][maxn];
bool visited[maxn][maxn];

inline bool isvalid(int y,int x,int m,int n){
	return (y>0 && y<=n) && (x>0 && x<=m);
}

void floodfill(int x,int y,int m,int n,char c1){
	char c2 = array[y][x];
	//cout<<"x="<<x<<" y="<<y<<" m="<<m<<" n="<<n<<" c1="<<c1<<" c2="<<c2<<endl;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			visited[i][j] = false;
		}
	}
	queue<pair<int,int>> q;
	pair<int,int> p;
	q.push({y,x});
	visited[y][x]=true;
	int y1,x1;
	while(!q.empty()){
		p = q.front();
		q.pop();
		y1 = p.first;
		x1 = p.second;
	//	cout<<"y1="<<y1<<" x1="<<x1<<endl;
		array[y1][x1] = c1;
		for(int i=-1;i<=1;++i){
			for(int j=-1;j<=1;++j){
				if(!(i == 0 && j == 0)){
					if(!visited[y1+i][x1+j] && array[y1+i][x1+j]==c2 && isvalid(y1+i,x1+j,m,n) ){
						q.push({y1+i,x1+j});
						visited[y1+i][x1+j]=true;
					}
				}
			}
		}
	} 
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	char c;
	int m,n;
	int x,y;
	int x1,x2,y1,y2;
	char c1;
	string name;
	while(cin>>c && c!='X'){
		switch(c){
		case('I'):
			cin>>m>>n;
			//cout<<"m="<<m<<" n="<<n<<endl;
		case('C'):
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					array[i][j]='O';
				}
			}
			break;
		case('L'):
			cin>>x>>y>>c1;
			array[y][x] = c1;
			break;
		case('V'):
			cin>>x>>y1>>y2>>c1;
			//cout<<"x="<<x<<" y1="<<y1<<" y2="<<y2<<" c1="<<c1<<endl;
			if(y1>y2){
				int temp=y1;
				y1=y2;
				y2=temp;
			}
			for(int i=y1;i<=y2;++i){
				array[i][x] = c1;
			}
			break;
		case('H'):
			cin>>x1>>x2>>y>>c1;
			if(x1>x2){
				int temp=x1;
				x1=x2;
				x2=temp;
			}
			for(int i=x1;i<=x2;++i){
				array[y][i] = c1;
			}
			break;
		case('K'):
			cin>>x1>>y1>>x2>>y2>>c1;
			if(y1>y2){
				int temp=y1;
				y1=y2;
				y2=temp;
			}
			if(x1>x2){
				int temp=x1;
				x1=x2;
				x2=temp;
			}
			for(int i=x1;i<=x2;++i){
				for(int j=y1;j<=y2;++j){
					array[j][i] = c1;
				}
			}
			break;
		case('F'):
			cin>>x>>y>>c1;
			floodfill(x,y,m,n,c1);
			break;
		case('S'):
			cin>>name;
			cout<<name<<endl;
			//cout<<"m="<<m<<" n="<<n<<endl;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					//cout<<"i="<<i<<" j="<<j<<endl;
					cout<<array[i][j];
					//cout<<endl;
				}
				cout<<endl;
			}
			break;
		default:
			break;
		}
	}
	
	return 0;
}