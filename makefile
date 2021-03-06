CC = gcc
CFLAGS = -g -Wall

executable: main.o game.o monopoly_new_player.o monopoly_roll_dice.o properties.o chance_chest_cards.o
	$(CC) $(CFLAGS) -o simulation main.o game.o monopoly_new_player.o monopoly_roll_dice.o properties.o chance_chest_cards.o -pthread

main.o: main.c game.h
	$(CC) $(CFLAGS) -c main.c -pthread 

game.o: game.c game.h monopoly.h
	$(CC) $(CFLAGS) -c game.c -pthread -time

properties.o: properties.c game.h
	$(CC) $(CFLAGS) -c properties.c

chance_chest_cards.o: chance_chest_cards.c monopoly.h
	$(CC) $(CFLAGS) -c chance_chest_cards.c

monopoly_new_player.o: monopoly_new_player.c monopoly.h
	$(CC) $(CFLAGS) -c monopoly_new_player.c

monopoly_roll_dice.o: monopoly_roll_dice.c monopoly.h
	$(CC) $(CFLAGS) -c monopoly_roll_dice.c

clean:
	-rm *.o simulation