/**
 * judger.cpp: Judger for Interactive Problem
 *
 * @author Sshwy
 * @copyright 2021 Sshwy (Weiyao Huang)
 * @license MIT
 * @date 2021.4.26
 *
 * Usage: judger [command1] [command2]
 */
#include <stdio.h>
#include <unistd.h>
using namespace std;

int main(int argc, char ** argv){
  if(argc != 3) {
    fprintf(stderr, "Usage: %s [command1] [command2]\n", argv[0]);
    return 0;
  }

  int p1[2], p2[2];
  if(pipe(p1) == -1 || pipe(p2) == -1) 
    return fprintf(stderr, "fail to create pipe\n"), 1;

  pid_t id = fork();

  if(id < 0) return fprintf(stderr, "error fork\n"), 1;

  if(id == 0){ // child : a
    if (dup2(p2[0], fileno(stdin)) == -1) 
      return fprintf(stderr,"Error 1"), 1;
    if (dup2(p1[1], fileno(stdout)) == -1) 
      return fprintf(stderr,"Error 2"), 1;

    execve(argv[1], nullptr, nullptr);
  } else {
    if (dup2(p1[0], fileno(stdin)) == -1) 
      return fprintf(stderr,"Error 3"), 1;
    if (dup2(p2[1], fileno(stdout)) == -1)
      return fprintf(stderr,"Error 4"), 1;

    execve(argv[2], nullptr, nullptr);
  }
  return 0;
}