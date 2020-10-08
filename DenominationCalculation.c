#include <stdio.h>

int CompChange(int,int);

int main(void){

	int Coins[]={500,100,50,10,5,1};
	int price;
	int payment;
	int num;
	int Change;

	setvbuf(stdout,NULL,_IONBF,0);

	printf("値段を入力して下さい\n");
	scanf("%d",&price);

	printf("支払金額を入力して下さい\n");
	scanf("%d",&payment);


	if(price<payment){
		Change = payment-price;
		printf("お釣りは %d 円です。\n",Change);

		printf("お釣りの硬貨は\n");
		for(num=0;num<6;num++){
			if(CompChange(Change,Coins[num])!=0){
				printf("%d 円硬貨が%d枚\n",Coins[num],CompChange(Change,Coins[num]));
			}
			Change -= Coins[num] * CompChange(Change,Coins[num]);
		}
	}
	else if(price==payment){
		printf("ちょうどお預かりしました。");
	}
	else{
		printf("支払金額が %d 円不足しています。\n",price-payment);
	}

	return 0;
}


int CompChange(int x,int y){
	int n;
	n = x/y;
	return n;
}

