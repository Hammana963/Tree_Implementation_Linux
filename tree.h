#ifndef TREE_H
#define TREE_H
#define FILE_IDX 1
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

struct list {
    char** array;
    int capacity;
    int curr_len;

};

struct stat statbuf;

void *checked_malloc(int len);

struct list* array_list_new();

struct list* array_list_add_to_end(struct list *l, char *string);

void listFiles(const char* dirname, char* spaces, int first, int aFlag, int sFlag, int level);

void processInput(int argc, char* argv[]);

static int sortAlpha(const void* a, const void* b);

#endif
