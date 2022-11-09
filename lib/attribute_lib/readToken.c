#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib/attribute_lib/attribute.h"
#include "lib/attribute_lib/attribute_parse.h"
#include "lib/string_extensions/string_extensions.h"

/**
 * @brief Save a string into an attribute node
 *
 * @param node
 * @param strPtr
 */
void saveNode(attribute_s *node, char *strPtr)
{
  char *key;
  char *value;
  str_split(strPtr, "=", &key, &value);
  node->type = (long long)key;
  node->constraint = (long long)value;
}

/**
 * @brief Read until a null character (end of string), a comma (","), or a closing brace (")")
 *
 * @param charPtr
 * @param nodeRef
 * @return char*
 */
char *readToken(char *charPtr, attribute_s **nodeRef)
{
  char *strPtrStart;                                // A reference to the start of the string
  char *strPtr;                                     // A reference to the current position within the string
  strPtrStart = strPtr = calloc(128, sizeof(char)); // MEMORY ALLOCACTION. Must be `free`'d

  attribute_s *node = newAttribute();
  *nodeRef = node;

  // Loop until a token delimiter is found
  while (*charPtr != '\0' && *charPtr != ',' && *charPtr != ')')
  {
    // Check if the current token is a collection of sub-attributes
    if (*charPtr == '(')
    {
      saveNode(node, strPtrStart);
      charPtr = createSubAttributeChain(node, charPtr);
      return charPtr;
    }

    *strPtr = *charPtr;
    charPtr++;
    strPtr++;
  }
  saveNode(node, strPtrStart);
  return charPtr;
}