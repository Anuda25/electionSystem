#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <string.h>

int checkSTAT=3;                                    // variable to check voting status 1=start 0=end 3=not started
char line[256];                                     //variable to candidate number
int fpassword(char filename[]);                     //function for compare username password
void readprint(char file[],char display[]);         //function to move file line for other file
void title(char name[]);                            //function for title print
void voter();            
void candidate();
void admin();
void seewinner();
void display();

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
    
    title("ADMIN SECTION");
    do{
        unlock=fpassword("admin.txt"); 
        if (unlock!=1){
        printf("..........username or password is incorrect...........\n");}
    }while(unlock!=1); 
    
    
    do{
        printf("\n\n\n1 : Party Registration\n2 : candidate approval\n3 : start or end vote\n4 : Exit\n");
        printf("Enter your choice :");
        scanf("%d",&list);
        
        switch(list){
            case 1:
                title("PARTY REGISTRATION");
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

                printf("\n........party registration successful..........");

                break;
            case 2:
                list1=0;
                title("CANDIDATE APPROVAL");
                FILE *ctemp;
                char cnic[20],cname[20],cdistrict[20],cparty[20];
                ctemp=fopen("candidatedetails.txt","r");
                
                while(fgets(line, sizeof(line), ctemp)){
                    
                    sscanf(line,"%[^,],%[^,],%[^,],%[^,]",cnic,cname,cdistrict,cparty);
                    printf("Candidate NIC \t\t: %s\nCandidate name \t\t: %s\nCandidate district \t: %s\nCandidate party \t: %s\n",cnic,cname,cdistrict,cparty);
                    printf("---------------------------------------------------------------\n");
                    printf("1 = approve\n2 = reject\n3 = pass\nEnter your choice : ");
                    scanf("%d",&list1);
                    
                    while(list1<1 || list1>3){
                        title("INVALID INPUT");
                        printf("1 = approve\n2 = reject\n3 = pass\nEnter your choice : ");
                        scanf("%d",&list1);
                    }

                    switch(list1){
                        case 1:
                            readprint("candidate.txt","APPROVED SUCCESSFULL");
                            break;
                        case 2:
                            readprint("rejectedcandidates.txt","REJECTED");
                            break;       
                        case 3:
                            readprint("temp1.txt","PASS");
                            break;
                    }
                }fclose(ctemp);             
                remove("candidatedetails.txt");
                rename("temp1.txt","candidatedetails.txt");
                break;
            case 3:
                list1=0;
                title("START OR END VOTE");
                printf("1 = start vote\n2 = end vote\n3=registration open \nEnter your choice : ");          
                scanf("%d",&list1);            // variable to check voting status 1=start 0=end 3=registration open
                if(list1==1){
                    title("VOTING STARTED");
                    checkSTAT=1;
                }else if(list1==2){
                    title("VOTING ENDED");
                    checkSTAT=0;
                }else if(list1==3){
                    title("REGISTRATION OPENED");
                    checkSTAT=3;
                }else if(list1==4){
                    title("EXIT");
                    break;
                }else{
                    title("INVALID INPUT");
                }
                break;  
            case 4:
                title("EXIT");
                break;


            default:
                title("INVALID INPUT");
                break;
        }
    }while(list!=4);
}
void seewinner(){
	
	
}
int fpassword(char filename[]){  
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
                printf("...................password is correct.................\n");
                return 1;
                break;
            }
        }    
        fclose(admin);
}
void title(char name[]){
    printf("\n\n\n-------------------------------%s--------------------------------\n\n",name);
}
void readprint(char file[],char display[]){
    FILE *rejected;
    rejected=fopen(file,"a");
    fprintf(rejected,"%s",line);
    printf("\n\n\n-------------------------------%s--------------------------------\n\n",display);
    fclose(rejected);
}
//main display part
void display(){
    printf("------------------\n");
    printf("Parliment Election");
    printf("\n\t2030");
    printf("\n  Matara District\n");
    printf("------------------\n\n");

}