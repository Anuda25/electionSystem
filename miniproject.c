#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <string.h>
#define MAX 500

int voteno=0;                                   
char line[256];                                     //variable to candidate number
int cno=001;                                       //candidate number
int checkSTAT;
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
            continue;
        }
        else if(list1==3){
			admin();
			continue;
        }
        else if(list1==4){
			seewinner();
			continue;
        }
        else if (list1==5){
            printf("\n\nParliament Election Programe End....");
            exit(0);
        }
        else{
            printf("\nInvalid Input!!Please try again....\n\n");
            
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
        printf("\n=================\n");
        printf("  Voter Section\n");
        printf("=================\n\n");
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
                scanf(" %[^\n]", V_name);
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
            char username[20],password[20],fusername[256],fpassword[256],fname[256],fdistrict[256],line[256];
            int log =0;
            //...VOTER LOGIN...
            printf("\n====================");
            printf("\n    Voter Login");
            printf("\n====================");
            do{

                printf("\nEnter the username:");
                scanf("%s",&username);
                printf("Enter the password: ");
                scanf("%s",&password);
            
                FILE *file1;
                file1=fopen("voterdetails.txt","r");
                    if (file1 == NULL) {
                        printf("\n  Error   cannot open file 'voterdetails.txt'\n");
                    
                }
                
                int x =0;
                while(fgets(line, sizeof(line), file1)){
                    sscanf(line,"%[^,],%[^,],%[^,],%[^,]",fusername,fpassword,fname,fdistrict);
                    if((strcmp(fpassword,password)==0)&&(strcmp(username,fusername)==0)){
                        x =1;
                        break;
                    }
                    }    
                    fclose(file1);
                    if (x==1){
                        printf("\n... your coorrect username and password ...\n");
                        log=1;
                    }else{
                        printf("\n!!! Error incoorrect username and password !!!\n");
                    }
                
            
            }while (log==0);
                    printf("\n=======================\n");
                    printf("     Your Loging\n");  
                    printf("=======================\n");
                    int choice,choice2;
                    char v_pchoice[50];
                    char c_vote[50];
                    printf("1.  Your Profile Details\n2. Cast Your Voting\n3. Exit");
                    printf("\n\nYour Choice\t:");
                    scanf("%d",&choice);
                    switch (choice){
                        //...PROFILE DETAILS...
                        case 1:  
                        printf("\n==========================\n");
                        printf("   Your Profile Details  \n");
                        printf("==========================\n");
                        FILE *temp;
                            long long V_nic;
                            char V_pwd[20];
                            char V_name[50];
                            char V_district[50];
                            
                        temp= fopen("voterdetails.txt","r");
                        
                        while(fgets(line, sizeof(line), temp)){
                        
                            sscanf(line,"%[^,],%[^,],%[^,],%[^,]",fusername,fpassword,fname,fdistrict);
                            if((strcmp(fpassword,password)==0)&&(strcmp(username,fusername)==0)){
                                printf("\nNIC\t\t= %s\nPassword\t= %s\nname\t\t= %s\nDistrict\t= %s\n",fusername,fpassword,fname,fdistrict);
                                break;
                            }
                        }fclose(temp);
                        
                            printf("\n\n1 .Exit\t:"); 
                            scanf("%d",&choice2);
                            printf("\n=======================");
                        break;
                        // ...CAST YOUR VOTE...
                        case 2: {
                            char votedfname[50];
                            int voteno=0;
                            

                            char party[50][50];
                            int partyCount = 0;  //party.txt file enter party  count
                            int uservoted=0;
                            printf("\n=======================");
                            printf("\n  Casting Your Vote    ");
                            printf("\n=======================");
                            FILE *stat;
                            stat=fopen("status.txt","r");
                            fscanf(stat,"%d",&checkSTAT);
                            fclose(stat);
                            if(checkSTAT==1){
                                printf("\n\n.. Voting Time Start ..  ");
                                FILE *file2;
                                file2=fopen("voting.txt","r");
                                if(file2!=NULL){   
                                    
                                        while (fgets(line, sizeof(line), file2)) {
                                        line[strcspn(line, "\r\n")] = '\0';      //new line remove
                                        sscanf(line,"%[^,],%[^,],%[^,],%[^,]",v_pchoice,c_vote,fdistrict,votedfname);
                                        if(strcmp(votedfname,username) ==0){
                                        uservoted=1;
                                        break;
                                        }
                                    }
                                    fclose(file2);
                                }
                                        if(uservoted==1){
                                        
                                            printf("\n\n\n...Your Already Voted...\n");
                                            printf("\n=======================");
                                        }else{
                                            
                                            FILE *fparty;
                                            char pname[50],pmark[20],pcolor[20];
                                            
                                            fparty=fopen("party.txt","r");
                                            while (fgets(line, sizeof(line), fparty)) {  //party list line count
                                                    
                                                    line[strcspn(line, "\n")] = '\0';
                                                    strcpy(party[partyCount], line);
                                                    partyCount++; 
                                                }
                                                
                                                // Party list print
                                                printf("\n\n.... Party list...\n");
                                                for (int i = 0; i < partyCount; i++) {
                                                    sscanf(party[i],"%[^,],%[^,],%[^,]",pname,pmark,pcolor); 
                                                    printf("%d. %s\n", i + 1, pname);
                                                }fclose(fparty);

                                                printf("Enter your choice party name :"); //you vate party choice
                                                scanf("%s",v_pchoice);
                                                
                                                //new line remove
                                                v_pchoice[strcspn(v_pchoice, "\n")] = '\0';
                                                fdistrict[strcspn(fdistrict, "\n")] = '\0';

                                                FILE *candidate;
                                                char  cnumber[20],cnic[20],cname[20],cdistrict[50],cparty[50];
                                                int candidatecount=0;
                                                
                                                candidate=fopen("Nominated_Candidatedetails.txt","r");
                                                printf("\n\n....%s list(%s :)\n\n",v_pchoice,fdistrict);
                                                
                                                while(fgets(line,sizeof(line),candidate)){
                                                    sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,]",cnumber,cnic,cname,cdistrict,cparty);                                        
                                                    
                                                    line[strcspn(line, "\n")] = '\0';  //new line remove
                                                    cdistrict[strcspn(cdistrict, "\n")] = '\0';
                                                    cparty[strcspn(cparty, "\n")] = '\0';

                                                    if((strcmp(fdistrict,cdistrict) == 0) && (strcmp(v_pchoice,cparty) == 0)){ 
                                                        candidatecount++;
                                                        printf("\n\t%d. %s\t%s",candidatecount,cname,cnumber);
                                                    }
                                                }
                                                if(candidatecount==0){
                                                    
                                                    printf("....No candidates found for ths party in you district....\n\n");
                                                break;
                                                }
                                                fclose(candidate);
                                            
                                                printf("\n\n\nCast Your Voted Name:");
                                                scanf("%s",c_vote); 
                                                
                                                    //voting file print
                                                    FILE *vote; 
                                                    vote=fopen("voting.txt","a");
                                                    voteno++;
                                                    fprintf(vote,"%s,%s,%s,%s\n",v_pchoice,c_vote,fdistrict,fusername);
                                                    printf("\n\n....YOUR VOTE SUCCESSFUL...\n");
                                                    fclose(vote);
                                        }
                                    
                                        
                                    
                                    }else{
                                        printf("\n\n... voting time pending ...\n");
                                    }
                                    break;
                                }
                                
                                case 3:
                                    printf("\nEXIT\n");
                                    break;

                                default:
                                    printf("...INVALID INPUT......Please try again...\n\n");
                                    break;
                                }
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
    char C_nic[30], F_nic[30]; //Candidate nic , registered txt file nic
    char C_name[50], C_district[50], C_party[50] , C_password[50]; //
    bool exists = false;
    
    char line[256];
    int choice = 0 ;
    
    while(true){
        printf("\n======================================\n");
        printf("\t|CANDIDATE SECTION|\t\n");
        printf("======================================\n\n");
        printf("1 = Registration\n2 = Login\n3 = Exit\n"); //Candidate Main Menu
        printf("\nYour Choice: ");
        scanf("%d", &choice );

        if(choice == 1){
            bool exists = false;
            printf("\n======================================\n");
            printf("\tCANDIDATE REGISTRATION\t\n");
            printf("======================================\n\n");
            //Getting ID as a nic
            printf("Enter Your ID Number: ");  
            scanf("%s", C_nic);

            FILE *N_C_list, *C_details; //File pointer

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
            else{
                printf("-----File Openning Error------");
            }
            if (exists) {
                printf("\n----Already Registered!Please Log into Your Account----\n\n");
            } else {
                // Save NIC to permanent list
                N_C_list = fopen("Nominated_Candidate_List.txt", "a");
                fprintf(N_C_list, "%s\n", C_nic);
                fclose(N_C_list);

                // Get other details
                printf("Enter your Name: ");
                scanf(" %[^\n]", C_name);
                printf("Enter Your Password: ");
                scanf("%s", C_password );
                printf("Enter Your District: ");
                scanf("%s", C_district);
                printf("Enter Your Party: ");
                scanf("%s", C_party);

                // Save candidate details
                C_details = fopen("Candidatedetails.txt", "a");
                fprintf(C_details, "%s,%s,%s,%s,%s\n", C_nic, C_name, C_password,C_district, C_party);
                fclose(C_details);

                printf("\n-----Registration Successfully!-----\n\n");
             }
        }
        else if(choice == 2){
            char username[30] ;
            char password[30] ;
            int in = 0 ;
            // Candidate Login Section
            printf("\n======================================\n");
            printf("\tCANDIDATE LOGIN\t\n");
            printf("======================================\n\n");

            do{
                printf("\nEnter the Username: ");
                scanf("%s" , username);
                printf("Enter the Password: ");
                scanf("%s" , password);

                FILE *C_details ;

                C_details = fopen("Candidatedetails.txt" , "r");
                if(C_details == NULL){
                    printf("-----Opening Error ! File Candidatedetails.txt-----");
                }
                else{
                    //Check username & password are valid or not
                    int x = 0 ;
                    while(fgets(line,sizeof(line),C_details)){
                        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,]", C_nic , C_name , C_password , C_district , C_party);
                        if ((strcmp(C_nic, username) == 0) && (strcmp(C_password, password) == 0)){
                                x = 1 ;
                                break;
                        }
                    }
                    fclose(C_details);
                    //if username and password correct display login success or  not
                    if(x==1){
                        printf("\n----Login Succesfull----\n");
                        in = 1;
                    }
                    else{
                        printf("\n----Incorrect Password or Username-----\n");
                    }
                }
            }while(in == 0 );
            //After login completetd show dashboard menu
            while(1){
            printf("\n======================================\n");
            printf("\tDASHBOARD\t\n");
            printf("======================================\n\n");
            int dashchoice ;

            printf("1.View Profile\n2.See Approvel\n3.Exit");
            printf("\n\nYour Choice\t:");
            scanf("%d", &dashchoice);
            if(dashchoice == 1){
                    printf("\n======================================\n");
                    printf("\tPROFILE DETAILS\t\n");
                    printf("======================================\n\n");

                    FILE * C_details ;
                    C_details = fopen("Candidatedetails.txt" , "r"); 
                    if(C_details == NULL){
                        printf("Opening Error ! File Candidatedetails.txt");
                    }
                    // Show User Details
                    while(fgets(line,sizeof(line),C_details)){
                        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,]", C_nic , C_name , C_password , C_district , C_party);
                        if ((strcmp(C_password, password) == 0)&&(strcmp(C_nic, username) ==0 )){
                            printf("\nNIC\t\t%s\nName\t\t%s\nPassword\t%s\nDistrict\t%s\nParty\t\t%s" , C_nic , C_name , C_password , C_district , C_party);
                            break;
                        }
                    }
                    fclose(C_details);
                    printf("\n\n1.Exit\t: ");
                    scanf("%d", &choice );
                    continue; 
            }
                else if(dashchoice==2){
                    // Check User Registration Approved or not by the admin with "candidate"
                    exists = false ;
                    FILE * Approved  ;
                    Approved = fopen("candidate.txt" , "r");
                    if (Approved == NULL){
                        printf("-----File Opening Error-----");
                    }
                    else{
                        // Check user Approvel using nic & username
                        while (fgets(line, sizeof(line), Approved)){
                            sscanf(line, "%s", C_nic);
                            if(strcmp(C_nic,username)==0){
                                exists = true ;
                                break;
                            }
                        }
                        fclose(Approved);
                    }
                    if (exists) {
                        printf("\n----Congrats!You Have Nominated For the  Election----\n\n");
                    } 
                    else {
                        printf("-----Registration Pending-----\n");
                    }
                }
                else{
                    printf("-----Invalid Input! Please Try  Again-----\n\n");
                    break;   
            }
        }
    }
        else if(choice == 3){
            printf("\n-----Exiting Candidate Section-----\n\n");
            display();
            break;
        }
        else{
            printf("\n-----Invalid Input!!\nPlease try again-----\n\n");
        }
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
                char name[50],mark[20],color[20],fname[20];
                FILE *admin ;
                admin=fopen("party.txt","r");
                do{
                printf("Enter party name  : ");
                scanf("%s",name);
                printf("Enter party mark  : ");
                scanf("%s",mark);
                printf("Enter party color : ");
                scanf("%s",color);
                
                
                
                while(fgets(line, sizeof(line), admin)){
                    sscanf(line,"%[^,]",fname);
                }if(strcmp(fname,name)==0)
                    printf("...................this party is already registered.................\n");
            }while(strcmp(fname,name)==0);
            
           
        fclose(admin);

                FILE *fparty;
                fparty=fopen("party.txt","a");
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
                        case 1:{
                            FILE *candidate;
                            candidate=fopen("candidate.txt","a");
                            fprintf(candidate,"C00%d,%s",cno,line);
                            printf("\n\n\n-------------------------------%s--------------------------------\n\n","APPROVED SUCCESSFULL");
                            fclose(candidate);
                            cno++;
                            break;}
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
                FILE *status;
                status=fopen("status.txt","w");
                if(list1==1){
                    title("VOTING STARTED");
                    fprintf(status,"1");
                }else if(list1==2){
                    title("VOTING ENDED");
                    fprintf(status,"0");
                }else if(list1==3){
                    title("REGISTRATION OPENED");
                    fprintf(status,"3");
                }else if(list1==4){
                    title("EXIT");
                    break;
                }else{
                    title("INVALID INPUT");
                }fclose(status);
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
    FILE *stat;
    stat=fopen("status.txt","r");
    fscanf(stat,"%d",&checkSTAT);
    fclose(stat);
    if(checkSTAT==2){
       
         
            char v_party[50],v_candidate[50],v_district[50],v_userid[50];
            char line[500];

            char districts[MAX][50];
            char parties[MAX][50];
            char candidates[MAX][50];
            int votes[MAX] = {0};
            int count = 0;

            FILE *winner;
            winner= fopen("voting.txt", "r");
            if (winner == NULL) {
                printf("\n...!! ERROR: cannot open voting.txt file !!.. ");
                
            }

            while (fgets(line, sizeof(line), winner)) {
                
                sscanf(line, "%[^,],%[^,],%[^,],%[^,]",v_party,v_candidate,v_district,v_userid);
                
                int out = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(districts[i],v_district) == 0 &&
                        strcmp(parties[i],v_party) == 0 &&
                        strcmp(candidates[i],v_candidate) == 0) {
                        votes[i]++;
                        out = 1;
                        break;
                    }
                }

                if (!out) {
                    strcpy(districts[count],v_district);
                    strcpy(parties[count],v_party);
                    strcpy(candidates[count],v_candidate);
                    votes[count] = 1;
                    count++;
                }
            }
            fclose(winner);

            printf("\n========================================");
            printf("\n District Wise Party & Candidate Winners ");
            printf("\n========================================\n");

            
            for (int i = 0; i < count; i++) {
                int alreadyChecked = 0;

                
                for (int j = 0; j < i; j++) {
                    if (strcmp(districts[i], districts[j]) == 0) {
                        alreadyChecked = 1;
                        break;
                    }
                }

                if (!alreadyChecked) {
                    int maxVotes = votes[i];
                    int winnerIndex = i;

                    for (int k = i + 1; k < count; k++) {
                        if (strcmp(districts[k], districts[i]) == 0 && votes[k] > maxVotes) {
                            maxVotes = votes[k];
                            winnerIndex = k;
                        }
                    }

                    // Print winning candidate and district
                    printf("%s | %s | %s Votes: %d\n",districts[winnerIndex],parties[winnerIndex],candidates[winnerIndex],votes[winnerIndex]);
                    FILE *fwinner;
                    fwinner=fopen("seewinner.txt","a");
                    fprintf(fwinner,"%s,%s,%s,%d\n",districts[winnerIndex],parties[winnerIndex],candidates[winnerIndex],votes[winnerIndex]);
                    fclose(fwinner);
                }
            }
            printf("\n\nTotal Number of votes cast :\t%d\n",voteno);
            printf("========================================\n\n\n");
            
           
        }else{ 
             printf("\n\n...Winner Is Pending...\n===========================\n\n\n\n");
            }
       
       
	
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
    printf("\n========================================");
    printf("\n            %s ",name);
    printf("\n========================================\n");
}
void readprint(char file[],char display[]){
    FILE *rejected;
    rejected=fopen(file,"a");
    fprintf(rejected,"%s",line);
    title(display);
    fclose(rejected);
}
//main display part
void display(){
    printf("===========================================================\n");
    printf("\t\tParliment Election");
    printf("\n\t\t\t2030");
    printf("\n\t\t Matara District\n");
    printf("===========================================================\n\n\n");

}