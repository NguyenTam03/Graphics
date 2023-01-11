#include<iostream>
#include<mylib.h>
#include<time.h>
using namespace std;
void heart();
void create_dinosaur();
void create_frame();
void jump_up();
void fall();
void create_tree(int &n);
void input(void);
void CheckKey(void);
void lose();
bool check();
void points();
bool res = true;
int point(0);
int sl = 5;
int tree[5]={0};
int y_coordinates=21;
int x_coordinates=18;
int falling_time(-1);
int speed(60);
int mang(4);
int immortal(3);
int tmp = x_coordinates;
int main(){
	int m=100;
	srand(time(NULL));
	for(int i = 0 ;i < 5;i++){
		tree[i]=100+rand()%10+i*15;
	}
	heart();
	int heartx =79;
	while(true){
		ShowCur(0);
		create_frame();
		create_dinosaur();
		CheckKey();
		if(falling_time>-1 && falling_time<9)	falling_time++;
		// khi thuc hien duoc 8 vong lap while khi bat dau jump_up thi create_dinosaur se fall xuong
		if( falling_time == 8 )	fall();
		points();
		// In cay 
		for(int i=0;i<sl;i++){
			if(tree[i]>100)	tree[i]--; // cho cay chay o trong khung
			if(tree[i]==10)	tree[i]=100+rand()%10+i*15; // cho cay chay lai tu dau
			if(tree[i]<=100) create_tree(tree[i]); // bat dau cho cay chay trong khung
		}
		lose();
		if(res == false){
			tmp = 0;
			immortal = 3; // cho bat tu 3 vong lap while
			res = true;
			mang--;
			gotoxy(heartx,5);
			cout << " ";
			heartx-=2;
			if(mang==0)
				break;
		}
		if(--immortal==0)	tmp = x_coordinates; // het bat tu thi` gan lai
		Sleep(speed);
		gotoxy(55,12);
		cout << point;
	}
}
// ----------------- //
void heart(){
	gotoxy(75,5);
	SetColor(4);
	cout << char(3)<<" "<<char(3)<<" "<<char(3)<<" ";
	SetColor(7);
}
// ----------------- //
void create_dinosaur(){
	gotoxy(x_coordinates,y_coordinates);
	cout<< char(220)<<char(220);
	gotoxy(x_coordinates-2,y_coordinates);
	cout<< "~~";
	gotoxy(x_coordinates+2,y_coordinates);
	cout<< char(148);
	gotoxy(x_coordinates,y_coordinates+1);
	cout << "||";
}
// ----------------- //
void create_frame(){
	char temp =179;
	for(int i=10;i<101;i++){
		gotoxy(i,1);
		cout << "+";
		gotoxy(i,26);
		cout << "+";
		gotoxy(i,23);
		cout << char(223) ;
	}
	for(int i = 2 ;i<27;i++){
		gotoxy(10,i);
		cout <<"+";
		gotoxy(100,i);
		cout <<"+";
	}		
}
// ----------------- //
void create_tree(int &n){
	char temp = 30;
	gotoxy(--n,22);
	cout << temp;
	gotoxy(n + 1 ,22);// xoa phan tu cu
	cout << " ";
}
// ----------------- //
void CheckKey(void){
	int key;
	if (kbhit()) {
    	key=getch();
    	if (key == 224 && y_coordinates == 21) {
        	do {
            	key=getch();
        	}while(key==224);
        	switch (key) { //  nu't len 
           		case 72:
                jump_up();
                break;
        	}
    }
    if(key == 119 &&y_coordinates == 21) // de player ko nhan w tren 2 lan
		jump_up();
    }
}
// ----------------- //
void jump_up(){
	falling_time = 0;
	y_coordinates-=2;
	create_dinosaur();// jump_up len 2 o
	gotoxy(x_coordinates-2,y_coordinates+2); // y = 21 (chua bi tru) khi bi giam 2 lan thanh y = 19 => xoa y= 21 va y=22 
	cout <<"     ";
	gotoxy(x_coordinates,y_coordinates+3);
	cout <<"    ";
}
// ----------------- //
void fall(){
	y_coordinates+=2; //  jump_up xuong 2 o
	create_dinosaur();
	gotoxy(x_coordinates-2,y_coordinates-2);// y = 21 (da cong vao) => xoa y = 20 va y = 19
	cout <<"      ";
	gotoxy(x_coordinates,y_coordinates-1);
	cout <<"    ";	
}
// ----------------- //
void input(void){
	char t;
	t = getch();
	if(t == 'w'&&y_coordinates == 21) // de player ko nhan w tren 2 lan
		jump_up();
		
}
// tinh diem va tang time chay cua cay
void points(){
	for(int i = 0;i< sl ;i++){
		if(tree[i] == x_coordinates -1 ){ //  qua 2 chan +1 diem
			point++;
			if(speed>3)	speed--;
		}
	}
}
// ----------------- //
void lose(){
	if( y_coordinates+1 == 22 && check()==false)
		res = false;
}
// ----------------- //
bool check(){
	for(int i = 0;i< sl ;i++){
		if(tree[i]==tmp+1||tree[i]==tmp) // neu cha.m 1 trong 2 chan thi chet
			return false;
	}
	return true;
}
// Nguyen Tam
