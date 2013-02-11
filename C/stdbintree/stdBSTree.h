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

/* 
   WORK IN PROGRESS!! WRITE NICE WORDS.
   implementation of a very basic binary search tree 
   the implementation is mostly iterative (exept inorder tree walk). 
   see stdbintree.sml for a recursive (and functional) approach. 
   for a discussion regarding efficiency, please visit my website.

   we might conveniently state the defining BST property as follws:
     Let x be a node in a BST. If y is a node in the left subtree of x,
     then y.key <= x.key. If y is a node in the right subtree of x, then y.key >= x.key [reference]
*/

#ifndef STDBINSEARCH_H
#define STDBINSEARCH_H

/* 
 * Datatypes
 *
 **************************/

/* 
 * we use a void * for the key to make a polymorphic type tree
 * this is not obviously natural to do in C and thus we should consider wether
 * we are using the right language for the job (in this case we are, 
 * since this is merely an exercise ).
*/
typedef void *Key;

/* 
 * sattelite data contained in a node. here we use a void *
 * again, we should reconsider the use of void *'s
*/
typedef void *Data;

/* 
 * the basic unit of the tree. also known as a node.
 * a node has a left child, 
 * a right child(not that the left child is wrong in any way) and a parent.
 * also it has a key, that should be a sum type, and a pointer to sattelite data.
*/
typedef struct tNode_ {
  Key key;
  Data data;
  struct tNode_ *parent;
  struct tNode_ *left;
  struct tNode_ *right;
} tNode;

/*
 * the definition of a stdbintree
 * here we use a pointer-pointer structure
*/
typedef tNode **Tree;

/* 
 * Prototypes
 *
 **************************/

/* 
 * insert new node, given key and sattelite data.
*/
void insert(Tree tree, Key key, Data data);

/* 
 * delete node x iff x.key = key
*/
void delete(Tree tree, Key key);

/* 
 * given a Tree, return node x iff x.key = key
 * CONSIDER USING A FUNCTION POINTER TO SOME COMPARATOR FUN IN ORDER TO GENERALIZE
 * IT IS NOT USEFULL FOR INTEGER KEYS, BUT KEYS SHOULD BE MORE GENERAL TOO.
 * SHOULD key BE A UNION DATA TYPE?
*/
tNode *search(Tree tree, Key key);

/* 
 * returns pointer to node x iff x.key < all other x.key's
 * we might appreciate that this is a node for which we might choose 
 * the obvious name "first" or "head".
*/
tNode *minimum(Tree tree);

/* 
 * returns pointer to node with "maximum" key 
*/
tNode *maximum(Tree tree);

/* 
 * procedure to walk the tree inorder, printing each element
*/
void inorderWalk(Tree tree);

/* 
 * DEVELOPMENT
 *
 **************************/

/* 
 * return a pointer to a subtree with root where node.key = key
*/
Tree getSubtree(Tree tree, Key key);

/* 
 * procedure to output a file suitable for compilation with dottotex (or similar).
*/
void treeToTex(Tree tree);

/* 
 * procedure to output a file to mathematica to 
 * manipulate and simulate / gather stats from tree.
*/
void toMathematica(Tree tree);

#endif




