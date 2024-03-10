#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


typedef struct
{
    char name[50];
    int bus_num;
    int num_of_seats;
} jatri;





void reservation(void);
void viewdetails(void);
void printticket(char name[],int,int,float);
void specificbus(int);
float charge(int,int);



int main()

{
    system("cls");
    printf("\t\t|           BUS TICKET RESERVATION SYSTEM           |\n");
    printf("\t\t------------------------------------------------------\n");
    printf("\t\t---------------press any key to continue--------------\n");
    printf("\t\t------------------------------------------------------\n");
    getch();
    system("cls");
    int menu_choice,choice_return;
start:
    system("cls");
    printf("\n*********************************\n");
    printf("    BUS RESERVATION SYSTEM");
    printf("\n*********************************");
    printf("\n1>> Reserve A Ticket");
    printf("\n------------------------");
    printf("\n2>> View All Available Bus");
    printf("\n------------------------");
    printf("\n3>> Exit");
    printf("\n------------------------");
    printf("\n\n-->");
    scanf("%d",&menu_choice);
    switch(menu_choice)
    {
    case 1:
        reservation();
        break;
    case 2:
        viewdetails();
        printf("\n\nPress any key to go to Main Menu");
        getch();
        break;
    case 3:
        return(0);
    default:
        printf("\nInvalid choice");
    }
    goto start;
    return(0);
}

void viewdetails(void)
{
    system("cls");
    printf("\nBUS.No\tBUS Name\t\tDestinations\t\tfare\t\tTime\n");
    printf("\n01\tShyamoli Paribahan\tDhaka to Cox's Bazar\tBDT.1200\t9AM");
    printf("\n02\tSaintmartin Paribahan\tDhaka to Shylet\t\tBDT.1500\t12PM");
    printf("\n03\tHanif Travels\t\tDhaka to Rajshahi\tBDT.900\t\t8AM");
    printf("\n04\tEna Paribahan\t\tDhaka to Faridpur\tBDT.1100\t11am");
    printf("\n05\tPabna Express\t\tDhaka to Pabna\t\tBDT.850\t\t7am");
}


void reservation(void)
{
    char confirm;
    int i=0;
    float charges;
    jatri passdetails;
    FILE *fp;
    fp=fopen("seats_reserved.txt","a");
    system("cls");

    printf("\nEnter Your Name:> ");
    fflush(stdin);
    gets(passdetails.name);

    printf("\nEnter Number of seats:> ");
    scanf("%d",&passdetails.num_of_seats);
    printf("\n\n>>Press Enter To View Available Bus<< ");
    getch();
    system("cls");
    viewdetails();
    printf("\n\nEnter bus number:> ");
start1:
    scanf("%d",&passdetails.bus_num);
    if(passdetails.bus_num>=01 && passdetails.bus_num<=05)
    {
        charges=charge(passdetails.bus_num,passdetails.num_of_seats);
        printticket(passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
    }
    else
    {
        printf("\nInvalid bus Number! Enter again--> ");
        goto start1;
    }

    printf("\n\nConfirm Ticket (y/n):>");
start:
    scanf(" %c",&confirm);
    if(confirm == 'y')
    {
        fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
        printf("==================");
        printf("\n Reservation successful\n");
        printf("==================");
        printf("\nPress any key to go back to Main menu");
    }
    else
    {
        if(confirm=='n')
        {
            printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
        }
        else
        {
            printf("\nInvalid choice entered! Enter again-----> ");
            goto start;
        }
    }
    fclose(fp);
    getch();
}

float charge(int bus_num,int num_of_seats)
{
    if (bus_num==01)
    {
        return(1200.0*num_of_seats);
    }
    if (bus_num==02)
    {
        return(1500.0*num_of_seats);
    }
    if (bus_num==03)
    {
        return(900.0*num_of_seats);
    }
    if (bus_num==04)
    {
        return(1100.0*num_of_seats);
    }
    if (bus_num==05)
    {
        return(850.0*num_of_seats);
    }
}

void printticket(char name[],int num_of_seats,int bus_num,float charges)
{
    system("cls");
    printf("-------------------\n");
    printf("\tTICKET\n");
    printf("-------------------\n\n");
    printf("Name:\t\t\t%s",name);
    printf("\nNumber Of Seats:\t%d",num_of_seats);
    printf("\nBus Number:\t\t%d",bus_num);
    specificbus(bus_num);
    printf("\nCharges:\t\t%.2f",charges);
}

void specificbus(int bus_num)
{

    if (bus_num==01)
    {
        printf("\nBus:\t\t\tShyamoli Paribahan");
        printf("\nDestination:\t\tDhaka to Cox's Bazar");
        printf("\nDeparture:\t\t9am ");
    }
    if (bus_num==02)
    {
        printf("\nBus:\t\t\tSaintmartin Paribahan");
        printf("\nDestination:\t\tDhaka to Shylet");
        printf("\nDeparture:\t\t12pm");
    }
    if (bus_num==03)
    {
        printf("\nBus:\t\t\tHanif Travels");
        printf("\nDestination:\t\tDhaka to Rajshahi");
        printf("\nDeparture:\t\t8am");
    }
    if (bus_num==533104)
    {
        printf("\nBus:\t\t\tEna Paribahan");
        printf("\nDestination:\t\tDhaka to faridpur");
        printf("\nDeparture:\t\t11am ");
    }
    if (bus_num==05)
    {
        printf("\nBus:\t\t\tPabna Express");
        printf("\nDestination:\t\tDhaka to Pabna");
        printf("\nDeparture:\t\t7am");
    }

}
