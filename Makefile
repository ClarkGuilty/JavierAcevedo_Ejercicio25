sample.pdf: satan.dat
	python plots.py
	rm satan.a
	rm stan.dat

satan.dat: sample.c
	gcc -o satan.a sample.c -lm
	./satan.a
	./satan.a 2000 8 2
	rm satan.a

