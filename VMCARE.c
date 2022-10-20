#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<TIME.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

int userType=0;
char pwd[35];
int *p;
void login();
void mainMenu(int usertype);

struct employee{
	int empId;
	char empName[35];
	int phno[12];
	char address[55];
	int empType;
	char specialization[45];
	double salary;
	int deptNo;
};

struct department{
	int deptNo;
	char deptName[35];
};

struct patient{
	int patientId;
	char patientName[35];
	char address[55];
	char bloodGroup[3];
	int mobileNo[10];
	int emergencyContactNo[10];
	int doctorId;
	int precriptionId;
};
//void empIdGeneration(){
//	
//	FILE *fp;
//	int empId;
//	fp=fopen("employeeList.txt","r");
//	if(fp=='null'){
//		printf("\nError File Missing!");
//	}
//	else{
//		while(!feof(fp)){
//			
//			fscanf(fp,"%d",empId);
//			if()
//			
//		}
//	}
//	
//	
//}
void addDepartment(){
	
	struct department dept;
	
	printf("\nEnter the department Id:");
	scanf("%d",&dept.deptNo);
	printf("\nEnter the Department Name:");
	getchar();
	gets(dept.deptName);
	
	FILE *fp;
	fp=fopen("departmentList.txt","a+");
	fprintf(fp,"%d",dept.deptNo);
	fprintf(fp,"\n");
  	fprintf(fp,"Department Id : ");
  	fprintf(fp,"%d",dept.deptNo);
  	fprintf(fp,"\n");
  	fprintf(fp,"Department Name : ");
  	fprintf(fp,"%s",dept.deptName);
  	fprintf(fp,"\n");
  	fprintf(fp,"************************************");
  	
  	fclose(fp);
  	
  	printf("\nDepartment Added Successfully!");
  	sleep(5);
  	system("cls");
	
}


void addDoctor(){
	
	struct employee emp;
	printf("\nEnter the Doctor Id: #");
	scanf("%d",&emp.empId);
	printf("\nEnter the Doctor Name: ");
	getchar();
	gets(emp.empName);
	printf("\nEnter the Specialization: ");
	gets(emp.specialization);
	printf("\nEnter the Doctor Salary: ");
	scanf("%lf",&emp.salary);
	printf("\nEnter the Mobile Number: ");
	scanf("%d",&emp.phno);
	printf("\nEnter the Address: ");
	getchar();
	gets(emp.address);
	printf("\nEnter the Department Id: ");
	scanf("%d",&emp.deptNo);
	emp.empType=1;

		
	//to insert into the employee list File
	FILE *fp;
  	fp= fopen("employeeList.txt","a+");
  	
  	fprintf(fp,"\n");
  	fprintf(fp,"Employee Id : #");
  	fprintf(fp,"%d",emp.empId);
  	fprintf(fp,"\n");
  	fprintf(fp,"Employee Name : ");
  	fprintf(fp,"%s",emp.empName);
  	fprintf(fp,"\n");
  	fprintf(fp,"Employee Specialization : ");
  	fprintf(fp,"%s",emp.specialization);
  	fprintf(fp,"\n");
  	fprintf(fp,"Employee Salary : ");
  	fprintf(fp,"%lf",emp.salary);
  	fprintf(fp,"\n");
  	fprintf(fp,"Employee Mobile No : ");
  	fprintf(fp,"%d",emp.phno);
  	fprintf(fp,"\n");
  	fprintf(fp,"Employee Address : ");
  	fprintf(fp,"%s",emp.address);
  	fprintf(fp,"\n");
	fprintf(fp,"Employee type : ");
  	fprintf(fp,"%d",emp.empType);
	fprintf(fp,"\n");
  	fprintf(fp,"Department Id : ");
  	fprintf(fp,"%d",emp.deptNo);
  	fprintf(fp,"\n");
  	fprintf(fp,"************************************");
  	
  	fclose(fp);
	
	//to write into the doctorsList File
	
  	fp= fopen("doctorsList.txt","a+");
  	
  	fprintf(fp,"\n");
  	fprintf(fp,"Doctor Id : #");
  	fprintf(fp,"%d",emp.empId);
  	fprintf(fp,"\n");
  	fprintf(fp,"Doctor Name : ");
  	fprintf(fp,"%s",emp.empName);
  	fprintf(fp,"\n");
  	fprintf(fp,"Doctor Specialization : ");
  	fprintf(fp,"%s",emp.specialization);
  	fprintf(fp,"\n");
  	fprintf(fp,"Doctor Salary : ");
  	fprintf(fp,"%lf",emp.salary);
  	fprintf(fp,"\n");
  	fprintf(fp,"Doctor Mobile No : ");
  	fprintf(fp,"%d",emp.phno);
  	fprintf(fp,"\n");
  	fprintf(fp,"Doctor Address : ");
  	fprintf(fp,"%s",emp.address);
  	fprintf(fp,"\n");
  	fprintf(fp,"Department Id : ");
  	fprintf(fp,"%d",emp.deptNo);
	fprintf(fp,"Doctor type : ");
  	fprintf(fp,"%d",emp.empType);
  	fprintf(fp,"\n");
  	fprintf(fp,"************************************");
  	
  	fclose(fp);
  	
  	printf("\nDoctor Added Successfully!");
  	sleep(5000);
  	system("cls");
}

