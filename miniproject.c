#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
<<<<<<< HEAD
#include<string.h>
int fpassword(char filename[30]); 
=======
#include <string.h>
>>>>>>> TG2107
void voter();
void candidate();
void admin();
void seewinner();
void display();
int checkSTAT=3;  // variable to check voting status 1=start 0=end 3=not started
int main(){
    int list1;  
    display();
    while(true){
    	printf("1=Voter\n2=Candidate\n3=Admin\n4=See Winner\n5=Exit\n");
	    printf("\nYour Choise: ");
	    scanf("%d",&list1);
        if(list1==1){
			voter();
			
        }
        else if(list1==2){
			candidate();
			break;
        }
        else if(list1==3){
			admin();
			continue;
        }
        else if(list1==4){
			seewinner();
			break;
        }
        else if (list1==5){
            printf("\n\nParliament Election Programe End....");
            exit(0);
        }
        else{
            printf("\nInvalid Input!!\nPlease try again....\n\n");
            
        }
    }
    return 0;
}
void voter(){
	int choice;
    long long V_nic, fnic;
    char V_name[50];
    char V_district[50];
    char V_pwd[20];
    bool exists;

    FILE *file1, *file2;
    char line[256];

    while (true) {
        printf("\n---------------\n");
        printf("Voter Section\n");
        printf("---------------\n\n");
        printf("1 = Registration\n2 = Login\n3 = Exit\n");
        printf("\nYour Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter your NIC: ");
            scanf("%lli", &V_nic);

            // check if NIC already exists
            exists = false;
            file2 = fopen("voternic.txt", "r");
            if (file2 != NULL) {
                while (fgets(line, sizeof(line), file2)) {
                    sscanf(line, "%lli", &fnic);
                    if (fnic == V_nic) {
                        exists = true;
                        break;
                    }
                }
                fclose(file2);
            }

            if (exists) {
                printf("\nAlready Registered!\nPlease try again....\n\n");
            } 
            else {
                // save NIC
                file2 = fopen("voternic.txt", "a");
                fprintf(file2, "%lli\n", V_nic);
                fclose(file2);

                // get voter details
                printf("Enter your Name: ");
                scanf("%s", V_name);
                printf("Enter your District: ");
                scanf("%s", V_district);
                printf("Enter your Password: ");
                scanf("%s", V_pwd);

                // save voter details in text file
                file1 = fopen("voterdetails.txt", "a");
                fprintf(file1, "%lli,%s,%s,%s\n", V_nic,V_pwd, V_name, V_district);
                fclose(file1);

                printf("\nRegistered Successfully!\n\n");
            }
        } 
        else if (choice == 2) {
            printf("\nLogin feature coming soon...\n\n");
        } 
        else if (choice == 3) {
            printf("\nExiting voter Section...\n\n");
            display();
            break;
        } 
        else {
            printf("\nInvalid Input!!\nPlease try again....\n\n");
        }
    }	
}
void candidate(){  
    char C_nic[256], F_nic[256]; //Candidate nic , registered txt file nic
    char C_name[256], C_district[256], C_party[256]; //
    bool exists = false;
    FILE *N_C_list, *C_details; //File pointer
    char line[256];

    //Getting ID as a nic
    printf("Enter Your ID Number: ");  
    scanf("%s", C_nic);

    //Check if ID already exists in permanent list
    N_C_list = fopen("Nominated_Candidate_List.txt", "r");
    if (N_C_list != NULL) {
        while (fgets(line, sizeof(line), N_C_list)) {
            sscanf(line, "%s", F_nic);
            if (strcmp(F_nic, C_nic) == 0) {
                exists = true;
                break;
            }
        }
        fclose(N_C_list);
    }

    if (exists) {
        printf("\nAlready Registered!\n\n");
    } else {

        // Save NIC to permanent list
        N_C_list = fopen("Nominated_Candidate_List.txt", "a");
        fprintf(N_C_list, "%s\n", C_nic);
        fclose(N_C_list);

        // Get other details
        printf("Enter your Name: ");
        scanf("%s", C_name);
        printf("Enter Your District: ");
        scanf("%s", C_district);
        printf("Enter Your Party: ");
        scanf("%s", C_party);

        // Save candidate details
        C_details = fopen("Candidatedetails.txt", "a");
        fprintf(C_details, "%s,%s,%s,%s\n", C_nic, C_name, C_district, C_party);
        fclose(C_details);

        printf("\nRegistration Successfully!\n\n");
    }
}
    

void admin(){
int list,list1;
    int unlock;
    do{
        unlock=fpassword("admin.txt"); 
        if (unlock!=1){
        printf("password is incorrect\n");}
    }while(unlock!=1); 
do{
    printf("\n---------------\n");
    printf("Admin Section\n");
    printf("---------------\n\n");
    printf("1 : Party Registration\n2 : candidate approval\n3 : start or end vote\n4 : Exit\n");
    printf("Enter your choice :");
    scanf("%d",&list);
    switch(list){
        case 1:
            printf("\n\n\n\nParty Registration\n");
            printf("---------------------------------------------------------------\n");

            FILE *fparty;
            fparty=fopen("party.txt","a");
            char name[50],mark[20],color[20];
            printf("Enter party name  : ");
            scanf("%s",name);
            printf("Enter party mark  : ");
            scanf("%s",mark);
            printf("Enter party color : ");
            scanf("%s",color);
            fprintf(fparty,"%s,%s,%s\n",name,mark,color);
            fclose(fparty);

            printf("\nparty registration successful..........");

            break;
        case 2:
            printf("\n\n\n\ncandidate approval\n");
            printf("---------------------------------------------------------------\n");

            /*FILE *admin ;
            char line[256];
            admin=fopen("admin.txt","r");
            while(fgets(line, sizeof(line), admin)){
                sscanf(line,"%[^,],%[^,]",fusername,fpassword);}
            fclose();*/
            break;
        case 3:
            printf("\n\n\n\nstart or end vote\n");
            printf("---------------------------------------------------------------\n");
            printf("1 = start vote\n2 = end vote\n3=registration open \nEnter your choice : ");          
            scanf("%d",&list1);            // variable to check voting status 1=start 0=end 3=registration open
            printf("---------------------------------------------------------------\n");
            if(list1==1){
                printf("Voting started\n");
                checkSTAT=1;
            }else if(list1==2){
                printf("Voting ended\n");
                checkSTAT=0;
            }else if(list1==3){
                printf("Registration opened\n");
                checkSTAT=3;
            }else if(list1==4){
                printf("Exit\n");
                break;
            }else{
                printf("Invalid Input!!\n");}
            break;
        case 4:

        default:
            printf("-------------------Invalid Input!!----------------------------\n");
            break;
      } 
}while(list!=4);

}
void seewinner(){
	
	
}
int fpassword(char filename[30]){  
        char username[20],password[20],fusername[256],fpassword[256],line[256];
        
        
        printf("ENTER YOUR USERNAME : ");
        scanf("%s",&username);
        printf("ENTER YOUR PASSWORD : ");
        scanf("%s",&password);

        FILE *admin ;
        admin=fopen(filename,"r");
        while(fgets(line, sizeof(line), admin)){
            sscanf(line,"%[^,],%[^,]",fusername,fpassword);
            if((strcmp(fpassword,password)==0)&&(strcmp(username,fusername)==0)){
                printf("password is correct\n");
                return 1;
                break;
            }
        }    
        fclose(admin);
}
//main display part
void display(){
    printf("------------------\n");
    printf("Parliment Election");
    printf("\n\t2030");
    printf("\n  Matara District\n");
    printf("------------------\n\n");

}