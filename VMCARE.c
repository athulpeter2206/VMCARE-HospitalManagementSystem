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
	char bloodGroup[5];
	char mobileNo[10];
	int doctorId;
	int precriptionId;
	char emergencyContactNo[10];
};

struct docQueue{
	int patientId;
	int doctorId;
	time_t t;
	struct docQueue *next;
};
struct docQueue *temp1;
struct docQueue *front1=NULL,*rear1=NULL,*front2=NULL,*rear2=NULL;

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
  	fprintf(fp,"|");
  	fprintf(fp,"%s",dept.deptName);
  	fprintf(fp,"\n");
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
	printf("\nEnter the Employee Type: ");
	scanf("%d",&emp.empType);
	emp.empType=1;

	FILE *fp;						//to insert into the employee list File
  	fp= fopen("employeeList.txt","a+");
  	
  	fprintf(fp,"\n");
  	fprintf(fp,"%d",emp.empId);
  	fprintf(fp,"|");
  	fprintf(fp,"%s",emp.empName);
  	fprintf(fp,"|");
  	fprintf(fp,"%s",emp.specialization);
  	fprintf(fp,"|");
  	fprintf(fp,"%lf",emp.salary);
  	fprintf(fp,"|");
  	fprintf(fp,"%d",emp.phno);
  	fprintf(fp,"|");
  	fprintf(fp,"%s",emp.address);
  	fprintf(fp,"|");
  	fprintf(fp,"%d",emp.empType);
	fprintf(fp,"|");
  	fprintf(fp,"%d",emp.deptNo);
  	
  	fclose(fp);
	
  	fp= fopen("doctorsList.txt","a+");		//to write into the doctorsList File
  	
  	fprintf(fp,"\n");
  	fprintf(fp,"%d",emp.empId);
  	fprintf(fp,"|");
  	fprintf(fp,"%s",emp.empName);
  	fprintf(fp,"|");
  	fprintf(fp,"%s",emp.specialization);
  	fprintf(fp,"|");
  	fprintf(fp,"%lf",emp.salary);
  	fprintf(fp,"|");
  	fprintf(fp,"%d",emp.phno);
  	fprintf(fp,"|");
  	fprintf(fp,"%s",emp.address);
  	fprintf(fp,"|");
  	fprintf(fp,"%d",emp.empType);
  	fprintf(fp,"|");
  	fprintf(fp,"%d",emp.deptNo);  	
  	fclose(fp);
  	
  	printf("\nDoctor Added Successfully!");
  	sleep(5);
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
  	fprintf(fp,"%d",emp.empId);
  	fprintf(fp,"|");
  	fprintf(fp,"%s",emp.empName);
  	fprintf(fp,"|");
  	fprintf(fp,"%s",emp.specialization);
  	fprintf(fp,"|");
  	fprintf(fp,"%lf",emp.salary);
  	fprintf(fp,"|");
  	fprintf(fp,"%d",emp.phno);
  	fprintf(fp,"|");
  	fprintf(fp,"%s",emp.address);
  	fprintf(fp,"|");
  	fprintf(fp,"%d",emp.empType);
  	fprintf(fp,"|");
  	fprintf(fp,"%d",emp.deptNo);
  	fprintf(fp,"|");
  	
  	fclose(fp);
  	
  	printf("\nEmployee Added Successfully!");
  	sleep(5);
  	system("cls");
  	
	
}

