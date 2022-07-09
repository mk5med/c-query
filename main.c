#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "attribute_lib/attribute.h"
#include "attribute_lib/attribute_parse.h"
#include "attribute_lib/attribute_print.h"

int main(int argc, char **argv)
{
  char *input = "cal(a,b)";
  attribute_s *nodeRef;
  readToken(input, &nodeRef);
  printAttributeTree(nodeRef);
}