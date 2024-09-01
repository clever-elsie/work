#!/bin/bash
sudo echo '/dev/shm/ /tmp tmpfs defaults,size=1024m 0 0' >> /etc/fstab
git clone https://github.com/atcoder/ac-library
git clone https://github.com/clever-elsie/lib_Clever_Elsie ../lib_Clever_Elsie
g++ macro.cpp -o macro.out -O2 -std=gnu++2a
g++ new.cpp -o new.out -O2 -std=gnu++2a
g++ local.h -o local.h.gch -std=gnu++2b -I . -I ./ac-library
g++ sample_in.cpp -o sample_in.out -O2 -std=gnu++2b
g++ sample_test.cpp -o sample_test.out -O2 -std=gnu++2b
ln -s /dev/shm ../shm