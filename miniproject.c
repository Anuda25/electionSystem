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
			break;
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
	int list2,c=0; //list2=store voter page user input c=count
    FILE *file1;
    file1=fopen("voterdetails.txt","w");
    char V_nic[20] ="200415504199";
    fprintf(file1,"%s",V_nic);
    fclose(file1);
	while(true){
        printf("1=Registration\n2=login\n3=Exit\n");
        printf("Your Choise: ");
        scanf("%d",&list2);
        if(list2==1){
            printf("Enter your NIC: ");
            scanf("%s",&V_nic);

            file1=fopen("voterdetails.txt","r");
            char line[256],fnic[256]; //line=text_file_line,fnic=text_file_nic
            while(fgets(line,sizeof(line),file1)){
                sscanf(line, "%[^,]",fnic);
                    
                    int size=sizeof(V_nic);
                    for(int i=0;i<size;i++){
                        if(fnic[i]==V_nic[i]){
                            c++;
                        }
                        if(c==12){
                            printf("\nAlready Registered!!\n");
                        }
                        else{
                            //Another part!!!!!
                        }
                    }

            }
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
                




        }
        else if(list2==3){

        }
        else{
            printf("\nInvalid Input!!\n\n");
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
