#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void receipt(char [][50],float [],float ,int [],int ,int); void summary(char [][50],int [],int ,int, int );
void sorting(char [][50],int [],int ,int ,int ); void choosingDonut(char[][50],int*  ,int ,int ,int );
void choosingBreadTopping(char [][50]);
int inputVal(int ,int ,int ,int ); int quantity();
float drinksSize(float ,float);

int main(void){

    int i,j,addFlavour,size,sizeSet,choice,category1,category2,category3,statusAddOn,statusCust,donutChoose,toppingChoose,drinksChoose,check,totalSales = 0;
    int countCategory1[3] = {0,0,0},countCategory2[10] = {0,0,0,0,0,0,0,0,0,0},countCategory3[8] = {0,0,0,0,0,0,0,0};
    int donutCount[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0},toppingCount[4] = {0,0,0,0},drinksCount[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char line[] = {"-------------------------------------------------"};
    char category1Name[][50] = {"Doughnuts                           ","Bread                               ","Drinks                              "};

    char category2Name[][50] = {"Set                                 ","Ala Carte                           ","Breakfast                           ","Sandwich                            ",
                                "Chocolate                           ","Tea                                 ","Chiller                             ",
                                "Coffea                              ","Coco Cola                           ","Mineral Water                       "};

    char category3Name[][50] = {"Original Glazed                     ","Assorted                            ","Hot Combo                           ","Cool Combo                          ",
                                "Breakfast Croissant                 ","Breakfast Panini                    ","Krispy Croissant                    ","Krispy Panini                       "};

    char setDonutName[][50] = {"Original Glazed(12)                 ","Original Glazed(6)                 ","Assorted(12)                        ","Assorted(6)                         ",
                                "Hot Combo                           ","Cool Combo                          "};

    char doughnuts[][50] = {"New York Cheesecake                 ","Kit Kat                             ","Original Glazed                     ",
                            "Classic Doughnuts                   ","Almond All Over                     ","Caramel Cookies                     ",
                            "Chocolate Iced Custard Filled       ","Chocolate Dream                     ","Chocolate Iced Glazed               ",
                            "Chocolate Iced Glazed (Sprinkles)   ","Chocolate Peanut Butter             ","Classic Cinnamon                    ",
                            "Orea                                ","Powdered Strawberry Filled          "};

    char menuBread[][50] = {"Breakfast Croissant                 ","Breakfast Panini                    ","Sandwich Krispy Croissant           ","Sandwich Krispy Panini              "};

    char breadTopping[4][50] = {"Chicken Strips                      ","Chicken Mayo                        ","Tuna                                ","Egg Mayo                            "};

    char drinks[][50] = {"Krispy Kreme Chocolate              ","Iced Krispy Kreme Chocolate         ","Hot Classic Tea                     ","Iced Classic Tea                    ",
                        "Classic Chiller                     ","Chocolate Chiller                   ","Caramel Chiller                     ","Vanilla Chiller                     ","Mocha Chiller                       ",
                        "Iced Americano                      ","Americano                           ","Cappuccino                          ","Iced Latte                          ","Latte                               ",
                        "Iced Caramel Latte                  ","Caramel Latte                       ","Iced Vanilla Latte                  ","Vanilla Latte                       ",
                        "Iced Hazelnut Latte                 ","Hazelnut Latte                      ","Iced Mocha                          ","Mocha                               ",
                        "Coco Cola                           ","Mineral Water                       "};
    do{
        int status,n,countAddOn = 0,countQuantity[50];
        float totalPrice = 0,custItemPrice[45];
        char custItemName[50][50];
        puts("\n                 ________________________                  ");
        puts("                _____________________________                ");
        puts("             ___________________________________             ");
        puts("         __________________________________________          ");
        puts("       ______________________________________________        ");
        puts("      ________________________________________________       ");
        puts("     __________________________________________________      ");
        puts("   ______________________________________________________    ");
        puts("  ________________________________________________________   ");
        puts(" __________________________________________________________  ");
        puts("__________________________             _____________________ ");
        puts("_________________________            _______________________ ");
        puts("___________________HI WELCOME TO KRISPY KREME_______________ ");
        puts("_________________________            _______________________ ");
        puts("____________________________________________________________ ");
        puts("  _________________________________________________________  ");
        puts("    _____________________________________________________    ");
        puts("     ___________________________________________________     ");
        puts("       _______________________________________________       ");
        puts("        _____________________________________________        ");
        puts("          __________________________________________         ");
        puts("            _____________________________________            ");
        puts("               ________________________________              ");
        puts("                   ________________________                  ");
        do{//status take out || dine in
            printf("\n%s\n| \t\t  1 - Take Out\t\t\t|\n| \t\t  2 - Dine In\t\t\t|\n%s\nEnter choice : ",line,line);
            check = scanf("%d",&status);
        }while(inputVal(check,status,1,2) != 1);
        do{
            do{
                printf("%s\n|Code\t\tCategory\t\t\t|\n%s\n|1\t\tDoughnuts\t\t\t|\n|2\t\tBread    \t\t\t|\n|3\t\tDrinks   \t\t\t|\n%s",line,line,line);
                printf("\nEnter category code : ");
                check = scanf("%d",&category1);
            }while(inputVal(check,category1,1,3) != 1);
            countCategory1[category1-1]++;

            if(category1 == 1){//Doughnuts
                do{
                    printf("%s\n|Code\t\tCategory\t\t\t|\n%s\n|1\t\tSet\t\t\t\t|\n|2\t\tAla Carte \t\t\t|\n%s",line,line,line);
                    printf("\nEnter dougnuts category code : ");
                    check = scanf("%d",&category2);
                }while(inputVal(check,category2,1,2) != 1);
                countCategory2[category2-1]++;

                if(category2 == 1){//set
                    do{
                        printf("%s\n|Code\t\tItem\t\t\t\t|\n%s\n|1\t\tOriginal Glazed\t\t\t|\n|2\t\tAssorted \t\t\t|\n|3\t\tHot Combo\t\t\t|\n|4\t\tCool Combo\t\t\t|\n%s",line,line,line);
                        printf("\nEnter dougnuts set code : ");
                        check = scanf("%d",&category3);
                    }while(inputVal(check,category3,1,4) != 1);
                    countCategory3[category3-1]++;

                    if(category3 == 1){//Original Glazed
                        do{
                            printf("%s\n|Code\t\tSize\t\tPrice(RM)\t|\n%s\n|1.\t\t12\t\t30.00\t\t|\n|2.\t\t6\t\t18.00\t\t|\n%s",line,line,line);
                            printf("\nEnter box code : ");
                            check = scanf("%d",&sizeSet);
                        }while(inputVal(check,sizeSet,1,2) != 1);
                        countQuantity[countAddOn] = 1;
                        donutCount[2] += sizeSet == 1?12:6,totalPrice += sizeSet == 1 ? 30:18;
                        strcpy(custItemName[countAddOn],setDonutName[sizeSet == 1?0:1]),custItemPrice[countAddOn] = sizeSet == 1 ? 30:18;

                    }else if(category3 == 2){//Assorted
                        do{
                            printf("%s\n|Code\t\tSize\t\tPrice(RM)\t|\n%s\n|1.\t\t12\t\t36.80\t\t|\n|2.\t\t6\t\t20.20\t\t|\n%s",line,line,line);
                            printf("\nEnter box code : ");
                            check = scanf("%d",&sizeSet);
                        }while(inputVal(check,sizeSet,1,2) != 1);
                        choosingDonut(doughnuts,donutCount,sizeSet,12,6);
                        totalPrice += sizeSet == 1 ? 36.8:20.2,countQuantity[countAddOn] = 1;
                        strcpy(custItemName[countAddOn],setDonutName[sizeSet == 1?2:3]),custItemPrice[countAddOn] = sizeSet == 1 ? 36.8:20.2;

                    }else if(category3 == 3){//Hot combo
                        choosingDonut(doughnuts,donutCount,1,2,2);
                        totalPrice += 15,countQuantity[countAddOn] = 1,strcpy(custItemName[countAddOn],setDonutName[4]),custItemPrice[countAddOn] = 15;
                    }else{//Cool Combo
                        choosingDonut(doughnuts,donutCount,1,2,2);
                        totalPrice += 16,countQuantity[countAddOn] = 1,strcpy(custItemName[countAddOn],setDonutName[5]),custItemPrice[countAddOn] = 16;;
                    }
                }else{//Ala carte
                    do{
                        do{
                            printf("%s\n|Code\tFlavour\t\t\t       Price(RM)|\n%s\n",line,line);
                            for( i = 0; i < 14; i++){
                                i < 2? printf("|%d.\t%s4.30|\n",i+1,doughnuts[i]):printf("|%d.\t%s%.2f|\n",i+1,doughnuts[i],i == 2?3.2:3.7);
                            }printf("%s\nEnter flavour code : ",line);
                            check = scanf("%d",&donutChoose);
                        }while(inputVal(check,donutChoose,1,14) != 1);
                        n = quantity(),countQuantity[countAddOn] = n;
                        donutCount[donutChoose-1] += n,strcpy(custItemName[countAddOn],doughnuts[donutChoose-1]);
                        donutChoose < 3?(totalPrice += n*4.3,custItemPrice[countAddOn] = 4.3):(totalPrice += n*(donutChoose == 3? 3.2:3.7),custItemPrice[countAddOn] = donutChoose == 3? 3.2:3.7);
                        do{//add more flavour
                            printf("Do you want to add more flavour? (1:yes, 2:no) : ");
                            check = scanf("%d",&addFlavour);
                        }while(inputVal(check,addFlavour,1,2) != 1);
                        if(addFlavour == 1){countAddOn++;}
                    }while(addFlavour == 1);
                }
            }
            else if(category1 == 2){//bread
                do{
                    printf("%s\n|Code\t\tCategory\t\t\t|\n%s\n|1\t\tBreakfast\t\t\t|\n|2\t\tSandwich\t\t\t|\n%s",line,line,line);
                    printf("\nEnter category code : ");
                    check = scanf("%d",&category2);
                }while(inputVal(check,category2,1,2) != 1);
                countCategory2[category2+1]++;

                if(category2 == 1){//Breakfast
                    do{
                        printf("%s\n|Code\t\tCategory\tPrice(RM)\t|\n%s\n|1\t\tCroissant\t11.55\t\t|\n|2\t\tPanini\t\t10.50\t\t|\n%s",line,line,line);
                        printf("\nEnter category code : ");
                        check = scanf("%d",&category3);
                    }while(inputVal(check,category2,1,2) != 1);
                    countCategory3[category3+3]++;
                    do{
                        printf("%s\n|Code\tFillings\t\t\t\t|\n%s\n",line,line);
                        for(int i = 0; i < 4; i++){
                            printf("|%d.\t%s\t|\n",i+1,breadTopping[i]);
                        }printf("%s\nEnter filling code : ",line);
                        check = scanf("%d",&toppingChoose);
                    }while(inputVal(check,category3,1,4) != 1);

                    n = quantity(),totalPrice += n*(category3 == 1? 11.55:10.50),countQuantity[countAddOn] = n;
                    toppingCount[toppingChoose-1] += n;
                    custItemPrice[countAddOn] = category3 == 1?11.55:10.50;
                    category3 == 1? strcpy(custItemName[countAddOn],menuBread[0]):strcpy(custItemName[countAddOn],menuBread[1]);
                }else{//Sandwich
                    do{
                        printf("%s\n|Code\t\tCategory\t\t\t|\n%s\n|1\t\tKrispy Croissant\t\t|\n|2\t\tKrispy Panini\t\t\t|\n%s",line,line,line);
                        printf("\nEnter category code : ");
                        check = scanf("%d",&category3);
                    }while(inputVal(check,category3,1,2) != 1);
                    countCategory3[category3+5]++;
                    category3 == 1? strcpy(custItemName[countAddOn],menuBread[2]):strcpy(custItemName[countAddOn],menuBread[3]);

                    do{
                        printf("%s-\n|Code\tFilling\t\t\t\tPrice(RM)|\n%s-\n",line,line);
                        for(int i = 0; i < 4; i++){
                            if(i == 0 || i == 1)
                                printf("|%d.\t%s11.33|\n",i+1,breadTopping[i]);
                            else if(i == 2)
                                printf("|%d\t%s10.07|\n",i+1,breadTopping[i]);
                            else
                                printf("|%d\t%s 9.00|\n",i+1,breadTopping[i]);
                        }printf("%s-\nEnter filling code : ",line);
                        check = scanf("%d",&toppingChoose);
                    }while(inputVal(check,toppingChoose,1,4) != 1);
                    n = quantity(),toppingCount[toppingChoose-1] += n,countQuantity[countAddOn] = n;
                    if(toppingChoose == 1 || toppingChoose == 2)
                        totalPrice += n*11.33,custItemPrice[countAddOn] = 11.33;
                    else
                        totalPrice += n*(toppingChoose == 3? 10.07:9),custItemPrice[countAddOn] = toppingChoose == 3?10.07:9;
                }
            }else{//drinks
                do{
                    printf("%s\n|Code\t\tCategory\t\t\t|\n%s\n|1\t\tChocolate Series\t\t|\n|2\t\tTea\t\t\t\t|\n|3\t\tChiller\t\t\t\t|\n|4\t\tCoffee\t\t\t\t|\n|5\t\tOther Drinks\t\t\t|\n%s",line,line,line);
                    printf("\nEnter category code : ");
                    check = scanf("%d",&category2);
                }while(inputVal(check,category2,1,6) != 1);
                countCategory2[category2+3]++;

                if(category2 == 1){//Chocolate
                    do{
                        printf("%s\n|Code\tItem\t\t\t\t\t|\n%s\n|1\tKrispy Kreme Chocolate\t\t\t|\n|2\tIced Krispy Kreme Chocolate\t\t|\n%s",line,line,line);
                        printf("\nEnter item code : ");
                        check = scanf("%d",&drinksChoose);
                    }while(inputVal(check,drinksChoose,1,2) != 1);
                    custItemPrice[countAddOn] = drinksSize(12.50,13),n = quantity();
                    drinksCount[drinksChoose-1] += n,countQuantity[countAddOn] = n;
                    totalPrice += n*(custItemPrice[countAddOn]),strcpy(custItemName[countAddOn],drinks[drinksChoose-1]);
                    strcat(custItemName[countAddOn],custItemPrice[countAddOn] == 12.5?"(R)":"(L)");

                }else if(category2 == 2){//Tea
                    do{
                        printf("%s\n|Code\tItem\t\t\t\t\t|\n%s\n|1\tHot Classic Tea\t\t\t\t|\n|2\tIced Classic Tea\t\t\t|\n%s",line,line,line);
                        printf("\nEnter item code : ");
                        check = scanf("%d",&drinksChoose);
                    }while(inputVal(check,drinksChoose,1,2) != 1);
                    custItemPrice[countAddOn] = drinksSize(9,10),n = quantity();
                    drinksCount[drinksChoose+1] += n,countQuantity[countAddOn] = n;
                    totalPrice += n*custItemPrice[countAddOn],strcpy(custItemName[countAddOn],drinks[drinksChoose+1]);
                    strcat(custItemName[countAddOn],custItemPrice[countAddOn] == 9?"(R)":"(L)");

                }else if(category2 == 3){//Chiller
                    do{
                        printf("%s\n|Code\tItem\t\tPrice(RM)\t Size   |\n|\t\t\t(16.00)\t       (Regular)|\n%s\n|1\tClassic\t\t\t\t\t|\n|2\tChocolate\t\t\t\t|\n|3\tCaramel\t\t\t\t\t|\n|4\tVanilla\t\t\t\t\t|\n|5\tMocha\t\t\t\t\t|\n%s",line,line,line);
                        printf("\nEnter item code : ");
                        check = scanf("%d",&drinksChoose);
                    }while(inputVal(check,drinksChoose,1,5) != 1);
                    n = quantity(),countQuantity[countAddOn] = n;
                    drinksCount[drinksChoose+3] += n,strcpy(custItemName[countAddOn],drinks[drinksChoose+3]);
                    strcat(custItemName[countAddOn],"(R)"),custItemPrice[countAddOn] = 16.00,totalPrice += n*16.00;

                }else if(category2 == 4){//Coffee
                    do{
                        printf("%s\n|Code\tItem\t\t\t\t\t|\n%s\n",line,line);
                        for(int i = 0; i < 13; i++){
                            printf("|%d.\t%s\t|\n",i+1,drinks[i+9]);
                        }printf("%s\nEnter item code : ",line);
                        check = scanf("%d",&drinksChoose);
                    }while(inputVal(check,drinksChoose,1,13) != 1);
                    strcpy(custItemName[countAddOn],drinks[drinksChoose+8]);
                    if(drinksChoose == 1 || drinksChoose == 2){
                        custItemPrice[countAddOn] = drinksSize(8.5,10);
                        strcat(custItemName[countAddOn],custItemPrice[countAddOn] == 8.5?"(R)":"(L)");
                    }else{
                        custItemPrice[countAddOn] = drinksChoose <= 5?drinksSize(10.5,12.5):drinksSize(13,14);
                        strcat(custItemName[countAddOn],custItemPrice[countAddOn] == 10.5?"(R)":"(L)");
                    }
                    n = quantity(),totalPrice += n*(custItemPrice[countAddOn]),countQuantity[countAddOn] = n;
                    drinksCount[drinksChoose+8] += n;

                }else{// Coco Cola && Mineral Water
                    do{
                        printf("%s\n|Code\tItem\t\tPrice(RM)\tSize\t|\n%s\n|1\tCoco Cola\t 3.50\t\tRegular |\n",line,line,line);
                        printf("|2\tMineral Water\t 3.20\t\tRegular |\n%s",line,line,line);
                        printf("\nEnter item code : ");
                        check = scanf("%d",&drinksChoose);
                    }while(inputVal(check,drinksChoose,1,2) != 1);
                    n = quantity(),countQuantity[countAddOn] = n;
                    drinksCount[drinksChoose == 1?22:23] += n,strcpy(custItemName[countAddOn],drinks[drinksChoose == 1?22:23]);
                    custItemPrice[countAddOn] = drinksChoose == 1?3.5:3.2,strcat(custItemName[countAddOn],"(R)"),totalPrice += drinksChoose == 1?n*3.5:n*3.2;
                }
            }
            do{
                printf("Add order ? (1 : Yes, 2 : No) :  ");
                check = scanf("%d",&statusAddOn);
            }while(inputVal(check,statusAddOn,1,2) != 1);
            if(statusAddOn == 1){countAddOn++;}
        }while(statusAddOn == 1);
        receipt(custItemName,custItemPrice,totalPrice,countQuantity,countAddOn,status);//receipt print
        printf("\nPlease enter any key to continue..");
        getch(),system("cls");
        do{
            printf("\nAnymore customer? (1 : Yes, 2 : No) :  ");
            check = scanf("%d",&statusCust);
        }while(inputVal(check,statusCust,1,2) != 1);
    }while(statusCust == 1);

    puts("\t\t     SUMMARY");//Summary
    summary(category1Name,countCategory1,0,3,0),summary(category2Name,countCategory2,0,2,1),summary(category2Name,countCategory2,2,4,2),
    summary(category2Name,countCategory2,4,10,3),summary(category3Name,countCategory3,0,4,4),summary(category3Name,countCategory3,4,6,5);
    summary(category3Name,countCategory3,6,8,6),summary(doughnuts,donutCount,0,14,8),summary(breadTopping,toppingCount,0,4,7),summary(drinks,drinksCount,0,2,9),
    summary(drinks,drinksCount,2,4,10),summary(drinks,drinksCount,4,9,11),summary(drinks,drinksCount,9,22,12),summary(drinks,drinksCount,22,24,13);

    printf("Please enter any key to continue..");
    getch(),system("cls");

    puts("\t\t     RANKING");//Ranking
    sorting(category1Name,countCategory1,0,3,0),sorting(category2Name,countCategory2,0,2,1),sorting(category2Name,countCategory2,2,4,2),
    sorting(category2Name,countCategory2,4,10,3),sorting(category3Name,countCategory3,0,4,4),sorting(category3Name,countCategory3,4,6,5),
    sorting(category3Name,countCategory3,6,8,6),sorting(breadTopping,toppingCount,0,4,7),sorting(drinks,drinksCount,0,2,8),
    sorting(drinks,drinksCount,2,4,9),sorting(drinks,drinksCount,4,9,10),sorting(drinks,drinksCount,9,22,11),sorting(drinks,drinksCount,22,24,12);
}

int quantity(){

    int check,amount;
    do{
        printf("Please enter the quantity : ");
        check = scanf("%d",&amount);
    }while(inputVal(check,amount,1,50) != 1);
    return amount;
}

int inputVal(int test,int var, int num1, int num2){
    fflush(stdin),system("cls");
    if(test != 1){
        puts("\nInvalid input.Please enter a digit");
        return 0;
    }else if(var < num1 || var > num2){
        printf("\nInvalid digit.Enter code(%d-%d)\n",num1,num2);
        return 0;
    }return 1;
}

void choosingDonut(char donutName[][50],int* countDonut,int magnitude,int b1,int b2){
    
    char line[] = {"-------------------------------------------------"};
    int i,j,size,donutSelect,check; 
    for( i = 0,size = magnitude == 1?b1:b2; i < size; i++){
        do{
            printf("%s\n|Code\tFlavour\t\t\t\t\t|\n%s\n",line,line);
            for( j = 0; j < 14; j++){
                printf("|%d.\t%s\t|\n",j+1,donutName[j]);
            }printf("%s\nCurrent number of donut = %d\nEnter flavour code : ",line,i+1);
            check = scanf("%d",&donutSelect);
        }while(inputVal(check,donutSelect,1,14) != 1);
        countDonut[donutSelect-1]++;
    }
}

void receipt(char list[][50],float price[],float total,int quan[],int count,int stat){

    int check,paymentMethod;
    float payment,balance = 0;
    char name[50],line[] = {"----------------------------------------------------"};
    do{
        printf("\nTotal Price: %.2f\n\n",total);
        printf("Enter the amount : ");
        check = scanf("%f",&payment);
        fflush(stdin),system("cls");
        if(check != 1)
            puts("\nInvalid amount. Enter digit.");
        else if(payment <= 0)
            puts("\nInvalid amount. Enter more than 0.");
        else if(payment < total)
            printf("\nInsufficient amount. Pay RM%.2f.",total);
    }while(check != 1 || payment < total || payment < 0);
    if(payment != total){balance = payment - total;}
    do{
        printf("Enter cashier name: ");
        gets(name),fflush(stdin),system("cls");
        if(strlen(name) == 0){puts("Please enter name");}
        else if((char)name[0] == 32){puts("Please enter real name");}
    }while(strlen(name) == 0 || (char)name[0] == 32);

    printf("%s\n|\t\tKRIPSY KREME DOUGNUTS\t\t   |\n|\t\t    MUAR, JOHOR\t\t\t   |\n|\t\t  (603) 7628 0039   \t\t   |",line);
    puts("\n|\t\tKRISPY KREME DOUGNUTS\t\t   |\n|\t\t Sdn Bhd (223886-W)\t\t   |\n|\t      SST ID : W10-1808-31018942\t   |");
    printf("|\t\t\t\t\t\t   |\n|\t\t\t\t\t\t   |\n");
    printf("%s\n|Tax Invoice No: 102122\t\t\t%s   |\n|Date: %s %s\t\t\t   |\n%s\n",line,stat == 1?"Take Out":"Dine In ",__DATE__,__TIME__,line);
    
    for(int i = 0; i <= count; i++){
        printf("\n %s %.2f x %d     ",list[i],price[i],quan[i]);
    }
    printf("\n\n%s\n\t\t\t\t  TOTAL: RM%.2f   \n\t\t\t     CASH TOTAL: RM%.2f\n\t\t\t\tBALANCE: RM%.2f   \n%s\n%s",line,total,payment,balance,line,line);

    printf("\n|\t\t\t\t\t\t   |\n|\t\t\t\t\t\t   |");
    puts("\n|\t\t\tTHANK YOU\t\t   |\n|\t\t   PLEASE POP BY AGAIN\t\t   |");
    puts("|\t\t      1247-8035 2698\t\t   |\n|\t\t   www.krispykreme.com.my\t   |");
    puts("|\t\t     KRISPY KREME. MALAYSIA\t   |");
    printf("|\t %s %s  %s 001-647296\t   |\n%s",__DATE__,__TIME__,name,line);
}

void summary(char arrayName[][50],int arrayCount[],int initial,int limit,int cateName){

    char line[] = {"----------------------------------------------------"};
    char name[][50] = {"      MAIN CATEGORY "," DOUGHNUTS CATEGORY ","   BREAD CATEGORY  ","   DRINKS CATEGORY ",
                        "DOUGHNUTS SET CATEGORY","  BREAKFAST SET BREAD","  SANDWICH BREAD","    BREAD FILLING    ","   DOUGHNUTS FILLING ",
                        "      CHOCOLATE       ","         TEA          ","       CHILLER        ","        COFFEE       ","     OTHER DRINKS     "};

    printf("%s\n|\t     %s \t\t   |\n%s",line,name[cateName],line);
    printf("\n| No  \tName                             Quantity  |\n%s",line);
    for(int i = initial,j=1; i < limit; i++,j++){
        printf("\n| %d\t%s %d     |",j,arrayName[i],arrayCount[i]);
    }printf("\n%s\n\n",line);
}

void sorting(char arr[][50],int arrCount[],int start,int end,int categoryName){

    char tempName[1][50],line[] = {"----------------------------------------------------"};
    char name[][50] = {"      MAIN CATEGORY "," DOUGHNUTS CATEGORY ","   BREAD CATEGORY  ","   DRINKS CATEGORY ",
                        "DOUGHNUTS SET CATEGORY","  BREAKFAST SET BREAD","  SANDWICH BREAD","    BREAD FILLING",
                        "      CHOCOLATE       ","         TEA          ","       CHILLER        ","      COFFEE         ","     OTHER DRINKS     "};
    int temp;

    for(int i = start; i < end-1; i++){
        for(int j = i+1; j < end; j++){
            if(arrCount[i] < arrCount[j]){
                temp = arrCount[i];
                arrCount[i] = arrCount[j];
                arrCount[j] = temp;
                strcpy(tempName[0],arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j],tempName[0]);
            }
        }
    }
    printf("%s\n|\t\t%s \t\t   |\n%s",line,name[categoryName],line);
    printf("\n|Name                             \tQuantity   |\n%s",line);
    for(int i = start; i < end;i++,start++){
        printf("\n|%s\t\t%d  |",arr[start],arrCount[start]);
    }printf("\n%s\n\n",line);
}

float drinksSize(float small, float large){
    int checking,sizeCup;
    char line[] = {"-------------------------------------------------"};
    do{
        printf("%s\n|Code\tSize\t\tPrice(RM)\t\t|\n%s\n|1\tRegular\t\t%.2f\t\t\t|\n|2\tLarge\t\t%.2f\t\t\t|\n%s",line,line,small,large,line);
        printf("\nEnter size code : ");
        checking = scanf("%d",&sizeCup);
    }while(inputVal(checking,sizeCup,1,2) != 1);

    return sizeCup == 1? small:large;
}
