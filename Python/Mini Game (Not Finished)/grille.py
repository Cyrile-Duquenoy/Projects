import random
'''_____________________________Classe_Grille_______________________________'''

class Grille():
    def __init__(self, largeur, hauteur):
        self.largeur=largeur
        self.hauteur=hauteur
        self.grille=[]
        self.joueurs={} #{numéro joueur : [zombie ou joueur, [position]]}
        for i in range(largeur):
            self.grille.append([0]*hauteur)
        
    def get_hauteur(self):
        return self.hauteur
    
    def get_largeur(self):
        return self.largeur
    
    def position(self,x,y):
        return [x,y]
        
    def position_libre(self, position):
        #Vérifie si la position indiquée est libre
        if (self.grille[position[0]][position[1]] == 0):
            return True
        else :
            return False
    
    def position_libre_aleatoire(self):
        #Renvoie aléatoirement une position libre
        P=0
        free_position=[]
        for i in range(self.largeur):
            for j in range(self.hauteur):
                if G.grille[i][j]==0:
                    P=P+1
                    free_position.append(self.position(i,j))
        if P==0 :
            print("Toutes les cases sont occupées")
            pass
        else :
            n=random.randint(0,P-1)
            return free_position[n]
            
    
    def ajouter_mur(self, position=None):
        if position !=None and ( (position[0] > self.largeur or position[1] > self.hauteur or position[0] <= 0 or position[1] <= 0 ) ) :
            print("Erreur de coordonnées")
            ValueError
        if position == None :
            self.grille[random.randint(0,self.largeur - 1)][random.randint(0,self.hauteur - 1)]=1
        else :
            if 0 < position[0] <= self.largeur and 0 < position[1] <= self.hauteur :
                self.grille[position[0] - 1][position[1] - 1] = 1
            else :
                ValueError
            
    def nb_joueurs(self):
        #compte et renvoie le nombre de joueurs
        nb_joueurs=0
        for i in range(self.largeur):
            for j in range(self.hauteur):
                if self.grille[i][j]==2:
                    nb_joueurs+=1
        return nb_joueurs
           
    def ajouter_joueur(self, position=None):
        if position != None and ( (position[0]>self.largeur or position[1]>self.hauteur or position[0]<=0 or position[1]<=0 ) ) :
            print("Erreur de coordonnées")
            ValueError
        n=self.nb_joueurs()
        if position == None :
            x=random.randint(0,self.largeur - 1)
            y=random.randint(0,self.hauteur - 1)
            if self.grille[x][y]==0:
                position=[x,y]
                self.grille[x][y]=2
                self.joueurs[n+1]=[2,[x+1,y+1]]
            else :
                self.ajouter_joueur(position)
        else :
            if 0<position[0]<=self.largeur and 0<position[1]<=self.hauteur :
                if self.position_libre([position[0] -1 ,position[1] -1]):
                    self.grille[position[0] -1 ][position[1] -1]=2
                    self.joueurs[n+1]=[2,position]
            else :
                self.ajouter_joueur(self,position=None)
    
    def get_position_joueur(self,joueur):
        return self.joueurs[joueur][1]
    
    def transformer_zombie(self, joueur=None):
        if joueur == None:
            x=random.randint(1,self.nb_joueurs())
            if self.joueurs[x][0]==2:
                self.joueurs[x][0]=3
                self.grille[self.get_position_joueur(x)[0] -1 ][self.get_position_joueur(x)[1] -1]=3
            else :
               self.transformer_zombie(joueur)
        else :
            self.joueurs[joueur][0]=3
            self.grille[self.get_position_joueur(joueur)[0] -1 ][self.get_position_joueur(joueur)[1] -1]=3
            
    
    def get_joueur_position(self, position):
        for key, val in self.joueurs.items():  
            if position == val[1]:
                return key
    
    def get_situation(self):
        situation=[]
        for i in range(self.largeur):
            situation.append(self.grille[i][:])
        return situation
    
    def afficher(self):
        for i in range(self.largeur):
            print(self.grille[i][:])
        
    def deplacer_et_manger(self,joueur,direction):
        if direction=="N": #Déplacer vers le Nord
            x=self.joueurs[joueur][1][0]-1
            y=self.joueurs[joueur][1][1]           
            if 1<self.get_position_joueur(joueur)[0]:
                if not self.est_zombie(joueur):
                    if self.position_libre([x-1,y-1]):
                        self.grille[x-1][y-1]=2
                        self.grille[x][y-1]=0
                        self.joueurs[joueur][1]=[x,y]
                        return False
                else :
                    if self.get_joueur_position([x,y]) == 2:
                        self.transformer_zombie(self.get_joueur_position([x,y]))
                        return True
                    if self.position_libre([x-1,y-1]):
                        self.grille[x-1][y-1]=3
                        self.grille[x][y-1]=0
                        self.joueurs[joueur][1]=[x,y]
                        return False
                        
        
        if direction=="E": #Déplacer vers l'Est
            x=self.joueurs[joueur][1][0]
            y=self.joueurs[joueur][1][1]+1
            if self.get_position_joueur(joueur)[1]<self.largeur:
                if not self.est_zombie(joueur):
                    if self.position_libre([x-1,y-1]):
                        self.grille[x-1][y-1]=2
                        self.grille[x-1][y-2]=0
                        self.joueurs[joueur][1]=[x,y]
                        return False
                else :
                    if self.get_joueur_position([x,y]) == 2:
                        self.transformer_zombie(self.get_joueur_position([x,y]))
                        return True
                    if self.position_libre([x-1,y-1]):
                        self.grille[x-1][y-1]=3
                        self.grille[x-1][y-2]=0
                        self.joueurs[joueur][1]=[x,y]
                        return False
                    
        if direction == "O": #Déplace vers l'Ouset
            x=self.joueurs[joueur][1][0]
            y=self.joueurs[joueur][1][1]-1
            if 1<self.get_position_joueur(joueur)[1]<=self.largeur :
                if not self.est_zombie(joueur):
                    if self.position_libre([x-1,y]):
                        self.grille[x-1][y-1]=2
                        self.grille[x-1][y]=0
                        self.joueurs[joueur][1]=[x,y]
                        return False
                else :
                    if self.get_joueur_position([x,y]) == 2:
                        self.transformer_zombie(self.get_joueur_position([x,y]))
                        return True
                    if self.position_libre([x-1,y]):
                        self.grille[x-1][y-1]=3
                        self.grille[x-1][y]=0
                        self.joueurs[joueur][1]=[x,y]
                        return False
                    
        if direction == "S" : #Déplace vers le Sud
            x=self.joueurs[joueur][1][0]+1
            y=self.joueurs[joueur][1][1]
            if self.get_position_joueur(joueur)[0]<self.hauteur :
                if not self.est_zombie(joueur):
                    if self.position_libre([x-1,y-1]):
                        self.grille[x-1][y-1]=2
                        self.grille[x-2][y-1]=0
                        self.joueurs[joueur][1]=[x,y]
                        return False
                else :
                    if self.get_joueur_position([x,y]) == 2:
                        self.transformer_zombie(self.get_joueur_position([x,y]))
                        return True
                    if self.position_libre([x-1,y-1]):
                        self.grille[x-1][y-1]=3
                        self.grille[x-2][y-1]=0
                        self.joueurs[joueur][1]=[x,y]
                        return False
                        
            if direction == "I" : #Reste immobile
                pass
                
    def est_zombie(self,joueur):
        if self.joueurs[joueur][0]==3:
            return True
        else :
            return False
    
    def tous_zombie(self):
        for i in self.joueurs :
            if self.joueurs[i] != 3 :
                return False   
'''_____________________________________MAIN________________________________'''


if __name__ == "__main__":
            
    
    G=Grille(5,5)
    
    print(G.grille)
    print(G.largeur)
    print(G.position_libre_aleatoire())
    print(G.grille)
    G.ajouter_mur([3,2])
    print(G.grille)
    G.ajouter_joueur([3,3])
    print(G.grille)
    print(G.nb_joueurs())
    print(G.get_situation())
    G.ajouter_joueur([2,3])
    #G.transformer_zombie(1)
    G.afficher()
    print(G.nb_joueurs())
    print(G.tous_zombie())
    print(G.joueurs)
    print(G.joueurs)
    print(G.get_position_joueur(1))
    print(G.get_joueur_position([3,4]))
    G.afficher()
    print("")
    
    G.deplacer_et_manger(1,"E")
    print(G.joueurs)
    G.afficher()
    print(G.joueurs[1][0])
    

