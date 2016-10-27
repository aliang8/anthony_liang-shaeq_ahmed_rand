randtest: rand.c
	gcc rand.c
run: randtest
	./a.out
clean:
	rm rand.txt
	rm *~
	rm a.out