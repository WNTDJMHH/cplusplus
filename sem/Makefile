INCLUDES= -I "./"
TARGETS=test_sem test_sem2
OBJS1=test_sem.o sem_hou.o
OBJS2=test_sem2.o sem_hou.o

ALL:${TARGETS}

test_sem:${OBJS1}
	g++ -o $@ $?

test_sem2:${OBJS2}
	g++ -o $@ $^

${OBJS1}:sem_hou.h
${OBJS2}:sem_hou.h

clean:
	rm -f ${OBJS1} ${OBJS2} ${TARGETS}
