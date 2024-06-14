#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int re[2];
int  Menu(void);
int min = 1, max = 100;
int range;
int rn;
int flag=0;
//int  Again(void);

int decide=1;

//Version 1.0 2024/6/14

typedef struct Player
{
    char name[1000];
    int HP;
    int level;
    int money;
    char area;
    int armor_level;
    int sword_level;
    int trophy_num;
}PL;
PL PLA;

typedef struct Enemy
{
            int HP;
            int BH;
            int D;
            int W;
}EM;
EM e;

float  algo_1(PL PLA);
void  algo_2(PL PLA);
float  algo_3(PL PLA);
float  algo_4(PL PLA);
float  algo_5(PL PLA);
float  algo_6(PL PLA);

int main()
{
    printf("声明：本程序完全由本人独立开发，遵守大学生互帮互助守则\n");
    printf("      由于C语言水平有限，已经尽力向各位带来最好的功能呈现\n");
    printf("      注意到不同编译环境可能采用不同的中文编码方式，以下主要文本用英文呈现\n");
    printf("\n");
    printf("\n");
    printf("\n");

    srand((unsigned int)time(NULL));

    range = max - min + 1;

                                                    do{

    printf("    Ok,Welcome to the World of a Simple RPG.\n");
    printf("    Let's choose one action you want to do. \n");
    printf("    ****************************************\n");

    //initialize basic information


    PLA.name[1000] = "HITer";
    PLA.HP = 100;
    PLA.level = 1;
    PLA.area = 'A';
    PLA.money = 100;
    PLA.sword_level = 1;
    PLA.armor_level = 1;
    PLA.trophy_num = 0;


     e.HP=100;//enemy_HP
     e.BH=10;//enemy Basic Harm
     e.D=1;//enemy defense just like player's armor
     e.W=1;//enemy Weapon level

    int CHOOSE;
    Start: CHOOSE=Menu();
    switch(CHOOSE)
    {
        case 0 :
            {
                printf("    Exit Successfully !!!\n");
                return 0;
            }
        case 1 :
            {
                algo_1(PLA);
                break;
            }
        case 2 :
            {
                algo_2(PLA);
                break;
            }
        case 3 :
            {
                algo_3(PLA);
                break;
            }
        case 4 :
            {
                algo_4(PLA);
                break;
            }
        case 5 :
            {
                algo_5(PLA);
                break;
            }
        case 6 :
            {
                algo_6(PLA);
                break;
            }
        default:
            {
                printf("    Illegal number !!!\n");
                printf("    We shall input again.\n");
                goto Start;
            }

    }

    char input;
    Reinput1:   printf("    ###     If you want to do other action,please input Y.      ###\n");
                printf("    ###     If not,please input N.      ###\n");
                printf("            Input:");

    scanf("%c",&input);

    if(input=='Y')
    {
        system("cls");
        printf("    ###     let's try again !       ###\n");
        decide=1;
    }
    else if(input=='N')
    {
        printf("    ###     Thanks for your using.      ###\n");
        decide=0;
    }
    else
    {
        printf("    Illegal number !!!\n");
        printf("    We shall input again.\n");
        goto Reinput1;
    }
                                            }while(decide==1);
    return 0;
}

//function of showing the Menu
int  Menu(void)
{
    int choose;
    printf("\n");
    printf("\n");
    printf("    ************************\n");
    printf("              MENU          \n");
    printf("                            \n");
    printf("    0.Exit                  \n");
    printf("    1.Name your character   \n");
    printf("    2.List the situation    \n");
    printf("    3.Move to other area    \n");
    printf("    4.Store                  \n");
    printf("    5.kill monster          \n");
    printf("    6.Save and open files   \n");
    printf("                            \n");
    printf("            Verion1.0       \n");
    printf("    ************************\n");
    printf("\n");
    printf("\n");
    printf("    Action  :");
    scanf("%d",&choose);
    return choose;
}

