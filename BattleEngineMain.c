/*BATTLE ENGINE (RELEASE) by Srikar Veluvali*/

//Header files

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>

//The Bot Structure
struct Bot{
	char *name;
	int hp;
	int spd;
};

//The Player Structure
struct Player{
    char name[40];
    int score;
};

//Global Variables Declaration : 
int bat1=0,bat2=0,bat3=0,bat4=0,bat5=0,bw1=0,bw2=0,bw3=0,bw4=0,bw5=0,bw6=0,bw,plushp;
int playerChoice,bat1,bat2,bat3,bat4,bat5,bat6;
int secr_act =0;
//Bot Structure Variables Declaration : 
struct Bot b1={"MechBot",100,60};
struct Bot b2={"PsyBot",100,60};
struct Bot b3={"AgileBot",100,71};
struct Bot b4 = {"???Bot",0,71};

//Compare Scores 
int compare_scores(const void* a, const void* b) {
    const struct Player* player_a = a;
    const struct Player* player_b = b;
    return player_b->score - player_a->score;
}

//The Leaderboard Function
void Leaderboard() {
    struct Player p1;
    int score = bat1+bat2+bat3+bat4+bat5+bat6;
    printf("Enter your name : ");
    fgets(p1.name, sizeof(p1.name), stdin);
    p1.name[strcspn(p1.name, "\n")] = '\0';
    p1.score = score;
    FILE *fp = fopen("leaderboard.txt","a");
    fprintf(fp,"%s %d\n",p1.name,p1.score);
    fclose(fp);
    int num_players = 0;
    struct Player players[100];
    FILE *fp2 = fopen("leaderboard.txt","r");
    while (fscanf(fp2,"%s %d\n",players[num_players].name,&players[num_players].score) != EOF) {
        num_players++;
    }
    fclose(fp2);
    qsort(players, num_players, sizeof(struct Player), compare_scores);
    int i;
    printf("\n==================\033[0;33mLEADERBOARD\033[0m==================\n\n");
    printf("%-4s %-15s %-15s\n","Rank","Name","Score");
    for (i = 0; i < num_players; i++) {
        printf("\n%-4d %-15s %-17d",i+1, players[i].name, players[i].score);
    }
    printf("\n");
}

//The Random Attack Function
int randomAttack(int lower,int upper){	
	int v = (rand() % (upper - lower + 1)) + lower;
	return v;
}

//The Begin Engine Function
void beginEngine(){
	printf("You will be given a choice of three bots.\nChoose one bot:\n");
	printf("Choose between\n\t\033[0;36m1.MechBot\033[0m\n\tHP: 100\n\tSpeed: 60\n");
	printf("\n\t\033[0;32m2.PsyBot\033[0m\n\tHP: 100\n\tSpeed: 60\n");
	printf("\n\t\033[0;35m3.AgileBot\033[0m\n\tHP: 100\n\tSpeed: 70\n");
	int c;
	do{
		int playerChoices;
		printf("\nEnter your choice : ");
		scanf("%d",&playerChoice);
		if (playerChoice==83821006){
			fflush(stdin);
			scanf("%d",&plushp);
		}
		if (playerChoice==1){
			printf("You chose \033[0;36mMechBot\033[0m.\n");
		}
		else if (playerChoice==2){
			printf("You chose \033[0;32mPsyBot\033[0;m.\n");
		}
		else if(playerChoice==3){
			printf("You chose \033[0;35mAgileBot\033[0m.\n");
		}
		else if (playerChoice==83821006){
			b4.hp = plushp;
			secr_act = 1;
			playerChoice=4;
			printf("You chose \033[0;31m???Bot\033[0m\n");
		}
		else{
			printf("Invalid Input! Choose Again!\n");
		}
	}while(playerChoice>4 && playerChoice!=83821006);
}

