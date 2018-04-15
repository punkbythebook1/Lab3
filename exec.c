#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
/*
 *   char *args[]={"./EXEC",NULL};
        execvp(args[0],args);
     
 * 
 */

int main(int argc, char** args)
{
     pid_t child_pid = fork();
     
    if (child_pid >= 0) {
    
      if (child_pid == 0) {
        // child process
        printf("start child\n");
        execvp("./out",args);
        printf("stop child\n");
        }

    }else{
      printf("Fork failed!\n");
      return 1;
    }
   int status; 
   wait(&status); 
   printf("parent end\n");
return 0;
}