void addPatient(){
	
	struct patient pti;
	printf("\nEnter the Patient Id: ");
	scanf("%d",&pti.patientId);
	printf("\nEnter the Patient Name: ");
	getchar();
	gets(pti.patientName);
	printf("\nEnter the Address: ");
	gets(pti.address);
	printf("\nEnter the Blood Group: ");
	gets(pti.bloodGroup);
	printf("\nEnter the Mobile Number: ");
	gets(pti.mobileNo);
	printf("\nEnter the Doctor Id: ");
	scanf("%d",&pti.doctorId);
	pti.precriptionId=-1;
	getchar();
	printf("\nEnter the Emergency Contact Number: ");
	gets(pti.emergencyContactNo);
	
	FILE *fp;
  	fp= fopen("patientList.txt","a+");
  	
  	fprintf(fp,"\n");
  	fprintf(fp,"%d",pti.patientId);
  	fprintf(fp,"|");
  	fprintf(fp,"%s",pti.patientName);
  	fprintf(fp,"|");
  	fprintf(fp,"%s",pti.address);
  	fprintf(fp,"|");
  	fprintf(fp,"%d",pti.bloodGroup);
  	fprintf(fp,"|");
  	fprintf(fp,"%s",pti.mobileNo);
  	fprintf(fp,"|");
  	fprintf(fp,"%d",pti.doctorId);
	fprintf(fp,"|");
  	fprintf(fp,"%d",pti.precriptionId);
  	fprintf(fp,"|");
  	fprintf(fp,"%s",pti.emergencyContactNo);

  	fclose(fp);
  	
	printf("\nPatient Added Successfully Currently in Doctor's Queue'!");
  	sleep(5);
  	system("cls");

	
	if(pti.doctorId==1000){			//ASSIGNING TO EACH DOCTOR'S QUEUE
		temp1=(struct docQueue *)malloc(sizeof(struct docQueue));
		temp1->patientId=pti.patientId;
		temp1->doctorId=pti.doctorId;
		temp1->next=NULL;
		if(front1==NULL){
			front1=temp1;	
			rear1=temp1;
			
		}
		else{
			rear1->next=temp1;
			rear1=rear1->next;
		}	
	}
	else{
		temp1=(struct docQueue *)malloc(sizeof(struct docQueue));
		temp1->patientId=pti.patientId;
		temp1->doctorId=pti.doctorId;
		temp1->next=NULL;
		if(front2==NULL){
			front2=temp1;
			rear2=temp1;
		}	
		else{
			rear2->next=temp1;
			rear2=rear2->next;
		}	
	} 	
}

