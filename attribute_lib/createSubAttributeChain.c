#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "attribute_lib/attribute.h"
#include "attribute_lib/attribute_parse.h"

char *createSubAttributeChain(attribute_s *nodeRef, char *charPtr)
{
  // Check that the current character is an open brace
  if (*charPtr != '(')
  {
    printf("Error createSubAttributeChain: Expected to begin when pointing at a '(' character. Got '%c'.\n", *charPtr);
    exit(1);
  }

  // Check that the nodeRef type is not null
  if (nodeRef->type == (long long)NULL)
  {
    printf("Error createSubAttributeChain: Expected nodeRef to have a non-null type.\n");
    exit(1);
  }

  if (nodeRef->sub_attribute != NULL)
  {
    printf("Error createSubAttributeChain: Expected nodeRef to have no existing sub-attribute chain.\n");
    exit(1);
  }

  charPtr++; // Move one character forward to skip the open brace
  attribute_s *parentNodeRef = nodeRef;

  // Loop until a close brace (')') is detected
  while (*charPtr != ')')
  {
    // Check if the current character is a null character
    // this happens if the input string does not have a closing brace
    if (*charPtr == '\0')
    {
      printf("Error createSubAttributeChain: NULL character reached without reading closing brace (')').\n");
      exit(1);
    }

    /* Read tokens and add them as subattributes */

    attribute_s *node;                   // This node reference is initialised by readToken
    charPtr = readToken(charPtr, &node); // Get the next token and move by the number of characters read

    // Check if no sub attribute chain exists
    // this occurs during the first run of the createSubAttributeChain loop
    if (parentNodeRef->sub_attribute == NULL)
    {
      nodeRef->sub_attribute = node; // Set up the sub-attribute chain
    }
    else
    {
      nodeRef->next_attribute = node; // Set the next attribute
    }

    // Set the node context of the next loop iteration to the new node
    nodeRef = node;

    // If the next character is a comma (',') skip it
    if (*charPtr == ',')
      charPtr++;
  }

  return charPtr;
}