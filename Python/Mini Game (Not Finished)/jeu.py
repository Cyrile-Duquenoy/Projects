from grille import Grille
import ia

'''
Fonctionnel
Reste à associé une strat à chaque joueur
'''   

class Jeu():
    def  ajouter_joueur(self, ma_fonction):
        G.ajouter_joueur()
    
    def get_score(self,joueur):
        return self.scores[joueur]
    
    def nouvelle_partie(self,nb_zombies):
        self.nb_players=10
        self.nb_tours_max=10
        self.tour=1
        self.scores={}
        G=Grille(10,10)
        self.G=G
        for murs in range(20):
            G.ajouter_mur()
        for nb_players in range(10):
            G.ajouter_joueur()
            self.scores[nb_players+1]=0
        for i in range(nb_zombies):
            G.transformer_zombie()
        G.afficher()
        print("position initiale joueur 1" ,G.joueurs)
        print()
        self.next_mvmt=1
    
    def partie_finie(self):
        if self.tour>self.nb_tours_max:
            return True
        else :
            x=0
            for i in self.G.joueurs:
                if self.G.est_zombie(i):
                    x+=1
            if x==self.G.nb_joueurs:
                return True
            else : return False

    def get_grille(self):
        return J.G.afficher()

    def prochain_mouvement(self):
        
        if self.partie_finie():
            print("Nombre de tours maximal atteint, partie terminé")
            return
        
        G=self.G
        x=ia.decider_mouvement(G.get_situation(),G.joueurs[self.next_mvmt][1],G.est_zombie(1))
        y=G.deplacer_et_manger(self.next_mvmt,x)
        y
        print("Joueur", self.next_mvmt, "décide", x)
        if G.joueurs[self.next_mvmt][0]==2:
            self.scores[self.next_mvmt]+=1
        elif G.joueurs[self.next_mvmt][0]==3 and y==True:
            self.scores[self.next_mvmt]+=15
        elif G.joueurs[self.next_mvmt][0]==3 and y==False:
            self.scores[self.next_mvmt]-=15
        
        #On passe au joueur suivant
        if 0<self.next_mvmt<10:
            self.next_mvmt+=1
        elif self.next_mvmt==10:
            self.next_mvmt=1
            
            
"""_________________________________Main____________________________________"""



J=Jeu()
J.nouvelle_partie(3)


'''
Mettre ce qui suit dans une fonction
Ca sera plus lisible
'''


for i in range(J.nb_tours_max):
    for i in range(J.nb_players):
        print()
        print("Tour", J.tour)
        J.prochain_mouvement()
        print("position joueur ",i+1, "au déplacement" ,i+1)
        print(J.G.get_position_joueur(i+1))
        J.get_grille()
        
        
        print("score",J.get_score(i+1))
        if J.partie_finie():
            print("Partie finie")
    print()
    J.tour+=1

print("score",J.G.joueurs)
print("score",J.scores)
