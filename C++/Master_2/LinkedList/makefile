# Définition des variables
CXX = g++                  # Le compilateur à utiliser
CXXFLAGS = -Wall -std=c++17 # Options de compilation : afficher tous les avertissements et utiliser le standard C++11
TARGET = main         # Nom de l'exécutable final
SRCS = main.cpp  # Liste des fichiers source
OBJS = $(SRCS:.cpp=.o)      # Fichiers objets associés

# Règle par défaut
all: $(TARGET)

# Compilation des fichiers objets à partir des fichiers sources
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Lien pour créer l'exécutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Règle pour exécuter le programme après la compilation
run:
	$(MAKE) all
	./$(TARGET)

# Nettoyage des fichiers générés
clean:
	rm -f $(OBJS) $(TARGET)

# Nettoyage complet
fclean: clean
	rm -f $(TARGET)

# Règle pour recompiler tout
re: fclean all