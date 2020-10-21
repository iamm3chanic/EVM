/* Inode.h */
/*
 *    Задание 2.14. Создать файловую систему по аналогии 
 *    с файловой системой EXT(UNIX), т.е. на основе множеств 
 *    блоков с древовидным хранением номеров файловых блоков.
 *
 *    Created on: 15.10.2020
 *    Author: iamm3chanic
 */
 
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h> 
#include <unistd.h>
#include <fcntl.h>
#include <string>

enum nodeType {File, Folder};

class node{
public:
    enum nodeType type;
    char* name;
    int numberOfItems;
    size_t size;
    time_t date;
    char* content;
    //std::string scontent;
    /*struct*/ node* previous;
    /*struct*/ node* parent;
    /*struct*/ node* next;
    /*struct*/ node* child;
    
    node()   { SetZero(); }
    ~node()  { Clean();   }
    void SetZero(){ name=NULL; content=NULL; numberOfItems=0;size=0;}
    void Clean() {delete[] name; delete[] content; SetZero();}
    //void CopyOnly(const node &n) { if(this!=&n){SetZero();numberOfItems=n.numberOfItems;size=n.size;} //мы ей не пользуемся
    
    node* getNode(node *currentFolder, char* name, enum nodeType type);
    node* getNodeTypeless(node *currentFolder, char* name);
    node* cd(node *currentFolder, char *command, char **path);
    node* cdup(node *currentFolder, char **path) ;
    void mkdir(node *currentFolder, char *command);
    void touch(node *currentFolder, char *command);
    void ls(node *currentFolder);
    void freeNode(node *freeingNode) ;
    void removeNode(node *removingNode);
    void rm(node *currentFolder, char *command);
    void moveNode(node *movingNode, node *destinationFolder) ;
    void lsrecursive(node *currentFolder, int indentCount);
    void edit(node *currentFolder, char *command) ;
    friend void pwd(char *path);
    friend void help() ;
    friend void mov(node *currentFolder, char *command);
    friend char *getString();
    friend char *user_input();
    //friend std::string user_input();
};
 void pwd(char *path);
 void help() ;
 void mov(node *currentFolder, char *command);
 char *getString();
 char *user_input();

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define BOLD "\033[1m"
#define DEFAULT "\033[0m"
