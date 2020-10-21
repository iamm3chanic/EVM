/* CFunctions.cpp */
/*
 *    Задание 2.14. Создать файловую систему по аналогии 
 *    с файловой системой EXT(UNIX), т.е. на основе множеств 
 *    блоков с древовидным хранением номеров файловых блоков.
 *
 *    Created on: 15.10.2020
 *    Author: Anfisa
 */
 
#include "INode.h"
////////////// common //////////////

void initialize(node **inodes, char **blocks) {
/*inodes = new node[NNODES];*/
inodes = (node**) malloc(sizeof(node*)*NNODES);
for (int i=0; i<NNODES; i++)
{inodes[i] = (node*) malloc(sizeof(node));}
//inodes[0]=node();
// *blocks = new char[NBLOCKS];
blocks = new char*[NBLOCKS];
for (int i=0; i<NBLOCKS; i++)
  {blocks[i] = new char[BLOCK_SIZE]; memcpy(blocks[i],"",512);}
  /* inodes = (node*)malloc(sizeof(node)*NNODES);
  blocks = (char**)malloc(sizeof(char*)*NBLOCKS);
  (blocks)[0]=(char*)((*blocks)+(NBLOCKS));
  inodes[0]=node();*/
}

node **init_n(node **inodes){
    inodes = (node**) malloc(sizeof(node*)*NNODES);
for (int i=0; i<NNODES; i++)
{inodes[i] = (node*) malloc(sizeof(node));}
return inodes;
}

char **init_b(char **blocks){
    blocks = (char**) malloc(sizeof(char*)*NBLOCKS);
for (int i=0; i<NBLOCKS; i++)
  {blocks[i] = (char*) malloc(sizeof(char));}
return blocks;
}

void clean(node **inodes, char **blocks) {
for (int i=0; i<NBLOCKS; i++)
  {free (blocks [i]);} 
free ( blocks);
for (int i=0; i<NNODES; i++)
  { inodes[i]->SetZero(); free(inodes[i]);/*inodes[i]->Clean();*/}
free (inodes);
}
////////////// node ////////////////

node* node::getNode(node *currentFolder, char* name, enum nodeType type) {

    if (currentFolder->child != NULL) {

        node *currentNode = currentFolder->child;

        while (currentNode->next != NULL) {

            if (strcmp(name, currentNode->name) == 0 && currentNode->type == type) {
                return currentNode;
            }
            currentNode = currentNode->next;
        }

        if (strcmp(name, currentNode->name) == 0 && currentNode->type == type) {
            return currentNode;
        } else return NULL;

    } else return NULL;
}

node* node::getNodeTypeless(node *currentFolder, char* name) {

    if (currentFolder->child != NULL) {

        node *currentNode = currentFolder->child;

        while (currentNode->next != NULL) {

            if (strcmp(name, currentNode->name) == 0) {
                return currentNode;
            }
            currentNode = currentNode->next;
        }

        if (strcmp(name, currentNode->name) == 0) {
            return currentNode;
        } else return NULL;

    } else return NULL;
}

void node::mkdir(node *currentFolder, char *command) {
    if (strtok(command, " ") != NULL) {
        char* folderName = strtok(NULL, " ");
        if (folderName != NULL) {
            if (getNodeTypeless(currentFolder, folderName) == NULL) {

                currentFolder->numberOfItems++;
                node *newFolder = (node*) malloc(sizeof(node));

                if (currentFolder->child == NULL) {
                    currentFolder->child = newFolder;
                    newFolder->previous = NULL;
                    newFolder->parent = currentFolder;
                } else {

                    node *currentNode = currentFolder->child;

                    while (currentNode->next != NULL) {
                        currentNode = currentNode->next;
                    }
                    currentNode->next = newFolder;
                    newFolder->previous = currentNode;
                    newFolder->parent = NULL;
                }

                char* newFolderName = (char*) malloc(sizeof(char)*(strlen(folderName)+1));
                strcpy(newFolderName, folderName);
               
                newFolder->name = newFolderName;
                //newFolder->name = folderName;
                newFolder->type = Folder;
                newFolder->numberOfItems = 0;
                newFolder->size = 0;
                newFolder->date = time(NULL);
                newFolder->content = NULL;
                newFolder->next = NULL;
                newFolder->child = NULL;

                printf("Folder '%s' added\n", newFolder->name);
                 //free(newFolderName);
            } else {
                fprintf(stderr, "\033[1;31m'%s' is already exist in current directory!\n\033[0m",  folderName);
            }
        }
    }
}

