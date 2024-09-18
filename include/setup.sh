#!/bin/bash
#sudo echo '/dev/shm/ /tmp tmpfs defaults,size=1024m 0 0' >> /etc/fstab
#git clone https://github.com/atcoder/ac-library
#git clone https://github.com/clever-elsie/lib_Clever_Elsie ../lib_Clever_Elsie
cd tools; make; cd -;
#ln -s /dev/shm ../shm