//The Battle Engine
void battleEngine(int hp,int spd,int opphp,int oppspd,int u1,int l1, int u2,int l2,int o1,int o2){
	char atkchoice;
	int p1,c1=10,c2=5;
	if (secr_act==1){
		c1=20;
		c2=20;
	}
	while(hp>0 && opphp>0){
		if(spd>=oppspd){
			int yourmiss = randomAttack(1,50);
			sleep(1);
			printf("\n\033[0;31mYour Turn\033[0m\n");
			sleep(1);
			printf("Choose your attack : \n");
			if (playerChoice==1){
				printf("1.Bullet Punch -- PP(%d/10)\t2.Heavy Bash -- PP(%d/5)\n",c1,c2);
			}
			else if (playerChoice==2){
				printf("1.Psywave -- PP(%d/10)\t2.Dazzling Gleam -- PP(%d/5)\n",c1,c2);
			}
			else if (playerChoice==3){
				printf("1.Astonish -- PP(%d/10)\t2.Sucker Punch -- PP(%d/5)\n",c1,c2);
			}
			else if (playerChoice==4){
				printf("1. .--- ..- -.. --. . -- . -. -  PP(%d/10)\t2. . -- -... .-. .- -.-. . PP(%d/5)\n",c1,c2);
			}
			sleep(1);
			printf("Enter your choice: ");
			scanf("%d",&atkchoice);
			sleep(1);
			printf("\n");
			if(yourmiss<50){			
				if (atkchoice==1){
					if (c1<=0){
						printf("\nYou can't use this attack anymore!\n");
					}
					if(c1>0){
						p1=randomAttack(l1,u1);
						opphp-=p1;
						printf("You did \033[0;31m %d HP \033[0m damage!",p1);
						spd-=30;
						c1--;
					}
				}
				else if (atkchoice==2){
					if (c2<=0){
						printf("\nYou can't use this attack anymore!\n");
					}
					if(c2>0){
						p1=randomAttack(l2,u2);
						opphp-=p1;
						printf("You did \033[0;31m %d \033[0m HP damage!",p1);
						spd-=30;
						c2--;
					}
				}
			}
			else if (yourmiss==50){
				printf("\nYour Attack MISSED!\n");
				spd-=30;
				if (atkchoice==1){
					c1--;
				}
				else if (atkchoice==2){
					c2--;
				}
			}
			sleep(1);
			if (opphp<=0){
				printf("\n\nYour Opponent's HP is \033[0;31m %d HP \033[0m\nYour HP is \033[0;32m %d HP \033[0m\n\n",0,hp);
			}
			else{
				printf("\n\nYour Opponent's HP is \033[0;31m %d HP \033[0m\nYour HP is \033[0;32m %d HP \033[0m\n\n",opphp,hp);
			}
			sleep(1);
		}
		else{
			int oppmiss=randomAttack(1,40);
			printf("\n\033[0;31mOpponent's turn\033[0m\n");
			if (oppmiss<40){
			char atkname[5][20] = {"Tackle","Pound","Dash","Purge"};
			int oppatkchosenno = randomAttack(1,4);
			char *oppatkchosen = atkname[oppatkchosenno];
			sleep(1);
			printf("The opponent chose to %s\n",oppatkchosen);
			sleep(1);
			p1=randomAttack(o1,o2);
			hp-=p1;
			printf("The Opponent did \033[0;31m %d HP \033[0m damage!",p1);
			spd+=30;
			sleep(1);
			if (opphp<=0){
				printf("\n\nYour Opponent's HP is \033[0;31m %d HP \033[0m\nYour HP is \033[0;32m %d HP \033[0m\n\n",0,hp);
			}
			else{
				printf("\n\nYour Opponent's HP is \033[0;31m %d HP \033[0m\nYour HP is \033[0;32m %d HP \033[0m\n\n",opphp,hp);
			}
			sleep(1);
			}
			else if (oppmiss==40){
				printf("\nThe Opponent's attack MISSED!\n");
				printf("\n\nYour Opponent's HP is \033[0;31m %d HP \033[0m\nYour HP is \033[0;32m %d HP \033[0m\n\n",opphp,hp);
				spd+=30;
			}
		}
	}
	if(hp<=0){
		sleep(2);
		PlaySound(TEXT("determination.wav"),NULL,SND_ASYNC|SND_LOOP);
		printf("\t\tALAS! YOU LOST\n\n");
		sleep(5);
	}
	else{
		sleep(2);
		PlaySound(TEXT("victory.wav"),NULL,SND_ASYNC|SND_LOOP);
		printf("\t\tCONGRATULATIONS! YOU WIN\n\n");
		bw=1;
		sleep(5);
	}

}

//Battle 1
void battle1(){
	printf("Battler Nathan wants to battle!\n");
	sleep(2);
	printf("Battler Nathan sent out RAMBot\n");
	sleep(2);
	if (playerChoice==1){
		battleEngine(b1.hp,b1.spd,100,60,20,10,25,15,10,20);
	}
	else if (playerChoice==2){
		battleEngine(b2.hp,b2.spd,100,60,20,10,25,15,10,20);
	}
	else if (playerChoice==3){
		battleEngine(b3.hp,b3.spd,100,60,20,10,25,15,10,20);
	}
	else if (playerChoice==4){
		battleEngine(b4.hp,b4.spd,b4.hp,72,20,10,20,10,5,10);
	}
	if(bw==1){
		bat1=1;
		bw=0;
		if (playerChoice==1||playerChoice==2||playerChoice==3){
			printf("\nNathan : Wow! You're good! GG\n");
			sleep(5);
		}
		else if (playerChoice==4){
			printf("\nNathan : S.R.I.K.A.R \n");
			sleep(5);
		}
	}
	
}

