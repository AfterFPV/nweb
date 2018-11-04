CC    = gcc

all: nweb pt_conversion client

nweb: nweb23.c
	$(CC) nweb23.c pt_conversion.o -o nweb -lstdc++

pt_conversion: pt_conversion.cpp
	$(CC) -c -o pt_conversion.o pt_conversion.cpp -lstdc++

client: client.c
	$(CC) client.c -o client


