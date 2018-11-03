#!/usr/bin/env bash

gcc nweb23.c -o nweb
killall nweb
./nweb 8181 ./web
