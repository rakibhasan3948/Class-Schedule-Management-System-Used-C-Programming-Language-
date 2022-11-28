
#include<stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include<conio.h>
#include <ctime>
using namespace std;
int Data[13][4];
struct routine
{
    char teacherName[30];
    char teacherIne[5];
    char room[20];
    char couseCode[20];
    char day[10];
    char time [20];
    char designation[20];


} Ro[13]=
{
    { "Akash Ahammed","AA", "AB04-217","CSE231","Sat","8:30","Lecturer"},
    { "Mati Akter","MA", "AB04-201","CSE226","Sat","11:30","Senior Lecturer"},
    { "Mati Akter","MA", "AB04-201","CSE237","Sat","1:30","Senior Lecturer"},
    { "Jerin Howa","JH", "AB04-303","CSE214","Sun","11:30","Senior Lecturer"},
    { "Sagor Mahabub","SM", "AB04-222","CSE236","Mon","12:30","Professor"},
    { "MST Nodi","ND", "AB04-216","STA221","Mon","1:30","Associate Professor"},
    { "Jorna Saroar","JS", "AB04-803","CSE235","Mon","2:30","Lecturer"},
    { "MST Nodi","ND", "AB04-221","STA221","Tues","1:30","Associate Professor"},
    { "Jorna Saroar","JS", "AB04-303","CSE235","Tues","2:30","Lecturer"},
    { "Jibon Khan","JK", "AB04-222","CSE233","Wed","11:30","Lecturer"},
    { "Akash Ahammed","AA", "AB04-503","CSE232","Wed","2:30","Lecturer"},
    { "Jibon Khan","JK", "AB04-513","CSE234","Thu","1:30","Lecturer"},


};

struct log
{
    char name[20];
    char password [20];
    char teacherIne[5];

} people[12]=
{
    {"Faisal","3956"},
    {"Tanvir","3949"},
    {"Rakib", "3948"},
    {"Kafy", "3946"},
    {"Dippo", "3963"},
    {"Akash", "12345a","AA"},
    {"Mati", "23451m","MA"},
    { "Howa","34512j","JH"},
    {"Sagor","45123s","SM"},
    { "Nodi","51234m","ND" },
    { "Jorna", "54321j","JS"},
    { "Jibon","54123j","JK" },
};

int Admin(int i);
int Teacher(int i);
void Department();

void head_text()
{
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############        DIU CLASS SCHEDULE MANAGEMENT SYSTEM       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t----------------------Presented BY Team BackBencher-------------------------\n");
    printf("\n\t\t\t---------------------------------------------------------------------------");
}

