PP = ~/work/shm/a.cpp
EXE= ~/work/shm/a.out

CC = g++ -std=gnu++2b -I ~/work/include -I ~/work/include/ac-library -O2 -DLOCAL
ED = code

tools = ~/work/include/tools/exe/
new = $(tools)new.out
macro = $(tools)macro.out

#C++
all: $(EXE)
	$(EXE)
$(EXE): $(PP)
	$(CC) $(PP) -o $(EXE)
$(PP):
	$(new)
n: clean shm/in shm/out
	$(new)
	$(ED) $(PP)
c:
	$(macro) | clip.exe
e:
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

sample_test = $(tools)sample_test.out
sample_in_out = $(tools)sample_in.out
test: $(EXE)
	$(sample_test)
sample_in:
	$(sample_in_out)

clean:
	-rm /dev/shm/*

# GDB
g:
	$(CC) -g $(PP) -o $(EXE)
	gdb $(EXE)

LOCALH = ~/work/include/local.h
local:
	$(CC) $(LOCALH) -o $(LOCALH).gch