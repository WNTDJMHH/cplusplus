#ifndef SEM_HOU_H
#define SEM_HOU_H

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *arry;
};


extern  int set_semvalue(int sem_id, int value);
extern  void del_semvalue(int sem_id);
extern  int sem_p(int sem_id);
extern  int sem_v(int sem_id);

#endif