void welcome_text()
{

    printf("\n\n\n\n\n");
    printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t\t        =                   TO                      =");
    printf("\n\t\t\t\t        =                SCHEDULE                   =");
    printf("\n\t\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
    system("cls");
}




int Login()
{


    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                    LogIn                          ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    int r=0;
    char name[20],password[20];
    printf("\n\n\n\t\t\tUser Name:");
    scanf("%s",name);
    printf("\n\t\t\tPassword:");
    scanf("%s",password);
    int  n= 12; // depend on data
    for(int i=0; i<n; i++)
    {


        if(strcmp(people[i].name,name) ==0)
        {
            if(strcmp(people[i].password,password)==0)
            {
                r++;


                if(i<5)
                {
                    if(i==0)
                    {

                        Department();
                        break;
                    }
                    else
                    {

                        Admin(i);
                        break;

                    }

                }
                else
                {
                    Teacher(i);
                    break;

                }



            }

        }


    }
    if(r==0)
    {

        printf("\n\n\n\t\t\tInvalid User Name or Password!");
        getch();
        Login();

    }

    return 0;


}

int Search(char ine[5])
{
    int i;
    for(i=0; i<13; i++)
    {

        if(strcmp(Ro[i].teacherIne,ine) ==0)

        {

            return i;

        }


    }

    return -1;

}

int Classtime(int x)
{


    time_t curr_time;
    curr_time = time(NULL);

    tm *tm_local = localtime(&curr_time);




    int d,m,y;

    d=tm_local->tm_mday;

    m=tm_local-> tm_mon +1;

    y=tm_local->tm_year+1900;
    int ne;

    ne=7;
    int m2[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int i,k=0,p,a;
    for(i=0; i<m; i++)
        k=k+m2[i];
    k=k+d+ne;
//cout<<new date=";
    if(k<=365)
    {
        for(i=0; i<13; i++)
        {
            p=k-m2[i];
            if(p<=m2[i+1])
            {
                a=i+1;
                break;
            }
            else
                k=p;
        }
        Data[x][1]=p;
        Data[x][2]=a;
        Data[x][3]=y;
    }
    else
    {
        k=k-365;
        for(i=0; i<13; i++)
        {
            p=k-m2[i];
            if(p<=m2[i+1])
            {
                a=i+1;
                break;
            }
            else
                k=p;
        }

        Data[x][1]=p;
        Data[x][2]=a;
        Data[x][3]=y;


    }

}


int DataADD(int i)
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                     Data Input                    ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    char day[10],Room_Number[10],time[10];
    printf("\n\n\n\t\t\tEnter Day:");
    scanf("%s",&day);
    fflush(stdin);

    printf("\n\t\t\tEnter Time:");
    scanf("%s",&time);
    fflush(stdin);
    printf("\n\t\t\tEnter Room Number:");
    scanf("%s",&Room_Number);
    fflush(stdin);

    int x,r=0;
    for(x=0; x<13; x++)
    {

        if(strcmp(Ro[x].day,day) ==0)

        {
            if(strcmp (Ro[x].time,time)==0)
            {
                if(strcmp(Ro[x].room,Room_Number)==0)
                {
                    printf("\n\n\n\t\t\tTeacher is.....");
                    printf("\n\n\t\t\t0.Absent\n\t\t\t1.Present");
                    printf("\n\t\t\tInput:");
                    scanf("%d",&Data[x][0]);
                    if(Data[x][0]==0)
                    {
                        Classtime(x);
                    }

                    r++;

                    fflush(stdin);
                    break;



                }

            }

        }

    }
    if(r==0)
    {
        system ("cls");
        printf("\n\n\n\t\t\tInvalid Input!");
        getch();

    }
    getch();
    Admin( i);


    return 0;

}





int Admin(int i)
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############             WELCOME TO ADMIN MODE                 ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    char a[100]= {"1.Data Input"};
    printf("\n\n\n\t\t\t%s",a);
    char b[100]= {"2.Search book by Teacher Initial"};
    printf("\n\t\t\t%s",b);
    char c[100]= {"3.Back"};
    printf("\n\t\t\t%s",c);
    char f[100]= {"Enter choice => "};
    printf("\n\n\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);
    char ini[5];
    switch(choice)
    {
    case 1:
        DataADD(i);
        break;
    case 2:

        system("cls");

        printf("\n\n\n\t\t\t###########################################################################");
        printf("\n\t\t\t############                                                   ############");
        printf("\n\t\t\t############                  Search Teacher                   ############");
        printf("\n\t\t\t############                                                   ############");
        printf("\n\t\t\t###########################################################################");



        printf("\n\n\n\t\t\tEnter Teacher Initial:");
        scanf("%s",&ini);

        printf("\n\n\t\t\tTeacher Name: %s\n",Ro[ Search(ini)].teacherName);
        printf("\t\t\tDesignation: %s",Ro[ Search(ini)].designation);


        getch();
        Admin(i);

        break;
    case 3:
        Login();

        break;

    default:
        system ("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                   Wrong Input!");
        getch();
    }



    return 0;
}
void T_profile(int p,int i)
{
    system("cls");
    time_t curr_time;
    curr_time = time(NULL);

    tm *tm_local = localtime(&curr_time);


    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                  Teacher Profile                  ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    printf("\n\n\t\t\tName: %s",Ro[p].teacherName);
    printf("\n\t\t\tInetial: %s",Ro[p].teacherIne);
    printf("\n\t\t\tDesignation: %s",Ro[p].designation);

    char a[100]= {"1.Edit User Name & Password"};
    char c[100]= {"2.Back"};
    printf("\n\n\t\t\t%s",a);
    printf("\n\t\t\t%s",c);
    char f[100]= {"Enter choice => "};
    printf("\n\n\n\t\t\t%s",f);


    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:

        system("cls");

        printf("\n\n\n\t\t\t###########################################################################");
        printf("\n\t\t\t############                                                   ############");
        printf("\n\t\t\t############              Edit User Name & Password            ############");
        printf("\n\t\t\t############                                                   ############");
        printf("\n\t\t\t###########################################################################");

        printf("\n\n\t\t\tName: %s",Ro[p].teacherName);
        printf("\n\t\t\tUserName: %s",people[i].name);
        printf("\n\n\t\t\tNew UserName: ");
        scanf("%s",&people[i].name);
        printf("\n\n\t\t\tNew Password: ");
        scanf("%s",&people[i].password);

        printf("\n\n\t\t\tUpdate Successfully Done........");
        getch();
        T_profile(p,i);


        break;

    case 2:
        Teacher(i);

        break;

    default:
        system ("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                   Wrong Input!");
        getch();
        T_profile( p,i);

    }


}
int Routine(int p,int i)
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                    Routine                        ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");


    printf("\n\n\t\t\t\t\tDAY\tTime\tRoom_Number\tCouse_Code\n");
    for(int j=0; j<13; j++)
    {
        if(strcmp(Ro[j].teacherIne,Ro[p].teacherIne) ==0)
        {

            printf("\n\t\t\t\t\t%s\t%s\t%s\t%s",Ro[j].day,Ro[j].time,Ro[j].room,Ro[j].couseCode);
        }

    }


    getch();

    Teacher(i);
    return 0;
}

