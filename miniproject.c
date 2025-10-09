#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
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
	
	printf("Hello");
}
void candidate(){
	
	
}
void admin(){
	
	
}
void seewinner(){
	
	
}