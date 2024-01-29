#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct point{
	int x,y;
	int step;
	int life;
};

int start_x,start_y;
int end_x,end_y;
int len,width;
int map[10][10];
int xy[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int flag = 0;

queue<point> q;

int check(int x,int y){
	if(x < 0 || x >= len || y < 0 || y >= width){
		return 0;
	}
	return 1;
}

void bfs(){
	q.push({start_x,start_y,0,6});
	while(!q.empty()){
		for(int i=0;i<4;i++){
			int x1 = q.front().x + xy[i][0];
			int y1 = q.front().y + xy[i][1];
			if(x1 == end_x && y1 == end_y && q.front().life - 1 != 0){
				cout << q.front().step + 1;
				flag = 1;
				return;
			}
			if(check(x1,y1) && map[x1][y1] != 0 && q.front().life - 1 != 0){
				if(map[x1][y1] == 4){
					q.push({x1,y1,q.front().step + 1,6});
					map[x1][y1] = 6;
				}else if(map[x1][y1] > 4 && map[x1][y1] - 5 < q.front().life - 1 || map[x1][y1] < 5){
					q.push({x1,y1,q.front().step + 1,q.front().life - 1});
					map[x1][y1] = q.front().life - 1 + 5;
				}
				
				
			}
		}
		q.pop();
	}
}


int main(){
	cin >> len >> width;
	for(int i=0;i<len;i++){
		for(int j=0;j<width;j++){
			cin >> map[i][j];
			if(map[i][j] == 2){
				start_x = i;
				start_y = j;
			}else if(map[i][j] == 3){
				end_x = i;
				end_y = j;
			}
		}
	}
	bfs();

	if(!flag){
		cout << -1;
	}

	return 0;
}
