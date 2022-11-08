#include "tree.h"
///Users/josephhammana
//leaks --atExit -- ./tree_tests /Users/josephhammana

static int sortAlpha(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void listFiles(const char* dirname, char* spaces, int first, int aFlag, int sFlag, int level) {
    struct list *l = array_list_new();
    char *new_str = "";
    char *path = "";
    struct stat sb;
    int i;
    int fileSize;

    if (first == 1) {
        
        int length = strlen(spaces) + strlen("|    ") + 1;
        new_str = checked_malloc(sizeof(char) * length);//free
        strcpy(new_str, spaces); 
        strcat(new_str, "|    "); 
    }
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        printf("ivalid directory: %s\n\n", dirname);
        return;
    }

    first = 1;

    struct dirent* entry;
    entry = readdir(dir);

    while (entry != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) { 
            if (aFlag == 1) { 
                array_list_add_to_end(l, strdup(entry->d_name));//free
            }
            else if (entry->d_name[0] != '.') {
                array_list_add_to_end(l, strdup(entry->d_name));//free
            }
        }
        entry = readdir(dir);
    }

    closedir(dir);
    qsort(l->array, l->curr_len, sizeof(char*), sortAlpha);
        for (i = 0; i < l->curr_len; i++) {

            int length = strlen(dirname) + strlen(l->array[i]) + strlen("/") + 1;
            path = checked_malloc(sizeof(char) * length); //free
            strcpy(path, dirname); 
            strcat(path, "/");
            strcat(path, l->array[i]); 
            lstat(path, &sb);

            
            if (sFlag == 1) {
                fileSize = sb.st_size;
                printf("%s| -- %s [size: %d]\n", new_str, l->array[i], fileSize);
            }
            else {
                printf("%s| -- %s\n", new_str, l->array[i]);
            }
            
            if ((sb.st_mode & S_IFMT) == S_IFDIR) {
                //recurse
                listFiles(path, new_str, first, aFlag, sFlag, ++level);   
                
            }
            free(path);
        }

    for (i = 0; i < l->curr_len; i++) {
        free(l->array[i]);
    }

    if (strcmp(new_str, "") != 0){
        free(new_str);
    }

    free(l->array);
    free(l);
}

void processInput(int argc, char* argv[]) {
    int i;
    int aFlag = 0;
    int sFlag = 0;
    int first = 0;
    int level = 0;

    for (i = FILE_IDX; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0) {
            aFlag = 1;
        }
        else if (strcmp(argv[i], "-s") == 0) {
            sFlag = 1;
        }
        else {
            printf("%s\n", argv[i]);
            listFiles(argv[i], "", first, aFlag, sFlag, level);
        }
    }
}

int main(int argc, char* argv[]) {
    processInput(argc, argv);
    return 0;
}
