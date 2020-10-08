#include <stdio.h>
#include <math.h>

void QuadEq(float,float,float,double*,double*);

int main(void){

	float a;
	float b;
	float c;
	double x1;
	double x2;

	setvbuf(stdout,NULL,_IONBF,0);

	printf("X^2の係数を入力して下さい\n");
	scanf("%f",&a);

	printf("Xの係数を入力して下さい\n");
	scanf("%f",&b);

	printf("定数項の値を入力して下さい\n");
	scanf("%f",&c);


	if(a==0){
		printf("X^2の係数は0以外の数を入力して下さい\n");
	}
	else{
		QuadEq(a,b,c,&x1,&x2);

		if(b*b-4*a*c>=0)
			printf("解は %.3f , %.3f です。\n",x1,x2);
		else{
			printf("解は %.3f+%.3fi , %.3f-%.3fi です。\n",x1,x2,x1,x2);
		}
	}
	return 0;
}


void QuadEq(float a,float b,float c,double *x1,double *x2){

	if(b*b-4*a*c >= 0){
		*x1 = (-b + sqrt(b*b-4*a*c))/(2*a);
		*x2 = (-b - sqrt(b*b-4*a*c))/(2*a);
	}
	else if(b*b-4*a*c == 0){
		*x1 = (-b)/(2*a);
		*x2 = *x1;
	}
	else{
		*x1 = (-b)/(2*a);
		*x2 = sqrt(-(b*b-4*a*c))/(2*a);
	}
}