void node::touch(node *currentFolder, char *command) {

    if (strtok(command, " ") != NULL) {
        char *fileName = strtok(NULL, " ");
        if (fileName != NULL) {
            if (getNodeTypeless(currentFolder, fileName) == NULL) {

                currentFolder->numberOfItems++;

                node *newFile = (node *) malloc(sizeof(node));

                if (currentFolder->child == NULL) {
                    currentFolder->child = newFile;
                    newFile->previous = NULL;
                    newFile->parent = currentFolder;
                } else {

                    node *currentNode = currentFolder->child;

                    while (currentNode->next != NULL) {
                        currentNode = currentNode->next;
                    }
                    currentNode->next = newFile;
                    newFile->previous = currentNode;
                    newFile->parent = NULL;
                }

                char* newFileName = (char*) malloc(sizeof(char)*(strlen(fileName)+1));
                strcpy(newFileName, fileName);

                newFile->name = newFileName;
                newFile->type = File;
                newFile->numberOfItems = 0;
                newFile->size = 0;
                newFile->date = time(NULL);
                newFile->content = NULL;
                newFile->next = NULL;
                newFile->child = NULL;

                printf("File '%s' added\n", newFile->name);
                  //free(newFileName);
                //freeNode(newFile);
            } else {
                fprintf(stderr, "\033[1;31m'%s' is already exist in current directory!\n\033[0m", fileName);
            }
        }
    }
}

void node::ls(node *currentFolder) {
    if (currentFolder->child == NULL) {
        printf("___Empty____\n");
    } else {

        node *currentNode = currentFolder->child;

        while (currentNode->next != NULL) {

            struct tm *date_time = localtime(&currentNode->date);
            char dateString[26];
            strftime(dateString, 26, "%d %b %H:%M", date_time);

            if (currentNode->type == Folder) {
                printf("%d items\t%s\t\033[1m%s\n\033[0m", currentNode->numberOfItems, dateString, currentNode->name);
            } else {
                printf("%dB\t%s\t\033[1m%s\n\033[0m", (int)currentNode->size, dateString, currentNode->name);
            }

            currentNode = currentNode->next;
        }

        struct tm *date_time = localtime(&currentNode->date);
        char dateString[26];
        strftime(dateString, 26, "%d %b %H:%M", date_time);

        if (currentNode->type == Folder) {
            printf("%d items\t%s\t\033[1m%s\n\033[0m", currentNode->numberOfItems, dateString, currentNode->name);
        } else {
            printf("%dB\t%s\t%s\n", (int)currentNode->size, dateString, currentNode->name);
        }
    }
}

void node::lsrecursive(node *currentFolder, int indentCount) {

    if (currentFolder->child == NULL) {
        for (int i = 0; i < indentCount; ++i) {
            printf("\t");
        }
        if (indentCount != 0 ) {
            printf("|_");
        }
        printf("___Empty____\n");
    } else {

        node *currentNode = currentFolder->child;

        while (currentNode->next != NULL) {

            for (int i = 0; i < indentCount; ++i) {
                printf("\t");
            }
            if (indentCount != 0 ) {
                printf("|_");
            }
            struct tm *date_time = localtime(&currentNode->date);
            char dateString[26];
            strftime(dateString, 26, "%d %b %H:%M", date_time);

            if (currentNode->type == Folder) {
                printf("%d items\t%s\t\033[1m%s\n\033[0m", currentNode->numberOfItems, dateString, currentNode->name);
            } else {
                printf("%dB\t%s\t\033[1m%s\n\033[0m", (int)currentNode->size, dateString, currentNode->name);
            }
            if (currentNode->type == Folder){
                lsrecursive(currentNode, indentCount+1);
            }
            currentNode = currentNode->next;
        }
        for (int i = 0; i < indentCount; ++i) {
            printf("\t");
        }
        if (indentCount != 0 ) {
            printf("|_");
        }
        struct tm *date_time = localtime(&currentNode->date);
        char dateString[26];
        strftime(dateString, 26, "%d %b %H:%M", date_time);

        if (currentNode->type == Folder) {
            printf("%d items\t%s\t\033[1m%s\n\033[0m", currentNode->numberOfItems, dateString, currentNode->name);
        } else {
            printf("%dB\t%s\t%s\n", (int)currentNode->size, dateString, currentNode->name);
        }
        if (currentNode->type == Folder){
            lsrecursive(currentNode, indentCount+1);
        }
    }
}

