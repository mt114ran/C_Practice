#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

	struct playersCard{
	    char name[20];
	    char cards[20];
	};

	int N;
	int CardsInHand;

void HandOutCards(struct playersCard *,int *);
void ShowHands(struct playersCard *);
void DeleteTheSame(struct playersCard *);
void Arrangement(char *, int);


int main(){
	
	printf("How many people do you want to play with ? >>> ");
	scanf("%d",&N);
	CardsInHand = 53/N+1;

	int i,j;
	int CardNum,CardsCount[14];
	int DistributedCard = 0;
	struct playersCard Player[N];

	for(i=0; i<14; i++){
		CardsCount[i] = 0;
	}

	for(i=0; i<N; i++){
		for(j=0; j<CardsInHand; j++){
			Player[i].cards[j] = '\0';
		}
	}

	for(i=0; i<N; i++){
		printf("Name of Player%d ? >>> ",i+1);
		scanf("%s",&Player[i].name);
	}

	printf("\n�z�z�����������J�[�h�i�����\���̌��ʁj\n");
	HandOutCards(Player,CardsCount);
	printf("\n");

	ShowHands(Player);

	printf("\n");
	printf("B�̃J�[�h�̔z�z�����F%d ��\n",CardsCount[0]);
	for(i=1; i<10; i++){
		printf("%d�̃J�[�h�̔z�z�����F%d ��\n",i,CardsCount[i]);
		}
	printf("T�̃J�[�h�̔z�z�����F%d ��\n",CardsCount[10]);
	printf("J�̃J�[�h�̔z�z�����F%d ��\n",CardsCount[11]);
	printf("Q�̃J�[�h�̔z�z�����F%d ��\n",CardsCount[12]);
	printf("K�̃J�[�h�̔z�z�����F%d ��\n",CardsCount[13]);
	printf("\n");

	DeleteTheSame(Player);

	return 0;
}


void HandOutCards(struct playersCard *p_player,int *p_CardsCount){

	int i,j,CardNum;
	int DistributedCard = 0;
	srand(time(NULL));

	j = 0;
	while(1){
		if(DistributedCard == 53) break;
		for(i = 0; i < N; i++) {
			if(DistributedCard == 53) break;
			
    		while(1){
    			CardNum = rand() % 14 ;
    			printf("%d, ",CardNum);
    			
    			if(CardNum == 0){
    				if(*(p_CardsCount+CardNum)<1){
    					(p_player+i)->cards[j] = 'B';
    					(*(p_CardsCount+CardNum))++;
    					DistributedCard++;
    					break;
    				}
    			}else if(*(p_CardsCount+CardNum)<4){
					switch (CardNum) {
						case 10:
							(p_player+i)->cards[j] = 'T';
							break;
						case 11:
							(p_player+i)->cards[j]  = 'J';
							break;
						case 12:
							(p_player+i)->cards[j]   = 'Q';
							break;
						case 13:
							(p_player+i)->cards[j]  = 'K';
							break;
						default:
							(p_player+i)->cards[j]  = '1' + CardNum-1;
							break;
						}
					(*(p_CardsCount+CardNum))++;
					DistributedCard++;
					break;
    			}
    		}
    	}
		j++;
    }
}



void ShowHands(struct playersCard *p_player){
	int i,j;

	for(i=0; i<N; i++){
		printf("\n");
		printf(">>>>>>   PLAYER %d�F%s   <<<<<<<<<<\n",i+1,p_player[i].name);
		printf("��D�F");
		for(j=0; j<CardsInHand; j++){
			if(p_player[i].cards[j] != '\0'){
				printf("%c , ",p_player[i].cards[j]);
				}else break;
			}
		printf("\n��D�̖����F%d ��\n",j);
		}
}



void DeleteTheSame(struct playersCard *p_player){
	int i,j,m,n;
	int flag =0;
	int newhands = 0;
	int HandsSize,DeleteCardsNum;
	char DeleteCards[CardsInHand];

	printf("��D�̃y�A�J�[�h���폜���܂�...\n");

	for(i=0; i<N; i++){
		printf("\n");
		DeleteCardsNum=0;
		for(n=0; n<CardsInHand;n++){
			DeleteCards[n] = '\0';
			}

		printf(">>>>>>   PLAYER %d�F%s   <<<<<<<<<<\n",i+1,p_player[i].name);
		printf("�����O�̎�D�F");
		for(j=0; j<CardsInHand; j++){
			if(p_player[i].cards[j] != '\0'){
				printf("%c , ",p_player[i].cards[j]);
				}else break;
			}
		HandsSize = j;
		printf("\n�����O�̎�D�����F%d ��\n",HandsSize);
		printf("...Delete...\n");

		j =0;
		while(p_player[i].cards[j]!='\0'){
			flag =0;
				for(m=1; m+j<=HandsSize; m++){
					if(p_player[i].cards[j] == p_player[i].cards[j+m]){
						DeleteCards[DeleteCardsNum] = p_player[i].cards[j];
						DeleteCardsNum++;
						DeleteCards[DeleteCardsNum] = p_player[i].cards[j+m];
						DeleteCardsNum++;
						Arrangement(p_player[i].cards,j+m);
						Arrangement(p_player[i].cards,j);
						flag++;
						break;
						}
					}
			if(flag==0) j++;
		}



		
		newhands = 0;
		
		for(j=0; j<CardsInHand; j++){
			if(p_player[i].cards[j] != '\0'){
				//printf("%c , ",p_player[i].cards[j]);
				newhands++;
				}
			}
		


		for(j=newhands; j<CardsInHand; j++){
			p_player[i].cards[j] = '\0';
			}


		printf("�폜�����J�[�h�F");
		for(j=0; j<HandsSize; j++){
			if(DeleteCards[j] != '\0'){
				printf("%c , ",DeleteCards[j]);
				}else break;
			}
		printf("\n�폜����J�[�h�̖����F%d ��\n",j);

		printf("...Post-deletion hand...\n");
		printf("������̎�D�F");

		HandsSize = 0;
		for(j=0; j<CardsInHand; j++){
			if(p_player[i].cards[j] != '\0'){
				printf("%c , ",p_player[i].cards[j]);
				HandsSize++;
				}
			}
		printf("\n������̎�D�����F%d ��\n",HandsSize);
		}
}

void Arrangement(char *Cards,int i){
	while(Cards[i]!='\0'){
		Cards[i] = Cards[i+1];
		i++;
	}
}
