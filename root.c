#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

void root(char* filename[])
{
    chown(filename, 0, 0);
    // chmod(filename, S_ISUID|S_ISGID|S_ISVTX|S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH);
    chmod(filename,07777);
}

int main(int argc, char* argv[]){
    if(geteuid()){
        printf("%s must be run as root at the first time", argv[0]);
        return 1;
    }
    root(argv[0]);
    if(argc == 2){
        root(argv[1]);
    }
    return 0;
}
