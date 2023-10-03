CC = gcc -Wall -Wextra

%.o: %.c %.h
	$(CC) -c $< -o $@

exec: pile.o automate_traitement.o main.o
	$(CC) $^ -o $@

automate_traitement.o: pile.h

main.o: automate_traitement.h pile.h

clear:
	rm -f *.o exec 