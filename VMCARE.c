#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<TIME.h>
int userType=0;
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

void mainMenu(int usertype){
	int ch;
	if(usertype==1){
		do{
		printf("************WELCOME TO VM CARE************");
		printf("\n1.Add Doctor\n2.Add Employees\n3.View Doctors\n4.View Employees\n5.Add Department\n6.Logout\nEnter your Choice: ");
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
			break;
			case 6:
				system("cls");
				login();
			break;	
				
		}
		}while(ch!=7);
	}
	
}

void login(){
	
	char username[35],password[35];
	printf("************WELCOME TO VM CARE************");
	printf("\nEnter the Username: ");
	gets(username);
	printf("\nEnter the Password: ");
	gets(password);
	
	if(strcmp(username,"ADMIN45")==0 && strcmp(password,"PASS123")==0){
		system("cls");
		printf("************WELCOME TO VM CARE************");
		printf("\nWelcome Admin");
		userType=1;
		mainMenu(userType);
	}
	else if(strcmp(username,"emp454")==0 && strcmp(password,"emp454")==0){
		printf("Welcome Employee454");
	}
	else{
		printf("Invalid Username or Password");
	}
	
}


void main(){
	
	login();
	
}
