#include "Arena.h"
#include "field.h"

Arena::Arena(unsigned size)
{
    exist = false;
    this->size = size;
    field_matrix = nullptr;
}

Arena::~Arena()
{
    if(field_matrix)
    {
        for(unsigned i = 0; i<size; ++i)
            if(field_matrix[i])
                delete[] field_matrix[i];
        delete[] field_matrix;
    }
}

field&  Arena::operator () (unsigned x, unsigned y)
{
    return field_matrix[x][y];
}


bool Arena::fill(field val)
{
    if (exist)
    {
        for (unsigned i = 0; i < size; ++i)
            for (unsigned j = 0; j < size; ++j)
                field_matrix[i][j] = val;
        return true;
    }
    return false;
}

bool Arena::create(const unsigned size)
{
    field val = field::UNTOUCHED;
    field_matrix = new field * [size];
    for(unsigned i=0; i<size; ++i)
        field_matrix[i]  = new field [size];
    fill(val);
    return 1;
}