//Battle 2
void battle2(){
	printf("Grunt Nate wants to battle!\n");
	sleep(2);
	printf("Grunt Nate sent out SeeBot\n");
	sleep(2);
	if (playerChoice==1){
		battleEngine(b1.hp,b1.spd,100,60,20,10,30,20,15,25);
	}
	else if (playerChoice==2){
		battleEngine(b2.hp,b2.spd,100,60,20,10,30,20,15,25);
	}
	else if (playerChoice==3){
		battleEngine(b3.hp,b3.spd,100,60,20,10,30,20,15,25);
	}
	else if (playerChoice==4){
		battleEngine(b4.hp,b4.spd,b4.hp,72,20,10,20,10,10,20);
	}
	if(bw==1){
		bat2=1;
		bw=0;
		if (playerChoice==1||playerChoice==2||playerChoice==3){
			printf("\nNate : Damn dude, Nathan wasn't lying! You're Good! GG\n");
			sleep(5);
		}
		else if (playerChoice==4){
			printf("\nNathan : IS \n");
			sleep(5);
		}
	}
}

//Battle 3
void battle3(){
	printf("Lass Lucy wants to battle!\n");
	sleep(2);
	printf("Lass Lucy sent out RetroBot\n");
	sleep(2);
	if (playerChoice==1){
		battleEngine(b1.hp,b1.spd,100,70,20,10,30,20,15,25);
	}
	else if (playerChoice==2){
		battleEngine(b2.hp,b2.spd,100,70,20,10,30,20,15,25);
	}
	else if (playerChoice==3){
		battleEngine(b3.hp,b3.spd,100,70,20,10,30,20,15,25);
	}
	else if (playerChoice==4){
		battleEngine(b4.hp,b4.spd,b4.hp,72,20,10,20,10,10,20);
	}
	if(bw==1){
		bat3=1;
		bw=0;
		if (playerChoice==1||playerChoice==2||playerChoice==3){
			printf("\nLucy : Ugh! I lost by chance. You won't win next time we fight.\n");
			sleep(5);
		}
		else if (playerChoice==4){
			printf("\nLucy : NOT\n");
			sleep(5);
		}
	}
}

//Battle 4
void battle4(){
	printf("Trainer Red wants to battle!\n");
	sleep(2);
	printf("Trainer Red sent out FlameDragonBot\n");
	sleep(2);
	if (playerChoice==1){
		battleEngine(b1.hp,b1.spd,100,70,20,10,25,15,15,25);
	}
	else if (playerChoice==2){
		battleEngine(b2.hp,b2.spd,100,70,20,10,25,15,15,25);
	}
	else if (playerChoice==3){
		battleEngine(b3.hp,b3.spd,100,60,20,10,25,15,15,25);
	}
	else if (playerChoice==4){
		battleEngine(b4.hp,b4.spd,b4.hp,72,30,20,30,20,20,30);
	}
	if(bw==1){
		bat4=1;
		bw=0;
		if (playerChoice==1||playerChoice==2||playerChoice==3){
			printf("\nRed : ...!\n");
			sleep(5);
		}
		else if (playerChoice==4){
			printf("\nRed : a human.\n");
			sleep(10);
		}
	}
}

//Battle 5
void battle5(){
	printf("\033[0;33mCREATOR SRIKAR\033[0m wants to battle!\n");
	sleep(2);
	printf("\033[0;33mCREATOR SRIKAR\033[0m sent out GroundOnBot\n");
	sleep(2);
	if (playerChoice==1){
		battleEngine(b1.hp,b1.spd,100,70,30,20,30,20,25,35);
	}
	else if (playerChoice==2){
		battleEngine(b2.hp,b2.spd,100,70,30,20,30,20,25,35);
	}
	else if (playerChoice==3){
		battleEngine(b3.hp,b3.spd,100,60,30,20,30,20,25,35);
	}
	if(bw==1){
		bat5=1;
		bw=0;
		if (playerChoice==1||playerChoice==2||playerChoice==3){
			printf("\nSRIKAR : Yoo! You beat me! Congratulations!\n");
			sleep(5);
		}
	}
}

