#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "attribute.h"

void printAttributeTree(attribute_s *root)
{
  // Check if the element has anything to print
  if (root->type == (long long)NULL) {
    printf("(null type)");
    return;
  }
  
  // Print the value
  if(root->constraint != (long long) NULL) {
    // Print with constraint
    printf("%s=%s", (char *)root->type, (char*) root->constraint);
  } else {
    // Print without constraint
    printf("%s", (char *)root->type);
  }
  

  // Recursively print the sub-attributes
  if (root->sub_attribute != NULL)
  {
    printf("(");
    printAttributeTree(root->sub_attribute);
    printf(")");
  }

  // Recursively print the next attribute
  if (root->next_attribute != NULL)
  {
    printf(",");
    printAttributeTree(root->next_attribute);
  }
}