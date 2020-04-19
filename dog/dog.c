#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void SimpOut(){
    char Reader;
    int Read_count;
    while(1){
        Read_count = read(0,&Reader,1);
        if(Read_count == 0){
            break;
        }
        write(1,&Reader,1);
    }
}

void FileOut(char* file_name){
    int file_check;
    char Reader;
    int Read_count;
    file_check = open(file_name, O_RDONLY);
    if(file_check == -1){
        fprintf(stderr, "%s\n", strerror(errno));
    }else{
        while(1){
            Read_count = read(file_check,&Reader,1);
            if(Read_count == 0){
                break;
            }else{
                write(1,&Reader,1);
            }
        }
    }
}

int main(int argc, char *argv[]){
    if(argc == 1){
        SimpOut();
    }else{
        for(int iter = argc - 1; iter > 0; --iter){
            if(strcmp(argv[iter], "-") == 0){
                SimpOut();
            }else{
                FileOut(argv[iter]);
            }
        }
    }
}