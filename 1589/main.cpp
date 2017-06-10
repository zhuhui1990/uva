//先读入所有棋子所在位置
//只需要判断九宫格的9个格子
//按照每个子所在位置和遮挡关系判断


#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int board[10][9]; //棋盘
bool palace[3][3]; //九宫格

int n;

int x0,y0; //对方将所在位置


char cc[10];
int xx[10],yy[10]; //本方棋子所在位置

//G:将
//R:车
//C:炮
//H:马
inline void fill_board(char c,int x,int y){
	int a = 1;
	board[x-1][y-1] = a;
}

void general(int i){
	int x1 = xx[i], y1 = yy[i];
	int x2 = x0 , y2 = y0 + 3;
	bool flag = true;
	int start = x2 + 1;
	int end = x1;
	//cout<<"start="<<start<<" end="<<end<<endl;
	for(int j = start;j < end; ++j){
		//cout<<"j="<<j<<" y1="<<y1<<" board[j][y1]="<<board[j][y1]<<endl;
		if(board[j][y1] > 0){
			flag = false;
			break;
		}
	}
	//cout<<"x1="<<x1<<" y1="<<y1<<" flag="<<flag<<endl;
	if(flag){
		for(int j=0;j<3;++j){
			palace[j][y1-3] = true;
		}
	}
}

void chariot(int i){
	int x1 = xx[i],  y1 = yy[i];
	int x2 = x0 , y2 = y0 + 3 ;
	
	if(y1 >= 3 && y1 <= 5){
		bool flag = true;
		int start = min(x1,x2)+1;
		int end = max(x1,x2);
		for(int j = start;j < end; ++j){
			if(board[j][y1] > 0){
				//cout<<"j="<<j<<" y1="<<y1<<endl;
				flag = false;
				break;
			}
		}
		//cout<<"x1="<<x1<<" y1="<<y1<<" x2="<<x2<<" y2="<<y2<<" flag="<<flag<<endl;
		if(flag){
			for(int j=0;j<3;++j){
				palace[j][y1-3] = true;
			}
		}
	}
	if(x1 >= 0 && x1 <= 2){
		bool flag = true;
		int start = min(y1,y2)+1;
		int end = max(y1,y2);
		for(int j = start;j < end; ++j){
			if(board[x1][j] > 0){
				flag = false;
				break;
			}
		}
		if(flag){
			for(int j=0;j<3;++j){
				palace[x1][j] = true;
			}
		}
	}
}

void cannon(int i){
	int x1 = xx[i],  y1 = yy[i];
	int x2 = x0 , y2 = y0 + 3 ;
	
	if(y1 >= 3 && y1 <= 5){
		int cnt = 0;
		int start = min(x1,x2)+1;
		int end = max(x1,x2);
		for(int j = start;j < end; ++j){
			if(board[j][y1] > 0){
				++cnt;
			}
		}
	
		if(cnt == 1){
			for(int j=0;j<3;++j){
				palace[j][y1-3] = true;
			}
		}
	}
	if(x1 >= 0 && x1 <= 2){
		int cnt = 0;
		int start = min(y1,y2)+1;
		int end = max(y1,y2);
		for(int j = start;j < end; ++j){
			if(board[x1][j] > 0){
				++cnt;
			}
		}

		if(cnt == 1){
			for(int j=0;j<3;++j){
				palace[x1][j] = true;
			}
		}
	}
}

void fill_one(int x, int y){
	if(x >= 0 && x <= 2 && y >= 3 && y<= 5){
	//cout<<"x="<<x<<" y-3="<<y-3<<endl;
		palace[x][y-3] = true;
	}
}

void horse(int i){
	int x1 = xx[i],  y1 = yy[i];
	//cout<<"x1="<<x1<<" y1="<<y1<<endl;
	if(x1 - 2 >= 0){
		if(board[x1-1][y1] == 0){
			fill_one(x1 - 2, y1 - 1);
			fill_one(x1 - 2, y1 + 1);
		}
	}
	if(x1 + 2 < 10){
		if(board[x1+1][y1] == 0){
			fill_one(x1 + 2, y1 - 1);
			fill_one(x1 + 2, y1 + 1);
		}
	}
	if(y1 - 2 >= 0){
		if(board[x1][y1-1] == 0){
			fill_one(x1 - 1, y1 - 2);
			fill_one(x1 + 1, y1 - 2);
		}
	}
	if(y1 + 2 < 9){
		if(board[x1][y1+1] == 0){
			fill_one(x1 - 1, y1 + 2);
			fill_one(x1 + 1, y1 + 2);
		}
	}
}

