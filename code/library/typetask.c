#include "typetask.h"
#include <stdio.h>
#include <stdlib.h>

//type task

void package(){
   FILE * fp;

   fp = fopen ("task.yaml", "a");
   fprintf(fp, "- name: install a package\n  package:\n");
   
   fclose(fp);
}

void service(){
   FILE * fp;

   fp = fopen ("task.yaml", "a");
   fprintf(fp, "- name: check service\n  service:\n");
   
   fclose(fp);
}

void file(){
    FILE * fp;

    fp = fopen ("task.yaml", "a");
    fprintf(fp, "- name: check a file\n  file:\n");

    fclose(fp);
}

void packages(char *word){
   FILE * fp;

   fp = fopen ("task.yaml", "a");
   fprintf(fp, "- name: install/remove a package\n  package: \n   name: %s\n", word);
   
   fclose(fp);
}

void services(char *word){
   FILE * fp;

   fp = fopen ("task.yaml", "a");
   fprintf(fp, "- name: check/stop a service\n  service: \n   name: %s\n", word);
   
   fclose(fp);
}