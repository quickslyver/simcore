all:
	mkdir -p build
	ghdl -a -Wc,-Os --workdir=build test/test.vhd
	gcc -g -Wall -std=c99 test/test.c build/test.o -obuild/test -Iinclude /usr/lib/ghdl/lib/gcc/i486-linux-gnu/4.3.4/vhdl/lib/v93/std/std_standard.o -ldl -rdynamic
  
run: all
	./build/test

clean:
	rm -rf build
