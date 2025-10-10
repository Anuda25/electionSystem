#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
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
        if(list1==1){ //voter part
            voter();
			
        }
        else if(list1==2){//candidate part
			candidate();
			break;
        }
        else if(list1==3){//admin part
			admin();
			break;
        }
        else if(list1==4){// see winner part
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
                fprintf(file1, "%lli,%s,%s,%s\n", V_nic, V_name, V_district, V_pwd);
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
    
	
}
void candidate(){
	
	printf("welcome");
}
void admin(){
int ladmin;
    printf("1 : Party Registration\n2 : candidate approval\n3 : start or end vote\n");
    printf("Enter your choice : ");
    scanf("%d",&ladmin);
    switch(ladmin){
        case 1:
            printf("\nParty Registration\n");
            break;
        case 2:
            printf("\ncandidate approval\n");
            break;
        case 3:
            printf("\nstart or end vote\n");
            printf("1 = start vote\n2 = end vote \nEnter your choice : ");
            scanf("%d",&checkSTAT);            // variable to check voting status 1=start 0=end 3=not started
            if(checkSTAT==1){
                printf("\nVoting started\n");
                checkSTAT=1;
            }else if(checkSTAT==2){
                printf("\nVoting ended\n");
                checkSTAT=0;
            }else if(checkSTAT==3){
                printf("\nVoting not started\n");
                checkSTAT=3;
            }else{
                printf("\nInvalid Input!!\n");}
            break;

        default:
            printf("\nInvalid Input!!\n");
    }



	
	
}
void seewinner(){
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
	
}
