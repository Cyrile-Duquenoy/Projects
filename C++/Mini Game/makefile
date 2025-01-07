# Définition des variables
CXX = g++                  # Le compilateur à utiliser
CXXFLAGS = -Wall -std=c++17 # Options de compilation : afficher tous les avertissements et utiliser le standard C++23
TARGETS = main_grille main_player main_jeu # Liste des exécutables
SRCS1 = main_grille.cpp
SRCS2 = main_player.cpp 
SRCS3 = class_jeu.cpp 

# Règles par défaut : compiler tous les exécutables
all: $(TARGETS)

# Règle générique pour chaque exécutable
main_grille: $(SRCS1)
	$(CXX) $(CXXFLAGS) $^ -o $@

main_player: $(SRCS2)
	$(CXX) $(CXXFLAGS) $^ -o $@

main_jeu: $(SRCS3)
	$(CXX) $(CXXFLAGS) $^ -o $@


# Règle pour exécuter un exécutable spécifique
run-%: %
	./$<

# Nettoyage des fichiers générés
clean:
	rm -f $(TARGETS) *.o

# Nettoyage complet et recompilation
re: clean all
