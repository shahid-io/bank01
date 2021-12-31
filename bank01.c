#include<stdio.h>
#include<stdlib.h>

float bal();
void deposit();
void withdraw();
bool pass_check(int);

float balance;
bool pass_bool;
float bal(){
        if(balance < 0){
                return 0;
        }
        return balance;
}

bool pass_check(int input_pass){
        pass_bool = false;

        int pass_word[] = {2001,2222,2244,1001};
        int i;
        int len = sizeof(pass_word)/sizeof(pass_word[0]);

        printf("Size of an pass_word array is : %d",len);
        for(i=0;i<=len;i++){
                if(pass_word[i]==input_pass){
                        pass_bool = true;
                        return pass_bool;
                }
        }
        //pass_bool = false;
        return pass_bool;
}

void deposit(){
        float temp;
        printf("Enter Amount for deposit : ");
        scanf("%f",&temp);
        if(temp>0){
                balance = balance + temp;
                printf("\n Transaction Successfull\n");
                printf("Deposited amount is : %.2f\n",temp);
                printf("Clear Amount is : %.2f\n",balance);

        }else{
                printf("\nerror occured!!!\n");
        }
}

void withdraw(){
        float temp;
        printf("Enter Amount to Withdraw : ");
        scanf("%f",&temp);
        if(temp<=balance){
                balance -= temp;
                printf("\n**Transaction Successfull**\n");
                printf("\n Withdrawal Amount : %.2f\n",temp);
                printf("Clear Balance is : %.2f\n",bal());
        }else{
                printf("\nInsuffcient Balance!!!!\n");
        }
}

int main(){
        //balance = balance + 100;

        int choice;
        int passcode;
        while(1){

                printf("0. Login\n1. Balance Check\n2. Deposit\n3. Withdraw\n4. Exit\n");
                printf("Enter your choice : ");
                scanf("%d",&choice);

                switch(choice){

                        case 0:
                                printf("Enter Passcode : ");
                                scanf("%d",&passcode);
                                if(pass_check(passcode))
                                        printf("\n||Login Successfull||\n");
                                else
                                        printf("\n!!Invalid Pascode!!\n");
                        break;

                        case 1:
                                printf("Current Balance is : %.2f\n",bal());

                        break;
                        case 2:
                                deposit();
                        break;
                        case 3:
                                withdraw();
                        break;
                        case 4:
                                exit(0);
                        break;
                        default:
                                printf("\nInvalid choice\n");
                        break;
                }
        }
        return 0;
}