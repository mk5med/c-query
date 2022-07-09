#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
struct attribute
{
  long long type;                   // Type enum. The type is determined by the user of the API
  long long constraint;             // Any data to be applied as a constraint
  struct attribute *sub_attribute;  // First subattribute. If there are multiple, sub_attribute.next_attribute will contain the next element. Can be `NULL`
  struct attribute *next_attribute; // The next attribute. This creates a linked list. Can be `NULL`
};

typedef struct attribute attribute_s;

/**
 * @brief Allocate a new empty attribute struct
 * 
 * @return attribute_s* 
 */
attribute_s *newAttribute();
#endif