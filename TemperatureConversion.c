/*
 * Task1_TemperatureConversion.c
 *
 *  Created on: 2020/05/25
 *      Author: 新宿MBD研修9
 */


#include <stdio.h>

int main(void){

	char character;
	float value;

	setvbuf(stdout,NULL,_IONBF,0);

	printf("温度を単位（大文字でCまたはF)を入れて入力して下さい\n");
	scanf("%f%c",&value,&character);

	switch(character){
		case 'C':
			printf("摂氏 %4.2f [C]を華氏に変換すると %4.2f [F]である。\n",value,9*value/5 + 32);
			break;

		case 'F':
			printf("華氏 %4.2f [F]を摂氏に変換すると %4.2f [C]である。\n",value,5*(value-32)/9);
			break;

		default:
			printf("単位記号指定に誤りがあります。\n");
			break;
	}

	return 0;

}
