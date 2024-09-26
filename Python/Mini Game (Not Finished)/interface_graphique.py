from grille import Grille
from jeu import Jeu
import ia

import gi
gi.require_version('Gtk','3.0')
from gi.repository import Gtk

def dessiner_grille(cr,situation,cote_carre):
    
    pass

if __name__ =='__main__':
    G=Grille(10,10)
    J=Jeu()
    win = Gtk.Window()
    win.set_size_request(400, 300)
    win.set_title("ceci est mon titre")
    
    def b1_on_clicked(widget):
        print ("Bouton b1 cliqué")
    
    vbox=Gtk.VBox()
    win.add(vbox)
    hbox=Gtk.HBox()
    #vbox.pack_start(hbox, expand=True, fill=True, padding=0)
    #b1 = Gtk.Button(label="Nouvelle Partie")
    #hbox.pack_start(b1, expand=True, fill=True, padding=0)
    #b1.connect("clicked", b1_on_clicked)
    
    
    darea = Gtk.DrawingArea()
    vbox.pack_start(darea,expand=True, fill=True, padding=0)
    
    nb_line_v=G.largeur
    nb_line_h=G.hauteur
    
    def darea_on_draw(darea, cr):
        print("Evenement draw recu")
        
        cr.rectangle(0,0,400,300)
        cr.stroke()
        
        for i in range(1,nb_line_v):
            cr.move_to(i*(400)/nb_line_v,0)
            cr.line_to(i*(400)/nb_line_v,300)
            cr.stroke()
            
        for i in range(1,nb_line_h):
            cr.move_to(0,i*(300)/nb_line_h)
            cr.line_to(400,i*(300)/nb_line_h)
            cr.stroke()
    
    darea.connect("draw", darea_on_draw)
    
    
    
    
    '''Fin du Main'''
    
    win.connect("destroy", Gtk.main_quit)
    win.show_all()
    Gtk.main()
    
    