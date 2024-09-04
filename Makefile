PP = ~/work/shm/a.cpp
EXE= ~/work/shm/a.out
LOCALH = ~/work/include/local.h
LOCALGCH = ~/work/include/local.h.gch

CC = g++ -std=gnu++2b -I ~/work/include -I ~/work/include/ac-library -O2 -DLOCAL
ED = code

#C++
all: $(EXE)
	$(EXE)
$(EXE): $(PP)
	$(CC) $(PP) -o $(EXE)
$(PP):
	cp template.cpp $(PP)
n: clean shm/in shm/out
	~/work/include/new.out
	$(ED) $(PP)
shm/in:
	touch shm/in
shm/out:
	touch shm/out

c:
	~/work/include/macro.out | clip.exe
e:
	$(ED) $(PP)
sample = ~/work/include/sample_in.out
sample_in: $(sample)
	$(sample)
sample_test = ~/work/include/sample_test.out
test: $(EXE)
	$(sample_test)

clean:
	-rm /dev/shm/*

# GDB
DCC:
	$(CC) -g $(PP) -o $(EXE)
g: DCC
	gdb $(EXE)

local:
	$(CC) $(LOCALH) -o $(LOCALGCH)

