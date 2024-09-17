PP = ~/work/shm/a.cpp
EXE= ~/work/shm/a.out

CC = g++ -std=gnu++2b -I ~/work/include -I ~/work/include/ac-library -O2 -DLOCAL
ED = code

#C++
all: $(EXE)
	$(EXE)
$(EXE): $(PP)
	$(CC) $(PP) -o $(EXE)
$(PP):
	~/work/include/new.out
n: clean shm/in shm/out
	~/work/include/new.out
	$(ED) $(PP)
IN = shm/in
OUT = shm/out
$(IN):
	touch shm/in
in: $(IN)
	$(ED) $(IN)
$(OUT):
	touch $(OUT)
out: $(OUT)
	$(ED) $(OUT)
c:
	~/work/include/macro.out | clip.exe
e:
	$(ED) $(PP)
test: $(EXE)
	$(sample_test)

clean:
	-rm /dev/shm/*

# GDB
g:
	$(CC) -g $(PP) -o $(EXE)
	gdb $(EXE)

LOCALH = ~/work/include/local.h
local:
	$(CC) $(LOCALH) -o $(LOCAL).gch