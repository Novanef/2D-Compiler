#include<string.h>
#include"instructionp2d.h"
#define MAX 1000

//@ requires une grille de caractere char, sa largeur, sa hauteur, une coordonnée position et une pile p 
//@ assigns nothing
//@ ensures affiche char avec des axes gradués de 5 en 5, indique la position sur les axes et en dessous de la grille et affiche la pile
void affichage(char** grille, int largeur, int hauteur, coord position, pile p){
  for (int i = 0; i<largeur; i++) {
    if (i%5==0) {
      if (i < 11) {
	printf("   %i ",i);
      }
      else {
	printf("  %2i ",i);
      }
    }
  }
  printf("\n");
  printf("   ");
  for (int i = 0; i<largeur; i++) {
    if (position.y == i) {
      printf("v");
    }
    else {
      if (i%5==0) {
	printf("|");
      }
      else {
	printf(" ");
      }
    }
  }
  printf("\n");
  for(int i = 0; i <hauteur; i++) {
    if (i%5 == 0) {
      printf("%2i" ,i);
      if (position.x == i) {
      printf(">");
      }
      else {
	printf("-");
      }
    }
    else {
      if (position.x == i) {
      printf("  >");
      }
      else {
	printf("   ");
      }
    }
    printf("%s\n",grille[i]);
  }
  printf("\n");
  affpile(p);
  printf("\n");
  printf("x: %i, y: %i\n",position.x,position.y);
}

