#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
int fpassword(char filename[30]); 
void voter();
void candidate();
void admin();
void seewinner();
int checkSTAT=3;  // variable to check voting status 1=start 0=end 3=not started
int main(){
    int list1;  
    while(true){
    	printf("1=Voter\n2=Candidate\n3=Admin\n4=See Winner\n5=Exit\n");
	    printf("Your Choise: ");
	    scanf("%d",&list1);
        if(list1==1){
			voter();
			break;
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
            exit(0);
        }
        else{
            printf("\nInvalid Input!!\n\n");
            
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
        printf("1 = Registration\n2 = Login\n3 = Exit\n");
        printf("Your Choice: ");
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
<<<<<<< HEAD
            fclose(file1);
        }
        else if(list2==2){
                char temp_V_nic[12];
                char temp_V_password[10];
                printf("Enter the user name :\t");
                scanf("\n%s",temp_V_nic);
                printf("Enter the user password :\t");
                scanf("\n%s",temp_V_password);
                FILE *file1;
                file1=fopen("voterdetails.txt","r");
                if(file1==NULL){
                    printf("!!Error !!");
                }
                 char line[256],fnic[256]; //line=text_file_line,fnic=text_file_nic
                 while(fgets(line,sizeof(line),file1)){
                     sscanf(line, "%[^,]",fnic);
                



=======
>>>>>>> 340672035acfe7eb0199082836bb5330625da7a1

            if (exists) {
                printf("\nAlready Registered!\n\n");
            } 
            else {
                // save NIC
                file2 = fopen("voternic.txt", "a");
                fprintf(file2, "%lli\n", V_nic);
                fclose(file2);

                // get other details
                printf("Enter your Name: ");
                scanf("%s", V_name);
                printf("Enter your District: ");
                scanf("%s", V_district);
                printf("Enter your Password: ");
                scanf("%s", V_pwd);

                // save voter details
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
            printf("Exiting program...\n");
            break;
        } 
        else {
            printf("Invalid choice! Try again.\n\n");
        }
    }
    
	
	printf("Hello");
}
void candidate(){
	
	
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
    printf("\n\n\n\n1 : Party Registration\n2 : candidate approval\n3 : start or end vote\n4 : Exit\n");
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
<<<<<<< HEAD
	if(checkSTAT==2){
        FILE *fvote;  //vote text file
        fvote=fopen("vote.txt","r");
        if(fvote==NULL){
            printf("\n!! ERROR The file is empty!!\n");
            
        }
        int max=0;
        
         




    }else{
        printf("\n !!! votted not ending !!!\n");
    }
=======
	
>>>>>>> 340672035acfe7eb0199082836bb5330625da7a1
	
}
int fpassword(char filename[30]){  
        char username[20],password[20],fusername[256],fpassword[256],line[256];
        printf("\n\n\n\nAdmin Panel\n");
        
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