/*
 * RAND.c
 *
 *  Created on: 2020/07/28
 *      Author: maitatomoya
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
#define CardsInHand 53/N+1

int main(){

	int i,CardNum;
	srand(time(NULL));// 現在時刻の情報で初期化
	for(i=0;i<5;i++){
		CardNum = rand() % 14 ;//カードの種類をランダムに取得
		printf("%d\n",CardNum);
		}
	return 0;
}
