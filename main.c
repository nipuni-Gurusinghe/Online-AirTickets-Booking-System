a#include <stdio.h>
#include <stdlib.h>
#define USERNAME_LENGTH 20
#define PASSPORTNO_LENGTH 20
#include <windows.h>
#include <string.h>


typedef struct
{
    char userName[50];
    int passN;
}user;

user arr[100];



int processPayment(float amount)
        {
          printf("Processing payment of $%.2f\n",amount);
          return 1;
        }

     //Function to calculate ticket price based on flight classes

     float CalculateTicketPrice(char TicketClass)
     {

   switch(TicketClass)
   {
   case 'F':
    return 160000;  //FIRST
   case 'B':
    return 180000; //BUSINESS
   case 'E':
    return 120000; //ECONOMY
   default:
    return 0.0;   //INVALID CLASS
   }
    }


int main()
 {



  system("color 6");


    strcpy(arr[0].userName,"Nipuni");
    arr[0].passN = 1001;

    strcpy(arr[1].userName,"Kushmi");
    arr[1].passN = 1002;

    strcpy(arr[2].userName,"Anushi");
    arr[2].passN = 1003;

    strcpy(arr[3].userName,"Niduli");
    arr[3].passN = 1004;

    strcpy(arr[4].userName,"Sula");
    arr[4].passN = 1005;

    // Variables to store user input
    char enteredUsername[50];
    int pass ;



    // Prompt for username
    printf("\t\t\t\t\t\t*******************\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t       LOGIN      \t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t*******************\t\t\t\t\t\t\n");
    printf("\t\t\t* Enter Your Username:  ");

    scanf("%s",enteredUsername);

    // Prompt for passport No
    printf("\t\t\t* Enter Your Passport No :  ");
    scanf("%d",&pass);

    for (int i = 0 ; i < 100 ; i++)
    {
        if (strcmp(arr[i].userName,enteredUsername)==0)
        {
            if (arr[i].passN == pass)
        {
        printf("\t\t\t\t\t\t*Login successful!*\t\t\t\t\t\t\n\n***** Welcome to our Sky path flight reservation system*****, %s \n",enteredUsername);
                break;
        }
            else
            {
                printf("Incorrect username or passportNo. Please try again.\n");
                break;
            }

        }
    }





   int choice,fno;


    printf("\n                     *****************---SKY PATH AIRWAYS FLIGHT RESERVATION SYSTEM---*****************\n\n");
    printf("                                                    1.Check Flight\n");
    printf("                                                    2.Book Flight \n");
    printf("                                                    3.Exit\n\n");


//Input the choice no...............
    printf("                                        Enter your choice\n");
    scanf("%d",&choice);
//Check Ticket..........................

     if(choice==1)
          {
            printf("     #####  FLIGHT DETAILS   #####     \n\n");

            char FlightDetails[100];
            FILE*tkt;
            tkt=fopen("DataF.txt","r");
            char Fno[10];
            if(tkt== NULL)
          {
              printf("file could not be opened\n");
              return 1;
          }
       while(fgets(FlightDetails,100,tkt)!=NULL)
        {
            printf("\n%s\n",FlightDetails);
        }

      fclose(tkt);
     Sleep(2);
     main();
          }
    else if(choice==2)  //Book Flight.................................
    {
        printf("\t\t\t\t****************\t\t\t\t\n");
        printf("\t\t\t\tTICKET DETAILS\t\t\t\t\n");
        printf("\t\t\t\t****************\t\t\t\t");
        FILE*ptr;
        char TicketDetails[100];
        ptr=fopen("TicketDetails.txt","r");

        char Tno[10];
       if(ptr== NULL)
          {
              printf("file could not be opened\n");
              return 1;
          }
       while(fgets(TicketDetails,100,ptr)!=NULL)
        {
            printf("\n%s\n",TicketDetails);
        }

      fclose(ptr);
        printf("Enter your desired flight no:\n");
        scanf("%d",&fno);

        FILE*ptr1=fopen("PassengerD.txt","a");
            char PassengerD[10];
            int count=0;
            if(ptr1==NULL)
            {
                printf("Error opening the file.\n");
                return 1;
            }
                printf("\t\t\t\t\t\t***************************\t\t\t\t\t\t\n");
                printf("\t\t\t\t\t          Enter passenger details  \t\t\t\t\t\n");
                printf("\t\t\t\t\t\t***************************\t\t\t\t\t\t\n");
            int Age;
            int PassportNo;
            char Name[100];
            char Email[100];
            for(int i=1;i>0;i++){
            printf("Enter your Passport Number (or 0 to break):\n");
            scanf("%d",&PassportNo);
            if(PassportNo==0)
            {
                break;
            }
            printf("\t\tEnter your Name :  ");
            scanf("%s",&Name);
            printf("\t\tEnter your Age :  ");
            scanf("%d",&Age);
            printf("\t\tEnter your Email:  ");
            scanf("%s",&Email);
            fprintf(ptr1,"Passport No: %d\n Name: %s\tAge: %d\tEmail:%s\n",PassportNo,Name,Age,Email);
            count++;
            }



            printf("Data inserted successfully!\n");
            fclose(ptr1);
            for( int i=0;i<count;i++)
            {
                printf("Your Ticket Number is 00%d\n",i+1);
            }
            printf("flight booking successfully!!!\n");


          ptr1=fopen("PassengerD.txt","a");
        while(fscanf(ptr1,"%d \n%s \t %d \t %s\n",PassportNo,Name,Age,Email)==4)
        {
            printf("Passport No: %d\n ",PassportNo);
            printf("Name: %s\n ",Name);
            printf("Age: %d\n ",Age);
            printf("Email: %s\n ",Email);
        }



char selectedClass;
   printf("\t\t\t* Enter your desired class(F for First,B for business,E for Economy) :  ");
   scanf(" %c",&selectedClass);
   float TicketPrice=CalculateTicketPrice(selectedClass);

   if(TicketPrice>0)
   {
       printf("\t* Total amount to pay : $%.2f\n",TicketPrice);

       int paymentResult=processPayment(TicketPrice);
       {
           if(paymentResult==1)
           {
               printf("\t\tPayment successfull!  Booking confirmed\n");
           }
           else
           {
              printf("\t\tPayment failed! Please Try again\n");
           }

       }

   }

fclose(ptr1);
    }
else if(choice==3)
{
    printf("\t\t\t\t****You are exiting from the programme. Thank you!****\t\t\t\t");
    sleep(2);

    return;
}

    return 0;
    }





