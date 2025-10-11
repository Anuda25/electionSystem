#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <string.h>
void voter();
void candidate();
void admin();
void seewinner();
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
			break;
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

}
void seewinner(){
	
	
}