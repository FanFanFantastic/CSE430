#include <unistd.h>
#include <linux/sched.h>
#include <string.h>
#include <stdio.h>
#define __NR_my_ps 360
struct my_struct 
{
	int task_pid;
	char task_tty[64];
	unsigned long task_time;
	char task_comm[32];	
}my_struct;

int main()
{	
	int i=0;
	int num =0; 
	struct my_struct userbuff[1024];
	unsigned long TIME;
//	num = sizeof(userbuff)/sizeof(my_struct);

/*
	printf("PID TTY\tTIME CMD\n");

	for(i =0;i<num;i++)
	{
        	printf("%d ",userbuff[i].task_pid);
		printf("%s",userbuff[i].task_tty);
		printf("%lu\t ",userbuff[i].task_time);
		printf("%s\n",userbuff[i].task_comm);
	}
*/

	num = syscall (__NR_my_ps,sizeof(userbuff),userbuff);
	
//	struct my_struct userbuff[num+1];
	printf(" PID TTY\t    TIME CMD\n");
	
	for(i =0;i<num;i++)
	{
		TIME = userbuff[i].task_time;
        	printf(" %4d  ",userbuff[i].task_pid);
		printf("%s\t",userbuff[i].task_tty);
		printf("%02lu:%02lu:%02lu ",TIME/(3600),TIME/60%60,TIME%60);
		printf("%s\n",userbuff[i].task_comm);
	
	}

	return 0;
}

