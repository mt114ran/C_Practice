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

//�v���g�^�C�v�錾
void HandOutCards(struct playersCard *,int *);//�J�[�h��z�z����֐�
void ShowHands(struct playersCard *);//��D��\������֐�
void DeleteTheSame(struct playersCard *);//��D���̂Q������J�[�h���폜����֐�
void Arrangement(char *, int);//��D�𐮗�����֐�

//���C���֐�
int main(){
	//�v���C���[�̐l���w��
	printf("How many people do you want to play with ? >>> ");
	scanf("%d",&N);
	CardsInHand = 53/N+1;

// �ϐ��E�\���̂̐錾�Ə�����
//	========================
	int i,j;
	int CardNum,CardsCount[14];
	int DistributedCard = 0;
	struct playersCard Player[N];

//	�z��CardsCount[i]�̏�����
	for(i=0; i<14; i++){
		CardsCount[i] = 0;
	}
//	�z�z�J�[�h�L�^�p�z��Ƀi������������
	for(i=0; i<N; i++){
		for(j=0; j<CardsInHand; j++){
			Player[i].cards[j] = '\0';
		}
	}

//	�v���C���[�̖��O�����
	for(i=0; i<N; i++){
		printf("Name of Player%d ? >>> ",i+1);
		scanf("%s",&Player[i].name);
	}

//�J�[�h�̔z�z�i�O���֐��g�p�j
	printf("\n�z�z�����������J�[�h�i�����\���̌��ʁj\n");
	HandOutCards(Player,CardsCount);
	printf("\n");


//�v���C���[���i���O�Ǝ�D�j�̕\���i�O���֐��g�p�j
	ShowHands(Player);

//�e�J�[�h�̔z�z������\��
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

//��D���̂Q������J�[�h���폜�i�O���֐��g�p�j
	DeleteTheSame(Player);

	return 0;
}


//�J�[�h��z�z����֐�
void HandOutCards(struct playersCard *p_player,int *p_CardsCount){
	//�ϐ��̐錾
	int i,j,CardNum;
	int DistributedCard = 0;
	srand(time(NULL));// ���ݎ����̏��ŏ�����

	j = 0;
	while(1){
		if(DistributedCard == 53) break;
		for(i = 0; i < N; i++) {
			if(DistributedCard == 53) break;
			//�J�[�h����ꂽ�玟�̃v���C���[�ɔz��

    		while(1){
    			CardNum = rand() % 14 ;//�J�[�h�̎�ނ������_���Ɏ擾
    			printf("%d, ",CardNum);
    			//�܂����̃J�[�h���z�z�\�ł���Έȉ������s
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
					break;//�P���z�z�ł�����while�𔲂���
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



//��D���̂Q������J�[�h���폜����֐�
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

		//�y�A�J�[�h���L�^���č폜����
		j =0;
		//���ׂĂ����J�[�h���k�������łȂ���Ώd���������J�n
		while(p_player[i].cards[j]!='\0'){
			flag =0;
//				j�Ԗڂ̃J�[�h�ɂ��đ��ɓ����J�[�h���Ȃ����m���߂�
				for(m=1; m+j<=HandsSize; m++){
//					�����d������J�[�h���������Ȃ�A�L�^���Ă���폜����������߂�flag�����Ă�
					if(p_player[i].cards[j] == p_player[i].cards[j+m]){
						DeleteCards[DeleteCardsNum] = p_player[i].cards[j];
						DeleteCardsNum++;
						DeleteCards[DeleteCardsNum] = p_player[i].cards[j+m];
						DeleteCardsNum++;
						Arrangement(p_player[i].cards,j+m);
						Arrangement(p_player[i].cards,j);
						flag++;
						break;//�폜���s������d���������ŏ������蒼��
						}
					}//�P���̃J�[�h�̏d�������I��
			if(flag==0) j++;//�����d���J�[�h���P�����Ȃ��̂ł���Β�������J�[�h��ς���
			}



		//�폜��̐V������D�̖������J�E���g
		newhands = 0;
		//printf("�������̎�D�F");
		for(j=0; j<CardsInHand; j++){
			if(p_player[i].cards[j] != '\0'){
				//printf("%c , ",p_player[i].cards[j]);
				newhands++;
				}
			}
		//printf("\n");


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

//�����񒆂̎w�肳�ꂽ
void Arrangement(char *Cards,int i){
	while(Cards[i]!='\0'){
		Cards[i] = Cards[i+1];
		i++;
	}
}