/*
//function of re-run the program again
int  Again(void)
{   char input;
    printf("If you want try other algorithm,please input Y.\n");
    printf("If not,please input N.\n");
    pinrtf("Input:");
    scanf("%c",&input);
    if(input=='Y')
    {
        Again();
    }
    if(input=='N')
    {
        return 0;
    }
    return 0;
}
*/

//1 function of name character
float  algo_1(PL PLA)
{
            char *pname=PLA.name;
    Rename: printf("    Please name your Character :");
            //gets( );
            gets(pname);
    Retype: printf("    Your name is ");
            puts(pname);
        printf("    Sure for this name ?\n");
    printf("    Y(Yes) or N(NO) :");
    char decide;
    scanf("%c",&decide);
    if(decide=='Y'){return 0;}
    else if(decide=='N')
    {
            printf("    fine ,let's rename \n");
        goto Rename;
    }
    else goto Retype;
}

//2 function of show all information.
void  algo_2(PL PLA)
{

    printf("\n");
    printf("    **********************\n");
    printf("    Name       :        %c\n",PLA.name);
    printf("    HP         :        %d\n",PLA.HP);
    printf("    Money      :        %d\n",PLA.money);
    printf("    Area       :        %c\n",PLA.area);
    printf("    Armor_level:        %d\n",PLA.armor_level);
    printf("    Sword_level:        %d\n",PLA.sword_level);
    printf("    **********************\n");
    printf("\n");
}

//3 move to other area
float  algo_3(PL PLA)
{
    printf("    ### Area A:area for beginning. easy monster. no danger.                 \n");
    printf("    ### Area B:area for skilled traveller. difficult monster. get danger.   \n");
    printf("    ### Area C:area for hero. evil monster. great danger.                   \n");
    printf("    Move to area (A/B/C)  : \n");
    char *parea=PLA.area;
    gets(&PLA.area);
    printf("    Area %c Arrived !       \n",PLA.area);
    return 0;
}

//4 function of store
float  algo_4(PL PLA)
{
    int choose;
    printf("    ###                         Store                               ###\n");
    printf("    ###     1.Heal me             -10$           HP          +10    ###\n");
    printf("    ###     2.Upgrade Sword       -200$          Sword_level +1     ###\n");
    printf("    ###     3.Upgarde Armor       -200$          Armor level +1     ###\n");
    printf("    ###     4.Sell trophy        -1 trophy       money       +20$   ###\n");
    printf("    ###     *.trophy ---> 战利品                                    ###\n");
    Reinput2:    printf("    ###     Choose action : ");

        scanf("%d",&choose);
    switch(choose)
    {
    case 1 :
        {
            if(PLA.money>=10){PLA.money=PLA.money-10;PLA.HP=PLA.HP+10;if(PLA.HP>=100){ PLA.HP=100; } }
            else { printf("no enough money.\n"); }
            break;
        }
    case 2 :
        {
            if(PLA.money>=200){PLA.sword_level=PLA.sword_level+1;PLA.money=PLA.money-200; }
            else { printf("no enough money.\n"); }
            break;
        }
    case 3 :
        {
            if(PLA.money>=200){PLA.money=PLA.money-200;PLA.armor_level=PLA.armor_level+1; }
            else { printf("no enough money.\n"); }
            break;
        }
    case 4 :
        {
            if(PLA.trophy_num>=1){PLA.money=PLA.money+20;PLA.trophy_num=PLA.trophy_num-1; }
            else { printf("no enough money.\n"); }
            break;
        }
    default :
        {
        printf("    Illegal number !!!\n");
        printf("    We shall input again.\n");
        goto Reinput2;

        }
    }

    return 0;
}

