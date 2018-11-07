#!/usr/bin/env bash

killall nweb
mkdir -p ./web/tmp/
rm -rf ./web/tmp/*
./nweb 8181 ./web
