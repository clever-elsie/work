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
n:
	~/work/include/new.out
	$(ED) $(PP)
c:
	~/work/include/macro.out | clip.exe
e:
	$(ED) $(PP)

# GDB
DCC:
	$(CC) -g $(PP) -o $(EXE)
g: DCC
	gdb $(EXE)

local:
	$(CC) $(LOCALH) -o $(LOCALGCH)

