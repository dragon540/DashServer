CC=gcc
PROGNAME=DashServer
CFLAG1=-Wall

all: $(PROGNAME) clean

server_config.o: src/server_config.c src/server_config.h src/page_map.h
	$(CC) -c src/server_config.c

page_map.o: src/page_map.c src/page_map.h
	$(CC) -c src/page_map.c

connect.o: src/connect.c src/connect.h
	$(CC) -c src/connect.c

communicate.o: src/communicate.c src/communicate.h src/connect.h src/read_resource.h src/helper.h src/page_map.h
	$(CC) -c src/communicate.c

read_resource.o: src/read_resource.c src/read_resource.h
	$(CC) -c src/read_resource.c

helper.o: src/helper.c src/helper.h
	$(CC) -c src/helper.c

main.o: src/main.c src/communicate.h src/server_config.h
	$(CC) -c src/main.c

$(PROGNAME): server_config.o page_map.o connect.o communicate.o read_resource.o helper.o main.o
	$(CC) $(CFLAG1) server_config.o page_map.o connect.o communicate.o read_resource.o helper.o main.o -o $(PROGNAME)

clean:
	rm *.o

run:
	./$(PROGNAME)


