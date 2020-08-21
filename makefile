# Make

.PHONY = clean all
KEYS :=
LIBS := -lpthread
CC := gcc

all : pthread_quest_mutex pthread_quest_onethread

pthread_quest_mutex : pthread_quest_mutex.o
	$(CC) $(KEYS) pthread_quest_mutex.o -o pthread_quest_mutex $(LIBS)

pthread_quest_mutex.o : pthread_quest_mutex.c
	$(CC) $(KEYS) -c pthread_quest_mutex.c -o pthread_quest_mutex.o $(LIBS)

pthread_quest_onethread : pthread_quest_onethread.o
	$(CC) $(KEYS) pthread_quest_onethread.o -o pthread_quest_onethread $(LIBS)

pthread_quest_onethread.o : pthread_quest_onethread.c
	$(CC) $(KEYS) -c pthread_quest_onethread.c -o pthread_quest_onethread.o $(LIBS)

clean :
	rm -f *.o *.gch pthread_quest_mutex pthread_quest_onethread
