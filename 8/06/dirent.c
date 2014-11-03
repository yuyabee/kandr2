#include <sys/stat.h>
#include <fcntl.h>

int fstat(int fd, struct stat *);

DIR *opendir(char *dirname)
{
  // file descriptor
  int fd;
  struct stat stbuf;
  DIR *dp;

  if ((fd = open(dirname, O_RDONLY, 0)) == -1 ||
      (fstat(fd, &stbuf) == -1) ||
      ((stbuf.st_mode & S_IFMT) != S_IFDIR) ||
      (dp = (DIR *) malloc(sizeof(DIR))) == NULL)
    return NULL;

  dp->fd = fd;
  return dp;
}

#include <sys/dir.h>
#include <string.h>

Dirent *readdir(DIR *dfd)
{
  struct direct dirbuf;
  struct DIR d;

  while (read(dfd->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
    if (dirbuf.d_ino == 0)
      continue;
    d->ino = dirbuf.d_ino;
    strncpy(d.name, dirbuf.d_name, DIRSIZ);
    d->name[DIRSIZ] = '\0';
    return &d;
  }
  return NULL;
}

void closedir(DIR *dp)
{
  if (dp) {
    close(dp->fd);
    free(dp);
  }
}
