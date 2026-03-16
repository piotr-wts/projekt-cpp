#ifndef ARENA_H
#define ARENA_H
#include "field.h"

class Arena
{
public:
    Arena(unsigned size);
    ~Arena();
    bool create(const unsigned size); ///tworzy i wype³nia tablicê(z pomoca "fill")
    bool fill(field val);/// wypelnia tablice

    field& operator () (unsigned,unsigned);
    field ** field_matrix;


private:

    unsigned size;
    bool exist;
};

#endif // ARENA_H
