#include <stdlib.h>
#include "attribute.h"

attribute_s *newAttribute()
{
  attribute_s *node = malloc(sizeof(attribute_s));
  node->type = (long long)NULL;
  node->next_attribute = NULL;
  node->sub_attribute = NULL;
  return node;
}