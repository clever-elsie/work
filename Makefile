PP = ~/work/shm/a.cpp
EXE= ~/work/shm/a.out

CC = g++ -std=gnu++2b -I ~/work/include -I ~/work/include/ac-library -O2 -DLOCAL -mtune=native -march=native -fconstexpr-depth=2147483647 -fconstexpr-loop-limit=2147483647 -fconstexpr-ops-limit=2147483647 
ED = code

tools = ~/work/include/tools/exe/
new = $(tools)new.out
macro = $(tools)macro.out

#C++
all: $(EXE)
	$(EXE)
$(EXE): $(PP) include/local.h
	$(CC) $(PP) -o $(EXE)
	clear
$(PP):
	$(new)
n: clean
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
RAND_GEN_FILE = shm/b.cpp
RAND_GEN = shm/b.out
$(RAND_GEN_FILE):
	cp ~/work/include/tools/resource/template.cpp $(RAND_GEN_FILE)
rand_gen_file: $(RAND_GEN_FILE)
	$(ED) $(RAND_GEN_FILE)
$(RAND_GEN): $(RAND_GEN_FILE)
	$(CC) $(RAND_GEN_FILE) -o $(RAND_GEN)
gen: $(RAND_GEN)
	$(RAND_GEN) > $(IN)


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
ACLEXPAND = $(tools)acl.out
acl: $(PP)
	$(macro) | $(ACLEXPAND) | clip.exe
