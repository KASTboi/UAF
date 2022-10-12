/*
   joshua kasten-lee 20164847

   parts of code adapted from 
   https://0x00sec.org/t/heap-exploitation-abusing-use-after-free/3580
   and pico ctf unsubscriptions are free
   
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>


typedef struct {
	uintptr_t (*whatToDo)();
	char *username;
} cmd;

char choice;
cmd *user;

void getFlag(){
 	printf("THIS IS A FLAG \n");
}


void doProcess(cmd* obj) {
	(*obj->whatToDo)();
}


void makeAccount(){
	printf("account created \n");
}

void leaveMessage(){
	printf("leave message here: \n");
	char* msg = (char*)malloc(8);
	read(0, msg, 8);
}

void deleteAccount(){
	char response;
  	printf("delete acount (Y/N)? \n");
	scanf(" %c", &response);
	if(toupper(response)=='Y'){
		printf("Bye! \n");
		//user = NULL;
		free(user);
	}
}

void printMenu(){
 	printf("MENU \n");
 	printf("(D) delete account \n");
 	printf("(M) make account \n");
	printf("(L) leave a message \n");
	printf("(q) quit \n");
}

void processInput(){
  scanf(" %c", &choice);
  choice = toupper(choice);
  switch(choice){
	case 'D':
 	user->whatToDo = (void*)deleteAccount;
	break;
	case 'M':
 	user->whatToDo = (void*)makeAccount;
	printf("Enter your username: \n");
	char name[20];
	scanf("%s",name);
	user->username =  name;
	break;
   	case 'L':
	leaveMessage();
	break;
	case 'Q':
	exit(0);
	default:
	printf("invalid input /n");
	exit(1);
	  break;
  }
}

int main(){
	setbuf(stdout, NULL);
	user = (cmd *)malloc(sizeof(user));
	while(1){
		printMenu();
		processInput();
		doProcess(user);	
	}
	return 0;
}

