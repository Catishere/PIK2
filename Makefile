OBJS	= main.o company_service.o date.o linked_list.o menu.o record.o regex.o
SOURCE	= main.c company_service.c date.c linked_list.c menu.c record.c regex.c
HEADER	= company_service.h date.h linked_list.h menu.h record.h regex.h macros.h
OUT	= KursovaPIK
CC	 = D:\Qt\Tools\mingw730_64\bin\gcc.exe
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c -std=c99

company_service.o: company_service.c
	$(CC) $(FLAGS) company_service.c -std=c99

date.o: date.c
	$(CC) $(FLAGS) date.c -std=c99

linked_list.o: linked_list.c
	$(CC) $(FLAGS) linked_list.c -std=c99

menu.o: menu.c
	$(CC) $(FLAGS) menu.c -std=c99

record.o: record.c
	$(CC) $(FLAGS) record.c -std=c99

regex.o: regex.c
	$(CC) $(FLAGS) regex.c -std=c99


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)