PP = ~/work/shm/a.cpp
EXE= ~/work/shm/a.out
LOCALH = ~/work/include/local.h
LOCALGCH = ~/work/include/local.h.gch

CC = g++ -std=gnu++2b -I ~/work/include -I ~/work/include/ac-library -O2
ED = code

#C++
all: $(EXE)
	$(EXE)
$(EXE): $(PP)
	$(CC) $(PP) -o $(EXE)
$(PP):
	cp template.cpp $(PP)
n: shm/in shm/out
	~/work/include/new.out
	$(ED) $(PP)
c:
	~/work/include/macro.out | clip.exe
e:
	$(ED) $(PP)


in:
	$(ED) shm/in
out:
	$(ED) shm/out
shm/in:
	touch shm/in
shm/out:
	touch shm/out
gen_in.cpp = shm/gen_in.cpp
gen_in.out = shm/gen_in.out
n_gen_in:
	cp ~work/include/template_gen_in.cpp $(gen_in.cpp)
ed_gen_in: $(gen_in.cpp)
	$(ED) $(gen_in.cpp)
gen_in: $(gen_in.out) $(EXE)
	$(gen_in.out)
$(gen_in.out): $(gen_in.cpp)
	$(CC) $(gen_in.cpp) -o $(gen_in.out)
$(gen_in.cpp):
	touch $(gen_in.cpp)
# GDB
DCC:
	$(CC) -g $(PP) -o $(EXE)
g: DCC
	gdb $(EXE)

local:
	$(CC) $(LOCALH) -o $(LOCALGCH)

