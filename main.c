#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


void get_memory_usage(){
 FILE *fp;
char line[256];
int total,free;

fp=fopen("/proc/meminfo","r");
if (fp == NULL){
printf("error opening meminfo\n");
return;
}


fscanf(fp,"memtotal:%d kb\n", &total);
fscanf(fp,"memfree:%d kb\n",&free);
printf("memory usage: %d%%\n",(total-free) * 100/total);

fclose(fp);
}

int main(){
while(1){
system("clear");

printf("===linux system monitor===\n\n");
get_memory_usage();
sleep(2);
}
return 0;
}  

