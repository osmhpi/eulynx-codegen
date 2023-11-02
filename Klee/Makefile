SRCS = $(wildcard *.c)
BCS = $(patsubst %.c,%.bc,$(SRCS))

all: $(BCS)

%.bc: %.c
	clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone $<

%.klee: %.bc
	klee -search=dfs -use-merge --emit-all-errors $< 2>&1 | tee $@
	(! grep "KLEE: ERROR" $@)
