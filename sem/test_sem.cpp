#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include "sem_hou.h"
#include <iostream>
using namespace std;

int main()
{
	key_t key;
	key = ftok("/ipc/sem", 'a');
	cout<<"key"<<key<<endl;	
	//创建信号量
	int sem_id = semget(key, 1,  IPC_CREAT);
	printf("sem_id %d\n", sem_id);
	if(sem_id == -1)
	{
		perror("sem create error");	
	}
	set_semvalue(sem_id, 1);
	while(true)
	{
		sem_p(sem_id);
		time_t curtime = time(NULL);
		cout<<"int the critical"<< curtime <<endl;
		sleep(1);
		sem_v(sem_id);
		sleep(1);
	
	}
	printf("program okkk\n");
	exit(EXIT_SUCCESS);



	return 0;
}
