#include <stdio.h>
#include <string.h>
#include <windows.h>

void receipt(char [][50],float [],float ,int ,int);
void summary(char [][50],int [],int ,int, int ,int );
void sorting(char [][50],int [],int ,int ,int ,int );
int inputVal(int ,int ,int ,int );
float drinksSize(float ,float);


int main(){

    int i,j,sizeSet,choice,category1,category2,category3,statusAddOn,statusCust,donutChoose,toppingChoose,drinksChoose,check,totalSales = 0;
    int countCategory1[3] = {0,0,0},countCategory2[10] = {0,0,0,0,0,0,0,0,0,0},countCategory3[8] = {0,0,0,0,0,0,0,0};
    int donutCount[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0},toppingCount[4] = {0,0,0,0},drinksCount[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char line[] = {"-------------------------------------------------"};
    char category1Name[][50] = {"DOUGHNUTS                           ","BREAD                               ","DRINKS                              "};

    char category2Name[][50] = {"SET                                 ","ALA CARTE                           ","BREAKFAST                           ",
                                "SANDWICH                            ","CHOCOLATE                           ","TEA                                 ","CHILLER                             ",
                                "COFFEA                              ","COCO COLA                           ","MINERAL WATER                       "};

    char category3Name[][50] = {"ORIGINAL GALZED                     ","ASSORTED                            ","HOT COMBO                           ","COOL COMBO                          ",
                                "BREAKFAST CROISSANT                 ","BREAKFAST PANINI                    ","KRISPY CROISSANT                    ","KRISPY PANINI                       "};

    char menuDoughnuts[][50] = {"ORIGINAL GALZED(12)                 ","ORIGINAL GALZED(6)                 ","ASSORTED(12)                        ","ASSORTED(6)                         ",
                                "HOT COMBO                           ","COOL COMBO                         ",
                                "NEW YORK CHEESECAKE                 ","KIT KAT                             ","ORIGINAL GLAZED                     ",
                                "CLASSIC DOUGUHNUTS                  ","ALMOND ALL OVER                     ","CARAMEL COOKIES                     ",
                                "CHOCOLATE ICED CUSTARD FILLED       ","CHOCOLATE DREAM                     ","CHOCOLATE ICED GLAZED               ",
                                "CHOCOLATE ICED GLAZED (SPRINKLES)   ","CHOCOLATE PEANUT BUTTER             ","CLASSIC CINNAMON                    ",
                                "OREA                                ","POWDERED STRAWBERRY FILLED          "};

    char menuBread[][50] = {"BREAKFAST CROISSANT                 ","BREAKFAST PANINI                    ","SANDWICH KRISPY CROISSANT           ","SANDWICH KRISPY PANINI              "};

    char breadTopping[4][50] = {"CHICKEN STRIPS                      ","CHICKEN MAYO                        ","TUNA                                ","EGG MAYO                            "};
    
    char drinks[][50] = {"KRISPY KREME CHOCOLATE              ","ICED KRISPY KREME CHOCOLATE         ","HOT CLASSIC TEA                     ","ICED CLASSIC TEA                    ",
                        "CLASSIC CHILLER                     ","CHOCOLATE CHILLER                   ","CARAMEL CHILLER                     ","VANILLA CHILLER                     ","MOCHA CHILLER                       ",
                        "ICED AMERICANO                      ","AMERICANO                           ","CAPPUCCINO                          ","ICED LATTE                          ","LATTE                               ",
                        "ICED CARAMEL LATTE                  ","CARAMEL LATTE                       ","ICED VANILLA LATTE                  ","VANILLA LATTE                       ",
                        "ICED HAZELNUT LATTE                 ","HAZELNUT LATTE                      ","ICED MOCHA                          ","MOCHA                               ",
                        "COCO COLA                           ","MINERAL WATER                       "};
    
    do{
        int status,countAddOn = 0;
        float custItemPrice[46],totalPrice = 0;
        char custItemName[50][50];
        do{
                puts("\n\t1 - Take Out\n\t2 - Dine In");
                printf("\nPlease enter your choice : ");
                check = scanf("%d",&status);
            }while(inputVal(check,status,1,2) != 1);
        do{
            do{
                printf("%s\nNo\t\tCategory\n%s\n1\t\tDOUGHNUTS\n2\t\tBREAD\n3\t\tDRINKS\n%s",line,line,line);
                printf("\nPlease enter based on the number : ");
                check = scanf("%d",&category1);
            }while(inputVal(check,category1,1,3) != 1);
            countCategory1[category1-1]++;

            if(category1 == 1){

                //Doughnuts
                do{
                    printf("%s\nNo\t\tCategory\n%s\n1\t\tSET\n2\t\tALA CARTE\n%s",line,line,line);
                    printf("\nPlease enter based on the number : ");
                    check = scanf("%d",&category2);
                }while(inputVal(check,category2,1,2) != 1);
                countCategory2[category2-1]++;

                //set
                if(category2 == 1){
                    do{
                        printf("%s\nNo\t\tCategory\n%s\n1\t\tORIGINAL GLAZED\n2\t\tASSORTED\n3\t\tHOT COMBO\n4\t\tCOOL COMBO\n%s",line,line,line);
                        printf("\nPlease enter based on the number : ");
                        check = scanf("%d",&category3);
                    }while(inputVal(check,category3,1,4) != 1);
                    countCategory3[category3-1]++;

                    if(category3 == 1){
                        do{
                            printf("%s\nSize\t\tPrice (RM)\n%s\n12\t\t30.00\n6\t\t18.00\n%s",line,line,line);
                            printf("\nPlease enter based on the number : ");
                            check = scanf("%d",&sizeSet);
                            fflush(stdin),system("cls");
                            if(check != 1)
                                puts("\nPlease enter again with a valid INPUT !");
                            else if(sizeSet != 12 && sizeSet != 6)
                                puts("\nPlease enter again with a valid NUMBER !");
                        }while(check != 1 || sizeSet != 12 && sizeSet != 6);
                        donutCount[2] += sizeSet,totalPrice += sizeSet == 12 ? 30:18;
                        strcpy(custItemName[countAddOn],menuDoughnuts[sizeSet == 12?0:1]),custItemPrice[countAddOn] = sizeSet == 12 ? 30:18;

                    }else if(category3 == 2){
                        do{
                            printf("%s\nSize\t\tPrice (RM)\n%s\n12\t\t36.80\n6\t\t20.20\n%s",line,line,line);
                            printf("\nPlease enter based on the number : ");
                            check = scanf("%d",&sizeSet);
                            fflush(stdin),system("cls");
                            if(check != 1)
                                puts("\nPlease enter again with a valid INPUT !");
                            else if(sizeSet != 12 && sizeSet != 6)
                                puts("\nPlease enter again with a valid NUMBER !");
                        }while(check != 1 || sizeSet != 12 && sizeSet != 6);
                        
                        for( i = 0; i < sizeSet; i++){
                            do{
                                printf("%s\nNo\tName\n%s\n",line,line);
                                for( j = 0; j < 14; j++){
                                    printf("%d.\t%s\n",j+1,menuDoughnuts[j+6]);
                                }printf("%s\nPlease enter based on the number : ",line);
                                check = scanf("%d",&donutChoose);
                            }while(inputVal(check,donutChoose,1,14) != 1);
                            donutCount[donutChoose-1]++;
                        }
                        totalPrice += sizeSet == 12 ? 36.8:20.2;
                        strcpy(custItemName[countAddOn],menuDoughnuts[sizeSet == 12?2:3]),custItemPrice[countAddOn] = sizeSet == 12 ? 36.8:20.2;
                    }else if(category3 == 3){
                        for(i = 0; i < 2; i++){
                            do{
                                printf("%s\nNo\tName\n%s\n",line,line);
                                for( j = 0; j < 14; j++){
                                    printf("%d.\t%s\n",j+1,menuDoughnuts[j+6]);
                                }printf("%s\nPlease enter based on the number : ",line);
                                check = scanf("%d",&donutChoose);
                            }while(inputVal(check,donutChoose,1,14) != 1);
                            donutCount[donutChoose-1]++;
                        }totalPrice += 15,strcpy(custItemName[countAddOn],menuDoughnuts[4]),custItemPrice[countAddOn] = 15;
;
                    }else{
                        for(int i = 0; i < 2; i++){
                            do{
                                printf("%s\nNo\tName\n%s\n",line,line);
                                for(j = 0; j < 14; j++){
                                    printf("%d.\t%s\n",j+1,menuDoughnuts[j+6]);
                                }printf("%s\nPlease enter based on the number : ",line);
                                check = scanf("%d",&donutChoose);
                            }while(inputVal(check,donutChoose,1,14) != 1);
                            donutCount[donutChoose-1]++;
                        }totalPrice += 16,strcpy(custItemName[countAddOn],menuDoughnuts[5]),custItemPrice[countAddOn] = 16;;
                    }
                //Ala carte
                }else{
                    do{
                        printf("%s\nNo\tName\t\t\t\tPrice\n%s\n",line,line);
                        for( i = 0; i < 14; i++){
                            if(i == 0 || i == 1)
                                printf("%d.\t%s4.30\n",i+1,menuDoughnuts[i+6]);
                            else
                                printf("%d.\t%s%.2f\n",i+1,menuDoughnuts[i+6],i == 2?3.2:3.7);
                        }printf("%s\nPlease enter based on the number : ",line);
                        check = scanf("%d",&donutChoose);
                    }while(inputVal(check,donutChoose,1,14) != 1);
                    donutCount[donutChoose-1]++,strcpy(custItemName[countAddOn],menuDoughnuts[donutChoose+5]);

                    if(donutChoose == 1 || donutChoose == 2)
                        totalPrice += 4.3,custItemPrice[countAddOn] = 4.3;
                    else    
                        totalPrice += donutChoose == 3? 3.2:3.7,custItemPrice[countAddOn] = donutChoose == 3? 3.2:3.7;
                }
            }
            else if(category1 == 2){
                //bread
                do{
                    printf("%s\nNo\t\tCategory\n%s\n1\t\tBREAKFAST\n2\t\tSANDWICH\n%s",line,line,line);
                    printf("\nPlease enter based on the number : ");
                    check = scanf("%d",&category2);
                }while(inputVal(check,category2,1,2) != 1);
                countCategory2[category2+1]++;

                if(category2 == 1){
                    do{
                        printf("%s\nNo\t\tCategory\tPrice(RM)\n%s\n1\t\tCROISSANT\t11.55\n2\t\tPANINI\t\t10.50\n%s",line,line,line);
                        printf("\nPlease enter based on the number : ");
                        check = scanf("%d",&category3);
                    }while(inputVal(check,category2,1,2) != 1);
                    countCategory3[category3+3]++,totalPrice += category3 == 1? 11.55:10.50;

                    do{
                        printf("%s\nNo\tName\n%s\n",line,line);
                        for(int i = 0; i < 4; i++){
                            printf("%d.\t%s\n",i+1,breadTopping[i]);
                        }printf("%s\nPlease enter based on the number : ",line);
                        check = scanf("%d",&toppingChoose);
                    }while(inputVal(check,category3,1,4) != 1);
                    toppingCount[toppingChoose-1]++;
                    custItemPrice[countAddOn] = category3 == 1?11.55:10.50;
                    category3 == 1? strcpy(custItemName[countAddOn],menuBread[0]):strcpy(custItemName[countAddOn],menuBread[1]);
                }else{
                    do{
                        printf("%s\nNo\t\tCategory\n%s\n1\t\tKRISPY CROISSANT\n2\t\tKRISPY PANINI\n%s",line,line,line);
                        printf("\nPlease enter based on the number : ");
                        check = scanf("%d",&category3);
                    }while(inputVal(check,category2,1,2) != 1);
                    countCategory3[category3+5]++;
                    category3 == 1? strcpy(custItemName[countAddOn],menuBread[2]):strcpy(custItemName[countAddOn],menuBread[3]);

                    do{
                        printf("%s\nNo\tName\t\t\t\tPrice\n%s\n",line,line);
                        for(int i = 0; i < 4; i++){
                            if(i == 0 || i == 1)
                                printf("%d.\t%s11.33\n",i+1,breadTopping[i]);
                            else
                                printf("%d.\t%s%.2f\n",i+1,breadTopping[i],i == 2?10.07:9);
                        }printf("%s\nPlease enter based on the number : ",line);
                        check = scanf("%d",&toppingChoose);
                    }while(inputVal(check,toppingChoose,1,4) != 1);
                    toppingCount[toppingChoose-1]++;
                    if(toppingChoose == 1 || toppingChoose == 2)
                        totalPrice += 11.33,custItemPrice[countAddOn] = 11.33;
                    else
                        totalPrice += toppingChoose == 3? 10.07:9,custItemPrice[countAddOn] = toppingChoose == 3?10.07:9;
                }
            }else{

                //drinks
                do{
                    printf("%s\nNo\t\tCategory\n%s\n1\t\tCHOCOLATE SERIES\n2\t\tTEA\n3\t\tCHILLER\n4\t\tCOFFEE\n5\t\tCOCO COLA\n6\t\tMINERAL WATER\n%s",line,line,line);
                    printf("\nPlease enter based on the number : ");
                    check = scanf("%d",&category2);
                }while(inputVal(check,category2,1,6) != 1);
                countCategory2[category2+3]++;

                if(category2 == 1){
                    do{
                        printf("%s\nNo\tName\n%s\n1\tKRISPY KREME CHOCOLATE\n2\tICED KRISPY KREME CHOCOLATE\n%s",line,line,line);
                        printf("\nPlease enter based on the number : ");
                        check = scanf("%d",&drinksChoose);
                    }while(inputVal(check,drinksChoose,1,2) != 1);
                    drinksCount[drinksChoose-1]++,custItemPrice[countAddOn] = drinksSize(12.50,13);
                    totalPrice += custItemPrice[countAddOn],strcpy(custItemName[countAddOn],drinks[drinksChoose-1]);

                }else if(category2 == 2){
                    do{
                        printf("%s\nNo\tName\n%s\n1\tHOT CLASSIC TEA\n2\tICED CLASSIC TEA\n%s",line,line,line);
                        printf("\nPlease enter based on the number : ");
                        check = scanf("%d",&drinksChoose);
                    }while(inputVal(check,drinksChoose,1,2) != 1);
                    drinksCount[drinksChoose+1]++,custItemPrice[countAddOn] = drinksSize(9,10);
                    totalPrice += custItemPrice[countAddOn],strcpy(custItemName[countAddOn],drinks[drinksChoose+1]);

                }else if(category2 == 3){
                    do{
                        printf("%s\nNo\tName\t\tPrice\t   Size\n\t\t\t(16.00)\t (REGULAR)\n%s\n1\tCLASSIC\t\n2\tCHOCOLATE\n3\tCARAMEL\n4\tVANILLA\n5\tMOCHA\n%s",line,line,line);
                        printf("\nPlease enter based on the number : ");
                        check = scanf("%d",&drinksChoose);
                    }while(inputVal(check,drinksChoose,1,5) != 1);
                    drinksCount[drinksChoose+3]++,strcpy(custItemName[countAddOn],drinks[drinksChoose+3]);
                    custItemPrice[countAddOn] = 16.00,totalPrice += 16.00;

                }else if(category2 == 4){
                    do{
                        printf("%s\nNo\tName\n%s\n",line,line);
                        for(int i = 0; i < 13; i++){
                            printf("%d.\t%s\n",i+1,drinks[i+9]);
                        }printf("%s\nPlease enter based on the number : ",line);
                        check = scanf("%d",&drinksChoose);
                    }while(inputVal(check,drinksChoose,1,13) != 1);
                    drinksCount[drinksChoose+8]++,strcpy(custItemName[countAddOn],drinks[drinksChoose+8]);
                    if(drinksChoose == 1 || drinksChoose == 2)
                        custItemPrice[countAddOn] = drinksSize(8.5,10),totalPrice += custItemPrice[countAddOn];
                    else if(drinksChoose <= 5){    
                        custItemPrice[countAddOn] = drinksSize(10.5,12.5);
                        totalPrice += custItemPrice[countAddOn];
                        
                    }else{
                        custItemPrice[countAddOn] = drinksSize(13,14);
                        totalPrice += custItemPrice[countAddOn];
                    }
                }else if(category2 == 5){
                    do{
                        printf("%s---\nNo\tName\t\tPrice(RM)\tSIZE\n%s---\n1\tCOCO COLA\t3.50\t\tREGULAR\n%s---",line,line,line);
                        printf("\nPlease enter based on the number : ");
                        check = scanf("%d",&drinksChoose);
                    }while(inputVal(check,drinksChoose,1,1) != 1);
                    drinksCount[22]++,strcpy(custItemName[countAddOn],drinks[drinksChoose+21]);
                    custItemPrice[countAddOn] = 3.5,totalPrice += 3.5;

                }else{
                    do{
                        printf("%s---\nNo\tName\t\tPrice(RM)\tSIZE\n%s---\n1\tMINERAL WATER\t3.20\t\tREGULAR\n%s---",line,line,line);
                        printf("\nPlease enter based on the number : ");
                        check = scanf("%d",&drinksChoose);
                    }while(inputVal(check,drinksChoose,1,1) != 1);
                    drinksCount[23]++,strcpy(custItemName[countAddOn],drinks[drinksChoose+22]),
                    custItemPrice[countAddOn] = 3.2,totalPrice += 3.2;
                }
            }
            do{
                printf("Do you wish to add anything else ? (1 : Yes, 0 : No) =  ");
                check = scanf("%d",&statusAddOn);
            }while(inputVal(check,statusAddOn,0,1) != 1);
            if(statusAddOn == 1)
                countAddOn++;
        }while(statusAddOn == 1);

        receipt(custItemName,custItemPrice,totalPrice,countAddOn,status);

        do{
            printf("\nAnymore Customer ? (1 : Yes, 0 : No) =  ");
            check = scanf("%d",&statusCust);
        }while(inputVal(check,statusCust,0,1) != 1);
    }while(statusCust == 1);

    puts("\t\t     SUMMARY");
    summary(category1Name,countCategory1,0,3,1,0),summary(category2Name,countCategory2,0,10,2,0);
    summary(category3Name,countCategory3,0,8,3,0),summary(menuDoughnuts,donutCount,6,20,0,1);
    summary(breadTopping,toppingCount,0,4,0,2),summary(drinks,drinksCount,0,24,0,3);

    puts("\t\t     RANKING");
    sorting(category1Name,countCategory1,0,3,1,0),sorting(category2Name,countCategory2,0,2,0,6);
    sorting(category2Name,countCategory2,2,4,0,7),sorting(category2Name,countCategory2,4,10,0,8);
    sorting(category3Name,countCategory3,0,4,0,9),sorting(category3Name,countCategory3,4,8,0,10);
    sorting(breadTopping,toppingCount,0,4,0,11),sorting(drinks,drinksCount,0,2,0,12);
}

void receipt(char list[][50],float price[],float total,int count,int stat){

    int check;
    float payment;
    char line[] = {"----------------------------------------------------"};
    
    do{
        printf("\n\t\t\tTotal Price: %.2f\n",total);
        printf("Enter the amount : ");
        check = scanf("%f",&payment);
    }while(inputVal(check,payment,total,total) != 1);

    printf("%s\n\t\tKRIPSY KREME DOUGNUTS\t\t    \n\t\tMUAR, JOHOR\n\t\t(603) 7628 0039",line);
    puts("\n\t\tKRISPY KREME DOUGNUTS\n\t\tSdn Bhd (223886-W)\n\t\tSST ID : W10-1808-31018942");
    printf("%s\nTax Invoice No: 102122\t\t%s\nDate: %s %s\n%s\n",line,stat == 1?"Take Out":"Dine In",__DATE__,__TIME__,line);
    for(int i = 0; i <= count; i++){
        printf("\n%s %.2f",list[i],price[i]);
    }
    printf("\n\n%s\n\t\t\t\tTOTAL RM %.2f\n%s\n%s",line,total,line,line);
}

void summary(char arrayName[][50],int arrayCount[],int initial,int tally,int cate,int cate2){

    char line[] = {"----------------------------------------------------"};
    char name[][20] = {"CATEGORY","DOUGHNUTS","BREAD","DRINKS"};
    int ending = tally - initial;
    if(cate2 == 0){
        printf("%s\n|\t\t    %s %d\t\t\t   |\n%s",line,name[cate2],cate,line);
        printf("\n| No  \tName                         No of chosen  |\n%s",line);
        for(int i = initial; i < tally; i++){
            printf("\n| %d\t%s %d     |",i+1,arrayName[i],arrayCount[i]);
        }
    }else{  
        printf("%s\n|\t\t    %s \t\t\t   |\n%s",line,name[cate2],line);
        printf("\n| No  \tName                         No of chosen  |\n%s",line);
        for(int i = 0; i < ending; i++,initial++){
            printf("\n| %d\t%s %d     |",i+1,arrayName[initial],arrayCount[i]);
        }
    }printf("\n%s\n\n",line);
}

void sorting(char arr[][50],int arrCount[],int start,int end,int c,int c2){

    char line[] = {"----------------------------------------------------"};
    char name[][25] = {"CATEGORY 1","CATEGORY 2","CATEGORY 3","DOUGHNUTS","BREAD","DRINKS",
                        "CATEGORY 2 DOUGHNUTS","CATEGORY 2 BREAD","CATEGORY 2 DRINKS",
                        "CATEGORY 3 DOUGHNUTS","CATEGORY 3 BREAD","BREAD TOPPING","DRINKS TYPE"};
    char tempName[45][50];
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

    printf("%s\n|\t\t%s \t\t   |\n%s",line,name[c2],line);
    printf("\n| Rank\tName                         No of chosen  |\n%s",line);
    for(int i = start,k = 1; i < end; k++,i++,start++){
        printf("\n|%d\t %s\t%d  |",k,arr[start],arrCount[start]);
    }printf("\n%s\n\n",line);

}

int inputVal(int test,int var, int num1, int num2){

    fflush(stdin),system("cls");
    if(test != 1){
        puts("\nPlease enter again with a valid INPUT !");
        return 0;
    }else if(var < num1 || var > num2){
        puts("\nPlease enter again with a valid NUMBER !");
        return 0;
    }return 1;
}

float drinksSize(float small, float large){

    int checking,sizeCup;
    char line[] = {"-------------------------------------------------"};
    do{
        printf("%s\nNO\tSIZE\t\tPRICE\n%s\n1\tREGULAR\t\t%.2f\n2\tLARGE\t\t%.2f\n%s",line,line,small,large,line);
        printf("\nPlease choose your drink size : ");
        checking = scanf("%d",&sizeCup);
    }while(inputVal(checking,sizeCup,1,2) != 1);

    return sizeCup == 1? small:large;
}