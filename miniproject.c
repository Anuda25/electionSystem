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
	
	printf("Hello");
}
void candidate(){
	
	
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
	
	
}