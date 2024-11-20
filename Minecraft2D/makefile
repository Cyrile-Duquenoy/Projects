# Si vous travaillez sur Windows, remplacer la ligne suivante par SYSTYPE=WIN32 ...
SYSTYPE = UNIX

#-------------------------- C O N F I G U R A T I O N -------------------------

ifeq ($(SYSTYPE),UNIX)

    # Unix/X11 systems (linux, Mac OS X, Cygwin, etc)               # SECTION A
    CC     = gcc
    CFLAGS = -Wall -W -std=c99 -pedantic -O2 -g 
    LIBS   = -lX11 -lXext
    LIBS_I = -lm

else ifeq ($(SYSTYPE),OSX_MACPORTS)

    # Mac OS X with macports
    CC     = gcc
    CFLAGS = -Wall -W -std=c99 -pedantic -O2 -g -I/opt/local/include
    LIBS   = -lX11 -lXext -L/opt/local/lib
    LIBS_I = -lm

else ifeq ($(SYSTYPE),WIN32)

    # Windows, all versions                                         # SECTION B
    CC     = gcc
    CFLAGS = -Wall -W -std=c99 -pedantic -O2
    LIBS   = -lgdi32
    LIBS_I = -lmsimg32

endif


minecraft2D : minecraft_core.c minecraft_graphics.c minecraft_main.c minecraft_terminal.c ez-image.c ez-draw.c
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LIBS_I)

fenetre_titre : fenetre_titre.c ez-image.c ez-draw.c
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LIBS_I)

fenetre_titre_interactive : fenetre_titre_interactive.c ez-image.c ez-draw.c
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LIBS_I)

grille_vide : grille_vide.c ez-image.c ez-draw.c
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LIBS_I)

ecran_jeu : ecran_jeu.c ez-image.c ez-draw.c
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LIBS_I)

grille_pleine : grille_pleine.c ez-image.c ez-draw.c
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LIBS_I)

# A COMPLETER

clean :
	rm -f minecraft2D fenetre_titre fenetre_titre_interactive grille_vide ecran_jeu grille_pleine
