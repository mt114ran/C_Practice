/*
 * memcpy.c
 *
 *  Created on: 2020/08/03
 *      Author: maitatomoya
 */


/*
 * BaBaNuki_5_Func_DeleteTheSame.c
 *
 *  Created on: 2020/07/31
 *      Author: maitatomoya
 *      •Ä“c’qÆ
 *      èD‚Ìd•¡‚ğíœ‚·‚é
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){

	char str1[] = {"ABCDEFG"};
	char str2[] = {"1234567"};

//	memcpy(str1,str2,3);
	printf("%c\n",str1[2]);


	memcpy(str1,str2,7);
	str1[3] = '\0';
	printf("%c\n",str1[3]);
	printf("%s",str1);

	return 0;
}

