import random


def decider_mouvement(situations,position,zombie): 
    """
    situations: la grille représenté avec des 0,1,2,3 respéctivement pour les cases libres, les murs, les humains ou les zombies.
    position: position actuelle du joueur
    zombie: True si le joueur est un zombie, False sinon 
    """
    choix = random.randint(0, 4)
    return "NSEOI"[choix]
     
'''if __name__ == "__main__":
   random.seed()
    for i in range(10):
        print(decider_mouvement(((0,)*10)*10,(1,1),True))'''