void node::edit(node *currentFolder, char *command) {

    if (strtok(command, " ") != NULL) {
        char *fileName = strtok(NULL, " ");
        if (fileName != NULL) {
            node * editingNode = getNode(currentFolder, fileName, File);
            if (editingNode != NULL) {
                printf("%s\n", "\033[1mPlease enter some text to overwrite the file content. \nUse \":wq\" to exit from this mode.\033[0m");
                char* content = user_input();
                if (editingNode->content != NULL) {
                    free(editingNode->content);
                }
                if (content!=NULL) {
                    editingNode->content = content;
                    editingNode->size = strlen(editingNode->content);
                    editingNode->date = time(NULL);
                }
                //free(content);
            }
        }
        //free(fileName);
    }
}

node* node::cd(node *currentFolder, char *command, char **path) {

    if (strtok(command, " ") != NULL) {
        char* folderName = strtok(NULL, " ");
        if (folderName != NULL) {

            node *destinationFolder = getNode(currentFolder, folderName, Folder);

            if ( destinationFolder != NULL) {

                size_t newPathLength = strlen(*path) + strlen(destinationFolder->name) + 2;

                *path = (char *) realloc(*path, sizeof(char)* newPathLength);

                strcat(strcat(*path, destinationFolder->name), "/");

                return destinationFolder;
            } else {
                fprintf(stderr, "\033[1;31mThere is no '%s' folder in current directory!\n\033[0m",  folderName);
                return currentFolder;
            }
        } else {
            return currentFolder;
        }
    } else {
        return currentFolder;
    }
}

node* node::cdup(node *currentFolder, char **path) {
    if (currentFolder->parent == NULL ) {return currentFolder;}
    size_t newPathLength = strlen(*path) - strlen(currentFolder->name);

    while (currentFolder->previous != NULL) {
        currentFolder = currentFolder->previous;
    }
    if (currentFolder->parent != NULL ) {

        *path = (char *) realloc(*path, sizeof(char)* newPathLength);
        (*path)[newPathLength-1] = '\0';

        currentFolder = currentFolder->parent;
        return currentFolder;
    } else {
        return currentFolder;
    }
}

void node::freeNode(node *freeingNode) {

    if (freeingNode->child != NULL) {

        node* currentNode = freeingNode->child;

        while (currentNode->next != NULL) {
            node* nextNode = currentNode->next;
            freeNode(currentNode);
            currentNode = nextNode;
        }
        freeNode(currentNode);
    }
    free(freeingNode->name);
    free(freeingNode->content);
    free(freeingNode);

}

void node::removeNode(node *removingNode) {
    if (removingNode->parent != NULL){
        if (removingNode->next != NULL) {
            removingNode->next->parent = removingNode->parent;
            removingNode->parent->child = removingNode->next;
            removingNode->next->previous = NULL;
        } else {
            removingNode->parent->child = NULL;
        }
    } else {
        if (removingNode->next != NULL) {
            removingNode->previous->next = removingNode->next;
            removingNode->next->previous  = removingNode->previous;
        } else {
            removingNode->previous->next = NULL;
        }
    }
}

