#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/sem.h>
#include "sem_hou.h"
#include "errno.h"

extern int errno;

int set_semvalue(int sem_id, int value)
{
	//用于初始化信号量，在使用信号量前必须这样做
	union semun sem_union;

	sem_union.val = value;
	if(semctl(sem_id, 0, SETVAL, sem_union) == -1)
		return 0;
	return 1;
}

void del_semvalue(int sem_id)
{
	//删除信号量
	union semun sem_union;

	if(semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
		fprintf(stderr, "Failed to delete sem\n");
}

int sem_p(int sem_id)
{
	//对信号量做减1操作，即等待P（sv）
	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op = -1;//P()
	sem_b.sem_flg = SEM_UNDO;
	if(semop(sem_id, &sem_b, 1) == -1)
	{
		fprintf(stderr, "sem_p failed\n");
		perror("sem_p perror:");
		printf("errorno:%d", errno);
		return -1;
	}
	return 0;
}

int sem_v(int sem_id)
{
	//这是一个释放操作，它使信号量变为可用，即发送信号V（sv）
	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op = 1;//V()
	sem_b.sem_flg = SEM_UNDO;
	if(semop(sem_id, &sem_b, 1) == -1)
	{
		fprintf(stderr, "sem_v failed\n");
		perror("sem_v perror:");
		printf("errorno:%d", errno);
		return -1;
	}
	return 0;
}
