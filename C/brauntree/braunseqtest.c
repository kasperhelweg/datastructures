#include <stdio.h>
#include <stdlib.h>
#include "braunseq.h"
#include <string.h>

#define INSERT_FRONT 1
#define INSERT_BACK  2
#define REMOVE_FRONT 3
#define REMOVE_BACK  4
#define QUIT         5
/*
 * internal helper functions
 *
 ****************************/

void printTree(Tree tree);
unsigned int getCommand(char *command);
void execute(Tree tree, int command, Data data);

/*
 * implementation
 *
 ****************************/

int main()
{
  /* Create empty tree*/  
  bNode* root = NULL;
  Tree tree = &root;
  
  int read;
  double* data;
  char* input;
  char* command;
  size_t bytes = 0;
  
  int i = 0;
  for (; i < 3; ++i) {
    addR(tree, i);
  }
  
  puts("Hello. This program is very unstable.");
  /* malloc suggestion. getline reallocs automatically */
  input = (char *) malloc(sizeof(char)); 
  /* malloc suggestion for command and data */
  command = (char *) malloc(sizeof(char));
  data = (double *) malloc(sizeof(double));
  
  /* Get input */
  while(1) {
    read = getline (&input, &bytes, stdin);
    
    /* Handle carriage return*/
    if (read == -1)
      {
	puts ("an error occured");
      exit(EXIT_FAILURE);
      }
    else
      {
	if (!strcmp(input, "quit\n")) {
	  puts("goodbye");
	  exit(EXIT_SUCCESS);
	} else if (!strcmp(input, "print\n"))
	  {
	    printTree(tree);
	  }
	else {
	  sscanf(input, "%2s %lf", command, data); 
	  execute(tree, getCommand(command), *data);
	}
      }
  }
  return 0;
}

/* 
 * Implementation internals
 *
 **************************/

/* Execute command*/
void execute(Tree tree, int command, Data data)
{
  switch(command) 
    {
    case 1:
      addL(tree, data);
      break;
    case 2:
      addR(tree, data);
      break;
    case 3:
      remvL(tree);
      break;
    case 4:
      remvR(tree);
      break;
    default :
      break;
    }
  /* printf("command: %i data: %lf\n", command, data); */
}

unsigned int getCommand(char *command)
{
  if (!strcmp(command, "if")) { return INSERT_FRONT; }
  if (!strcmp(command, "ib")) { return INSERT_BACK; }
  if (!strcmp(command, "rf")) { return REMOVE_FRONT; }
  if (!strcmp(command, "rb")) { return REMOVE_BACK; }
  return 0;
}

/* Print tree to screen. sequential.*/
void printTree(Tree tree) 
{
  int i = 0;
  Data x;
  for (; i < size(tree); ++i) {
    x = lookup(tree, i);
    printf("i: %i data: %f\n", i, (double) x);      
  }
}