void addEmployee(){
	struct employee emp;
	
	printf("\nEnter the Employee Id: #");
	scanf("%d",&emp.empId);
	printf("\nEnter the Employee Name: ");
	getchar();
	gets(emp.empName);
	printf("\nEnter the Employee Specialization: ");
	gets(emp.specialization);
	printf("\nEnter the Salary: ");
	scanf("%lf",&emp.salary);
	printf("\nEnter the Mobile Number: ");
	scanf("%d",&emp.phno);
	printf("\nEnter the Address: ");
	getchar();
	gets(emp.address);
	emp.empType=3;
	printf("\nEnter the Employee Department No: ");
	scanf("%d",&emp.deptNo);
	
	//to insert into the employee list File
	FILE *fp;
  	fp= fopen("employeeList.txt","a+");
  	
  	fprintf(fp,"\n");
  	fprintf(fp,"Employee Id : #");
  	fprintf(fp,"%d",emp.empId);
  	fprintf(fp,"\n");
  	fprintf(fp,"Employee Name : ");
  	fprintf(fp,"%s",emp.empName);
  	fprintf(fp,"\n");
  	fprintf(fp,"Employee Specialization : ");
  	fprintf(fp,"%s",emp.specialization);
  	fprintf(fp,"\n");
  	fprintf(fp,"Employee Salary : ");
  	fprintf(fp,"%lf",emp.salary);
  	fprintf(fp,"\n");
  	fprintf(fp,"Employee Mobile No : ");
  	fprintf(fp,"%d",emp.phno);
  	fprintf(fp,"\n");
  	fprintf(fp,"Employee Address : ");
  	fprintf(fp,"%s",emp.address);
  	fprintf(fp,"\n");
	fprintf(fp,"Employee type : ");
  	fprintf(fp,"%d",emp.empType);
  	fprintf(fp,"\n");
	fprintf(fp,"Employee dept No : ");
  	fprintf(fp,"%d",emp.deptNo);
  	fprintf(fp,"\n");
  	fprintf(fp,"************************************");
  	
  	fclose(fp);
  	
  	printf("\nEmployee Added Successfully!");
  	sleep(5000);
  	system("cls");
  	
	
}

void dispDoc(){
	
	char ch;
	FILE *fp;
	fp= fopen("doctorsList.txt","r");
	int c = getc(fp);
	while(c!=EOF){
		putchar(c);
		c=getc(fp);
	}
	fclose(fp);
	printf("\nDo you want to Clear Screen:Y/N");
	getchar();
	scanf("%c",&ch);
	if(ch=='Y' || ch=='y'){
		system("cls");
	}
}

