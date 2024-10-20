CC = g++ -std=gnu++2b -I ~/work/include -I ~/work/include/ac-library -O2 -DLOCAL
exe = ~/work/include/tools/exe/
src = ~/work/include/tools/src/

all_target = $(exe)macro.out $(exe)new.out $(exe)sample_in.out $(exe)sample_test.out $(exe)acl.out

all: $(all_target)

$(exe)%.out: $(src)%.cpp
	$(CC) $< -o $@