//@ requires un chemin de fichier correct chemin et une pile p 
//@ assigns un pointeur sur le fichier, neuf entiers, une grille de caractères, sept tableaux de caractères, une grille d'entier, une coordonnée, une pile_sauvegarde, deux sauvegardes 
//@ ensures lance le debuggeur sur le fichier correspondant au chemin chemin s'il existe et attends les commandes entrées par l'utilisateur. Se termine lorsque le programme p2d se termine (ie l'arrivée sur le caractère '@') ou lorsque l'utilisateur entre "quit". Si le chemin est incorrect, affiche l'erreur et met fin au programme en retournant EXIT_FAILURE
void exec(char* chemin, pile* p) {
  FILE* fichier = fopen(chemin, "r+");
  if (fichier == NULL) {
    fprintf(stderr,"Fichier introuvable.\n");
    exit( EXIT_FAILURE );
  }
  int largeur, hauteur;
  int mode_ascii = 0;
  fscanf(fichier, "%d %d\n",&largeur, &hauteur);
  char** grille = (char**)malloc(hauteur * sizeof(char*));
  for (int i = 0; i < hauteur; i++) {
    grille[i] = (char*)calloc(largeur+1,sizeof(char));
  }
  char s[MAX];
  int** breakpoints = (int**)malloc(hauteur * sizeof(int*));
  for (int i = 0; i < hauteur; i++) {
    breakpoints[i] = (int*)calloc(largeur,sizeof(int));
  }
  int count = 0;
  while(fgets(s,MAX,fichier) != NULL) {//se termine lorsque l'on atteint le bout du fichier
    for (int i = 0; i < largeur; i++) {
      grille[count][i] = s[i];
    }    
    count++;
  }
  fclose(fichier);
  coord position;
  position.x = 0;
  position.y = 0;
  int direction = 2;
  char commande[MAX];
  char* fincommande;
  char commandeprec[MAX] = "step";
  pile_sauvegarde historique = NULL;
  while(grille[position.x][position.y] != '@') {//se termine lorsque le caractère de grille à position est '@'
    affichage(grille, largeur, hauteur, position, *p);
    fgets(commande,MAX,stdin);
    fincommande = strchr(commande,'\n');
    *fincommande = '\0';
    //on commence à déterminer quelle commande a été rentrée
    if (strlen(commande) == 0) {
      strcpy(commande,commandeprec);
    }
    if (!strcmp(commande,"step")) {
      
      empile_sauvegarde(&historique,grille,position,direction,*p,mode_ascii);
      pas(grille,  largeur, hauteur, &position, &direction,  p, &mode_ascii);
      deplacement(direction,largeur,hauteur, &position);
    }
    else {
      //pour déterminer si la commande commence par "step" je stock ses quatre premiers carctères dans un string pour ensuite le comparer à "step"
      char temp[5] = {'0','0','0','0','\0'};
      strncpy(temp,commande,4);
      if (!strcmp(temp,"step")) {
	int n;
	sscanf(commande,"step %i",&n);
	for (int i = 0; i<n;i++) {
	  empile_sauvegarde(&historique,grille,position,direction,*p,mode_ascii);
	  pas(grille,  largeur, hauteur, &position, &direction,  p, &mode_ascii);
	  deplacement(direction,largeur,hauteur, &position);
	  if (breakpoints[position.x][position.y] || grille[position.x][position.y] == '@') {
	    break;
	  }
	}
      }
      else {
	if (!strcmp(commande,"run")) {
	  while(grille[position.x][position.y] != '@') {//se termine lorsque le caractère de grille à position est '@'
	    empile_sauvegarde(&historique,grille,position,direction,*p,mode_ascii);
	    affichage(grille, largeur, hauteur, position, *p);
	    pas(grille,  largeur, hauteur, &position, &direction,  p, &mode_ascii);
	    deplacement(direction,largeur,hauteur, &position);
	    if (breakpoints[position.x][position.y]) {
	    break;
	    }
	  }
	}
	else {
	  if(!strcmp(commande,"quit")) {
	    goto fin;
	  }
	  else {
	    if(!strcmp(commande,"restart")) {
	      while (*p != NULL) {//se termine lorsque l'on atteint le bout de la pile p
		depile(p);
	      }
	      exec(chemin,p);
	      goto fin;
	    }
	    else{
	      //même méthode que pour step n
	      char temp2[11] = {'0','0','0','0','0','0','0','0','0','0','\0'};
	      strncpy(temp2,commande,10);
	      if (!strcmp(temp2,"breakpoint")) {
		int x;
		int y;
		sscanf(commande,"breakpoint %i %i",&x,&y);
		if ( 0<= x && x<hauteur && 0<= y && y<largeur) {
		  breakpoints[x][y] = 1;
		}
		else {
		  printf("breakpoint : Coordonnées en dehors de la grille\n");
		};
	      }
	      else {
		//même méthode que pour step n et breakpoint x y
		char temp3[9] = {'0','0','0','0','0','0','0','0','\0'};
		strncpy(temp3,commande,8);
		if (!strcmp(temp3,"removebp")) {
		  int x;
		  int y;
		  sscanf(commande,"removebp %i %i",&x,&y);
		  breakpoints[x][y] = 0;
		}
		else {
		  if (!strcmp(commande,"prec")) {
		    if (historique == NULL) {
		      printf("prec : aucune étape précédent celle-ci.\n");
		    }
		    else {
		      sauvegarde sauv = depile_sauvegarde(&historique);
		      grille = sauv.grille;
		      position = sauv.position;
		      direction = sauv.direction;
		      int tempi;
		      while (*p!=NULL){//se termine lorsque l'on atteint le bout de la pile p
			depile(p);
		      }
		      while(sauv.p != NULL) {//se termine lorsque l'on atteint le bout de la pile sauv.p
			tempi = depile(&(sauv.p));
			empile(p,tempi);
		      }
		      mode_ascii = sauv.mode_ascii;
		    }
		  }
		  else {
		    //même méthode que pour step n, breakpoint x y et removebp x y
		    char temp4[5] = {'0','0','0','0','\0'};
		    strncpy(temp4,commande,4);
		    if (!strcmp(temp4,"prec")) {
		      int n;
		      sscanf(commande,"prec %i",&n);
		      sauvegarde sauv;
		      for (int i = 0; i < n; i++){
			if (historique == NULL) {
			  printf("prec %i : aucune étape restante, ne recule que de %i étape(s).\n",n,i);
			  break;
			}
			else {
			  sauv = depile_sauvegarde(&historique);
			  grille = sauv.grille;
			  position = sauv.position;
			  direction = sauv.direction;
			  int tempi;
			  while (*p != NULL) {//se termine lorsque l'on atteint le bout de la pile p
			    depile(p);
			  }
			  while(sauv.p != NULL) {//se termine lorsque l'on atteint le bout de la pile sauv.p
			    tempi = depile(&(sauv.p));
			    empile(p,tempi);
			  }
			  mode_ascii = sauv.mode_ascii;
			}
		        if (breakpoints[position.x][position.y]) {
			  break;
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  strcpy(commandeprec,commande);
  }
 fin:;
  //on libère la mémoire utilisée en faisant attention aux structures complexes
  for (int i = 0; i < hauteur; i++) {
    free(grille[i]);
  }
  free(grille);
  for (int i = 0; i < hauteur; i++) {
    free(breakpoints[i]);
  }
  free(breakpoints);
  sauvegarde sauv_free;
  while(historique != NULL) {//se termine lorsque l'on atteint le bout de la pile de sauvegarde historique
    sauv_free = depile_sauvegarde(&historique);
    while(sauv_free.p != NULL) {//se termine lorsque l'on atteint le bout de la pile sauv_free.p
       depile(&(sauv_free.p));
    }
  }
}
	

int main(int argc, char*argv[]) {
  if (argc <= 1) {
    printf("Usage : %s chemin_du_fichier\n",argv[0]);
  }
  else {
    pile p = creerpile();
    exec(argv[1], &p);
    // on libère la mémoire allouée à la pile
    while(p != NULL) {//se termine lorsque l'on atteint le bout de la pile p
      depile(&p);
    }
  }
  return 0;
}
