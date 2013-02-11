/*
 * Copyright (C) 2011 Me
 * Author: Kasper Helweg Jonassen <hcj163@alumni.ku.dk>
 *
 * This file is part of stdBSTree.
 *
 * stdBSTree is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * stdBSTree is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with stdBSTree. If not, see <http://www.gnu.org/licenses/>.
 */

/* io is just...convenient */
#include <stdio.h>
/* mostly using NULL */
#include <stdlib.h>
/* well, we WILL need a tree */
#include "stdBSTree.h"

/*
 * internal helper functions
 *
 ****************************/

/* report an error and exit */
void error(char* msg) { 
  printf("PROGRAM ERROR: %s\n", msg);
  exit(EXIT_FAILURE);
}

/* allocate sizeof(tNode) space on the heap  */
tNode* mallocNode();

/*
 * implementation
 *
 ****************************/

void insert(Tree tree, Key key, Data data);
void delete(Tree tree, Key key);
tNode* search(Tree tree, Key key);
tNode* minimum(Tree tree);
tNode* maximum(Tree tree);
void inorderWalk(Tree tree);

/* 
 * Implementation internals
 *
 **************************/

tNode* mallocNode() 
{
  tNode* newNode = (tNode*) malloc(sizeof(tNode));
  if (newNode == NULL) {
    printf("Out of memory.\n");
    exit(EXIT_FAILURE);
  } 
 
  return newNode;
}
