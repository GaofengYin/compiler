#include "value.h"
#include <stdio.h>
#include <stdlib.h>

//class

void class(){
   FILE * fp;

   fp = fopen ("task.yaml", "a");
   fprintf(fp, "---\n");
   
   fclose(fp);
}

//static value

void present(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "present\n");

    fclose(fp);
}

void started(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "started\n");

    fclose(fp);
}

void directory(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "directory\n");

    fclose(fp);
}

void absent(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "absent\n");

    fclose(fp);
}

void install(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "installed\n");

    fclose(fp);
}

void latest(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "latest\n");

    fclose(fp);
}

void stopped(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "stopped\n");

    fclose(fp);
}

void yes(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "yes\n");

    fclose(fp);
}

void no(){
    FILE * fp;

    fp = fopen("task.yaml", "a");
    fprintf(fp, "no\n");

    fclose(fp);
}

void pword(char *word){
   FILE * fp;

   fp = fopen ("task.yaml", "a");
   fprintf(fp, "%s\n", word);
   
   fclose(fp);
}

void pfile(char *file){
   FILE * fp;

   fp = fopen ("task.yaml", "a");
   fprintf(fp, "%s\n", file);
   
   fclose(fp);
}

void pdirectory(char *directory){
   FILE * fp;

   fp = fopen ("task.yaml", "a");
   fprintf(fp, "%s\n", directory);
   
   fclose(fp);
}

void pnumber(int *number){
   FILE * fp;

   fp = fopen ("task.yaml", "a");
   fprintf(fp, "%d\n", number);
   
   fclose(fp);
}

void designation(char *word){
   FILE * fp;

   fp = fopen ("task.yaml", "a");
   fprintf(fp, "%s\n", word);
   
   fclose(fp);
}

void words(char *word){
   FILE * fp;

   fp = fopen ("task.yaml", "a");
   fprintf(fp, "  - %s\n", word);
   
   fclose(fp);
}
