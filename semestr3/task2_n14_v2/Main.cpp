/* Main.cpp */
/*
 *    Задание 2.14. Создать файловую систему по аналогии 
 *    с файловой системой EXT(UNIX), т.е. на основе множеств 
 *    блоков с древовидным хранением номеров файловых блоков.
 *
 *    Created on: 15.10.2020
 *    Author: iamm3chanic
 */
#include "INode.h"

int main() {

    node *root = (node*) malloc(sizeof(node));

    char *rootName = (char *) malloc(sizeof(char)*2);
    strcpy(rootName, "/");
    root->type = Folder;
    root->name = rootName;
    root->numberOfItems = 0;
    root->size = 0;
    root->date = time(NULL);
    root->content =NULL;
    root->previous = NULL;
    root->parent = NULL;
    root->next = NULL;
    root->child = NULL;

    node *currentFolder = root;

    char *path = (char *) malloc(sizeof(char)*2);
    strcpy(path, "/");

    printf("\033[1;34mWELCOME TO COMMAND LINE!\nWrite \"help\" to get list of all commads.\033[0m\n");

    while (1) {

        printf("> ");
        char *command = getString();

        if (strncmp(command, "mkdir", 5) == 0) {
            currentFolder->mkdir(currentFolder, command);
        } else if (strncmp(command, "touch", 5) == 0) {
            currentFolder->touch(currentFolder, command);
        } else if (strcmp(command, "ls") == 0) {
            currentFolder->ls(currentFolder);
        } else if (strcmp(command, "lsrecursive") == 0) {
            currentFolder->lsrecursive(currentFolder, 0);
        } else if (strncmp(command, "edit", 4) == 0 ) {
            currentFolder->edit(currentFolder, command);
        } else if (strcmp(command, "pwd") == 0) {
            pwd(path);
        } else if (strcmp(command, "cdup") == 0) {
            currentFolder = currentFolder->cdup(currentFolder, &path);
        } else if (strncmp(command, "cd", 2) == 0){
            currentFolder = currentFolder->cd(currentFolder, command, &path);
        } else if (strncmp(command, "rm", 2) == 0) {
            currentFolder->rm(currentFolder, command);
        } else if (strncmp(command, "mov", 3) == 0) {
            mov(currentFolder, command);
        } else if (strncmp(command, "help", 4) == 0) {
            help();
        } else if (strcmp(command, "exit") == 0){
            free(command);
            currentFolder->freeNode(root);
            free(path);
            break;
        }
        free(command);
    }

    return 0;
}
