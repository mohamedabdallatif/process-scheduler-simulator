#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/syscall.h>


FILE *fp;
#define MAXBUFLEN 10000000
unsigned char buf[MAXBUFLEN];int buflen=0;


int main(int argc,char *argv[]){
system("ps -A -o pid >process.txt");
int pid;
int i=0;
buflen=0;
char *proc= "/proc/";
char *exten="/status";
char int_str[20];
char leo;
FILE *ff=fopen("process.txt","r");
fscanf(ff,"%s",&leo);

while(fscanf(ff,"%d",&pid) == 1){
sprintf(int_str,"%d",pid);

char filespec[strlen(proc)+strlen(exten)+strlen(int_str)+1];
snprintf(filespec,sizeof(filespec),"%s%s%s",proc,int_str,exten);
fp=fopen(filespec,"r");
if(fp!=NULL){
while(!feof(fp)){
buflen=fread(buf,1,MAXBUFLEN,fp);
}
}
if(buflen>1){
for(i=0;i<buflen;i++){
printf("%c",buf[i]);
}
printf("---------------------------------------------------------------------------\n");
}

}

fclose(fp);
}
