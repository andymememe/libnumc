OUTPUT=./lib/libnumc.dll
OBJECTS=numarray.o
all: $(OUTPUT)

INCLUDE=../include

$(OUTPUT): $(OBJECTS)
	gcc -s -shared -o $(OUTPUT) $^ -I$(INCLUDE)

$(OBJECTS): %.o: ../src/%.c
	gcc -Wall -O2 -fPIC -c $< -o $@ -I$(INCLUDE)

.PHONY: clean clean-output test
clean:
	rm -rf *.o

clean-all:
	rm -rf *.o
	rm -rf ./test/*
	rm -rf ./lib/*
	rm -rf ./*.dll

test: ../test/test.c
	gcc -Wall -g -o ./test/test-out $< -I$(INCLUDE) -L./lib -lnumc -lbcunit
	ln -s $(OUTPUT) ./libnumc.dll
	./test/test-out
