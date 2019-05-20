#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
//#include "stack.h"
//#include <stack>
//#include <iostream>
//using namespace std;
int MAXSIZE = 50;       
char *stack[50];     
int top = -1;            
char**arg=NULL;
struct Node*head=NULL;
struct Node*tail=NULL;
struct Node*curr=NULL;
int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

char* peek() {
   return stack[top];
}

char* pop() {
   char* data;
	
   if(!isempty()) {
      
      return(stack[top--]);
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int pushh(char* data) {

   //printf("ENTERED\n");
   if(!isfull()) {
      top = top + 1;   
      //avoiding shallow copy problem
      stack[top]=(char*) malloc(strlen(data)+1);
      int i = 0;
      for (i = 0; data[i] != '\0'; ++i)
      {
      	stack[top][i]=data[i];
      }
     
      
      
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
   //printf("%s\n",stack[0]);
}
struct Node{
    char*fname;
    char*password;
    struct Node*next;
};
void take_input(char*c)
{
      //cout<<"Enter Input"<<endl;
      fgets(c,50,stdin);
      int k = strlen(c)-1;
      c[k]='\0';    
}
int check(char*str1,char*str2)
{
     //int k;
     //k = strlen(str1);
     //printf("%d",k);
     //k = strlen(str2);
     //printf("%d",k);
     int i=0;
     for (i=0;str2[i]!='\0';i++){
          //printf("Ok\n");
          if(str1[i]!=str2[i]){
             return 0;
          }
          //printf("reachedhere\n");
     }
     return 1;
}
void getuser()
{

   printf("17L_4222-");
   char adjust[50];
   getcwd(adjust,50);
   char cwd[50];
   int count=0;
   int i=0;
   int k=0;
   for (i=0;adjust[i]!='\0';i++){
   count=0;
         if (adjust[i]=='/'){
             for (k=i;adjust[k]!='\0';k++){
                      adjust[k]=adjust[k+1];
                      cwd[count++]=adjust[k];
             }
         }
    
   }
   printf("%s",cwd);
   printf(">\n");

}
void modif_cd(char*c)
{
   char cmd[50];
   int count=0;
   int flag=0;
   int i=0;
   int k=0;
   for (i=0;c[i]!='\0';i++){
        if (c[i]==' '){
              flag=1;
              for (k=i;c[k+1]!='\0';k++){
                       c[k]=c[k+1];
                       cmd[count++]=c[k];
              }       
        }
   }
   if (flag==1){
   cmd[count]='\0';
   //printf("%s\n",cmd);
   for (i=0;cmd[i]!='\0';i++)
         c[i]=cmd[i];
   c[count]='\0';
   }
   //printf("%s\n",c);
}
void modif_ls(char*c)
{
       int count=1;
       int j=1;
       int flag=0;
       int i=0;
       int k=0;
       //printf("pinpoint\n");
       for (i=0;c[i]!='\0';i++){
           j=0;
           //printf("%d\n",i);
           if (c[i]==' '){
              flag=1;
              for (k=i+1;c[k]!=' ' && c[k]!='\0';k++){
                  //printf("%da\n",k); 
                   arg[count][j++]=c[k];
              }
              count++;
           }

       }
       //printf("pinpoint\n");
       if (flag==1)
          arg[count]='\0';
       if (count==1)
          arg[count]='\0';
    //cout<<"Exited"<<endl;
}
void initializer()
{
      //cout<<"Initializing"<<endl;
      int i=0;
      arg = (char**)calloc(4,sizeof(char*));
      for (i=0;i<4;i++){
          arg[i]=(char*)calloc(8,sizeof(char));
      }
      strcpy(arg[0],"ls");
      //printf("%s\n",arg[0]);
      //cout<<"Exiting Initializer"<<endl;
}
void modif_push(char*p)
{
      char cmd[20];
      int count=0;
      int flag=0;
      int i=0;
      int k=0;
      for (i=0;p[i]!='\0';i++){
            if (p[i]=='/'){
                flag=1;
                for (k=i+1;p[k]!='\0';k++){
                     cmd[count++]=p[k];
                }
           }   

      }
      if (flag==1){
      cmd[count]='\0';
            for (i=0;i<count;i++){
                 p[i]=cmd[i];
            }
      p[count]='\0';
      //printf("%s\n",p);
      }
}
void modif_cwd(char*c)
{
       char cwd[50];
       int count=0;
       int flag=1;
       int i=0;
       int k=0;
       for (i=0;c[i]!='\0';i++){
         if (c[i]=='/'){
             count=0;
             flag=1;
             for (k=i;c[k]!='\0';k++){
                      c[k]=c[k+1];
                      cwd[count++]=c[k];
             }
         }
       }
       //cout<<count<<endl;
       if (flag==1){
             //cout<<"Entered"<<endl;
             for (i=0;i<count;i++){
                 c[i]=cwd[i];
             }
            //cout<<c<<endl;
       }
}
void modif_private(char*p)
{
     char buffer[20];
     int count=0;
     int i=0;
     int k=0;
     for (i=0;p[i]!='\0';i++){
         if (p[i]==' '){
             for (k=i+1;p[k]!='\0';k++)
                  buffer[count++]=p[k];
            buffer[count]='\0';
            break;
            //for (i=0;i<count;i++){
                //p[i]=buffer[i];
            //}
            //p[count]='\0';
         }

     }
   strcpy(p,buffer);
   //printf("%s\n",buffer);
   //printf("%s\n",p);
}
void list_handling(char*fn,char*p)
{
      if (head==NULL){
         struct Node*n=(struct Node*) malloc (sizeof(struct Node));
         head=n;
         curr=head;
         int k = strlen (fn)+1;
         curr->fname = (char*)malloc(k);
         int i=0;
         for (i=0;i<k;i++)
              curr->fname[i]=fn[i];
         k = strlen (p)+1;
         curr->password = (char*)malloc(k);
         for (i=0;i<k;i++)
              curr->password[i]=p[i];
         head->next=NULL;
      }
      else{
         struct Node*n=(struct Node*) malloc (sizeof(struct Node));
         curr->next=n;
         curr=n;
         int k = strlen (fn)+1;
         curr->fname = (char*)malloc(k);
         int i=0;
         for (i=0;i<k;i++)
              curr->fname[i]=fn[i];
         k = strlen (p)+1;
         curr->password = (char*)malloc(k);
         for (i=0;i<k;i++)
              curr->password[i]=p[i];
         curr->next=NULL;
      }
}
void print(struct Node*head)
{
     while (head!=NULL){
         printf("%s\n",head->fname);
         printf("%s\n",head->password);
         head=head->next;
     } 
}
char*search(struct Node*ptr,char*pswd)
{

      while (ptr!=NULL){
             if (strcmp(ptr->password,pswd)==0){
                 ptr->password=NULL;
                 return (ptr->fname);
             }
             ptr=ptr->next;
      }
     return NULL;
}
int main()
{
      
      pid_t pid;
      //stack<char*>*s=new stack<char*>;

      char ls[]="ls";
      char cd[]="cd";
      char pwd[]="pwd";
      char push[]="push";
      char pop1[]="pop";
      char pop2[]="pop -showtop";
      char command[50]="a";
      char private1[]="private";
      char private2[]="ls -private";
      char filename[50];
      char password[20];
      int i=0;
      int k=0;

      ///*
      while(1){
      getuser();
      take_input(command);
      if (command[0]=='l' && command[1]=='s' && command[4]!='p'){
          //printf("e\n");

          initializer();      
          modif_ls(command);
          //printf("%s\n",arg[0]);
          //printf("%s\n",arg[1]);
          pid = fork();
          if (pid==0){
          //childprocess
              //printf("Entered Child Process\n");
              execvp(arg[0],(char*const*)arg);     
          }
          else if (pid>0){
          //parentprocess
              wait(NULL);
          }

      }
      else if (command[0]==cd[0] && command[1]==cd[1]){
          //printf("e\n");
          modif_cd(command);
          pid = fork();
          if (pid==0){
          //childprocess
          //printf("Entered Child Process\n");
              //printf("%s\n",command);
              k=chdir(command);
              //printf("%d",k);     
          }
          else if (pid>0){
          //parentprocess
              wait(NULL);
          }
      }
      else if (check(command,pwd)==1){
             //printf("Let Me Know\n");
             char path[50];
             getcwd(path,50);
             printf("%s\n",path);
      }
      else if (check(command,push)==1){
          //printf("easdasfasf\n");

          char cwd[50];
          char cmpcwd[50];
          getcwd(cwd,50);
          strcpy(cmpcwd,cwd);
          modif_cwd(cwd);
          //printf("%s\n",cwd);
          modif_push(command);
          //printf("%s\n",command);
          char*ptr = (char*)malloc(strlen(cmpcwd)+1);
          for (i=0;i<strlen(cmpcwd)+1;i++)
                    ptr[i]=cmpcwd[i];

          if (check(command,cwd)==1){
                pushh(ptr);
          //printf("ENTERED");
          //printf("%s\n",stack[0]);
          //cout<<s->top()<<endl;
          pid = fork();
          if (pid==0){
          //childprocess
          //printf("Entered Child Process\n");
             //cout<<"reached"<<endl;
             execlp("mkdir","mkdir","fast",NULL);
          }
          else if (pid>0){
          //parentprocess 
              char arr[25];
              getcwd(arr,25);
              while (check(arr,"/")==0){
                 //printf("Let Me Know\n");
                 chdir("..");
                 getcwd(arr,25);
                 //printf("%s\n",arr);
              }
              chdir("/home/oracle/Desktop");
              wait(NULL);
              chdir("fast");
          }
          }//endofif
          else{
             printf("This is not the directory you're working in\n");
          }

      }
      else if (check(command,pop1)==1){
          //printf("e\n");
          
          if (check(command,pop2)==1)
              printf("%s\n",peek());
          else if (check(command,pop1)==1){
              if (!isempty()){
              char arr[25];
              getcwd(arr,25);
              while (check(arr,"/")==0){
                 //printf("Let Me Know\n");
                 chdir("..");
                 getcwd(arr,25);
                 //printf("%s\n",arr);
              }
              chdir(peek());
              pop();
              }
              else{
                 printf("No directory on stack\n");
              }
          }
          
      }
      else if (check(command,private1)==1){
               
              modif_private(command);
              //cout<<command<<endl;
              //int fd=open(command,O_RDWR);
              //if(fd!=-1){
              int fd = open (command,O_RDWR);
              DIR*k = opendir(command);
              if (fd!=-1 || k!=NULL){
              printf("Password: ");
              fgets(password,20,stdin);
              list_handling(command,password);
              //printf("%s\n",curr->fname);
              //printf("%s\n",curr->password);
              //add_file(command,password);
              char buffer[20];
              buffer[0]='.';
              int count=1;
              for (i=0;command[i]!='\0';i++)
                     buffer[count++]=command[i];
              buffer[count]='\0';
              //printf("%s\n",buffer);
              //printf("%s\n",command);
              pid=fork();
              if(pid==0){
                   //childprocess
                   execlp("mv","mv",command,buffer,NULL);   
              }
              else if(pid>0){
                   //parentprocess
                   wait(NULL);
              }
              
              }//endofit
              //}//endofif
              else{
                 printf("File/Dir does not exist\n");
              }
      }
      else if (check(command,private2)==1){
               
              printf("Password: ");
              fgets(password,20,stdin);
              char*ptr;
              //print(head);
              //if (ptr!=NULL){
              while (ptr!=NULL){
              ptr=search(head,password);
              //printf("ENTERED\n");
              char buffer[20];
              buffer[0]='.';
              int count=1;
              for (i=0;ptr[i]!='\0';i++)
                     buffer[count++]=ptr[i];
              buffer[count]='\0';
              //printf("pp1\n");
              pid=fork();
              if(pid==0){
                   //childprocess
                   execlp("mv","mv",buffer,ptr,NULL);   
              }
              else if (pid>0){
                  //parentprocess
                  ptr=NULL;
                  wait(NULL);
                  pid=fork();
                  if (pid==0){
                  //childprocess
                  execlp("ls","ls",NULL);
                  }
                  else if (pid>0){
                  //parentprocess
                  wait(NULL);
                  
                  }
              }
              
              }//endofwhile
              
              }
              //}//endofif
              //else{
                //printf("Wrong Password Entered or File Not Found\n");
              //}
      
      else{
           printf("Invalid Command Entered\n");
      }
           
      }//endofwhile
      //*/     

      return 0;
}
