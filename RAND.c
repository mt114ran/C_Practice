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
	srand(time(NULL));// ���ݎ����̏��ŏ�����
	for(i=0;i<5;i++){
		CardNum = rand() % 14 ;//�J�[�h�̎�ނ������_���Ɏ擾
		printf("%d\n",CardNum);
		}
	return 0;
}
