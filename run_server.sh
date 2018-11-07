#!/usr/bin/env bash

killall nweb
rm -rf ./web/tmp/*
./nweb 8181 ./web
