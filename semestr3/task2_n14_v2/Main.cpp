/* Main.cpp */
/*
 *    Задание 2.14. Создать файловую систему по аналогии 
 *    с файловой системой EXT(UNIX), т.е. на основе множеств 
 *    блоков с древовидным хранением номеров файловых блоков.
 *
 *    Created on: 15.10.2020
 *    Author: Anfisa
 */
#include "INode.h"
 
/*Каждый inodes указывает на несколько первых блоков в массиве blocks.
Суть: в этой реализации не должна использоваться malloc.*/
int main() {

    //node inodes[NNODES]; 
    node **inodes=NULL; char **blocks=NULL;
    //char blocks[NBLOCKS][BLOCK_SIZE];
    //initialize(inodes, blocks);
    inodes = init_n(inodes);
    blocks = init_b(blocks);
    /*
    char** blocks;
    blocks = (char**)malloc(sizeof(char*)*NBLOCKS);
    *blocks = (char*)malloc(sizeof(char)*BLOCK_SIZE);
    */

    //node *root = (node*) malloc(sizeof(node));

    //char *rootName = (char *) malloc(sizeof(char)*2);
    char rootName[512];// = blocks[0];
   // strcpy(rootName, blocks[0]);
    strcpy(rootName, "/");
    //memcpy(blocks[0],rootName,sizeof(char)*512);
    /*root->type = Folder;
    root->name = rootName;
    root->numberOfItems = 0;
    root->size = 0;
    root->date = time(NULL);
    root->content =NULL;
    root->previous = NULL;
    root->parent = NULL;
    root->next = NULL;
    root->child = NULL;

    node *currentFolder = root;*/
    /*inodes[0]->type = Folder;
    inodes->name = rootName;
    inodes->numberOfItems = 0;
    inodes->size = 0;
    inodes->date = time(NULL);
    inodes->content =NULL;
    inodes->previous = NULL;
    inodes->parent = NULL;
    inodes->next = NULL;
    inodes->child = NULL;*/
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

    char *path = (char *) malloc(sizeof(char)*2);
    //char *path = blocks[1];
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
            //currentFolder->freeNode(/*root*/inodes);
            /*if (inodes[0]->child != NULL) {
            node* currentNode = inodes[0]->child;

               while (currentNode->next != NULL) {
                node* nextNode = currentNode->next;
                //node::freeNode(currentNode);
                free(currentNode->name);
                free(currentNode->content);
                free(currentNode);
                currentNode = nextNode;
               }
             free(currentNode->name);
             free(currentNode->content);
             free(currentNode);
             }*/
             //free(inodes->name);
             //free(inodes[0]->content);
            // free(inodes);
            //delete inodes;
            //free(rootName);
            free(path);
            //free(blocks);
            clean(inodes, blocks);
            break;
        }
        free(command);
    }

    return 0;
}