/*
void fill_palace(int n){
	for(int i = 0; i < n; ++i){
		switch(cc[i]){
			case('G'):
				general(i);
				break;
			case('R'):
				chariot(i);
				break;
			case('C'):
				cannon(i);
				break;
			case('H'):
				horse(i);
				break;
			default:
				break;
		}
	}
}
*/

bool fill_palace(int x00, int y00){
#ifdef LOCAL
	cout<<"x00="<<x00<<" y00="<<y00<<endl;
#endif
	memset(palace,false,sizeof(palace));
	if(board[x00][y00+3] == 0){ //不吃子
		for(int i = 0; i < n; ++i){
			switch(cc[i]){
			case('G'):
				general(i);
				break;
			case('R'):
				chariot(i);
				break;
			case('C'):
				cannon(i);
				break;
			case('H'):
				horse(i);
				break;
			default:
				break;
			}
#ifdef LOCAL
/*
			cout<<"i="<<i<<endl;
			cout<<"palace="<<endl;
			for(int i=0;i<3;++i){
				for(int j=0;j<3;++j){
					cout<<palace[i][j];
				}
				cout<<endl;
			}
*/
#endif
		}
#ifdef LOCAL
		cout<<"palace[x00][y00]="<<palace[x00][y00]<<endl;
#endif
		return palace[x00][y00];
	}else{ //吃子
#ifdef LOCAL
		cout<<"eat"<<endl;
#endif
		int j;
		for(int i= 0; i < n; ++i){
			if(xx[i] == x00 && yy[i] == y00+3){
				j = i;
				break;
			}
		}
		board[x00][y00+3] = 0;
		for(int i = 0; i < n; ++i){
			if(i != j){
				switch(cc[i]){
				case('G'):
					general(i);
					break;
				case('R'):
					chariot(i);
					break;
				case('C'):
					cannon(i);
					break;
				case('H'):
					horse(i);
					break;
				default:
					break;
				}
			}
		}
		board[x00][y00+3] = 1;
#ifdef LOCAL
		cout<<"palace[x00][y00]="<<palace[x00][y00]<<endl;
#endif
		return palace[x00][y00];
	}
}

bool direct_general(){
	for(int i=0;i<n;++i){
		if(cc[i] == 'G'){
			int x1 = xx[i], y1 = yy[i];
			if(y1 != y0 + 3){
				return false;
			}
			for(int i = x1 + 1; i < x0; ++i){
				if(board[i][y1] != 0){
					return false;
				}
			}
		}
	}
	return true;
}


bool check_palace(){
	//cout<<"x0="<<x0<<" y0="<<y0<<endl;
	//if(direct_general()){
	//	return false;
	//}
	if(fill_palace(x0,y0) == false){
		return false;
	}
	bool flag = true;
	if(x0 - 1 >= 0){
		flag &= fill_palace(x0-1,y0);
	}
	if(x0 + 1 <= 2){
		flag &= fill_palace(x0+1,y0);
	}
	if(y0 - 1 >= 0){
		flag &= fill_palace(x0,y0-1);
	}
	if(y0 + 1 <= 2){
		flag &= fill_palace(x0,y0+1);
	}
	return flag;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif 
	

	char c;
	int x,y;
	while(cin>>n>>x0>>y0){
		if(n == 0){
			break;
		}
		memset(board,0,sizeof(board));
		memset(palace,false,sizeof(palace));
		x0 -= 1;
		y0 -= 4;
		for(int i=0;i<n;++i){
			cin>>c>>x>>y;
			int x1 = x - 1, y1 = y - 1;
			int x2 = x0, y2 = y0 + 3;
			fill_board(c,x,y);
			cc[i] = c;
			xx[i] = x - 1;
			yy[i] = y - 1;
		}
		//fill_palace(n);
		if(check_palace()){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}