void node::rm(node *currentFolder, char *command) {

    if (strtok(command, " ") != NULL) {
        char *nodeName = strtok(NULL, " ");
        if (nodeName != NULL) {
            node *removingNode = getNodeTypeless(currentFolder, nodeName);

            if (removingNode != NULL) {

                printf("Do you really want to remove %s and all of its content? (y/n)\n", removingNode->name);

                char *answer = getString();
                if (strcmp(answer, "y") == 0 ) {
                    currentFolder->numberOfItems--;
                    removeNode(removingNode);
                    printf("%s and its all content is removed!\n", removingNode->name);
                    freeNode(removingNode);
                }
                free(answer);
            } else {
                fprintf(stderr, "'%s' does not exist in current directory!\n",  nodeName);
            }
        }
    }
}

void node::moveNode(node *movingNode, node *destinationFolder) {

    if (destinationFolder->child == NULL) {
        destinationFolder->child = movingNode;
        movingNode->previous = NULL;
        movingNode->parent = destinationFolder;
        movingNode->next = NULL;
    } else {

        node *currentNode = destinationFolder->child;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }

        currentNode->next = movingNode;
        movingNode->previous = currentNode;
        movingNode->parent = NULL;
        movingNode->next = NULL;
    }
    destinationFolder->numberOfItems++;
}

////////////// friend functions ////////////////

void help() {
printf("\033[1;32mmkdir       - creates directory\n");
printf("touch       - creates file\n"); 
printf("ls          - list of nodes in current dir\n"); 
printf("lsrecursive - list of nodes and their content in current dir\n"); 
printf("edit        - write something to file\n"); 
printf("pwd         - print working directory\n"); 
printf("cd          - change directory\n"); 
printf("cdup        - move one directory up\n"); 
printf("mov         - move something somewhere\n"); 
printf("rm          - remove something\n"); 
printf("help        - help\n\033[0m"); 
printf("\033[1;31mexit        - exit\n\033[0m"); 
printf("Use exit rather then Ctrl+C to clean memory :)\n");
}

void mov(node *currentFolder, char *command) {

    char* nodeName;
    char* destinationName;

    if (strtok(command, " ") != NULL) {
        nodeName = strtok(NULL, " ");
        if (nodeName != NULL) {
            destinationName = strtok(NULL, " ");
            if (destinationName != NULL) {
                if (strtok(NULL, " ")) {
                    return;
                } else {

                    node* movingNode = currentFolder->getNodeTypeless(currentFolder, nodeName);
                    node* destinationFolder = currentFolder->getNode(currentFolder, destinationName, Folder);

                    if (destinationFolder != NULL && movingNode != NULL && destinationFolder != movingNode) {

                        currentFolder->removeNode(movingNode);
                        currentFolder->moveNode(movingNode, destinationFolder);
                    } else {
                        fprintf(stderr, "\033[1;31mSomething went wrong!\n\033[0m");
                    }
                }
            }
        }
    }
}


void pwd(char *path) {
    if (strlen(path) != 1){

        for (int i = 0; i < (int)(strlen(path)-1) ; ++i) {
            printf("%c", path[i]);
        }
        printf("\n");
    } else {
        printf("%s\n", path);
    }
}

char *getString(){
    size_t size = 10;
    char *str;
    int ch;
    size_t len = 0;
    str=(char*)realloc(NULL, sizeof(char)*size);
    //str = new char[size];
    if(!str)return str;
    while(EOF!=(ch=fgetc(stdin)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str=(char*)realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';
    str=(char*)realloc(str, sizeof(char)*len);
    //delete [] str;
    return str;
}

char *user_input()
{
    printf("Enter file content : \n");    
    char *s, *tmp_s;
    //s=new char[1000];
    s=(char*)realloc(NULL, sizeof(char)*1024);       //max input size
    //tmp_s=(char*)realloc(NULL, sizeof(char)*100);  //max string size
    strcpy(s,"");
    do
    {  
        tmp_s=getString();
        strcat(s, tmp_s);
        strcat(s, "\n");
    } while(strcmp(tmp_s, ":wq")); // while (tmp_s!=":wq"); 
    //free (tmp_s); delete tmp_s;
    return s;
}
/*
std::string user_input()
{
    printf("Enter file content : \n");
    
    std::string s, tmp_s;
    do
    {
       // string tmp_s;
        tmp_s=getString();
        s += (tmp_s + "\n");
    } while (tmp_s!=":wq");   //(!cin.eof());
    s.pop_back();
    s.pop_back();
    return s;
}*/
