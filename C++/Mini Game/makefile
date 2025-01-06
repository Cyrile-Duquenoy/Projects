# Définition des variables
CXX = g++                  # Le compilateur à utiliser
CXXFLAGS = -Wall -std=c++17 # Options de compilation : afficher tous les avertissements et utiliser le standard C++23
TARGETS = main_grille main_player # Liste des exécutables
SRCS1 = main_grille.cpp
SRCS2 = main_player.cpp # Sources pour main1


# Règles par défaut : compiler tous les exécutables
all: $(TARGETS)

# Règle générique pour chaque exécutable
main_grille: $(SRCS1)
	$(CXX) $(CXXFLAGS) $^ -o $@

main_player: $(SRCS1)
	$(CXX) $(CXXFLAGS) $^ -o $@


# Règle pour exécuter un exécutable spécifique
run-%: %
	./$<

# Nettoyage des fichiers générés
clean:
	rm -f $(TARGETS) *.o

# Nettoyage complet et recompilation
re: clean all