void dispDoc(){
	char ch;
	FILE *fp;
	int i=-1;
	fp=fopen("doctorsList.txt","r");
	if(fp==NULL){
		printf("\nCannot Open Doctors File!");	
	}
	else{
		char str[300];
		while(fgets(str,300,fp)){		//this loop for reading each line
			char *token = strtok(str, "|");
			i++;	
			while( token != NULL ) {		//this loop is to split line to different variables using '|'
				printf("\nEmployeeId: %s",token);
				token = strtok(NULL, "|");
				printf("\nEmployeeName: %s",token);
				token = strtok(NULL, "|");
				printf("\nEmployeeSpecialization: %s",token);
				token = strtok(NULL, "|");
				printf("\nEmployeeSalary: %s",token);
				token = strtok(NULL, "|");
				printf("\nMobileNumber: %s",token);
				token = strtok(NULL, "|");
				printf("\nEmployeeAddress: %s",token);
				token = strtok(NULL, "|");
				printf("\nEmployeeType: %s",token);
				token = strtok(NULL, "|");
				printf("\nEmployeeDeptNo: %s",token);
				token = strtok(NULL, "|");
 			}
		}
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
	int i=-1;
	fp=fopen("employeeList.txt","r");
	if(fp==NULL){
		printf("\nCannot Open Doctors File!");	
	}
	else{
		char str[300];
		while(fgets(str,300,fp)){		//this loop for reading each line
			char *token = strtok(str, "|");
			i++;	
			while( token != NULL ) {		//this loop is to split line to different variables using '|'
				printf("\nEmployeeId: %s",token);
				token = strtok(NULL, "|");
				printf("\nEmployeeName: %s",token);
				token = strtok(NULL, "|");
				printf("\nEmployeeSpecialization: %s",token);
				token = strtok(NULL, "|");
				printf("\nEmployeeSalary: %s",token);
				token = strtok(NULL, "|");
				printf("\nMobileNumber: %s",token);
				token = strtok(NULL, "|");
				printf("\nEmployeeAddress: %s",token);
				token = strtok(NULL, "|");
				printf("\nEmployeeType: %s",token);
				token = strtok(NULL, "|");
				printf("\nEmployeeDeptNo: %s",token);
				token = strtok(NULL, "|");
 			}
		}
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
	int i=-1,count=0,j;
	struct department dept[15];
	fp=fopen("departmentList.txt","r");
	if(fp==NULL){
		printf("\nCannot Open Department File!");	
	}
	else{
		char str[200];
		while(fgets(str,200,fp)){		//this loop for reading each line
			char *token = strtok(str, "|");
			count=0;
			i++;	
			while( token != NULL ) {		//this loop is to split line to different variables using '|'
				if(count==0){
					dept[i].deptNo=atoi(token);
				}
				else{	
					strcpy(dept[i].deptName,token);
				}
				token = strtok(NULL, "|");
				count++;
 			}
		}
	}
	for(j=0;j<=i;j++){
			printf("\nDeptId: %d",dept[j].deptNo);
			printf("\nDeptName: %s\n",dept[j].deptName);
			count++;
	}
	printf("\nDo you want to Clear Screen:Y/N");
	getchar();
	scanf("%c",&ch);
	if(ch=='Y' || ch=='y'){
		system("cls");
	}
}
void searchDepartment(){
	FILE *fp;
	int deptId,count=0,i=-1,j;
	struct department dept[15];
	printf("\nEnter the Department Id to search:");
	scanf("%d",&deptId);
	fp=fopen("departmentList.txt","r");
	if(fp==NULL){
		printf("\nCannot Open File!");	
	}
	else{
		char str[200];
		while(fgets(str,200,fp)){		//this loop for reading each line
			char *token = strtok(str, "|");
			count=0;
			i++;	
			while( token != NULL ) {		//this loop is to split line to different variables using '|'
				if(count==0){
					dept[i].deptNo=atoi(token);
				}
				else{	
					strcpy(dept[i].deptName,token);
				}
				token = strtok(NULL, "|");
				count++;
 			}
		}
	count=0;			//for searching the element in structure
	for(j=0;j<=i;j++){
			
		if(dept[j].deptNo==deptId){
			printf("\nDepartment Found!");
			printf("\nDeptId: %d",dept[j].deptNo);
			printf("\nDeptName: %s\n",dept[j].deptName);
			count++;
		}
	}
	if(count==0){
		printf("\nDepartment Not Found!\n");
	}
		
	}
	fclose(fp);
}

void updatePatient(){
	char choice;
	int ch;
	FILE *fp;
	int i=-1,count=0,j,patId;
	struct patient pti[15];

	fp=fopen("patientList.txt","r");
	if(fp==NULL){
		printf("\nCannot Open Patient File!");	
	}
	else{
	char str[200];
		while(fgets(str,200,fp)){		//this loop for reading each line
			char *token = strtok(str, "|");
			count=0;
			i++;		//this loop is to split line to different variables using '|'
			printf("\nPatientId: %s",token);
			pti[i].patientId=atoi(token);
			token = strtok(NULL, "|");
			printf("\nPatientName: %s",token);
			strcpy(pti[i].patientName,token);
			token = strtok(NULL, "|");
			strcpy(pti[i].address,token);
			token = strtok(NULL, "|");
			strcpy(pti[i].bloodGroup,token);
			token = strtok(NULL, "|");
			strcpy(pti[i].mobileNo,token);
			token = strtok(NULL, "|");
			pti[i].doctorId=atoi(token);
			token = strtok(NULL, "|");
			pti[i].precriptionId=atoi(token);
			token = strtok(NULL, "|");
			strcpy(pti[i].emergencyContactNo,token);
			token = strtok(NULL, "|");
		}
	update:
	printf("\nEnter the Patient Id to Update Details:");
	scanf("%d",&patId);
	for(j=0;j<=i;j++){
		if(patId==pti[j].patientId){
			printf("\n1.UpdateName\n2.UpdateAddress\n3.BloodGroup\n4.MobileNumber\n5.EmergencyContactNumber\nEnter your choice:");
			scanf("%d",&ch);
			getchar();
			switch(ch){
				case 1: 
					printf("\nEnter the Name to be Updated!");
					gets(pti[j].patientName);
				break;
				case 2:
					printf("\nEnter the Updated Address:");
					gets(pti[j].address);
				break;
				case 3:
					printf("\nEnter the Blood Group to be updated:");
					gets(pti[j].bloodGroup);
				break;
				case 4:
					printf("\nEnter the Mobile Number to be updated:");
					gets(pti[j].mobileNo);
				break;
				case 5:
					printf("\nEnter the Emergency Contact Number to be Updated:");
					gets(pti[j].emergencyContactNo);
				break;
				default:
					printf("\nInvalid Choice!");
				break;							
			}
			count++;	
		}		
	}
	if(count==0){
		printf("\nPatient Not Found!");
	}
	printf("\nDo you want to continue Updating?Y/N");
	scanf("%c",&choice);
	if(choice=='Y' || choice=='y'){
		goto update;
	}
	fp=fopen("patientList.txt","w");   		//to write back the changes to the file.
	for(j=0;j<=i;j++){
	  	fprintf(fp,"%d",pti[j].patientId);
	  	fprintf(fp,"|");
	  	fprintf(fp,"%s",pti[j].patientName);
	  	fprintf(fp,"|");
	  	fprintf(fp,"%s",pti[j].address);
	  	fprintf(fp,"|");
	  	fprintf(fp,"%d",pti[j].bloodGroup);
	  	fprintf(fp,"|");
	  	fprintf(fp,"%s",pti[j].mobileNo);
	  	fprintf(fp,"|");
	  	fprintf(fp,"%d",pti[j].doctorId);
		fprintf(fp,"|");
	  	fprintf(fp,"%d",pti[j].precriptionId);
	  	fprintf(fp,"|");
	  	fprintf(fp,"%s",pti[j].emergencyContactNo);
	}
	printf("\nUpdate Successfull!");
  	sleep(5);
  	system("cls");
	fclose(fp);	
	}
}
void dispPatient(){
	char ch;
	FILE *fp;
	int i=-1;
	fp=fopen("patientList.txt","r");
	if(fp==NULL){
		printf("\nCannot Open Patient File!");	
	}
	else{
		char str[300];
		while(fgets(str,300,fp)){		//this loop for reading each line
			char *token = strtok(str, "|");
			i++;
			printf("\nPatientId: %s",token);
			token = strtok(NULL, "|");
			printf("\nPatientName: %s",token);
			token = strtok(NULL, "|");
			printf("\nPatient Address: %s",token);
			token = strtok(NULL, "|");
			printf("\nPatient Blood Group: %s",token);
			token = strtok(NULL, "|");
			printf("\nPatient MobileNumber: %s",token);
			token = strtok(NULL, "|");
			printf("\nDoctor Id: %s",token);
			token = strtok(NULL, "|");
			printf("\nPrescription Id: %s",token);
			token = strtok(NULL, "|");
			printf("\nEmergency Contact Number: %s",token);
			token = strtok(NULL, "|");
		}
	}
	fclose(fp);	
	printf("\nDo you want to Clear Screen:Y/N");
	getchar();
	scanf("%c",&ch);
	if(ch=='Y' || ch=='y'){
		system("cls");
	}
}

void dispPatientWithID(){
	
	FILE *fp;
	int patid,count=0,i=-1,j;
	struct patient pat[15];
	printf("\nEnter the Patient Id to search:");
	scanf("%d",&patid);
	getchar();

	fp=fopen("patientList.txt","r");
	if(fp==NULL){
		printf("\nCannot Open File!");	
	}
	else{

		char str[300];
		while(fgets(str,300,fp)){
				//this loop for reading each line
			char *token = strtok(str, "|");
			i++;		
			pat[i].patientId=atoi(token);
			token = strtok(NULL, "|");	
			strcpy(pat[i].patientName,token);
			token = strtok(NULL, "|");	
			strcpy(pat[i].address,token);
			token = strtok(NULL, "|");
			strcpy(pat[i].bloodGroup,token);	
			token = strtok(NULL, "|");	
			strcpy(pat[i].mobileNo,token);
			token = strtok(NULL, "|");
			pat[i].doctorId=atoi(token);
			token = strtok(NULL, "|");
			pat[i].precriptionId=atoi(token);
			token = strtok(NULL, "|");
			strcpy(pat[i].emergencyContactNo,token);
			token = strtok(NULL, "|");											
	}
	fclose(fp);	
	count=0;			//for searching the element in structure
	for(j=0;j<=i;j++){
			
		if(pat[j].patientId==patid){
			printf("\nPatient Found!");
			printf("\nPatientId: %d",pat[j].patientId);
			printf("\nPatientName: %s\n",pat[j].patientName);
			printf("\nPatientAddress: %s\n",pat[j].address);
			count++;
		}
	}
	if(count==0){
		printf("\nPatient ID %d Not Found!",patid);
	}
	
	
	}
}

void viewPatientsAllotted(){
	if(userType==3){
		if(front1==NULL){
			printf("\nEmpty Queue\n");
		}	
		else{
			temp1=front1;
			while(temp1!=NULL){
				printf("\nPatient Id: %d",temp1->patientId);
				printf("\nDoctor Id: %d",temp1->doctorId);
				printf("\n**********************************");
				temp1=temp1->next;
			}
			char c;
			printf("\nDo you want to Clear Screen:Y/N");
			getchar();
			scanf("%c",&c);
			if(c=='Y' || c=='y'){
				system("cls");
			}
		}
	}
	if(userType==4){
		if(front2==NULL){
			printf("\nEmpty Queue\n");
		}	
		else{
			temp1=front2;
			while(temp1!=NULL){
				printf("\nPatient Id: %d",temp1->patientId);
				printf("\nDoctor Id: %d",temp1->doctorId);
				printf("\n**********************************");
				temp1=temp1->next;
			}
			char c;
			printf("\nDo you want to Clear Screen:Y/N");
			getchar();
			scanf("%c",&c);
			if(c=='Y' || c=='y'){
				system("cls");
			}
		}
	}
}
void addPrescription(int patientId){
	getchar();
	char pris[200];
	FILE *fp;
	char fileName[30];
	sprintf(fileName,"%d.txt",patientId);
	fp=fopen(fileName,"w");
	if(fp==NULL){
		printf("\nCannot Open Doctors File!");	
	}
	else{
		printf("%s",fileName);
		printf("\nEnter the Prescription:");
		gets(pris);
		fprintf(fp,"\n");
		fprintf(fp,"%s",pris);		
	}
	fclose(fp);
	
}
void admitPatient(){
	int patientId;
	struct patient pti[25];
	FILE *fp;
	int i=-1,j;
	if(userType==3){
		if(front1==NULL){
			printf("\nEmpty Queue\n");
		}	
		else{
			patientId=front1->patientId;
			fp=fopen("patientList.txt","r");
			if(fp==NULL){
				printf("\nCannot Open Doctors File!");	
			}
			else{
				char str[300];
				while(fgets(str,300,fp)){
					char *token = strtok(str, "|");
					i++;
					pti[i].patientId=atoi(token);
					token = strtok(NULL, "|");
					strcpy(pti[i].patientName,token);
					token = strtok(NULL, "|");
					strcpy(pti[i].address,token);
					token = strtok(NULL, "|");
					strcpy(pti[i].bloodGroup,token);
					token = strtok(NULL, "|");
					strcpy(pti[i].mobileNo,token);
					token = strtok(NULL, "|");
					pti[i].doctorId=atoi(token);
					token = strtok(NULL, "|");
					pti[i].precriptionId=atoi(token);
					token = strtok(NULL, "|");
					strcpy(pti[i].emergencyContactNo,token);
					token = strtok(NULL, "|");
				}
			}
			printf("\n----------------Patient Details----------------------");
			for(j=0;j<=i;j++){
				if(pti[j].patientId==patientId){
					printf("\nPatientId: %d",pti[j].patientId);
					printf("\nPatientName: %s",pti[j].patientName);
					printf("\nPatientAddress: %s",pti[j].address);
					printf("\nPatientBloodGroup: %s",pti[j].bloodGroup);
					printf("\nPatient Mobile Number: %s",pti[j].mobileNo);
					printf("\nDoctorId: %d",pti[j].doctorId);
					printf("\nEmergency Contact No: %s",pti[j].emergencyContactNo);
				}
			}
			int ch;
			printf("\n1.Add Prescription\n2.Remove Patient from Queue\nEnter Your Choice:");
			scanf("%d",&ch);
			switch(ch){
				case 1:
					//system("cls");
					printf("**************ADD PRESCRIPTION******************\n");
					addPrescription(patientId);
			
					if(front1==NULL){
						printf("\nEmptyQueue");
					}
					else{
						printf("\nConsultation Completed!");
						front1=front1->next;
						if(front1==NULL){
							rear1==NULL;
						}
					}
				break;
				case 2:
					printf("**************REMOVE PATIENT FROM QUEUE******************\n");
					if(front1==NULL){
						printf("\nEmptyQueue");
					}
					else{
						printf("\nPATIENT NOT AVAILABLE!");
						front1=front1->next;
						if(front1==NULL){
							rear1==NULL;
						}
					}
				break;	
			}
			char c;
			printf("\nDo you want to Clear Screen:Y/N");
			getchar();
			scanf("%c",&c);
			if(c=='Y' || c=='y'){
				system("cls");
			}
		}
	}
	if(userType==4){
		if(front2==NULL){
			printf("\nEmpty Queue");
		}	
		else{
			patientId=front2->patientId;
			fp=fopen("patientList.txt","r");
			if(fp==NULL){
				printf("\nCannot Open Patientslist File!");	
			}
			else{
				char str[300];
				while(fgets(str,300,fp)){
					char *token = strtok(str, "|");
					i++;
					pti[i].patientId=atoi(token);
					token = strtok(NULL, "|");
					strcpy(pti[i].patientName,token);
					token = strtok(NULL, "|");
					strcpy(pti[i].address,token);
					token = strtok(NULL, "|");
					strcpy(pti[i].bloodGroup,token);
					token = strtok(NULL, "|");
					strcpy(pti[i].mobileNo,token);
					token = strtok(NULL, "|");
					pti[i].doctorId=atoi(token);
					token = strtok(NULL, "|");
					pti[i].precriptionId=atoi(token);
					token = strtok(NULL, "|");
					strcpy(pti[i].emergencyContactNo,token);
					token = strtok(NULL, "|");
				}
			}
			printf("\n----------------Patient Details----------------------");
			for(j=0;j<=i;j++){
				if(pti[j].patientId==patientId){
					printf("\nPatientId: %d",pti[j].patientId);
					printf("\nPatientName: %s",pti[j].patientName);
					printf("\nPatientAddress: %s",pti[j].address);
					printf("\nPatientBloodGroup: %s",pti[j].bloodGroup);
					printf("\nPatient Mobile Number: %s",pti[j].mobileNo);
					printf("\nDoctorId: %d",pti[j].doctorId);
					printf("\nEmergency Contact No: %s",pti[j].emergencyContactNo);
				}
			}
			int ch;
			printf("\n1.Add Prescription\n2.Remove Patient from Queue\nEnter Your Choice:");
			scanf("%d",&ch);
			switch(ch){
				case 1:
					//system("cls");
					printf("**************ADD PRESCRIPTION******************\n");
					addPrescription(patientId);
			
					if(front1==NULL){
						printf("\nEmptyQueue");
					}
					else{
						printf("\nConsultation Completed!");
						front2=front2->next;
						if(front2==NULL){
							rear2==NULL;
						}
					}
				break;
				case 2:
					printf("**************REMOVE PATIENT FROM QUEUE******************\n");
					if(front1==NULL){
						printf("\nEmptyQueue");
					}
					else{
						printf("\nPATIENT NOT AVAILABLE!");
						front2=front2->next;
						if(front2==NULL){
							rear2==NULL;
						}
					}
				break;	
			}
			char c;
			printf("\nDo you want to Clear Screen:Y/N");
			getchar();
			scanf("%c",&c);
			if(c=='Y' || c=='y'){
				system("cls");
			}
		}
	}
}

void mainMenu(int usertype){
	int ch=0;
	if(usertype==1){
		system("cls");
		do{
		printf("************WELCOME TO VM CARE************");
		printf("\n1.Add Doctor\n2.Add Employees\n3.Add Department\n4.View Doctors\n5.View Employees\n6.View Departments\n7.Search Department\n8.Logout\n9.Exit\nEnter your Choice: ");
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
			case 4:
				system("cls");
				printf("**************VIEW DOCTORS*****************\n");
				dispDoc();
			break;
			case 5:
				system("cls");
				printf("**************VIEW EMPLOYEES****************\n");
				dispEmp();
			break;
			case 3:
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
				searchDepartment();
			break;
			case 8:
				system("cls");
				login();
			break;	
				
		}
		}while(ch!=9);
	}
	if(userType==2){
		system("cls");
		do{
			printf("************WELCOME TO VM CARE************");
			printf("\n1.Add Patient\n2.Update Patient\n3.Display Patients\n4.Search Patient Details\n5.Logout\nEnter your Choice: ");
			scanf("%d",&ch);
			getchar();
			switch(ch){
				case 1:
					system("cls");
					printf("**************ADD PATIENT****************\n");
					addPatient();
				break;
				case 2:
					system("cls");
					printf("**************UPDATE PATIENT****************\n");
					updatePatient();
				break;
				case 3:
					system("cls");
					printf("**************DISPLAY PATIENT****************\n");
					dispPatient();
				break;
				case 4:
					system("cls");
					printf("**************SEARCH PATIENT****************\n");
					dispPatientWithID();
				break;
				case 5:
					system("cls");
					login();
				break;							
			}
		}while(ch!=5);
	}
	if(usertype==3){
		system("cls");
		do{
			printf("************WELCOME TO VM CARE************");
			printf("\n1.View Patients allotted\n2.Admit Patient for Consultation\n3.Logout\nEnter your Choice: ");
			scanf("%d",&ch);
			switch(ch){
				case 1:
					system("cls");
					printf("**************VIEW PATIENTS ALLOTTED****************\n");
					viewPatientsAllotted();
				break;
				case 2:
					system("cls");
					printf("**************ADMIT PATIENT FOR CONSULTATION****************\n");
					admitPatient();	
				break;
				case 3:
					system("cls");
					login();	
				break;	
			}
			
		}while(ch!=4);
	}
	if(usertype==4){
		system("cls");
		do{
			printf("************WELCOME TO VM CARE************");
			printf("\n1.View Patients allotted\n2.Admit Patient for Consultation\n3.Logout\nEnter your Choice: ");
			scanf("%d",&ch);
			switch(ch){
				case 1:
					system("cls");
					printf("**************VIEW PATIENTS ALLOTTED****************\n");
					viewPatientsAllotted();
				break;
				case 2:
					system("cls");
					printf("**************ADMIT PATIENT FOR CONSULTATION****************\n");
					admitPatient();	
				break;
				case 3:
					system("cls");
					login();	
				break;	
			}
			
		}while(ch!=4);
	}
	
}


void login(){
		
	int i=0;
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
	if(strcmp(username,"admin")==0 && strcmp(pwd,"admin")==0){
		system("cls");
		printf("************WELCOME TO VM CARE************");
		printf("\nWelcome Admin");
		userType=1;
		mainMenu(userType);
	}
	else if(strcmp(username,"emp")==0 && strcmp(pwd,"emp")==0){
		printf("Welcome Employee454");
		userType=2;
		mainMenu(userType);
	}
	else if(strcmp(username,"doc1000")==0 && strcmp(pwd,"doc1000")==0){
		printf("Welcome Dr.Roshan K");
		userType=3;
		mainMenu(userType);
	}
	else if(strcmp(username,"doc1002")==0 && strcmp(pwd,"doc1002")==0){
		printf("Welcome Dr.Reyvanth K");
		userType=4;
		mainMenu(userType);
	}
	else{
		printf("\nInvalid Username or Password!!");
		sleep(3);
		system("cls");
		login();
	}
}


void main(){
	
	login();
	
}
