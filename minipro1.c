#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct items{
    char item[20];
    float price;
    int qty;
};

struct orders{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

void generateBillHeader(char name[50],char date[30]){
    printf("\n\n");
        printf("\t\t\tciclo. Cafe");
        printf("\n\t   -----------------");
        printf("\nDate:%s",date);
        printf("\nInvoice To: %s",name);
        printf("\n");
        printf("---------------------------------------\n");
        printf("Items\t\t");
        printf("Qty\t\t");
        printf("Total\t\t");
        printf("\n---------------------------------------");
        printf("\n\n");
}
void generateBillBody(char item[30],int qty, float price){
    printf("%s\t\t",item);
        printf("%d\t\t",qty);
        printf("%.2f\t\t",qty * price);
        printf("\n");
}



void generateBillFooter(float total){
    printf("\n");
    float dis = 0.1*total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal,grandTotal=netTotal + 2*cgst;//netTotal + cgst + sgst
    printf("---------------------------------------\n");
    printf("Sub Total\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t%.2f","%",dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f",netTotal);
    printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
    printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
    printf("\n---------------------------------------");
    printf("\nGrand Total\t\t\t%.2f",grandTotal);
    printf("\n---------------------------------------\n");
}
int main(){
   int i;
    int opt,n;
    struct orders ord;
    struct orders order;
   
    char name[50];
     FILE *bill;
       
   
    float total = 0;
   
    printf("\t============ciclo Cafe============");
  printf("\t\n==========Menu===========");
  printf("\t\n1.cheese toast- 85");
  printf("\t\n 2.jam toast- 70");
  printf("\t\n 3.espresso- 150");
   printf("\t\n 4.cocoa- 150");
   printf("\t\n 5.latte- 180");

    printf("\n\nPlease select your prefered operation");
    printf("\n\n1.Generate Invoice");
    printf("\n2.Download Invoice");
 printf("\n3.Exit");
    printf("\n\nYour choice:\t");
    scanf("%d",&opt);
   
    switch(opt){
        case 1:
        printf("\nPlease enter the name of the customer:\t");
        scanf("%s",ord.customer);
        strcpy(ord.date,_DATE_);
        printf("\nPlease enter the number of items:\t");
        scanf("%d",&n);
        ord.numOfItems = n;
        for(int i=0;i<n;i++){
            printf("\n\n");
            printf("Please enter the item %d:\t",i+1);
            scanf("%s",ord.itm[i].item);
            printf("Please enter the quantity:\t");
            scanf("%d",&ord.itm[i].qty);
            printf("Please enter the unit price:\t");
            scanf("%f",&ord.itm[i].price);
            total += ord.itm[i].qty * ord.itm[i].price;
        }

        generateBillHeader(ord.customer,ord.date);
        for(int i=0;i<ord.numOfItems;i++){
            generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
        }
        generateBillFooter(total);

       
        

    case 2:
    
    bill =fopen("Desktop/bill.txt","w");
    
        printf("\nPlease enter the name of the customer:\t");
        scanf("%s",ord.customer);
        strcpy(ord.date,_DATE_);
        printf("\nPlease enter the number of items:\t");
        scanf("%d",&n);
        ord.numOfItems = n;
        for( i=0;i<n;i++){
            printf("\n\n");
            printf("Please enter the item %d:\t",i+1);
            scanf("%s",ord.itm[i].item);
            fscanf(bill,"%s",ord.itm[i].item);
           
            printf("Please enter the quantity:\t");
            scanf("%d",&ord.itm[i].qty);
            fscanf(bill,"%d",&ord.itm[i].qty);
            printf("Please enter the unit price:\t");
            scanf("%f",&ord.itm[i].price);
            fscanf(bill,"%f",&ord.itm[i].price);
            total += ord.itm[i].qty * ord.itm[i].price;
             }
        
       
      
    fprintf(bill,"\n\n");
        fprintf(bill,"\t\t\tciclo. Cafe");
        fprintf(bill,"\n\t   -----------------");
        fprintf(bill,"\nDate:%s",ord.date);
        fprintf(bill,"\nInvoice To: %s",ord.customer);
       
        fprintf(bill,"---------------------------------------\n");
        
        fprintf(bill,"Thankyou for choosing our cafe");
        fprintf(bill,"\n---------------------------------------");
        fprintf(bill,"\n");
        fprintf(bill,"---------------------------------------\n");
        



    fprintf(bill,"\n");
    float dis = 0.1*total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal,grandTotal=netTotal + 2*cgst;//netTotal + cgst + sgst
    fprintf(bill,"---------------------------------------\n");
   fprintf(bill,"Sub Total\t\t\t%.2f",total);
    fprintf(bill,"\nDiscount @10%s\t\t%.2f","%",dis);
    fprintf(bill,"\n\t\t\t\t-------");
    fprintf(bill,"\nNet Total\t\t\t%.2f",netTotal);
    fprintf(bill,"\nCGST @9%s\t\t\t%.2f","%",cgst);
    fprintf(bill,"\nSGST @9%s\t\t\t%.2f","%",cgst);
    fprintf(bill,"\n---------------------------------------");
    fprintf(bill,"\nGrand Total\t\t\t%.2f",grandTotal);
    fprintf(bill,"\n---------------------------------------\n");

     fclose(bill);  
   break;
  case 3:
    printf("====THANKYOU VISIT AGAIN====");
   
    break;
  }