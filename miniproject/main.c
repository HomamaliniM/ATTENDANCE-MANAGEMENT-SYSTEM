#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <conio.h>
#include<windows.h>
#include <string.h>
#include <stdlib.h>
void home();
void welcome();
void management_login();
void management();
void addteachers();
void deleteteachers();
void viewteachersdetails();
void teacher_login();
void teacher_home();
void addstudents();
void deletestudents();
void viewstudentdetails();
void mark_attendence();
void edit_personal_details();
void view_student_attendence();
void student_login();
void student_home();
void checkattendence();
void exit();
void gotoxy(int, int);
int main()
{
    home();
    return 0;
}
void home()
{
    system("cls");
    int choice;
    welcome();
    ADD:
    printf("\n\n\t\t\t\t\t\t 1.MANAGEMENT LOGIN\n");
    printf("\n\t\t\t\t\t\t 2.TEACHER LOGIN\n");
    printf("\n\t\t\t\t\t\t 3.STUDENT LOGIN\n");
    printf("\n\t\t\t\t\t\t 4.EXIT\n");
    printf("\n\t\t\t\t\t\tSelect an Option: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        management_login();
        break;
    case 2:
        teacher_login();
        break;
    case 3:
        student_login();
        break;
    case 4:
        exitt();
        break;
    default:
        printf("\nINVALID CHOICE!!!");
        goto ADD;
        break;
    }
}
void welcome()
{
    printf("\n\n\n\n\n\t\t\t\t\t\t\tWELCOME\n");
    printf("\t\t\t\t\tSTUDENT ATTENDENCE MANAGEMENT SYSYTEM\n");
    printf("\t\t\t*********************************************************************\n");
}
void management_login()
{
    char muserid[50] = "190";
    char mpassword[50] = "14092001";
    char muserid1[50];
    char mpassword1[50];
    system("cls");
    printf("\n\n\n\t\t\t\t\t\tMANAGEMENT LOGIN\n\n");
    printf("\t\t*******************************************************************************\n");
    ADD:
    printf("\t\t\t\t ENTER ID->>");
    scanf("%s", &muserid1);
    printf("\n\t\t\t\t ENTER PASSWORD->>");
    scanf("%s", &mpassword1);
    if (strcmp(muserid1, muserid) == 0)
    {
        if (strcmp(mpassword1, mpassword) == 0)
        {

            printf("Login Successful");
            management();
        }
        else
        {

            printf("Wrong password");
            management_login();
        }

    }
    else
    {
        printf("\n\t\t\tEntered Wrong ID.Try Again!!!\n");
        goto ADD;
    }
}
void management()
{
    int ch;
    system("cls");
    printf("\n\n\n\t\t\t\t\tMANAGEMENT\n\n");
    printf("\t\t\t*********************************************************\n");
    ADD2:
    printf("\n\n\t\t\t\t\t 1.ADD TEACHERS\n");
    printf("\n\t\t\t\t\t 2.DELETE TEACHERS\n");
    printf("\n\t\t\t\t\t 3.VIEW TEACHERS DETAILS\n");
    printf("\n\t\t\t\t\t 4.EXIT\n");
    printf("\n\t\t\t\tSelect an Option: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1: addteachers();
        break;
    case 2:deleteteachers();
        break;
    case 3: viewteachersdetails();
        break;
    case 4: exitt();
        break;
    default:
        printf("\nINVALID CHOICE!!!");
        goto ADD2;
        break;
    }
}
struct teachers
{
    char name[50];
    char id[55];
    char password[55];
    char phonenumber[15];
    char email[35];
} s;
void addteachers()
{
    FILE* f;
    int i,  valid = 0, flag = 0;
    f = fopen("add.txt", "a+");
    system("cls");
    printf("\n                     ENTER TEACHER DETAILS  ");
    printf("\n           ****************************************");
    do
    {
    name1:
        printf("\n Enter your Name\t\t: ");
        scanf("%s", &s.name);
        for (i = 0; i < strlen(s.name); i++)
        {
            if (isalpha(s.name[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
    } while (!valid);
    do
    {
    id1:
        printf("\n Enter id\t: ");

        scanf("%s", s.id);
        if (strlen(s.id) < 4 || strlen(s.id) > 12)
        {
            printf("\nId should be more than 4 and less than 13. Please enter valid number.\n");
            goto id1;
        }
        for (i = 0; i < strlen(s.id); i++)
        {
            if (!isalpha(s.id[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\nEntered Invalid ID.Try Again\n");
            goto id1;
        }
    } while (!valid);
    do
    {
    password1:
        printf("\n Enter Password\t: ");

        scanf("%s",s.password);
        if (strlen(s.password) < 0 || strlen(s.password) > 10)
        {
            printf("\npassword should be of 10 numbers from 0-9. Please, enter valid number.\n");
            goto password1;
        }
        for (i = 0; i < strlen(s.password); i++)
        {
            if (!isalpha(s.password[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\nThe password is invalid. Please, enter numbers only.\n");
            goto password1;
        }
    } while (!valid);
    do
    {
    phonenumber1:
        printf("\n Enter Phone Number\t: ");

        scanf("%s",s.phonenumber);
        if (strlen(s.phonenumber) != 10 || strlen(s.phonenumber) > 10)
        {
            printf("\nPhone number should be of 10 numbers from 0-9. Please, enter valid number.\n");
            goto phonenumber1;
        }
        for (i = 0; i < strlen(s.phonenumber); i++)
        {
            if (!isalpha(s.phonenumber[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\nThe phone number is invalid. Please, enter numbers only.\n");
            goto phonenumber1;
        }
    } while (!valid);
    do
    {
    email1:
        printf("\nEnter Email\t\t: ");
        scanf("%s",s.email);
        if (strlen(s.email) > 35 || strlen(s.email) < 10)
        {
            printf("\nInvalid!!\n\tThe maximum number for email is less than 31 and more than 10.\n");
            goto email1;
        }
    } while (strlen(s.email) > 35 || strlen(s.email) < 10);

    fprintf(f, "%s %s %s %s %s\n", s.name, s.id, s.password, s.phonenumber, s.email);
    printf("\n\n Successfully Added!!");
    fclose(f);
    getch();
    management();
}
void deleteteachers()
{
    FILE* f, * t;
    int flag = 0;
    char iid[50];
    t = fopen("temp.txt", "w+");
    if ((f = fopen("add.txt", "r")) == NULL)
    {
        printf("EMPTY FILE.");
        management();
    }
    else
    {
        system("cls");
        printf("ENTER TEACHER ID TO DELETE : ");
        fflush(stdin);
        scanf("%s",iid);
        while (fscanf(f, "%s %s %s %s %s \n", s.name, s.id, s.password, s.phonenumber, s.email) != EOF)
        {
            if (strcmp(iid, s.id) == 0)
            {
                flag = 1;
            }
            else
            {
                fprintf(t, "%s %s %s %s %s \n", s.name, s.id, s.password, s.phonenumber, s.email);
            }

        }
    }
    fclose(f);
    fclose(t);
    if (flag != 1)
    {
        printf("\n\n Data not found !");
        getch();
    }
    else
    {
        printf("\n\tSuccessfully deleted.\n");
    }
    remove("add.txt");
    rename("temp.txt", "add.txt");
    getch();
    management();
}
void viewteachersdetails()
{
    FILE* f;
    int i, q = 9;
    if ((f = fopen("add.txt", "r")) == NULL)
        exit(0);
    system("cls");
    gotoxy(1, 6);
    printf("NAME ");
    gotoxy(15, 6);
    printf("ID ");
    gotoxy(30, 6);
    printf("PASSWORD");
    gotoxy(45, 6);
    printf("PHONENUMBER ");
    gotoxy(60, 6);
    printf("EMAIL\n ");


    for (i = 0; i < 100; i++)
    {
        printf("-");
    }

    while (fscanf(f, "%s %s %s %s %s \n", s.name, s.id, s.password, s.phonenumber, s.email) != EOF)
    {
        gotoxy(1, q);
        printf("%s", s.name);
        gotoxy(16, q);
        printf("%s", s.id);
        gotoxy(31, q);
        printf("%s", s.password);
        gotoxy(46, q);
        printf("%s", s.phonenumber);
        gotoxy(61, q);
        printf("%s", s.email);
        q++;
    }
    printf("\n");
    for (i = 0; i < 100; i++)
        printf("-");

    fclose(f);
    getch();
    management();
}
void gotoxy(int x, int y)
{
    COORD CR;
    CR.X = x;
    CR.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CR);
}
struct teachers q;
void teacher_login()
{
    system("cls");
    FILE* fp;
    char id1[30], c, pass[30];
    int z = 0;
    fp = fopen("add.txt", "r+");
    printf("\n\n\t\t\t\tWELCOME TO LOG IN ");
    printf("\n\t\t\t*****************************");
    printf("\n\n\t\t\t\t  ENTER ID: ");
    fflush(stdin);
    scanf("%s", id1);
    printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
    fflush(stdin);
    scanf("%s",pass);
    /*while((c=getch())!=20)
    {
        pass[z++]=c;
        printf("%c",'*');
    }
    pass[z]='\0';*/
    //while(!feof(fp))
   while(fscanf(&fp,"%s %s \n",q.id,q.password)!=EOF)
    {
        //fread(&q,sizeof(q),1,fp);
        //fprintf(fp,"%s %s\n",q.id,q.password);
        //printf("%s %s",id1,pass);
        if(strcmp(q.id,id1)==0 && strcmp(q.password,pass)==0)
        {
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            teacher_home();
            break;
        }
        else
        {
            printf("\n\n\n\t\t\tWRONG PASSWORD OR ID.TRY AGAIN");
            teacher_login();
        }
    }
    getch();
}
void teacher_home()
{
    int ch1;
    system("cls");
    printf("\n\n\n\t\t\t\t\t  TEACHER \n\n");
    printf("\t\t\t*********************************************************\n");
    ADD3:
    printf("\n\n\t\t\t\t\t 1.ADD STUDENTS\n");
    printf("\n\t\t\t\t\t 2.DELETE STUDENTS\n");
    printf("\n\t\t\t\t\t 3.VIEW STUDENTS DETAILS\n");
    printf("\n\t\t\t\t\t 4.MARK ATTENDENCE\n");
    printf("\n\t\t\t\t\t 5.VIEW STUDENTS ATTENDENCE\n");
    printf("\n\t\t\t\t\t 6.EDIT PERSONAL DETAILS\n");
    printf("\n\t\t\t\t\t 7.EXIT\n");
    printf("\n\t\t\t\tSelect an Option: ");
    scanf("%d", &ch1);
    //home1 = getch();
    switch (ch1)
    {
    case 1: addstudents();
        break;
    case 2: deletestudents();

        break;
    case 3: viewstudentdetails();
        break;
    case 4: mark_attendence();
        break;
    case 5: view_student_attendence();
        break;
    case 6: edit_personal_details();
        break;
    case 7: exitt();
        break;
    default:
        printf("Entered invalid Option!!!");
        goto ADD3;
        break;
    }
}
struct student
{
    char id[40];
    char name[30];
    char section[5];
    char password[30];
}s1;
void addstudents()
{
    FILE* f;
    int i, n, valid = 0;
    f = fopen("students.txt", "a+");
    system("cls");
    printf("\n                     ENTER STUDENT DETAILS  ");
    printf("\n         ********************************************");
    do
    {
    name2:
        printf("\n Enter your Name\t\t: ");
        scanf("%s",s1.name);
        for (i = 0; i < strlen(s1.name); i++)
        {
            if (isalpha(s1.name[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
    } while (!valid);
    do
    {
    id2:
        printf("\n Enter id\t: ");

        scanf("%s",s1.id);
        if (strlen(s1.id) < 4 || strlen(s1.id) > 12)
        {
            printf("\nId should be more than 4 and less than 13. Please enter valid number.\n");
            goto id2;
        }
        for (i = 0; i < strlen(s1.id); i++)
        {
            if (!isalpha(s1.id[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\nEntered Invalid ID.Try Again\n");
            goto id2;
        }
    } while (!valid);
    do
    {
    password2:
        printf("\n Enter Password\t: ");
        scanf("%s",s1.password);
        for (i = 0; i < strlen(s1.password); i++)
        {
            if (!isalpha(s1.password[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\nThe password is invalid. Please, enter numbers only.\n");
            goto password2;
        }
    }
    while (!valid);
    do
     {
    section:
    printf("\n Enter Section\t: ");
    scanf("%s",s1.section);
    if((s1.section=='cse') && (s1.section == 'it') && (s1.section == 'mechanical') && (s1.section == civil) && (s1.section == 'ece' ) && (s1.section == 'eee'))
    {
	valid = 1;
    }
    else
    {
	printf("\nThe Section is invalid. Please, enter cse or it or mechanical or civil or ece or eee.\n");   
         valid =0;
        goto section;
     }
    }while(!valid);
    fprintf(f, "%s %s %s %s \n", s1.name, s1.id, s1.password, s1.section);
    printf("\n\n Successfully Added!!!");
    fclose(f);
    getch();
    teacher_home();

}
void deletestudents()
{
    FILE* f, * t;
    int flag = 0;
    char idd[50];
    t = fopen("temp1.txt", "w+");
    if ((f = fopen("students.txt", "r")) == NULL)
    {
        printf("EMPTY FILE.");
        teacher_home();
    }
    else
    {
        system("cls");
        printf("ENTER STUDENT ID TO DELETE : ");
        fflush(stdin);
        scanf("%s",idd);
        while (fscanf(f, " %s %s %s %s \n", s1.name, s1.id, s1.password, s1.section) != EOF)
        {
            if (strcmp(idd, s1.id) == 0)
            {
                flag = 1;
            }
            else
            {
                fprintf(t, " %s %s %s %s \n", s1.name, s1.id, s1.password, s1.section);
            }

        }
    }
    fclose(f);
    fclose(t);
    if (flag != 1)
    {
        printf("\n\n Info not found !");
        getch();
    }
    else
    {
        printf("\n\tSuccessfully deleted.\n");
    }

    remove("students.txt");
    rename("temp1.txt", "students.txt");
    getch();
    teacher_home();
}

void viewstudentdetails()
{
    FILE* f;
    int i, q = 9;
    if ((f = fopen("students.txt", "r")) == NULL)
        exit(0);
    system("cls");
    gotoxy(1, 6);
    printf("NAME ");
    gotoxy(15, 6);
    printf("ID ");
    gotoxy(30, 6);
    printf("PASSWORD");
    gotoxy(45, 6);
    printf("SECTION");

    for (i = 0; i < 100; i++)
    {
        printf("-");
    }

    while (fscanf(f, " %s %s %s %s \n", s1.name, s1.id, s1.password, s1.section) != EOF)
    {
        gotoxy(1, q);
        printf("%s", s1.name);
        gotoxy(16, q);
        printf("%s", s1.id);
        gotoxy(31, q);
        printf("%s", s1.password);
        gotoxy(46, q);
        printf("%s", s1.section);
        q++;
    }
    printf("\n");
    for (i = 0; i < 100; i++)
        printf("-");

    fclose(f);
    getch();
    teacher_home();
}
struct student_attendence
{
    char id[20];
    char name[40];
    char section[5];
    char att[5];
    char date[20];
};
struct student_attendence st;
void mark_attendence()
{
    char att_date[20];
    int found = 0;
    char att_pre[5];
    char att_abs[5];
    char att_att[5];
    int att_count = 0;
    FILE * fptr5, * fptr6;
    printf("\n\n\n\t\t\t\t\t\t\tATTENDENCE");
    printf("\n\n\t\t\t******************************************");
    FILE * f, * f1;
    f = fopen("student.txt", "r");
    f1 = fopen("Attendence.txt", "a+");
    while (fscanf(f, "%s %s %s\n", s1.name, s1.id, s1.section) != EOF)
    {
            strcpy(st.name, s1.name);
            strcpy(st.id, s1.id);
            strcpy(st.section, s1.section);
            fprintf(f1, "%s %s %s\n", st.name, st.id, st.section);
     }
    fclose(f);
    fclose(f1);
    ADD4:
    printf("\n\t\t\Enter Current Date");
    scanf("%s", &att_date);
    fptr5 = fopen("students.txt", "r");
    fptr6 = fopen("Attendence.txt", "r");
    while (fscanf(fptr6, "%s %s %s %s %s\n", st.name, st.id, st.section, st.att, st.date) != EOF)
    {
        if (strcmp(st.date, att_date) == 0)
        {
            found = 1;
        }
    }
    fclose(fptr6);
    fptr6 = fopen("Attendence.txt", "a+");
    if (found == 0)
    {
        while (fscanf(fptr5, " %s %s %s %s\n", s1.name, s1.id, s1.password, s1.section) != EOF)
        {
            strcpy(st.date, att_date);
            strcpy(st.id, s1.id);
            strcpy(st.name, s1.name);
            printf("\n\n\t\t Student Name :%s\n\n\t\t Student ID :%s", st.name, st.id);
            printf("\t\t Enter p->>present a->>absent");
            scanf("%s",& att_att);
            if (strcmp(att_att, att_abs) == 0 || strcmp(att_pre, att_att) == 0)
            {
                if (strcmp(att_att, att_pre) == 0)
                {
                    att_count = att_count + 1;
                }
                else if (strcmp(att_att, att_abs) == 0)
                {
                    att_count = att_count + 0;
                }
                else
                {
                    printf("\n\n\t\t\t Entered Invalid Option");
                }
            }
            else
            {
                printf("\n\n\t\t\t Something Went Wrong.Try Again!!!");
                goto ADD4;
            }
            fprintf(fptr6, "%s %s %s %s %s \n", st.name, st.id, st.section, st.att, st.date);
        }
    }
    fclose(fptr6);
    fclose(fptr5);
    int cha;
    printf("\n\n\t\tDo you want to continue ??\n\t\tIf yes Enter 1 else Enter 2");
    scanf("%s", &cha);
    switch (cha)
    {
    case 1: teacher_home();
        break;
    case 2: exitt();
        break;
    default: printf("\n\t\tEntered Invalid Option.");
        teacher_home();
        break;
    }
}
struct teachers t1;
void edit_personal_details()
{
    system("cls");
    int found = 0;
    char edit_id[20];
    printf("\n  EDIT PERSONAL INFORMATION\n");
    FILE* edit1, * fpedt1;
    edit1 = fopen("add.txt", "r");
    printf("\n  Enter Your ID for Verification : ");
    scanf("%s",edit_id);
    while (fscanf(edit1, "%s %s %s %s %s\n", s.name, s.id, s.password, s.phonenumber, s.email) != EOF)
    {
        if (strcmp(edit_id, s.id) == 0)
        {
            found=1;
            fpedt1 = fopen("Edit Teacher.txt", "w");
            fflush(stdin);
            printf("\n  Enter New  Name:");
            scanf("%s",s.name);
            printf("  \nEnter New Password:");
            scanf("%s",s.password);
            printf("  \nEnter New EmailID: ");
            scanf("%s",s.email);
            printf("  \nEnter New MobileNo:");
            scanf("%s",s.phonenumber);
            strcpy(t1.name, s.name);
            strcpy(t1.id, edit_id);
            strcpy(t1.password, s.password);
            strcpy(t1.email, s.email);
            strcpy(t1.phonenumber, s.phonenumber);
            fprintf(fpedt1, "%s %s %s %s %s\n", s.name, s.id, s.password, s.phonenumber, s.email);
        }
        else
        {
            fprintf(fpedt1, "%s %s %s %s %s\n", s.name, s.id, s.password, s.phonenumber, s.email);
        }
        if (found == 0)
        {
            printf("\n\n  INFO NOT FOUND  \n\n");
        }
    }
    fclose(fpedt1);
    fclose(edit1);
    remove("add.txt");
    rename("Edit Teacher.txt", "add.txt");
    teacher_home();
}
void view_student_attendence()
{
    system("cls");
    float present = 0;
    float absent = 0;
    float mark_att1, mark_att2;
    int count = 0;
    char p[20] = { 'p' };
    char a[20] = { 'a' };
    FILE* satt;
    satt = fopen("Attendence.txt", "r");
    char ssid[20];
    char dtls;
    int i = 0, found = 0;
    printf(" Enter The ID You Want To Search: \n");
    fflush(stdin);
    scanf("%s",ssid);
    while (fscanf(satt, "%s %s %s %s %s\n", st.name, st.id, st.section, st.att, st.date) != EOF)
    {
        if (strcmp(st.id,ssid) == 0)
        {
            found =1;
            if (strcmp(p, st.att) == 0)
            {
                present = present + 1;
            }
            else
            {
                absent = absent + 1;
            }
            count = count + 1;
            printf(">> Attendance <<\n\n");
            printf("\nID:%s", st.id);
            printf("\nSection: %s", st.section);
            printf("\nTotal Class: %0.0f", count);
            printf("\nPresent: %0.0f Days", present);
            printf("\nAbsent: %0.0f Days", absent);
            mark_att1 = (present * 100) / count;
            mark_att2 = (absent * 100) / count;
            printf("Attendance Mark: %f out of %d\n", mark_att1, count);
            printf("Attendance Mark: %f  out of %d\n\n", mark_att2, count);
        }
        else
        {
            printf("ID not found");
            mark_attendence();
        }
    }
    sa:
    printf("Do you want to view attendance details[y/n]");
    scanf("%c", &dtls);
    if (dtls == 'y'||dtls=='Y')
    {
        FILE* temp;
        temp = fopen("Attendence.txt", "r");
        while (fscanf(temp, "%s %s %s %s %s\n", st.name, st.id, st.section, st.att, st.date) != EOF)
        {
            if (strcmp(ssid, st.id) == 0)
            {
                while(fscanf(temp,"%s %s\n",st.date,st.att)!=EOF)
                {
                    if (strcmp(p, st.att) == 0)
                    {
                        printf("%s: Present\n", st.date);
                    }
                    else if (strcmp(a, st.att) == 0)
                    {
                        printf("%s: Absent\n", st.date);
                    }
                }
            }
        }
        fclose(temp);
    }
    else
    {
        printf("Invalid.Try Again!!!");
        goto sa;
    }
    fclose(satt);
    teacher_home();
}
void student_login()
{
    system("cls");
    FILE* fp;
    char id1[30], pass[30];
    fp = fopen("students.txt", "r");
    printf("\n\n\t\t\t\tWELCOME TO LOG IN ");
    printf("\n\t\t\t*********************************");
    printf("\n\n\t\t\t\t  ENTER ID: ");
    scanf("%s", id1);
    printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
    scanf("%s",pass);
        //while(fscanf(&fp,"%s %s %s %s %s\n",q.name,q.id,q.password,q.phonenumber,q.email)!=EOF)
    {
        fread(&s1, sizeof(s1), 1, fp);
        if (strcmp(id1, s1.id) == 0 && strcmp(pass, s1.password) == 0)
        {
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            student_home();
            break;
        }
        else
        {
            printf("\n\n\n\t\t\tWRONG PASSWORD OR ID");
            student_login();
        }
    }
    getch();
}
void student_home()
{
    int ch1;
    system("cls");
    printf("\n\n\n\t\t\t\t\t  STUDENT \n\n");
    printf("\t\t\t*********************************************************\n");
    ADD1:
    printf("\n\n\t\t\t\t\t 1.Check Attendence\n");
    printf("\n\t\t\t\t\t 2.EXIT\n");
    printf("\n\t\t\t\tSelect an Option: ");
    scanf("%d", &ch1);
    //home1 = getch();
    switch (ch1)
    {
    case 1:checkattendence();
        // printf("..");
        break;
    case 2: exitt();
    //    printf("Exit");
        break;
    default:
        printf("Entered invalid Option!!!");
        goto ADD1;
        break;
    }
}
void checkattendence(char id1[30])
{
    system("cls");
    float present = 0;
    float absent = 0;
    float mark_att1, mark_att2;
    float count = 0;
    char p[20] = { 'p' };
    char a[20] = { 'a' };
    FILE* satt;
    satt = fopen("Attendence.txt", "r");
    char dtls;
    int i = 0, found = 0;
    while (fscanf(satt, "%s %s %s %s %s\n", st.name, st.id, st.section, st.att, st.date) != EOF)
    {
        if (strcmp(st.id,id1) == 0)
        {
            found =1;
            if (strcmp(p, st.att) == 0)
            {
                present = present + 1;
            }
            else
            {
                absent = absent + 1;
            }
            count = count + 1;
            printf(">> Attendance <<\n\n");
            printf("\nID:%s", st.id);
            printf("\nSection: %s", st.section);
            printf("\nTotal Class: %0.0f", count);
            printf("\nPresent: %0.0f Days", present);
            printf("\nAbsent: %0.0f Days", absent);
            mark_att1 = (present * 100) / count;
            mark_att2 = (absent * 100) / count;
            printf("Attendance Mark: %f out of %d\n", mark_att1, count);
            printf("Attendance Mark: %f  out of %d\n\n", mark_att2, count);
        }
        else
        {
            printf("ID not found");
            mark_attendence();
        }
    }
    sq:
    printf("Do you want to view attendance details[y/n]");
    scanf("%c", &dtls);
    if (dtls == 'y'||dtls=='Y')
    {
        FILE* temp;
        temp = fopen("Attendence.txt", "r");
        while (fscanf(temp, "%s %s %s %s %s\n", st.name, st.id, st.section, st.att, st.date) != EOF)
        {
            if (strcmp(id1, st.id) == 0)
            {
                while(fscanf(temp,"%s %s\n",st.date,st.att)!=EOF)
                {
                    if (strcmp(p, st.att) == 0)
                    {
                        printf("%s: Present\n", st.date);
                    }
                    else if (strcmp(a, st.att) == 0)
                    {
                        printf("%s: Absent\n", st.date);
                    }
                }
            }
        }
        fclose(temp);
    }
    else
    {
        printf("Invalid.Try Again!!!");
        goto sq;
    }
    fclose(satt);
    teacher_home();
}
void exitt()
{
    printf("\n\t\tTHANK YOU FOR USING ATTENDENCE MANAGEMENT SYSTEM");
}
