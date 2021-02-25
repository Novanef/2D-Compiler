#include"instructionp2d.h"
#define MAX 1000

//@ requires un chemin de fichier correct chemin et un pointeur vers une pile p
//@ assigns  un pointeur vers un fichier, quatre entiers, une grille de caractères, un tableau de caractères et une coordonnée
//@ ensures interprète le fichier correspondant à chemin s'il existe. Si le chemin est incorrect, affiche l'erreur et met fin au programme en retournant EXIT_FAILURE
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
    grille[i] = (char*)calloc(largeur,sizeof(char));
  }
  char s[MAX];
  int count = 0;
  while(fgets(s,MAX,fichier) != NULL) {//se termine lorsque l'on atteint la fin du fichier
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
  while(grille[position.x][position.y] != '@') {//se termine lorsque le carctère de grille à position est '@'
    pas(grille,  largeur, hauteur, &position, &direction,  p, &mode_ascii);
    deplacement(direction,largeur,hauteur, &position);
  }
  //on libère la mémoire utilisée en faisant attention aux structures complexes
  for (int i = 0; i < hauteur; i++) {
    free(grille[i]);
  }
  free(grille);
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
