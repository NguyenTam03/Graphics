#include<iostream>
#include<mylib.h>
#include<time.h>
using namespace std;
#define FOR(i,r,l) for(int i=r;i<l;i++)
int y = 0;
char pai =219;
bool res = false;
int point1(0),point2(0);
void remove(int x);
void move(int x,char a);
void ve_canh();
void nhap(int &x,char &random);
void start(int &x,char &random);
void ty_so();
void result();
int main(){
	srand(time(NULL));
	int tmp = rand()%25;
	int x = tmp + 2*(tmp+1);
	char random = tmp + 65;
	while(true){
		ve_canh();
		ShowCur(0);
		remove(x);
		move(x,random);
		if (_kbhit()){
			nhap(x,random);
		}	
		if(y==20){
			point1++;
			start(x,random);
		}
		ty_so();
		Sleep(200);
		result();
		if(res == true)
			break;
	}
	return 0;
}
// Xoa phan tu di qua
void remove(int x){
	gotoxy(x,y);
	cout << " ";	
}
// Di chuyen 
void move(int x,char a){
	y++;
	gotoxy(x,y); //  di chuyen chu~ den y + 1
	cout << a;
}
// Quay lai ban dau
void start(int &x,char &random){	
	gotoxy(x,y);
	cout << " ";
	y = 0;		
	int tmp = rand()%26;
	random = tmp + 65;
	x = tmp + 2*(tmp+1); //  de cac tu` ca'ch nhau ra xa 
}
// Ve cac canh
void ve_canh(){
	char temp = pai + 1;
	SetColor(14);
	FOR(i,0,101){
		gotoxy(i,20);
		cout << temp;
		gotoxy(i,0);
		cout << temp;
	}
	FOR(i,1,21){
		gotoxy(0,i);
		cout <<pai;
		gotoxy(80,i);
		cout <<pai;
		gotoxy(100,i);
		cout <<pai;
	}
	FOR(i,81,100){
		gotoxy(i,10);
		cout << temp;
	}
}
void nhap(int &x,char &random){
		char tmp;
		tmp = getch();
		gotoxy(25,25);
	if(tmp == random|| tmp - 32 == random ){
			point2++;
			start(x,random);
		}
	else{
		point1++;
		start(x,random);	
	}
}
void ty_so(){
	gotoxy(88,1);
	SetColor(2);
	cout<<"-Bot-";
	gotoxy(90,2);
	cout<< point1;
	gotoxy(86,12);
	SetColor(12);
	cout<<"-Player-";
	gotoxy(90,13);
	cout<< point2;
}
void result(){
	if(point1 == 5){
		res = true;
		AllocConsole();
		MessageBox(FindWindowA("ConsoleWindowClass", NULL), "--BOT WIN--", "RESULT", MB_ICONHAND);
	}
	if(point2 == 5){
		res = true;
		AllocConsole();
		MessageBox(FindWindowA("ConsoleWindowClass", NULL), "--PLAYER WIN--", "RESULT", MB_ICONHAND);
	}
}
