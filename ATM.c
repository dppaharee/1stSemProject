#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Balance
{
	int bal;
	char dateNtime[];	
};

struct Accounts
{
	int accNo;
	char name[50];
	int pin[4];
	long long int balance;
	char accType[50];
	struct Balance transaction[];
};

void  Authenticaton()
{

}
void Withdraw()
{
	Authenticaton();

}
void Deposit()
{
	Authenticaton();

}
void BalanceInquiry()
{
	Authenticaton();

}
void NewID()
{

}
void Exit()

/*AVOID THIS!!
#include <stdio.h>
#include <time.h>

int main() {
    char date_string[100];
    time_t raw_time = time(NULL); // Get current epoch time
    struct tm *local_time = localtime(&raw_time); // Convert to local time components

    // Format: "YYYY-MM-DD HH:MM:SS"
    strftime(date_string, sizeof(date_string), "%Y-%m-%d %H:%M:%S", local_time);

    printf("Formatted Date/Time: %s\n", date_string);
    return 0;
}
*/
int main()
{
	FILE *ptr=fopen("C:\\codes\\nodeRepo.bin","wb");//need to change wb to rb+ later also create a folder in C drive named codes in your computer
	char choice;
	printf("\t\t\t\t\t\tWelcome To KIST Sem1 Banking/ATM System");
	printf("----------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\na. Withdraw Cash");
	printf("\nb. Deposit Cash");
	printf("\nc. Balance Inquiry");
	printf("\nd. Balance Inquiry");
	printf("----------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\nProceed to select an option: ");
	fflush(stdin);
	scannf
  /*AVOID THIS!!!
  time_t now = time(NULL);
	char *string =ctime(&now);
	printf("%s\n",string);*/
 switch(choice) 
   	case 'a'://withdraw
			
			goto	STARTUP;
		case 'b'://deposit
			
			goto	STARTUP;
		case 'c'://balance inquiry
			
			goto	STARTUP;
		case 'd'://new acc creation
			
			goto	STARTUP;
		default:
			printf("\nGiven input is out of range, please select option from range (a to d).")
	}  
	return 0;
}
