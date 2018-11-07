# C/C++ Coding Exercise
A web server that can read in JSON and return it as XML.

### Requirements
1) Boost - sudo apt-get install libboost-all-dev
2) gcc 4.2.x+
3) Linux/Unix or MacOS X
4) xmllint (needed only for tests) - sudo apt install libxml2-utils

### Use
1) ```$ make```
2) ```$ ./run_server.sh```
3) ```$ ./client```

### Notes
1) Server is setup to run on localhost 8181, If this is not available in your test env, changes will need to be made to run_server.sh and client.c
3) Files are hosted from ./web, this directory must be readable 
4) ./web/tmp must also be present

### References
1) nweb - https://github.com/ankushagarwal/nweb
2) boost - https://www.boost.org/
3) Bash on Ubuntu on Windows - Developed on Ubuntu VM running on Windows 10
