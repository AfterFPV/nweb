#!/usr/bin/env bash

make clean
make
./run_server.sh
./client example_4.json
