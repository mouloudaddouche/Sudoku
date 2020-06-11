CFLAGS = -g -Wall -c
CFLAGSGR = ${CFLAGS} `sdl-config --cflags`
LFLAGS = -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

run: sudoku
	./sudoku exemple.sudoku.txt

# Edition de lien du programme principal
sudoku: sudoku.o afficher.o gestion_sudoku.o lire_ecrire.o  listecircu.o liste.o generateur_sudoku.o
	gcc -o $@ $^ ${LFLAGS}

# Compilation du programme principal
sudoku.o: sudoku.c lire_ecrire.h gestion_sudoku.h constantes.h  listecircu.h liste.h sudoku.h generateur_sudoku.h afficher.h
	gcc ${CFLAGSGR} $*.c

# Compilation des différents.o
afficher.o: afficher.c afficher.h gestion_sudoku.h constantes.h   listecircu.h liste.h sudoku.h
	gcc ${CFLAGSGR} $*.c

gestion_sudoku.o: gestion_sudoku.c gestion_sudoku.h  listecircu.h liste.h sudoku.h
	gcc ${CFLAGS} $*.c

lire_ecrire.o: lire_ecrire.c lire_ecrire.h gestion_sudoku.h  listecircu.h sudoku.h
	gcc ${CFLAGS} $*.c

listecircu.o : listecircu.c listecircu.h
	gcc ${CFLAGS} $*.c
	
liste.o : liste.h liste.c
	gcc ${CFLAGS} $*.c
	
generateur_sudoku.o : generateur_sudoku.c generateur_sudoku.h
	gcc ${CFLAGS} $*.c


# Le clean
clean:
	rm -f *.o
	rm -f sudoku


# Pour faire un zip
# Mettre son nom à la place de SUDOKU
LENOM=Addouche_Mouloud
zip:
	rm -rf ${LENOM}
	rm -rf ${LENOM}.zip
	mkdir ${LENOM}
	cp Makefile ${LENOM}
	cp *.h *.c ${LENOM}
	cp A_LIRE.txt ${LENOM}
	zip -r ${LENOM}.zip ${LENOM}
	rm -rf ${LENOM}
