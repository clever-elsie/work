#!/bin/bash
#sudo apt update && sudo apt upgrade -y
#sudo apt install build-essential gcc g++ python3 nginx git make
#sudo apt install cmake libasio-dev
#cd && git clone https://github.com/CrowCpp/Crow.git && mkdir Crow/build && cd Crow/build && cmake .. -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF && make -j$(nproc) && make install && make clean && cd && rm -rf Crow
#git clone https://github.com/atcoder/ac-library
#git clone https://github.com/clever-elsie/lib_Clever_Elsie ../lib_Clever_Elsie
cd tools; make; cd -;
cd server; make; cd -;
#sudo echo '/dev/shm/ /tmp tmpfs defaults,size=1024m 0 0' >> /etc/fstab
#ln -s /dev/shm ../shm