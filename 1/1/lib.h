#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
struct Particle;
double max_(double a, double b);
void make_orcode(int orrcode, int orcode[6]);
void sort_abbr(struct Particle *Particles);
void sort_orcode(struct Particle *Particles);
int delta_m(struct Particle A, struct Particle B);
int cmp_orcode(struct Particle A, struct Particle B);
int my_strcmp(struct Particle A, struct Particle B);
void make_parent(struct Particle *A, int i);
void print_(struct Particle *A);
struct Particle *make_part();
