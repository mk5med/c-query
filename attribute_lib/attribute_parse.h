#ifndef PARSEATTRIBUTE_H
#define PARSEATTRIBUTE_H
#include "attribute.h"
char *createSubAttributeChain(attribute_s *nodeRef, char *charPtr);
char *readToken(char *charPtr, attribute_s **nodeRef);
#endif