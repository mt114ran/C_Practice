#include <stdio.h>

int Factorial(int);

int main(void){

	int x;
	int y;
	int Ans;

	setvbuf(stdout,NULL,_IONBF,0);

	printf("終点のX座標を入力して下さい\n");
	scanf("%d",&x);

	printf("終点のY座標を入力して下さい\n");
	scanf("%d",&y);

	Ans = Factorial(x+y)/(Factorial(x)*Factorial(y));

	printf("始点（0,0）から終点（%d,%d）までの経路の総数は %d です。\n",x,y,Ans);

	return 0;
}


int Factorial(int x){
	int Ans;

	if(x>0){
		Ans = x * Factorial(x-1);
		return Ans;
	}
	else{
		return 1;
	}


}



