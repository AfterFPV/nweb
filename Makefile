CC    = gcc

all: pt_conversion nweb client

pt_conversion: pt_conversion.cpp
	$(CC) -c -o pt_conversion.o pt_conversion.cpp -lstdc++

nweb: nweb23.c
	$(CC) nweb23.c pt_conversion.o -o nweb -lstdc++
client: client.c
	$(CC) client.c -o client

clean: 
	rm nweb pt_conversion.o client
