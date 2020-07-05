#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

char get_level() {
    printf("Choix de niveau \n");
    printf(" niveau 1 : 100 tentative \n");
	printf(" niveau  2: 25 tentative\n");
	printf(" niveau 3: 10 tentative \n");
    
    char level; 
    int b = 0;
    do{
    	printf("taper (1) ou (2) ou (3) selon le niveau : ");
        scanf("%c", &level);
       
        if((level == '1') || (level == '2') || (level == '3')){
            b=1;
        }
        else {
            b=0;
        }
    }while(b==0);
  return level;
}
int get_number() {
    printf("\033[0;32m");
    printf("veuillez saisir un chiffre entre 0 et 100 : ");
    printf("\033[0m");
    int number;
    
    int b = 0;
    do{
        scanf("%d", &number);
        
        if((number >= 0) && (number <= 100)){
            b=1;
        }
        else {
            b=0;
        }
    }while(b==0);
  return number;
}
int play(){
    time_t t;
    srand((unsigned) time(&t));
    int value = rand() % 99;
    printf("%d \n",value);
    int  tentative = 0;
    int point;
    int level = get_level();
    switch(level){
        case '1' :
            tentative = 100;
            break;
        case '2' :
            tentative = 25;
            break;
        case '3' :
            tentative = 10;
    }
    int b=0;
    int essai = 0;
    do{
        if(essai <=tentative){
            essai++;
            int guess = get_number();
            if(guess>value){
                printf("\033[1;31m");
                printf(" plus !!!\n");
                printf("\033[0m");
            }
            else if(guess<value){
                printf("\033[1;31m");
                printf("moins !!!\n");
                printf("\033[0m");
            }
            else{
                b=1;
                point = tentative - essai + 1;
                printf("\033[032m");
       			printf("bingo  !!!\n");
        		printf("\033[0m");
        		printf("votre point(s): %d\n", point);
        		sleep(3);
        		system("cls");           
			}
        }
        else{
            b=2;
            printf("\033[1;31m");
        	printf("tentative terminé !!!");
        	printf("\033[0m");
        }
    }while (b==0);
    return point;
}
int main()
{   
	int cont = 0;
	int mode = 0;
	printf("=== PLUS OU MOINS ===\n\n");
    printf("Le but du jeu est de deviner le nombre mystere !\n\n");
    do{
        printf("=== MENU ===\n");
        printf("Choisissez un mode de jeu : \n");
        printf("1. Mode solo\n");
        printf("2. Mode multijoueur\n");
        do
        {
 
        	printf("Votre choix ? ");
        	scanf("%d", &mode);
        	system("cls");
        	}while(mode < 1 || mode > 2);
        	if(mode == 1)
        	{
        		int jou = play();
        		
			}
			else
			{
				printf("..............joueur 1.............\n");
				int joueur1 = play();
			
				printf(".............joueur2...........\n");
				int joueur2 = play();
				if ( joueur1 < joueur2)
				{
					printf(" le gagnant est joueur2 ");
				}
				else if(joueur1 > joueur2)
				{
					printf("le gagnat est joueur1");
				}
				else
				{
					printf("vous etes a egalite");
				}
			
			}
			printf("\n------------------------------------\n");
    		printf("Souhaitez-vous refaire une partie ?\n");
  	    	printf("1. Oui\n");
       		 printf("2. Non\n");
        	printf("Votre choix ? ");
        	scanf("%d", &cont);
        	printf("-------------------------------------\n\n");
        	system("cls");
 
	}while( cont == 1);
    return 0;
}