//5 kill monster
float  algo_5(PL PLA)
{
    printf("    ###         Area %c         ###\n",PLA.area);

    switch(PLA.area)
    {
    case 'A' :
        {
            printf("    ###   you meet a slime                  ###\n");
            printf("    ###   HP                    :30         ###\n");
            printf("    ###   Basic Harm            :1          ###\n");
            printf("    ###   enemy defense level   :1          ###\n");
            printf("    ###   enemy weapon level    :1          ###\n");
            e.HP=30;
            e.BH=1;
            e.D=1;
            e.W=1;
            break;
        }
    case 'B' :
        {
            printf("    ###   you meet a Corrupted Knight       ###\n");
            printf("    ###   HP                    :150        ###\n");
            printf("    ###   Basic Harm            :15         ###\n");
            printf("    ###   enemy defense level   :3          ###\n");
            printf("    ###   enemy weapon level    :3          ###\n");
            e.HP=150;
            e.BH=15;
            e.D=3;
            e.W=3;
            break;
        }
    case 'C' :
        {
            printf("    ###   you meet the Lich King !!!        ###\n");
            printf("    ###   HP                    :500        ###\n");
            printf("    ###   Basic Harm            :100        ###\n");
            printf("    ###   enemy defense level   :10         ###\n");
            printf("    ###   enemy weapon level    :10         ###\n");
            e.HP=500;
            e.BH=100;
            e.D=10;
            e.W=10;
            break;
        }
    default :
        {
            printf("    ### Illegal Area ! \n");
            printf("    ### Please back to type the right area name. \n");
        }
    }

    //re[0] for Player to Monster; re[1] for Monster to player
    AT1(PLA,e,re);//Player attack monster
    AT2(e,PLA,re);//monster attack player
    int deci=1;
    while(deci==1)
    {
            printf("    ###     1.fight !           ###\n");
            printf("    ###     2.Run Away !        ###\n");
            printf("    ###     Action (1 or 2):    ###\n");
        int action_fr;
        scanf("%d",&action_fr);
        if(action_fr==2){deci=0;}
        else if(action_fr==1)
        {//0.1s
            e.HP=e.HP-re[0];
        if(e.HP<=0)
            {
                printf("    ###  you kill the monster !!!      ###\n");
                PLA.trophy_num=PLA.trophy_num+e.D;
            }else if(e.HP>0)
                    {
                        PLA.HP=PLA.HP-re[1];
                        if(PLA.HP<=0)
                            {  printf("     ### !!!  DEATH  !!! ###\n"); deci=0;}
                        else if(PLA.HP>0)
                            {
                                printf("    ### you HP      :%d     ###\n",PLA.HP);
                                printf("    ### monster HP  :%d     ###\n",e.HP);
                                deci=1;
                            }
                    }
        }//0.1e

    }


}

//function of A attack B
int AT1(PL PLA,EM e,int re[] )
{
    /*
    here is the basic rule of attack.
    A attack B : harm_AtoB = A's basic harm + 10*sword level - 10*armor level + 1% critical strike harm (+50% basic harm).
    player basic harm : 10
    */
    int harmAtoB;

    rn= min + rand() % range;
    if(rn==43){flag=1;}
    else{flag=0;}

    harmAtoB= 10+10*PLA.sword_level-10*e.D+ 0.5*10*flag;
    re[0]=harmAtoB;
    return re[0];
}

//function of B attack A
int AT2(EM e,PL PLA ,int re[] )
{
    /*
    here is the basic rule of attack.
    A attack B : harm_AtoB = A's basic harm + 10*sword level - 10*armor level + 1% critical strike harm (+50% basic harm).
    player basic harm : 10
    */
    int harmBtoA;

    rn= min + rand() % range;
    if(rn==43){flag=1;}
    else{flag=0;}

    harmBtoA= e.BH+10*e.W-10*PLA.armor_level+ 0.5*e.BH*flag;
    re[1]=harmBtoA;
    return re[1];
}

//6 save and open files
float  algo_6(PL PLA)
{
    return 0;
}
