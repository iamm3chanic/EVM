/* Main.cpp */
/*
 *    Задание 2.14. Создать файловую систему по аналогии 
 *    с файловой системой EXT(UNIX), т.е. на основе множеств 
 *    блоков с древовидным хранением номеров файловых блоков.
 *
 *    Created on: 20.10.2020
 *    Author: iamm3chanic
 */
#include "INode.h"

/*
Реализованы функции
-mkdir       - creates directory
-touch       - creates file
-ls          - list of nodes in current dir 
-lsrecursive - list of nodes and their content in current dir
-edit        - write something to file
-pwd         - print working directory
-cd          - change directory
-cdup        - move one directory up
-cat         - show file content
-mov         - move something somewhere
-rm          - remove something
-help        - show help message
*/
node **inodes =init_n(inodes);   //отвечает за хранение узлов
char **blocks = init_b(blocks);  //отвечает за хранение имен, содержания файлов и текущего пути path
int NODE_FLAG = 1;               //счетчик по массиву узлов
int CHAR_FLAG = 1;               //счетчик по массиву имен


int main() {


    char *rootName=blocks[0];
    strcpy(rootName, "/");
  
    inodes[0]->type = Folder;
    inodes[0]->name = rootName;
    inodes[0]->numberOfItems = 0;
    inodes[0]->size = 0;
    inodes[0]->date = time(NULL);
    inodes[0]->content =NULL;
    inodes[0]->previous = NULL;
    inodes[0]->parent = NULL;
    inodes[0]->next = NULL;
    inodes[0]->child = NULL;

    node *currentFolder = inodes[0];

    //char *path = (char *) malloc(sizeof(char)*2);
    char *path = blocks[CHAR_FLAG++];
    strcpy(path, "/");

    printf("\033[1;34mWELCOME TO COMMAND LINE!\nWrite \"help\" to get list of all commads.\033[0m\n");

    while ((CHAR_FLAG<=NBLOCKS)&&(NODE_FLAG<=NNODES)) {

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
        } else if (strncmp(command, "cat", 3) == 0) {
            currentFolder->cat(currentFolder, command);
        } else if (strncmp(command, "help", 4) == 0) {
            help();
        } else if (strcmp(command, "exit") == 0){
            free(command);
            clean(inodes, blocks);
            return 0;
        }
        free(command);
    }
fprintf(stderr, "\033[1;31mNo space left in filesystem!\n\033[0m");
    return 0;
}