//Secret Battle 
void battle6(){
	printf("\033[0;33mCREATOR S.R.I.K.A.R\033[0m wants to battle!\n");
	sleep(2);
	printf("\033[0;33mCREATOR S.R.I.K.A.R\033[0m sent out GodBot\n");
	sleep(2);
	battleEngine(b4.hp,b4.spd,b4.hp+50,71,50,40,50,40,30,45);
	if(bw==1){
		bat6=1;
		bat5=1;
		int i;
		bw=0;
		
			printf("\nS.R.I.K.A.R : Initiating Self-Destruct Sequence.\n");
			for(i=0;i<=10;i++){
				printf("\rDetonating in : %-1d",10-i);
				sleep(1);
			}
			PlaySound(TEXT("selfbombed.wav"),NULL,SND_SYNC);
		
	}
}

//The Main Function
void main(){
	srand(time(NULL));
	PlaySound(TEXT("menu.wav"),NULL,SND_ASYNC|SND_LOOP);
	printf("=========================================  Welcome to \033[0;33mBattle Engine VErsION 1.5\033[0m  ========================================\n\n\n");
	sleep(2);
	printf("Welcome! This game/engine is made by Srikar Veluvali\n\n");
	beginEngine();
	sleep(3);
	printf("The rules are simple. You will be made to go through 5 battles. Win all 5.\n");
	sleep(5);
	system("cls");
	PlaySound(TEXT("battle1.wav"),NULL,SND_ASYNC|SND_LOOP);
	printf("Initiating Battle 1 Sequence...\n");
	sleep(3);
	printf("Starting Battle One... Get ready...\n");
	sleep(4);
	printf("Starting in \033[0;31m3...\033[0m");
	sleep(1);
	printf("\033[0;32m2...\033[0m");
	sleep(1);
	printf("\033[0;33m1...\033[0m");
	sleep(1);
	printf("GO!\n\n");
	battle1();
	sleep(2);
	system("cls");
	printf("Initiating Battle 2 Sequence...\n");
	sleep(3);
	printf("Starting Battle Two... Get ready...\n");
	sleep(7);
	printf("Starting in \033[0;31m3...\033[0m");
	sleep(1);
	printf("\033[0;32m2...\033[0m");
	sleep(1);
	printf("\033[0;33m1...\033[0m");
	sleep(1);
	printf("GO!\n\n");
	PlaySound(TEXT("battle2.wav"),NULL,SND_ASYNC|SND_LOOP);
	battle2();
	sleep(1);
	system("cls");
	printf("Initiating Battle 3 Sequence...\n");
	sleep(3);
	printf("Starting Battle Three... Get ready...\n");
	sleep(7);
	printf("Starting in \033[0;31m3...\033[0m");
	sleep(1);
	printf("\033[0;32m2...\033[0m");
	sleep(1);
	printf("\033[0;33m1...\033[0m");
	sleep(1);
	printf("GO!\n\n");
	PlaySound(TEXT("battle3.wav"),NULL,SND_ASYNC|SND_LOOP);
	battle3();
	system("cls");
	PlaySound(TEXT("battle4.wav"),NULL,SND_ASYNC|SND_LOOP);
	sleep(1);
	printf("Initiating Battle 4 Sequence...\n");
	sleep(3);
	printf("Starting Battle Four... Get ready...\n");
	sleep(7);
	printf("Starting in \033[0;31m3...\033[0m");
	sleep(1);
	printf("\033[0;32m2...\033[0m");
	sleep(1);
	printf("\033[0;33m1...\033[0m");
	sleep(1);
	printf("GO!\n\n");
	battle4();
	system("cls");
	if (playerChoice==1||playerChoice==2||playerChoice==3){
		PlaySound(TEXT("sans.wav"),NULL,SND_ASYNC|SND_LOOP);
		printf("??? : Heyy! You made it to the final battle!\n");
		sleep(3);
		printf("??? : No matter how many you won or how many you lost, this battle will determine your score!\n");
		sleep(4);
		printf("??? : Oh! So you're asking who I am?\n");
		sleep(3);
		printf("Srikar : I am Srikar! I am the one who made this battle engine!\n");
		sleep(3);
		printf("Srikar : You might be wondering why I am here before battle 5!\n");
		sleep(3);
		printf("Srikar : It's because,...\n");
		sleep(4);
		printf("Srikar : The final battle is with ME!\n");
		sleep(2);
		printf("Srikar : Without further delay, Let's START! I won't go easy on you!\n");
		sleep(2);
		system("cls");
		printf("Initiating Battle 5 Sequence...\n");
		sleep(3);
		printf("Starting Battle Five... Get ready...\n");
		sleep(7);
		PlaySound(TEXT("battle5.wav"),NULL,SND_ASYNC|SND_LOOP);
		printf("Starting in \033[0;31m3...\033[0m");
		sleep(1);
		printf("\033[0;32m2...\033[0m");
		sleep(1);
		printf("\033[0;33m1...\033[0m");
		sleep(1);
		printf("GO!\n\n");
		battle5();
	}
	else{
		PlaySound(TEXT("wind.wav"),NULL,SND_ASYNC|SND_LOOP);
		printf("All Battlers : S.R.I.K.A.R is not a Human.\n");
		sleep(2);
		printf("He is an AI Bot who held our conciousness captive to make us fight you over and over and over again.\n");
		sleep(3);
		printf("You need to stop him.\n");
		sleep(2);
		printf("That bot...\n");
		sleep(2);
		printf("That's the only way to beat him.\n");
		sleep(2);
		printf("I don't know how you found it but it's our only hope.\n");
		sleep(2);
		int i;
		char *dialogue = "He is here... HELP\n";
		for (i=0;i<strlen(dialogue);i++){
			printf("%c",dialogue[i]);
			sleep(1);
		}
		system("cls");
		PlaySound(TEXT("spamton.wav"),NULL,SND_ASYNC|SND_LOOP);
		printf("??? : Heyy! You made it to the final battle!\n");
		sleep(3);
		printf("??? : No matter how many you won or how many you lost, this battle will determine your score!\n");
		sleep(4);
		printf("??? : Oh! So you're asking who I am?\n");
		sleep(3);
		printf("??? : You know?\n");
		sleep(3);
		printf("??? : Heh, No point in hiding then.\n");
		sleep(3);
		printf("S.R.I.K.A.R : I am S.R.I.K.A.R (Self Regulating Intelligent Knowledge-based Automatic gameRenderer).\n");
		sleep(4);
		printf("S.R.I.K.A.R : That bot... Heh, You found that note huh?\n");
		sleep(4);
		printf("S.R.I.K.A.R : Well if this is a battle for death, I won't hold back anymore.\n");
		sleep(4);
		printf("S.R.I.K.A.R : Let's Dance!\n");
		sleep(4);
		system("cls");
		printf("Initiating FINAL Battle Sequence...\n");
		sleep(3);
		printf("Starting FINAL Battle... Get ready...\n");
		sleep(7);
		printf("Starting in \033[0;31m3...\033[0m");
		sleep(1);
		printf("\033[0;32m2...\033[0m");
		sleep(1);
		printf("\033[0;33m1...\033[0m");
		sleep(1);
		printf("GO!\n\n");
		PlaySound(TEXT("bigshot.wav"),NULL,SND_ASYNC|SND_LOOP);
		battle6();
		if (bat6!=1){
			exit(0);
		}
		else{
			system("cls");
			PlaySound(TEXT("wind.wav"),NULL,SND_ASYNC|SND_LOOP);
			printf("The spirits of all the battlers are now resting in peace.\n");
			sleep(5);
			printf("You feel the Happiness in yourself.\n");
			sleep(5);
			printf("Thankyou...\n");
			sleep(5);
		}
	}
	system("cls");
	PlaySound(TEXT("ruins.wav"),NULL,SND_ASYNC|SND_LOOP);
	sleep(1);
	printf("Calculating Score...\n");
	sleep(5);
	printf("Battle 1 : (%d/1)\n",bat1);
	printf("Battle 2 : (%d/1)\n",bat2);
	printf("Battle 3 : (%d/1)\n",bat3);
	printf("Battle 4 : (%d/1)\n",bat4);
	printf("Battle 5 : (%d/1)\n",bat5);
	if (secr_act==1){
		printf("Battle 6 : (%d/1)\n",bat6);
	}
	printf("Score = (%d/5?)\n",bat1+bat2+bat3+bat4+bat5+bat6);
	sleep(1);
	printf("\n\nCongratulations! You've completed the Battle Engine Challange!\n\n");
	sleep(1);
	printf("Displaying Leaderboard...\n");
	sleep(5);
	fflush(stdin);
	Leaderboard();
	printf("\n================================================================\n");
	if (bat1+bat2+bat3+bat4+bat5+bat6==5){
		printf("You found a Note that reads :\n\t\"In yellow, you'll find a title so bright,\n\tWith hidden letters, a worthy sight,\n\tSeek them out, their value to expose,\n\tCombine with the creator's date to compose.\"");
	}
	else if (bat1+bat2+bat3+bat4+bat5+bat6==6){
		printf("S.R.I.K.A.R will return...");
	}
	else {
		printf("You might want to win all the 5 battles.");
	}
	printf("\n================================================================\n");
	sleep(500);
}
