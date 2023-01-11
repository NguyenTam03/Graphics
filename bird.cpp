#include<iostream>
#include<time.h>
#include<mylib.h>
#define FOR(i,r,l)	for(int i=r;i<l;i++)
using namespace std;
int pipe[6]={30,44,58,72,86,100};
int pipe_up[6]={6,5,4,3,2,1};
int pipe_down[6]={1,2,3,4,5,6};
int y_coordinate_bird =13;
int frame_up = 6;
int frame_down = 20;
int point(0);
bool result = true;
void create_frame();
void create_pipe();
void create_bird();
void move();
void lose();
void show_point();
int main(){
	while(1){
		ShowCur(0);
		create_frame();
		move();
		create_bird();
		create_pipe();
		lose();
		show_point();
		if(result == false)
			break;
		Sleep(100);
	}
}
void create_bird(){
	gotoxy(20,y_coordinate_bird);
	cout << char(219)<< char(219)<< char(2);
}
void create_frame(){
	FOR(i,17,101){
		gotoxy(i,5);
		cout << char(220);
		gotoxy(i,21);
		cout << char(223);
	}
	FOR(i,6,21){
		gotoxy(17,i);
		cout << char(219);
		gotoxy(100,i);
		cout << char(219);
	}
}
void create_pipe(){

	srand(time(NULL));
		FOR(i,0,6){
			if(pipe[i]<15){
				pipe[i]=99;
				pipe_up[i]=rand()%6+2;
				pipe_down[i] = 11 - pipe_up[i];
			}

		}
		// pipe up
	FOR(i,0,6){
		--pipe[i];
		FOR(j,0,pipe_up[i]){
			gotoxy(pipe[i],frame_up+j);
			cout << char(221);
			gotoxy(pipe[i]+3,frame_up+j);
			cout << char(222);
			gotoxy(pipe[i],frame_up + pipe_up[i] );
			cout << char(223) << char(223)<< char(223)<< char(223);
			
			gotoxy(pipe[i]+1,frame_up+j);
			cout << " ";
			gotoxy(pipe[i]+4,frame_up+j);
			cout << " ";
			gotoxy(pipe[i]+4,frame_up + pipe_up[i] );
			cout << " ";
		}
		// pipe down
		FOR(j,0,pipe_down[i]){
			gotoxy(pipe[i],frame_down-j);
			cout << char(221);
			gotoxy(pipe[i]+3,frame_down-j);
			cout << char(222);
			gotoxy(pipe[i],frame_down - pipe_down[i] );
			cout << char(220) << char(220)<< char(220)<< char(220);
			
			gotoxy(pipe[i]+1,frame_down-j);
			cout << " ";
			gotoxy(pipe[i]+4,frame_down-j);
			cout << " ";
			gotoxy(pipe[i]+4,frame_down - pipe_down[i] );
			cout << " ";
		}
			FOR(k,5,21){ // xoa phan ra ngoai frame
			gotoxy(12,k);
			cout << "     ";
		}
	}
}
int count(0);
void move(){
	int key;
	count++;
	if(count%5==0 && y_coordinate_bird < 20 ){
		gotoxy(20,++y_coordinate_bird);
		cout << char(219)<< char(219)<< char(2);
		gotoxy(20,y_coordinate_bird-1);
		cout << "   ";
	}
	if(kbhit()){
		key = getch();
		if(key == 119 && y_coordinate_bird > 6 ){
			gotoxy(20,--y_coordinate_bird);
			cout << char(219)<< char(219)<< char(2);
			gotoxy(20,y_coordinate_bird+1);
			cout << "   ";
		}
		if(key == 115&& y_coordinate_bird < 20){
			gotoxy(20,++y_coordinate_bird);
			cout << char(219)<< char(219)<< char(2);
			gotoxy(20,y_coordinate_bird-1);
			cout << "   ";	
		}
		if(key==224){
			do{
				key = getch();
			}while(key==224);
			if(key==72&& y_coordinate_bird > 6){
				gotoxy(20,--y_coordinate_bird);
				cout << char(219)<< char(219)<< char(2);
				gotoxy(20,y_coordinate_bird+1);
				cout << "   ";
			}
			if(key==80&& y_coordinate_bird < 20){
				gotoxy(20,++y_coordinate_bird);
				cout << char(219)<< char(219)<< char(2);
				gotoxy(20,y_coordinate_bird-1);
				cout << "   ";
			}
		}
	}
}
void lose(){
	FOR(i,0,6){
		if(y_coordinate_bird == 20 || (pipe[i]<=22&&pipe[i]+4>=20&&(y_coordinate_bird<= frame_up + pipe_up[i] || y_coordinate_bird >= frame_down - pipe_down[i])))
			result = false;
	}
}
void show_point(){
	FOR(i,0,6){
		if(pipe[i]+4==20)
			point++;
	}
	gotoxy(90,4);
	cout << point;
}

