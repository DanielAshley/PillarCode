
all: src/kata.c tests/check_kata.c
	gcc -lcheck -o testKata src/kata.c tests/check_kata.c `pkg-config --cflags --libs check`

clean: 
	$(RM) testKata
