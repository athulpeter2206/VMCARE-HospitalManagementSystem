#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void login();

struct doctor{
	int doctorId;
	char doctorName[35];
	char specialization[45];
	double salary;
};

void addDoctor(){
	
	struct doctor doc;
	printf("\nEnter the Doctor Id: ");
	scanf("%d",&doc.doctorId);
	printf("\nEnter the Doctor Name: ");
	getchar();
	gets(doc.doctorName);
	printf("\nEnter the Specialization: ");
	gets(doc.specialization);
	printf("\nEnter the Doctor Salary: ");
	scanf("%lf",&doc.salary);
	
	FILE *fp;
  	fp= fopen("doctorsList.txt","a+");
  	
  	fprintf(fp,"************************************");
  	fprintf(fp,"\n");
  	fprintf(fp,"Doctor Id : ");
  	fprintf(fp,"%d",doc.doctorId);
  	fprintf(fp,"\n");
  	fprintf(fp,"Doctor Name : ");
  	fprintf(fp,"%s",doc.doctorName);
  	fprintf(fp,"\n");
  	fprintf(fp,"Doctor Specialization : ");
  	fprintf(fp,"%s",doc.specialization);
  	fprintf(fp,"\n");
  	fprintf(fp,"Doctor Salary : ");
  	fprintf(fp,"%d",doc.salary);
  	fprintf(fp,"\n");
  	fprintf(fp,"************************************");
  	
  	fclose(fp);
}

void mainMenu(int usertype){
	int ch;
	if(usertype==1){
		do{
		printf("\n1.Add Doctor\n2.Add Employees\n3.View Doctors\n4.View Employees\n5.Add Department\n6.Logout\nEnter your Choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				system("cls");
				printf("**************ADD DOCTOR******************");
				addDoctor();
			break;
			case 2:
				system("cls");
				printf("**************ADD EMPLOYEE****************");
			break;
			case 3:
				system("cls");
				printf("**************VIEW DOCTORS*****************");
			break;
			case 4:
				system("cls");
				printf("**************VIEW EMPLOYEES****************");
			break;
			case 5:
				system("cls");
				printf("**************ADD DEPARTMENT****************");
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
		mainMenu(1);
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
