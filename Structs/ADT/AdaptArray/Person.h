//
// Created by sagi yosef azulay on 13/03/2023.
//

#ifndef CBOOTCAMP_PERSON_H
#define CBOOTCAMP_PERSON_H

#endif //CBOOTCAMP_PERSON_H

#ifndef PERSON_H
#define PERSON_H
#include "AdptArray.h"
typedef struct PERSON_{
char *first_name;
char *last_name;
int id;
} person, *pperson;

PElement copy_person(PElement original);
void delete_person(PElement to_del);
void print_person(PElement b_);
pperson creat_person(char* first_name ,char* last_name, int id);
#endif