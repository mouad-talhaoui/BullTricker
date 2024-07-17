make:
	gcc BULLTRICKER.c -w -lSDL2 -o bulltricker

run: bulltricker
	./bulltricker

clean:
	rm -f bulltricker
check:
		gcc main.c -w -lSDL2 -o check
		./check