#include<iostream>
#include<mylib.h>
using namespace std;
#define FOR(i,r,l)	for(int i=r;i<l;i++)
string s[4] = {"option 1", "option 2","option 3","option 4"};
int a[4]={2,0,0,0};
int nextBG(-1);
void create_frame();
void choose();
void option_1();
void option_2();
void option_3();
void option_4();
void input();
void hello1(){
	SetBGColor(a[0]);
	gotoxy(12,13);
	cout << "hello_1"; 
	SetBGColor(0);
}
int main(){		
	while(1){
		ShowCur(0);
		create_frame();
		if(nextBG==-1)		choose();
		else{
			switch(nextBG){
				case 0:
					hello1();
				break;
				case 1:
				break;
				case 2:
				break;
				case 3:
				break;
			}
		}
		input();
	}
}
void create_frame(){
	SetColor(14);
	FOR(i,11,20){
		gotoxy(10,i);
		cout << char(219);
		gotoxy(21,i);
		cout << char(219);
	}
	FOR(i,10,22){
		gotoxy(i,10);
		cout << char(220);
		gotoxy(i,20);
		cout << char(223);
	}
}
void option_1(){
	SetBGColor(a[0]);
	gotoxy(12,13);
	cout << s[0]; 
}
void option_2(){
	SetBGColor(a[1]);
	gotoxy(12,14);
	cout << s[1]; 
}
void option_3(){
	SetBGColor(a[2]);
	gotoxy(12,15);
	cout << s[2]; 
}
void option_4(){
	SetBGColor(a[3]);
	gotoxy(12,16);
	cout << s[3]; 
}
void choose(){
	option_1();
	option_2();
	option_3();
	option_4();
	SetBGColor(0); //  huy background 
}
int pos = 0;
void input(){
	int key;
	if(kbhit()){
		key = getch();
		if(key==224){ //  dieu kien cua cac nut up down left right
			do {
            	key=getch();
        	}while(key==224);
        	if(key == 72 && pos > 0){ // up 
        		pos--;// di chuyen len
        		FOR(i,0,4){
        			if(i==pos)	a[i]=2; // danh dau o^ duoc chon = 2
        			else a[i] = 0; // co`n lai gan = 0
				}
			}
			if(key == 80 && pos < 3){ // down  thay 3 = variable 
        		pos++; //  di chuyen xuong
        		FOR(i,0,4){
        			if(i == pos)	a[i]=2;
        			else a[i] = 0;
				}
			}
		}
		if(key== 13){ //  enter
			clrscr();
			nextBG = pos;
		}
	}
}
