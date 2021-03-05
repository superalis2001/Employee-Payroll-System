#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define FILE_NAME  "EmployeeRecord.bin"
/// Global Funcctions
void titleHeader();
void noRecordsdisplay();
void empFileMenu();
void aboutCreator();
void errorChoicedisplay();
void processPayrollmenu();
void generateReportmenu();
void addingEmployee();
void searchEmployee();
void listAllemployee();
void editEmployee();
void deleteEmployee();
void showCurrentpayroll();
void empAbsent();
void viewPreviouspayroll();
void compute_payroll();
void payrollFile();
void compute13month();
void show13month();
void loadingscreen();
void payrollMonth (char *whatMonth);
void chooseMonth (char *whatMonth);
int cutofftime(int* );

typedef struct{
    int empNumber;
    char empName[100];
    float empSalary;
    int numDependents;
    float month13pay;
} EMPINFO;

typedef struct{
    int workingDays;
    float recSalary;
    float taxReduc;
    float sssReduc;
    float pagibigReduc;
    float netPay;
    int daysAbsent;
} PAYROLL;


int main()
{
    char choice;
    int condit;
    do{
    system("cls");
    system ("COLOR 0F");
    titleHeader();
    printf("\tMAIN MENU\n-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
    printf("[1] Employee File\n[2] Process Payroll\n[3] Generate Report\n[4] About Creators\n[5] Exit\n\n\n");
    printf("Your Choice: ");
    choice = getche();

    switch(choice)
    {
        case '1':
        empFileMenu();
        condit = 1;
        break;

        case '2':
        processPayrollmenu();
        condit = 1;
        break;

        case '3':
        generateReportmenu();
        condit = 1;
        break;

        case '4':
        aboutCreator();
        condit = 1;
        break;

        case '5':
        system("cls");
        printf("\n\n");
        printf("\t\t\t\t **********************************\n");
        printf("\t\t\t\t *       T H A N K    Y O U       *\n");
        printf("\t\t\t\t **********************************\n\n");
        exit (1);

        default:
        errorChoicedisplay();
        condit = 1;
        break;
    }
    }while (condit == 1);
    return 0;
}

void titleHeader()
{
    printf("\t\t\t\t **********************************\n");
    printf("\t\t\t\t *  G E N E R A L  P A Y R O L L  *\n");
    printf("\t\t\t\t **********************************\n\n");
}

void noRecordsdisplay()
{
    printf("\n\n\t\t\t\t **********************************\n");
    printf("\t\t\t\t *      N O    R E C O R D S      *\n");
    printf("\t\t\t\t **********************************\n\n");
}

void errorChoicedisplay(){
    printf("\nInvalid Choice. Please Try Again.\n\n");
    system ("pause");
    system ("cls");
}

void aboutCreator()
{
    system("cls");
    FILE *fpDisplay = fopen("Aboutcreator.DAT", "r");
    int ch;
    do{
        ch = getc(fpDisplay);
        putchar(ch);
    }while (ch != EOF);
    printf("\n\n");
    fclose(fpDisplay);
    system("pause");
    system("cls");
}
void empFileMenu()
{
    char choice, decision;
    int condit,loop;

    FILE *fp = NULL;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fclose(fp);
    do{
    system ("cls");
    printf("\tEmployee File\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
    printf("[1] ADD New Employee\n[2] Edit Employee Record\n[3] Display Employee Information\n");
    printf("[4] List All Employees\n[5] Delete Employee\n[6] Back to Main\n\n");
    printf("Your Choice: ");
    choice = getche();

    switch (choice)
    {
        case '1':
            do{

            system ("cls");
            addingEmployee();

            begin:
            printf("Would you like to add another employee?(y/n): ");
            decision = getche();

            switch (decision)
            {
                case 'y':
                loop = 0;
                printf("\n\n");
                system("pause");
                break;

                case 'n':
                printf("\n\n");
                system("pause");
                loop = 1;
                break;

                default:
                printf("\n");
                errorChoicedisplay();
                goto begin;
                fflush(stdin);
                loop = 0;
                break;
            }
            }while (loop == 0);
            condit = 1;
            break;

        case '2':
            editEmployee();
            condit = 1;
            break;

        case '3':
            searchEmployee();
            condit = 1;
            break;

        case '4':
            listAllemployee();
            condit = 1;
            break;

        case '5':
            deleteEmployee();
            condit = 1;
            break;

        case '6':
            system ("cls");
            main();
            condit = 0;

        default:
            errorChoicedisplay();
            condit = 1;
            break;
    }
    }while (condit == 1);

}

void processPayrollmenu()
{
    char choice;
    int condit;
    do{

    system ("cls");
    system ("COLOR 0F");
    printf("\tProcess Payroll\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
    printf("[1] Compute Current Payroll\n[2] Display previous Payroll\n");
    printf("[3] Compute 13th Month\n[4] Back to Main\n\n");
    printf("Your Choice: ");
    choice = getche();

    switch (choice)
    {
        case '1':
            compute_payroll();
            condit = 1;
            break;

        case '2':
            viewPreviouspayroll();
            condit = 1;
            break;

        case '3':
            compute13month();
            condit = 1;
            break;

        case '4':
            system ("cls");
            main();
            condit = 0;
            break;

        default:
            errorChoicedisplay();
            condit = 1;
            break;
    }
    }while (condit == 1);
}

void generateReportmenu()
{
    char choice;
    int condit;
    do{

    system ("cls");
    printf("\tGenerate Report\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
    printf("[1] Print Current Payroll\n[2] Print Employees with NO Absence\n");
    printf("[3] Print 13th Month Payroll\n[4] Back to Main\n\n");
    printf("Your Choice: ");
    choice = getche();

    switch(choice)
    {
        case '1':
            showCurrentpayroll();
            condit = 1;
            break;

        case '2':
            empAbsent();
            condit = 1;
            break;

        case '3':
            show13month();
            condit = 1;
            break;

        case '4':
            system ("cls");
            main();
            condit = 0;
            break;

        default:
            errorChoicedisplay();
            condit = 1;
            break;

    }
    }while (condit == 1);
}


void addingEmployee()
{
    EMPINFO addEmployee = {0};
    FILE *fp = NULL;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    printf("\t\t\t\tADD NEW EMPLOYEES");
    printf("\n\nENTER YOUR DETAILS BELOW:");
    printf("\n---------------------------------------------------------------------------\n");
    srand(time(0));
    addEmployee.empNumber = rand();
    printf("\nEmployee ID: %d\n", addEmployee.empNumber);
    fflush(stdin);
    printf("\nFull Name of Employee: ");
    fgets(addEmployee.empName,100, stdin);
    addEmployee.empName[strlen(addEmployee.empName)-1]='\0';

		do{
        printf("\nSalary: ");
		scanf("%f",&addEmployee.empSalary);
		if (addEmployee.empSalary < 0 || addEmployee.empSalary > 40000)
            printf("Error, Please Try again.\n");
		}while (addEmployee.empSalary < 0 || addEmployee.empSalary > 40000);


        do{
        printf("\nEnter number of dependents: ");
        scanf("%d", &addEmployee.numDependents);
        if (addEmployee.numDependents < 0)
            printf("Error, Please Try again.\n");
        }while(addEmployee.numDependents < 0);


    fwrite(&addEmployee,sizeof(addEmployee), 1, fp);
    fclose(fp);
}

void searchEmployee()
{
    system("cls");
    int found = 0;
    int employeeId = 0;
    EMPINFO addEmployee = {0};
    FILE *fp = NULL;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    printf("\n\t\t\tSEARCH EMPLOYEE");
    printf("\n---------------------------------------------------------------------------\n");
    printf("\nEnter employee ID NO to search:");
    fflush(stdin);
    scanf("%d",&employeeId);
    while (fread (&addEmployee, sizeof(addEmployee), 1, fp))
    {
        if(addEmployee.empNumber == employeeId)
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("\nEmployee id: %d",addEmployee.empNumber);
        printf("\nEmployee name: %s",addEmployee.empName);
        printf("\nEmployee Salary: %.2f",addEmployee.empSalary);
        printf("\nNumber of Dependents = %d\n\n",addEmployee.numDependents);
    }
    else
    {
        noRecordsdisplay();
    }
    fclose(fp);
    fflush(stdin);
    system("pause");
}

void listAllemployee()
{
    system("cls");
    int found = 0;
    EMPINFO addEmployee = {0};
    FILE *fp = NULL;
    unsigned int countEmployee = 0;
    printf("\n\t\t\t\tLIST OF EMPLOYEES");
    printf("\n-------------------------------------------------------------------------------------\n");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    printf("Employee ID:\t\tName:\t\t\t\tSalary[PHP]:\tDependents:\n\n");
    while (fread (&addEmployee, sizeof(addEmployee), 1, fp))
    {
        printf("%d\t\t\t",addEmployee.empNumber);
        printf("%-20s\t",addEmployee.empName);
        printf(" %15.2f\t",addEmployee.empSalary);
        printf("%d\n",addEmployee.numDependents);
        found = 1;
        ++countEmployee;
    }
    if(!found)
    {
       noRecordsdisplay();
    }
    printf("\nEmployee Count = %d\n\n",countEmployee);
    fclose(fp);
    fflush(stdin);
    system ("pause");
}

void deleteEmployee()
{

    fflush(stdin);
    system("cls");
    int found = 0;
    int employeeDelete = 0;
    EMPINFO addEmployee = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    printf("\n\t\t\tDelete employee Details");
    printf("\n---------------------------------------------------------------------------\n");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    tmpFp = fopen("temporary.bin","wb");
    if(tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }

    printf("\nEnter employee ID NO. for delete: ");
    scanf("%d",&employeeDelete);
    while (fread (&addEmployee, sizeof(addEmployee), 1, fp))
    {
        if(addEmployee.empNumber != employeeDelete)
        {
            fwrite(&addEmployee,sizeof(addEmployee), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\nRecord deleted successfully.....\n\n"):noRecordsdisplay();
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("temporary.bin",FILE_NAME);
    system("pause");
}

void editEmployee()
{
    system("cls");
    int found = 0, condit,loop;
    int employeeEdit = 0;
    char choice, option;
    EMPINFO addEmployee = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    printf("\n\t\t\tEdit employee Details");
    printf("\n---------------------------------------------------------------------------\n");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    tmpFp = fopen("temporary.bin","wb");
    if(tmpFp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }

    printf("\nEnter employee ID NO: ");
    scanf("%d",&employeeEdit);
    while (fread (&addEmployee, sizeof(addEmployee), 1, fp))
    {


        if(addEmployee.empNumber != employeeEdit)
        {
            fwrite(&addEmployee,sizeof(addEmployee), 1, tmpFp);
        }
        else
        {
            found = 1;
        }

    if (found == 1)
    {
        if(addEmployee.empNumber == employeeEdit)
        {
            do{
            system("cls");
            printf("\n\t\t\tEdit employee Details");
            printf("\n---------------------------------------------------------------------------\n");

            printf("\nWhat info would you like to edit?\n\n");
            printf("[1] Employee Name\n[2] Employee Salary\n[3] Number of Dependents\n\n");
            printf("Your Choice: ");
            choice = getche();

            switch(choice)
            {
                case '1':
                    fflush(stdin);
                    printf("\n\nOld name of Employee: %s", addEmployee.empName);
                    printf("\n\nEnter New Name of Employee: ");
                    fgets(addEmployee.empName,100, stdin);
                    addEmployee.empName[strlen(addEmployee.empName)-1]='\0';
                    condit = 0;
                    break;

                case '2':
                    do{
                        printf("\n\nOld Salary: %.2f", addEmployee.empSalary);
                        printf("\nEnter New Salary: ");
                        scanf("%f",&addEmployee.empSalary);
                        if (addEmployee.empSalary < 0 || addEmployee.empSalary > 40000)
                            printf("Error, Please Try again.\n");
                    }while (addEmployee.empSalary < 0 || addEmployee.empSalary > 40000);
                    condit = 0;
                    break;

                case '3':
                    do{
                        printf("\n\nOld number of dependents: %d", addEmployee.numDependents);
                        printf("\nEnter New number of dependents: ");
                        scanf("%d", &addEmployee.numDependents);
                        if (addEmployee.numDependents < 0)
                            printf("Error, Please Try again.\n");
                    }while(addEmployee.numDependents < 0);
                    condit = 0;
                    break;
                default:
                    errorChoicedisplay();
                    condit = 1;
                    break;
            }
            }while(condit == 1);
            fwrite(&addEmployee,sizeof(addEmployee), 1, tmpFp);
        }
    }
    }

     if((addEmployee.empNumber != employeeEdit) && found !=1)
        {
            noRecordsdisplay();
            fflush(stdin);
            fclose(fp);
            fclose(tmpFp);
            remove("temporary.bin");
            system("pause");
            empFileMenu();
        }
    do{
        system("cls");
        printf("\n\t\t\tEdit employee Details");
        printf("\n---------------------------------------------------------------------------\n");
        printf("\n\nDo you want to save the record?(Y/N)\n\n");
        printf("Your Choice: ");
        option = getche();

        switch (option)
        {
            case 'Y':
                fclose(fp);
                fclose(tmpFp);
                remove(FILE_NAME);
                rename("temporary.bin",FILE_NAME);
                printf("\n\n");
                fflush(stdin);
                system("pause");
                loop = 0;
                break;

                case 'N':
                fclose(fp);
                fclose(tmpFp);
                remove("temporary.bin");
                printf("\n\n");
                fflush(stdin);
                system("pause");
                loop = 0;
                break;

                case 'y':
                fclose(fp);
                fclose(tmpFp);
                remove(FILE_NAME);
                rename("temporary.bin",FILE_NAME);
                printf("\n\n");
                fflush(stdin);
                system("pause");
                loop = 0;
                break;

                case 'n':
                fclose(fp);
                fclose(tmpFp);
                remove("temporary.bin");
                printf("\n\n");
                fflush(stdin);
                system("pause");
                loop = 0;
                break;

                default:
                errorChoicedisplay();
                loop = 1;
                break;
                    }
    }while (loop == 1);
}


int cutofftime(int *cutoff)
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Current Date (MM/DD/YY): %d-%d-%d",  tm.tm_mon+1, tm.tm_mday, tm.tm_year+1900);
    if (tm.tm_mon+1 == 1){
        if (tm.tm_mday == 15 || tm.tm_mday == 30)
            *cutoff = 1;
        else
            *cutoff = 0;
    }
    else if(tm.tm_mon+1 == 2){
        if (tm.tm_mday == 15 || tm.tm_mday == 28)
            *cutoff = 1;
        else
            *cutoff = 0;
    }
    else if(tm.tm_mon+1 == 3){
        if (tm.tm_mday == 15 || tm.tm_mday == 30)
            *cutoff = 1;
        else
            *cutoff = 0;
    }
    else if(tm.tm_mon+1 == 4){
        if (tm.tm_mday == 15 || tm.tm_mday == 30)
            *cutoff = 1;
        else
            *cutoff = 0;
    }
    else if(tm.tm_mon+1 == 5){
        if (tm.tm_mday == 15 || tm.tm_mday == 30)
            *cutoff = 1;
        else
            *cutoff = 0;
    }
    else if(tm.tm_mon+1 == 6){
        if (tm.tm_mday == 15 || tm.tm_mday == 30)
            *cutoff = 1;
        else
            *cutoff = 0;
    }
    else if(tm.tm_mon+1 == 7){
        if (tm.tm_mday == 15 || tm.tm_mday == 30)
            *cutoff = 1;
        else
            *cutoff = 0;
    }
    else if(tm.tm_mon+1 == 8){
        if (tm.tm_mday == 15 || tm.tm_mday == 30)
            *cutoff = 1;
        else
            *cutoff = 0;
    }
    else if(tm.tm_mon+1 == 9){
        if (tm.tm_mday == 15 || tm.tm_mday == 30)
            *cutoff = 1;
        else
            *cutoff = 0;
    }
    else if(tm.tm_mon+1 == 10){
        if (tm.tm_mday == 15 || tm.tm_mday == 30)
            *cutoff = 1;
        else
            *cutoff = 0;
    }
    else if(tm.tm_mon+1 == 11){
        if (tm.tm_mday == 15 || tm.tm_mday == 30)
            *cutoff = 1;
        else
            *cutoff = 0;
    }
     else if(tm.tm_mon+1 == 12){
        if (tm.tm_mday == 15 || tm.tm_mday == 30)
            *cutoff = 1;
        else
            *cutoff = 0;
    }

    return *cutoff;
}

void compute_payroll()
{
    int cutoff;
    system("cls");
    titleHeader();
    printf("COMPUTE CURRENT PAYROLL FILE");
    printf("\n---------------------------------------------------------------------------\n");
    cutofftime(&cutoff);
    if (cutoff == 1)
    {
        printf("\n\n\aNot Yet Cut-Off\n\n");
        system("pause");
        processPayrollmenu();
    }
    else
    {
        payrollFile();
    }


}

void payrollFile()
{
    EMPINFO addEmployee = {0};
    PAYROLL taxCalculations = {0};
    int found = 0;
    char whatMonth[100];
    FILE *fp = NULL;
    FILE *fpPayroll = NULL;

    fp = fopen(FILE_NAME,"rb");

    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }

    payrollMonth(whatMonth);

    fpPayroll = fopen(whatMonth,"wb");
    if(fpPayroll == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    while (fread (&addEmployee, sizeof(addEmployee), 1, fp))
    {
        printf("\n\nEmployee ID: %d\n",addEmployee.empNumber);
        printf("Name: %s\n",addEmployee.empName);
        printf("Salary %.2f\n",addEmployee.empSalary);

        do{
        printf("Enter days worked: ");
        scanf("%d", &taxCalculations.workingDays);
        if (taxCalculations.workingDays < 0 || taxCalculations.workingDays > 11)
            printf("Error, Please Try again.\n");
		}while (taxCalculations.workingDays < 0 || taxCalculations.workingDays > 11);

        taxCalculations.recSalary = (addEmployee.empSalary/11) * taxCalculations.workingDays;
        taxCalculations.daysAbsent = 11 - taxCalculations.workingDays;

        if (taxCalculations.recSalary == 0){
            taxCalculations.sssReduc = 0;
            taxCalculations.pagibigReduc = 0;
            taxCalculations.taxReduc = 0;
            taxCalculations.netPay = taxCalculations.recSalary - (taxCalculations.sssReduc + taxCalculations.pagibigReduc + taxCalculations.taxReduc);
        }
        else if (taxCalculations.recSalary < 20000 && taxCalculations.recSalary > 0){
            taxCalculations.sssReduc = taxCalculations.recSalary * 0.01;
            taxCalculations.pagibigReduc = 200;
            taxCalculations.taxReduc = 0;
            taxCalculations.netPay = taxCalculations.recSalary - (taxCalculations.sssReduc + taxCalculations.pagibigReduc + taxCalculations.taxReduc);
        }
        else if ((taxCalculations.recSalary >= 20000 && taxCalculations.recSalary < 30000) && addEmployee.numDependents == 0){
            taxCalculations.sssReduc = taxCalculations.recSalary * 0.02;
            taxCalculations.pagibigReduc = 200;
            taxCalculations.taxReduc = taxCalculations.recSalary * 0.10;
            taxCalculations.netPay = taxCalculations.recSalary - (taxCalculations.sssReduc + taxCalculations.pagibigReduc + taxCalculations.taxReduc);
        }
         else if ((taxCalculations.recSalary >= 20000 && taxCalculations.recSalary < 30000) && ( addEmployee.numDependents == 1 || addEmployee.numDependents == 2)){
            taxCalculations.sssReduc = taxCalculations.recSalary * 0.02;
            taxCalculations.pagibigReduc = 200;
            taxCalculations.taxReduc = taxCalculations.recSalary * 0.07;
            taxCalculations.netPay = taxCalculations.recSalary - (taxCalculations.sssReduc + taxCalculations.pagibigReduc + taxCalculations.taxReduc);
        }
         else if ((taxCalculations.recSalary >= 20000 && taxCalculations.recSalary < 30000) && addEmployee.numDependents >= 3){
            taxCalculations.sssReduc = taxCalculations.recSalary * 0.02;
            taxCalculations.pagibigReduc = 200;
            taxCalculations.taxReduc = taxCalculations.recSalary * 0.05;
            taxCalculations.netPay = taxCalculations.recSalary - (taxCalculations.sssReduc + taxCalculations.pagibigReduc + taxCalculations.taxReduc);
        }
        else if ((taxCalculations.recSalary >= 30000 && taxCalculations.recSalary <= 40000) && addEmployee.numDependents == 0){
            taxCalculations.sssReduc = taxCalculations.recSalary * 0.03;
            taxCalculations.pagibigReduc = 200;
            taxCalculations.taxReduc = taxCalculations.recSalary * 0.15;
            taxCalculations.netPay = taxCalculations.recSalary - (taxCalculations.sssReduc + taxCalculations.pagibigReduc + taxCalculations.taxReduc);
        }
        else if ((taxCalculations.recSalary >= 30000 && taxCalculations.recSalary <= 40000) && (addEmployee.numDependents == 1 || addEmployee.numDependents == 2)){
            taxCalculations.sssReduc = taxCalculations.recSalary * 0.03;
            taxCalculations.pagibigReduc = 200;
            taxCalculations.taxReduc = taxCalculations.recSalary * 0.12;
            taxCalculations.netPay = taxCalculations.recSalary - (taxCalculations.sssReduc + taxCalculations.pagibigReduc + taxCalculations.taxReduc);
        }
        else if ((taxCalculations.recSalary >= 30000 && taxCalculations.recSalary <= 40000) && addEmployee.numDependents >= 3){
            taxCalculations.sssReduc = taxCalculations.recSalary * 0.03;
            taxCalculations.pagibigReduc = 200;
            taxCalculations.taxReduc = taxCalculations.recSalary * 0.10;
            taxCalculations.netPay = taxCalculations.recSalary - (taxCalculations.sssReduc + taxCalculations.pagibigReduc + taxCalculations.taxReduc);
        }
        else{
            printf("Error, please try again.");
            exit (100);
        }


        fwrite(&taxCalculations,sizeof(taxCalculations), 1, fpPayroll);
        found = 1;

    }

    if(!found)
    {
        printf("\n\t\t\tNO RECORDS");
        printf("\n---------------------------------------------------------------------------\n");
    }
    fclose(fpPayroll);
    fclose(fp);
    fflush(stdin);

    system("pause");
}

void showCurrentpayroll()
{
    system("cls");
    EMPINFO addEmployee = {0};
    PAYROLL taxCalculations = {0};
    char whatMonth[100];
    FILE *fp = NULL;
    FILE *fpPayroll = NULL;
    payrollMonth(whatMonth);
    system("cls");
    fp = fopen(FILE_NAME,"rb");

    fpPayroll = fopen(whatMonth,"rb");
    titleHeader();

    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if(fpPayroll == NULL)
    {
        printf("Payroll for the month of %s", whatMonth);
        printf("\n---------------------------------------------------------------------------\n");
        noRecordsdisplay();
        system ("pause");
        generateReportmenu();
    }
    printf("Payroll for the month of %s", whatMonth);
    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("Employee ID:\t\tName:\t\t\t    SSS:\t    PAGIBIG:\t     TAX:\t  NET PAY:\n\n");
    while (fread (&addEmployee, sizeof(addEmployee), 1, fp) && fread (&taxCalculations, sizeof(taxCalculations), 1, fpPayroll))
    {
        printf("%d\t\t\t",addEmployee.empNumber);
        printf("%-20s\t",addEmployee.empName);
        printf("%10.2f\t",taxCalculations.sssReduc);
        printf("%10.2f\t",taxCalculations.pagibigReduc);
        printf("%10.2f\t",taxCalculations.taxReduc);
        printf("%10.2f\n\n",taxCalculations.netPay);
    }

    fclose(fp);
    fclose(fpPayroll);
    fflush(stdin);
    system ("pause");
}

void viewPreviouspayroll()
{
    EMPINFO addEmployee = {0};
    PAYROLL taxCalculations = {0};
    char whatMonth[100];
    FILE *fp = NULL;
    FILE *fpPayroll = NULL;
    system("cls");
    fflush(stdin);
    printf("\n\t\t\tDisplay Previous Payroll");
    printf("\n---------------------------------------------------------------------------\n");
    printf("\nEnter the month: ");
    scanf("%s", whatMonth);

    chooseMonth(whatMonth);

    if (strcmpi(whatMonth,"Error") == 0)
    {
        processPayrollmenu();
    }

    system("cls");
    fp = fopen(FILE_NAME,"rb");

    fpPayroll = fopen(whatMonth,"rb");
    titleHeader();

    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if(fpPayroll == NULL)
    {
        printf("Payroll for the month of %s", whatMonth);
        printf("\n---------------------------------------------------------------------------\n");
        noRecordsdisplay();
        system ("pause");
        processPayrollmenu();
    }
    printf("Payroll for the month of %s", whatMonth);
    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("Employee ID:\t\tName:\t\t\t    SSS:\t    PAGIBIG:\t     TAX:\t  NET PAY:\n\n");
    while (fread (&addEmployee, sizeof(addEmployee), 1, fp) && fread (&taxCalculations, sizeof(taxCalculations), 1, fpPayroll))
    {
        printf("%d\t\t\t",addEmployee.empNumber);
        printf("%-20s\t",addEmployee.empName);
        printf("%10.2f\t",taxCalculations.sssReduc);
        printf("%10.2f\t",taxCalculations.pagibigReduc);
        printf("%10.2f\t",taxCalculations.taxReduc);
        printf("%10.2f\n\n",taxCalculations.netPay);
    }

    fclose(fp);
    fclose(fpPayroll);
    fflush(stdin);
    system ("pause");
}

void empAbsent()
{
    system("cls");
    EMPINFO addEmployee = {0};
    PAYROLL taxCalculations = {0};
    char whatMonth[100];
    FILE *fp = NULL;
    FILE *fpPayroll = NULL;
    fp = fopen(FILE_NAME,"rb");
    printf("\n\t\t\tEMPLOYEES WITH NO ABSENCE");
    printf("\n---------------------------------------------------------------------------\n");
    printf("\nEnter the month: ");
    scanf("%s", whatMonth);
    chooseMonth(whatMonth);

    if (strcmpi(whatMonth,"Error") == 0)
    {
        empAbsent();
    }


    fpPayroll = fopen(whatMonth,"rb");

    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    if(fpPayroll == NULL)
    {
        system("cls");
        printf("\n\t\t\tEMPLOYEES WITH NO ABSENCE");
    printf("\n---------------------------------------------------------------------------\n");
        noRecordsdisplay();
        system("pause");
        generateReportmenu();
    }
    system ("cls");
    printf("\n\t\t\tEMPLOYEES WITH NO ABSENCE");
    printf("\n---------------------------------------------------------------------------\n");
    printf("Employee ID:\t\tName:\n");
    while (fread (&addEmployee, sizeof(addEmployee), 1, fp) && fread (&taxCalculations, sizeof(taxCalculations), 1, fpPayroll))
    {
        if(taxCalculations.daysAbsent == 0)
        {
            printf("%d\t\t\t",addEmployee.empNumber);
            printf("%-20s\n",addEmployee.empName);

        }
    }
    fclose(fp);
    fclose(fpPayroll);
    fflush(stdin);
    printf("\n\n");
    system("pause");
}

void compute13month()
{
    system("cls");
    EMPINFO addEmployee = {0};
    FILE *fp = NULL;
    FILE *fp13 = NULL;
    fp = fopen(FILE_NAME,"rb");
    fp13 = fopen("13thMonth.bin","wb+");
    int monthsWorked;
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if(fp13 == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    titleHeader();
    while (fread (&addEmployee, sizeof(addEmployee), 1, fp))
    {
        printf("\n\nName: %s\n", addEmployee.empName);

        do{
        printf("How many months did you worked for the year?: ");
        scanf("%d", &monthsWorked);
        if (monthsWorked < 1 || monthsWorked >12)
        {
            printf("Error, Please Try Again.\n\n");
        }
        }while(monthsWorked < 1 || monthsWorked >12);
        addEmployee.month13pay = (addEmployee.empSalary * monthsWorked)/12 ;
        fwrite(&addEmployee,sizeof(addEmployee), 1, fp13);
    }

    loadingscreen();
    fflush(stdin);
    fclose(fp);
    fclose(fp13);
    system("pause");
}

void show13month()
{
    system("cls");
    EMPINFO addEmployee = {0};
    FILE *fp = NULL;
    FILE *fp13 = NULL;
    fp = fopen(FILE_NAME,"rb");
    fp13 = fopen("13thMonth.bin","rb");
    if(fp13 == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    printf("\n\t\t13TH MONTH PAYROLL");
    printf("\n---------------------------------------------------------------------------\n");
    printf("NAME:\t\t\t\t13th Month:\n");

    while (fread (&addEmployee, sizeof(addEmployee), 1, fp) && fread (&addEmployee,sizeof(addEmployee), 1, fp13))
    {
        printf("%-20s\t\t", addEmployee.empName);
        printf("%5.2f\n", addEmployee.month13pay);
    }
    printf("\n");
    fclose(fp);
    fflush(stdin);

    system("pause");
}
void loadingscreen()
{
    char a = 177, b = 219;
    system("cls");
    printf("\n\n\t\t\t\t\tProcessing 13th Month Pay...\n\n");
    printf("\t\t\t\t\t");
    //initial bar (background)
    for (int i = 0; i < 26; i++)
        printf("%c", a);
    printf("\r");
    printf("\t\t\t\t\t");
    //progress bar
    for (int i = 0; i < 26; i++) {
        printf("%c", b);

        // delay per print
        Sleep(50);
    }
    printf("\n\nProcess completed");
    printf("\n---------------------------------------------------------------------------\n\n\n");
}

void payrollMonth(char *whatMonth)
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    int condit;
    char choice;
    if (tm.tm_mon+1 == 1){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] January 1-15\n [2] January 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "January 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "January 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(tm.tm_mon+1 == 2){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] February 1-15\n [2] February 16-28\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "February 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "February 16-28");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(tm.tm_mon+1 == 3){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] March 1-15\n [2] March 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "March 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "March 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(tm.tm_mon+1 == 4){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] April 1-15\n [2] April 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "April 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "April 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(tm.tm_mon+1 == 5){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] May 1-15\n [2] May 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "May 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "May 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(tm.tm_mon+1 == 6){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] June 1-15\n [2] June 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "June 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "June 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(tm.tm_mon+1 == 7){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] July 1-15\n [2] July 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "July 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "July 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(tm.tm_mon+1 == 8){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] August 1-15\n [2] August 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "August 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "August 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(tm.tm_mon+1 == 9){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] September 1-15\n [2] September 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "September 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "September 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(tm.tm_mon+1 == 10){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] October 1-15\n [2] October 16-31\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "October 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "October 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(tm.tm_mon+1 == 11){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] November 1-15\n [2] November 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "November 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "November 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(tm.tm_mon+1 == 12){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] December 1-15\n [2] December 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "December 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "December 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
}

void chooseMonth(char *whatMonth)
{
    int condit;
    char choice;

    if (strcmpi(whatMonth, "January") == 0){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] January 1-15\n [2] January 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "January 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "January 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(strcmpi(whatMonth, "February") == 0){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] February 1-15\n [2] February 16-28\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "February 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "February 16-28");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(strcmpi(whatMonth, "March") == 0){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] March 1-15\n [2] March 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "March 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "March 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(strcmpi(whatMonth, "April") == 0){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] April 1-15\n [2] April 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "April 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "April 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(strcmpi(whatMonth, "May") == 0){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] May 1-15\n [2] May 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "May 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "May 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(strcmpi(whatMonth, "June") == 0){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] June 1-15\n [2] June 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "June 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "June 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(strcmpi(whatMonth, "July") == 0){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] July 1-15\n [2] July 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "July 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "July 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(strcmpi(whatMonth, "August") == 0){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] August 1-15\n [2] August 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "August 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "August 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(strcmpi(whatMonth, "September") == 0){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] September 1-15\n [2] September 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "September 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "September 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(strcmpi(whatMonth, "October") == 0){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] October 1-15\n [2] October 16-31\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "October 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "October 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(strcmpi(whatMonth, "November") == 0){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] November 1-15\n [2] November 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "November 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "November 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else if(strcmpi(whatMonth, "December") == 0){
    do{
        printf("\nWhich Period would you like to choose?\n\n");
        printf(" [1] December 1-15\n [2] December 16-30\n\n");
        printf("Your Choice: ");
        choice = getche();

        switch (choice)
        {
            case '1':
                strcpy(whatMonth, "December 1-15");
                condit = 0;
                break;

            case '2':
                strcpy(whatMonth, "December 16-30");
                condit = 0;
                break;

            default:
                errorChoicedisplay();
                condit = 1;
                break;
        }
    }while (condit == 1);
    }
    else
    {
        errorChoicedisplay();
        strcpy(whatMonth, "Error");
    }
}
