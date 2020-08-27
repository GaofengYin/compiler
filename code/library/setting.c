#include "setting.h"
#include <stdio.h>
#include <stdlib.h>

//setting

void name(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "   name: ");

    fclose(fp);
}

void path(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "   path: ");

    fclose(fp);
}

void state(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "   state: ");

    fclose(fp);
}
void enable(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "   enabled: ");

    fclose(fp);
}

void mode(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "   mode: ");

    fclose(fp);
}

void name_word(char *word){
   FILE * fp;

   fp = fopen ("task.yaml", "a");
   fprintf(fp, "   name: %s \n ", word);
   
   fclose(fp);
}

void group(){
   FILE * fp;

   fp = fopen ("task.yaml", "a");
   fprintf(fp, "   group: ");
   
   fclose(fp);
}

void owner(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "   owner: ");

    fclose(fp);
}