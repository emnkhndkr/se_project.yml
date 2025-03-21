#include<stdio.h>
#include<string.h>

void setPW(char *password);
int authenticateUser(char *password);
void openDoor(int *isOpen, int *isLocked);
void closeDoor(int *isOpen);
void lockDoor(int *isOpen, int *isLocked);
void unlockDoor(int *islocked);
void checkStatus(int isOpen, int isLocked);

int main() {
int isOpen=0;
int isLocked=0;
char password[20]="123";

setPW(password);

for (int trials=0; trials<3; trials++){
    if (authenticateUser (password)){
        break;
    }
    printf("Incorrect PW! Try Again.\n");
    }
for(;;){
    int choice;
    printf("\nDoor Control System\n");
    printf("1. Open Door\n 2.Close Door\n 3.Lock Door\n 4.Unlock Door\n 5.Check Status\n 6.Exit\n ");
    printf("Enter Your Choice:");
    scanf("%d", &choice);

    switch(choice){
    case 1: openDoor(&isOpen, isLocked); break;
    case 2: closeDoor(&isOpen); break;
    case 3: lockDoor(&isOpen, &isLocked); break;
    case 4: unlockDoor(&isLocked); break;
    case 5: checkStatus(isOpen, isLocked); break;
    case 6: return 0;
    default: printf("Invalid Choice. Please Try Again.\n");
    }
}
    return 0;
}
void setPW(char *password){
char setpassword[20];
printf("Admin: set a new PW:");
scanf("%s", setpassword);
return strcmp(setpassword, password)== 0;
}

void openDoor(int *isOpen, int* isLocked){
if(*isOpen){
    *isOpen=0;
    printf("The Door is now closed.\n");
}else{
   *isLocked=1;
   printf("The door is already closed.\n");}

}
void lockDoor(int *isOpen ,int *isLocked){
if(*isOpen){
    printf("Close the door before locking it.\n");
}else{
   *isLocked=1;
   printf("The door is now Locked.\n");
   }
}
 void unlockDoor(int *isLocked){
 *isLocked=0;
 printf("The door is now unlocked.\n");
 }
void checkStatus(int isOpen, int isLocked){
printf("Door Status: Open:%s, Locked:%s\n", isOpen? "Yes":"No", isLocked? "Yes":"No");
}
