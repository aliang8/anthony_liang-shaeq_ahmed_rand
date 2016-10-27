randtest: rand.c
	gcc rand.c
run: randtest
	./a.out
clean:
	rm rand.txt