#define NAME_MAX 14

typedef struct {
  long ino; // inode
  char name[NAME_MAX+1]; // dirname + \0
} Dirent;

typedef struct {
  int fd;
  Dirent d;
} DIR;

DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);