void dispEmp(){
	
	char ch;
	FILE *fp;
	fp= fopen("employeeList.txt","r");
	int c = getc(fp);
	while(c!=EOF){
		putchar(c);
		c=getc(fp);
	}
	fclose(fp);
	printf("\nDo you want to Clear Screen:Y/N");
	getchar();
	scanf("%c",&ch);
	if(ch=='Y' || ch=='y'){
		system("cls");
	}
}
void dispDepartment(){
	char ch;
	FILE *fp;
	fp= fopen("departmentList.txt","r");
	int c = getc(fp);
	while(c!=EOF){
		putchar(c);
		c=getc(fp);
	}
	fclose(fp);
	printf("\nDo you want to Clear Screen:Y/N");
	getchar();
	scanf("%c",&ch);
	if(ch=='Y' || ch=='y'){
		system("cls");
	}
}

void mainMenu(int usertype){
	int ch=0;
	if(usertype==1){
		system("cls");
		do{
		printf("************WELCOME TO VM CARE************");
		printf("\n1.Add Doctor\n2.Add Employees\n3.View Doctors\n4.View Employees\n5.Add Department\n6.View Departments\n7.Logout\n8.Exit\nEnter your Choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				system("cls");
				printf("**************ADD DOCTOR******************\n");
				addDoctor();
			break;
			case 2:
				system("cls");
				printf("**************ADD EMPLOYEE****************\n");
				addEmployee();
			break;
			case 3:
				system("cls");
				printf("**************VIEW DOCTORS*****************\n");
				dispDoc();
			break;
			case 4:
				system("cls");
				printf("**************VIEW EMPLOYEES****************\n");
				dispEmp();
			break;
			case 5:
				system("cls");
				printf("**************ADD DEPARTMENT****************\n");
				addDepartment();
			break;
			case 6:
				system("cls");
				printf("**************VIEW DEPARTMENT****************\n");
				dispDepartment();
			break;
			case 7:
				system("cls");
				login();
			break;	
				
		}
		}while(ch!=8);
	}
	if(userType==2){
		system("cls");
		do{
			printf("************WELCOME TO VM CARE************");
			printf("\n1.Add Patient\n2.Update Patient\n3.Delete Patient\n4.Logout\nEnter your Choice: ");
			scanf("%d",&ch);
			switch(ch){
				case 1:
					system("cls");
					printf("**************ADD PATIENT****************\n");
				break;
				case 2:
					system("cls");
					printf("**************UPDATE PATIENT****************\n");
				break;
				case 3:
					system("cls");
					printf("**************DELETE PATIENT****************\n");
				break;	
				case 4:
					system("cls");
					login();
				break;							
			}
		}while(ch!=5);
	}
	
}


void login(){
		
	int i;
    char ch;
    fflush(stdin);
	char username[35],password[35];
	printf("************WELCOME TO VM CARE************");
	printf("\nEnter the Username: ");
	gets(username);
	printf("\nEnter the Password: ");
	//TO CAPTURE THE PASSWORD AS *
    while(1){
        ch = getch();
        if(ch == ENTER || ch == TAB){
            pwd[i] = '\0';
            break;
        }
		else if(ch == BCKSPC){
            if(i>0){
                i--;
                printf("\b \b");
            }
        }
		else
		{
            pwd[i++] = ch;
            printf("* \b");
        }
    }
	
	if(strcmp(username,"ADMIN45")==0 && strcmp(pwd,"PASS123")==0){
		system("cls");
		printf("************WELCOME TO VM CARE************");
		printf("\nWelcome Admin");
		userType=1;
		mainMenu(userType);
	}
	else if(strcmp(username,"emp454")==0 && strcmp(pwd,"emp454")==0){
		printf("Welcome Employee454");
		userType=2;
		mainMenu(userType);
	}
	else{
		printf("Invalid Username or Password");
	}
}


void main(){
	
	login();
	
}