void Feadback(int p,int i)
{
    system("cls");
    int s=0;
    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                      Feadback                     ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    printf("\n\t\t\tYou have not taken Those Class:\n");
    printf("\t\t\tDAY\tTime\tRoom_Number\tCouse_Code\n");

    for(int j=0; j<13; j++)
    {
        if(strcmp(Ro[j].teacherIne,Ro[p].teacherIne) ==0 &&Data[j][0]==0 )
        {

            printf("\n\t\t\t%s\t%s\t%s\t%s",Ro[j].day,Ro[j].time,Ro[j].room,Ro[j].couseCode);
            printf("\n\n\t\t\t Are you take tis class within %d/%d/%d  (1.Yes,2.No) ",Data[j][1],Data[j][2],Data[j][3]);
            printf("\n\t\t\tEnter your chose:");
            scanf("%d",&Data[j][0]);
            s++;
        }



    }
    if(s==0) printf("\n\t\t\t\t\t No Class");
    getch();
    Teacher(i);



}

int Teacher(int i)
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############              WELCOME TO Teacher MODE              ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    char a[100]= {"1.Profile"};
    printf("\n\n\n\t\t\t%s",a);
    char b[100]= {"2.Routine"};
    printf("\n\t\t\t%s",b);
    printf("\n\t\t\t3.Feadback");
    char c[100]= {"4.Back/Logout"};
    printf("\n\t\t\t%s",c);
    char f[100]= {"Enter choice => "};
    printf("\n\n\n\t\t\t%s",f);
    char k[5];

    strcpy(k,people[i].teacherIne);

    int p=0;

    for(int j=0; j<13; j++)
    {

        if(strcmp(Ro[j].teacherIne,k) ==0)
        {
            p=j;
        }


    }


    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        T_profile(p,i);

        break;
    case 2:
        Routine( p,i);
        break;
    case 3:
        Feadback(p,i);

        break;

    case 4:
        Login();
        break;
    default:
        system ("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                   Wrong Input!");
        getch();
        Teacher(i);
    }


    return 0;
}

void Department()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                       Department                  ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    int i;
    printf("\n\n\t\t\tClass Missed:");
    printf("\n\n\t\t\tDAY\tTime\tRoom_Number\tCouse_Code\tTeacherName\n");

    for (i=0; i<13; i++)
    {
        if(Data[i][0]==2)
        {
            printf("\n\t\t\t%s\t%s\t%s\t%s\t\t%s(%s)",Ro[i].day,Ro[i].time,Ro[i].room,Ro[i].couseCode,Ro[i].teacherName,Ro[i].teacherIne);


        }

    }
    getch();
    Login();



}



int main()
{

    int k;
    for(int k=0; k<13; k++)
    {

        Data[k][0]=-1;

    }


    //Department();
    head_text();
    welcome_text();
    Login();

    return 0;
}

