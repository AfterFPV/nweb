SHELL = /bin/sh
CC    = gcc

all: nweb client

nweb: nweb23.c
	$(CC) nweb23.c -o nweb

client: client.c
	$(CC) client.c -o client


