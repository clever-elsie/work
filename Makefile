PP = shm/a.cpp
EXE= shm/a.out

LIB1 = /usr/local/include/ac-library
LIB2 = /usr/local/include/lib_Clever_Elsie

CC = g++ -std=gnu++2b -I ./include -I $(LIB1) -I $(LIB2) -O2 -DLOCAL -g -mavx2 -mavx512f -march=native -mtune=native
ED = code

tools = include/tools/exe/
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
pre: clean
	cp include/tools/resource/template_pre.cpp $(PP)
	$(ED) $(PP)
c:
	$(macro) | iconv -t sjis | clip.exe
e:
	$(ED) $(PP)
z: $(PP)
	$(CC) $(PP) -o $(EXE)

ojt:
	$(CC) $(PP) -o $(EXE)
	cd shm && oj test -N -s -j $(ojt_thread) --no-print-input -t 15 && cd -

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
	cp include/tools/resource/template.cpp $(RAND_GEN_FILE)
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
	-rm shm/*

# GDB
g: $(EXE)
	gdb $(EXE)

LOCALH = include/local.h
local:
	$(CC) $(LOCALH) -o $(LOCALH).gch
ACLEXPAND = $(tools)acl.out
acl: $(PP)
	$(macro) | $(ACLEXPAND) | clip.exe

prec = $(tools)precompile.out
lib:
	echo $(CC) | ($(prec) 2> /dev/shm/out)
