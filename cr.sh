cp /storage/emulated/0/gitcode /.
clang nweb23.c -o nweb
killall nweb
./nweb 8181 ./web
