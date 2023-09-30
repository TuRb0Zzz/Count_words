all: test_parse

test_parse: main.o parse_text.o count_words.o
	g++ main.o parse_text.o count_words.o -ldl -lpthread

main.o: main.c
	g++ -c main.c

parse_text.o: parse_text.c
	g++ -c parse_text.c

count_words.o: count_words.c
	g++ -c count_words.c

clean:
	rm -rf *.o *.exe *.out