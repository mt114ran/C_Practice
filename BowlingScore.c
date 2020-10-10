#include <stdio.h>

struct FRAME{
	int no1;
	int no2;
	int no3;
	int score;
}Frame[10] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

void ReadScore();

void CalcScore();

void PrintScore();

int ScoreAll;





int main(void){

	setvbuf(stdout,NULL,_IONBF,0);

	ReadScore();

	CalcScore();

	PrintScore();

	return 0;
}





void ReadScore(){

	int i;
	int cnt=0;

	for(i=0;i<10;i++){

		cnt++;

		printf("%dフレーム目の１投目を入力して下さい\n",cnt);
		scanf("%d",&Frame[i].no1);

		if(Frame[i].no1 < 10 || cnt ==10){
			printf("%dフレーム目の２投目を入力して下さい\n",cnt);
			scanf("%d",&Frame[i].no2);
			}

		if(cnt ==10 && Frame[i].no1 + Frame[i].no2 == 10){
			printf("%dフレーム目の３投目を入力して下さい\n",cnt);
			scanf("%d",&Frame[i].no3);
			}
		}
	printf("特典が入力されました。\n");
}




void CalcScore(){

	int i;
	int cnt=0;

	for(i=0;i<10;i++){
		Frame[i].score = Frame[i].no1 + Frame[i].no2 + Frame[i].no3;
		ScoreAll += Frame[i].score
	}
}





