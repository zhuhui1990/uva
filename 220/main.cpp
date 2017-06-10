#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 9;

char board[maxn][maxn];
char side;
int cnt;
int dx[] = {-1, 0, 1,-1, 1,-1, 0, 1};
int dy[] = {-1,-1,-1, 0, 0, 1, 1, 1};


inline bool inboard(int x,int y){
	return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}

bool check_dir(int x,int y,int i,char side){
	char opp = side == 'W'? 'B' : 'W';
	int x1 = x + dx[i];
	int y1 = y + dy[i];
	if(inboard(x1,y1) && board[x1][y1] == opp){
		x1 += dx[i];
		y1 += dy[i];
		while(inboard(x1,y1)){
			if(board[x1][y1] == '-'){
				return false;
			}
			if(board[x1][y1] == side){
				return true;
			}
			x1 += dx[i];
			y1 += dy[i];
		}
	}
	return false;
}


bool legal(int x,int y,char side){
	if(board[x][y] != '-'){
		return false;
	}
	for(int i = 0;i < 8; ++i){
		if(check_dir(x,y,i,side)){
			return true;
		}
	}
	return false;
}

void list(){
	cnt = 0;
	for(int i = 1; i <= 8; ++i){
		for(int j = 1; j <= 8; ++j){
			if(legal(i,j,side)){
				if(cnt > 0){
					cout<<" ";
				}
				cout<<"("<<i<<","<<j<<")";
				++cnt;
			}
		}
	}
	if(cnt == 0){
		cout<<"No legal move.";
	}
	cout<<endl;
}

void stat(){
	int black = 0, white = 0;
	for(int i=1;i<=8;++i){
		for(int j=1;j<=8;++j){
			if(board[i][j] == 'B'){
				++black;
			}else if(board[i][j] == 'W'){
				++white;
			}
		}
	}
	printf("Black - %2d White - %2d\n",black,white);
	//cout<<"Black - "<<black<<" White - "<<white<<endl;
}

void move(int x,int y){
	//list(false);
	if(!legal(x,y,side)){
		side = side == 'W'? 'B' : 'W';
	}
	board[x][y] = side;
	char opp = side == 'W'? 'B' : 'W';
	for(int i=0;i<8;++i){
		if(check_dir(x,y,i,side)){
			int x1 = x + dx[i];
			int y1 = y + dy[i];
			while(board[x1][y1] == opp){
				board[x1][y1] = side;
				x1 += dx[i];
				y1 += dy[i];
			}
		}
	
	}
	side = opp;
	stat();
}

void print(){
	for(int i = 1; i <= 8; ++i){
		for(int j = 1; j <= 8; ++j){
			cout<<board[i][j];
		}
		cout<<endl;
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int ngame;
	cin>>ngame;
	int x,y,xy;
	char command;
	for(int igame = 0; igame < ngame; ++igame){
		if(igame > 0){
			cout<<endl;
		}
		memset(board,0,sizeof(board));
		for(int i = 1; i <= 8; ++i){
			for(int j = 1; j <= 8; ++j){
				cin>>board[i][j];
			}
		}
		cin>>side;
		while(cin>>command){
			//cout<<"command="<<command<<endl;
			if(command == 'L'){
				//print();
				list();
			} else if(command == 'M'){
				cin>>xy;
				x = xy / 10;
				y = xy % 10;
				move(x,y);
				//print();
			} else if(command == 'Q'){
				print();
				break;
			}
		}
	}
	return 0;
}