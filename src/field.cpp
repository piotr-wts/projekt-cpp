#include "field.h"

field::field(int initialState)
{
    currentState = initialState;
    nextState = initialState;
}


field::~field()
{
    //dtor
}

void field::setCurrState(int state)
{
    currentState = state;
}
void field::setNextState(int state)
{
    nextState = state;
}

int field::getCurrState() const
{
    return currentState;
}

int field::getNextState() const
{
    return nextState;
}

void field::forwardState()
{
    currentState = nextState;
}

int field::getwind_direction() const
{
    return wind_direction;
}

int field::getwind_power() const
{
    return wind_power;
}

void field::set_wind_direction(int direction)
{
    wind_direction = direction;
}

void field::set_wind_power(int power)
{
    wind_power = power;
}

////////////////////////////////////////////////////////////////////////
#include <iostream>
int calculateNextStateRandom(field** matrix, const int size, int i, int j)
{
    if (matrix[i][j].getCurrState() == field::states::BURNING)
        return field::BURNING2;


    if (matrix[i][j].getCurrState() == field::states::BURNING2)
        return field::BURNT;

    if (matrix[i][j].getCurrState() == field::states::BURNT)
        return field::BURNT;

    if (matrix[i][j].getCurrState() == field::ROCK)
        return field::states::ROCK;

    if(i == 0)
    {

        if (j == 0 &&(         ///gdy jest w lweym gornym rogu
                    matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                    matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                    matrix[i + 1][j].getCurrState() == field::states::BURNING)
           )
            return rand()%2;

        if(j == size - 1 &&(    /// gdy jest w lewym dolnym rogu
                    matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                    matrix[i + 1][j - 1].getCurrState() == field::states::BURNING	||
                    matrix[i + 1][j].getCurrState() == field::states::BURNING)
          )
            return rand()%2;

        if(                     /// gdy jest przy lewej scianie
            matrix[i + 1][j - 1].getCurrState() == field::states::BURNING ||
            matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
            matrix[i + 1][j].getCurrState() == field::states::BURNING ||
            matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
            matrix[i][j + 1].getCurrState() == field::states::BURNING
        )
            return rand()%2;

        return field::UNTOUCHED;
    }

    if(i == size - 1)
    {

        if(j == 0 &&( ///gdy jest w prawym gornym rogu
                    matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                    matrix[i - 1][j + 1].getCurrState() == field::states::BURNING	||
                    matrix[i][j + 1].getCurrState() == field::states::BURNING)
          )
            return rand()%2;

        if(j == size - 1 &&( ///gdy jest w prawy dolnym rogu
                    matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                    matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j - 1].getCurrState() == field::states::BURNING)
          )
            return rand()%2;

        if(             /// gdy jest przy prawej scianie
            matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
            matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
            matrix[i - 1][j].getCurrState() == field::states::BURNING ||
            matrix[i - 1][j + 1].getCurrState() == field::states::BURNING ||
            matrix[i][j + 1].getCurrState() == field::states::BURNING
        )
            return rand()%2;

        return field::UNTOUCHED;
    }

    if(j == 0 && (          /// gdy jest przy gornej krawedzi
                matrix[i-1][j].getCurrState() == field::states::BURNING ||
                matrix[i - 1][j + 1].getCurrState() == field::states::BURNING ||
                matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                matrix[i + 1][j].getCurrState() == field::states::BURNING)
      )
        return rand()%2;

    if(j == size - 1 && (    /// gdy jest przy dolnej krawedzi
                matrix[i-1][j].getCurrState() == field::states::BURNING ||
                matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                matrix[i][j - 1].getCurrState() == field::states::BURNING ||
                matrix[i + 1][j - 1].getCurrState() == field::states::BURNING ||
                matrix[i + 1][j].getCurrState() == field::states::BURNING)
      )
        return rand()%2;


    if (                    /// gdy jest gdzies w srodku
        matrix[i + 1][j].getCurrState() == field::states::BURNING	||
        matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
        matrix[i + 1][j + 1].getCurrState() == field::states::BURNING	||
        matrix[i + 1][j - 1].getCurrState() == field::states::BURNING	||
        matrix[i][j + 1].getCurrState() == field::states::BURNING 	||
        matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
        matrix[i - 1][j + 1].getCurrState() == field::states::BURNING	||
        matrix[i - 1][j - 1].getCurrState() == field::states::BURNING
    )
        return rand()%2;

    return field::states::UNTOUCHED;

}


////////////////////////////////////////////////////////////////////////


int calculateNextStateStar(field** matrix, const int size, int i, int j)
{
    if (matrix[i][j].getCurrState() == field::states::BURNING)
        return field::BURNING2;


    if (matrix[i][j].getCurrState() == field::states::BURNING2)
        return field::BURNT;

    if (matrix[i][j].getCurrState() == field::states::BURNT)
        return field::BURNT;

    if (matrix[i][j].getCurrState() == field::ROCK)
        return field::states::ROCK;

    if(i == 0)
    {

        if (j == 0 &&(         ///gdy jest w lweym gornym rogu
                    matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                    matrix[i + 1][j].getCurrState() == field::states::BURNING)
           )
            return field::states::BURNING;

        if(j == size - 1 &&(    /// gdy jest w lewym dolnym rogu
                    matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                    matrix[i + 1][j].getCurrState() == field::states::BURNING)
          )
            return field::states::BURNING;

        if(                     /// gdy jest przy lewej scianie
            matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
            matrix[i + 1][j].getCurrState() == field::states::BURNING   ||
            matrix[i][j + 1].getCurrState() == field::states::BURNING
        )
            return field::states::BURNING;

        return field::UNTOUCHED;
    }

    if(i == size - 1)
    {

        if(j == 0 &&( ///gdy jest w prawym gornym rogu
                    matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                    matrix[i][j + 1].getCurrState() == field::states::BURNING)
          )
            return field::states::BURNING;

        if(j == size - 1 &&( ///gdy jest w prawy dolnym rogu
                    matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                    matrix[i][j - 1].getCurrState() == field::states::BURNING)
          )
            return field::states::BURNING;

        if(             /// gdy jest przy prawej scianie
            matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
            matrix[i - 1][j].getCurrState() == field::states::BURNING ||
            matrix[i][j + 1].getCurrState() == field::states::BURNING
        )
            return field::states::BURNING;

        return field::UNTOUCHED;
    }

    if(j == 0 && (          /// gdy jest przy gornej krawedzi
                matrix[i-1][j].getCurrState() == field::states::BURNING ||
                matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                matrix[i + 1][j].getCurrState() == field::states::BURNING)
      )
        return field::states::BURNING;

    if(j == size - 1 && (    /// gdy jest przy dolnej krawedzi
                matrix[i-1][j].getCurrState() == field::states::BURNING ||
                matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                matrix[i][j - 1].getCurrState() == field::states::BURNING ||
                matrix[i + 1][j].getCurrState() == field::states::BURNING)
      )
        return field::states::BURNING;


    if (                    /// gdy jest gdzies w srodku
        matrix[i + 1][j].getCurrState() == field::states::BURNING	||
        matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
        matrix[i][j + 1].getCurrState() == field::states::BURNING 	||
        matrix[i][j - 1].getCurrState() == field::states::BURNING
    )
        return field::states::BURNING;

    return field::states::UNTOUCHED;
}

////////////////////////////////////////////////////////////////////////

int calculateNextState(field** matrix, const int size, int i, int j)
{
    if (matrix[i][j].getCurrState() == field::states::BURNING)
        return field::BURNING2;


    if (matrix[i][j].getCurrState() == field::states::BURNING2)
        return field::BURNT;

    if (matrix[i][j].getCurrState() == field::states::BURNT)
        return field::BURNT;

    if (matrix[i][j].getCurrState() == field::ROCK)
        return field::states::ROCK;


    if(i == 0)
    {

        if (j == 0 &&(         ///gdy jest w lweym gornym rogu
                    matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                    matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                    matrix[i + 1][j].getCurrState() == field::states::BURNING)
           )
            return field::states::BURNING;

        if(j == size - 1 &&(    /// gdy jest w lewym dolnym rogu
                    matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                    matrix[i + 1][j - 1].getCurrState() == field::states::BURNING	||
                    matrix[i + 1][j].getCurrState() == field::states::BURNING)
          )
            return field::states::BURNING;

        if(                     /// gdy jest przy lewej scianie
            matrix[i + 1][j - 1].getCurrState() == field::states::BURNING ||
            matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
            matrix[i + 1][j].getCurrState() == field::states::BURNING ||
            matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
            matrix[i][j + 1].getCurrState() == field::states::BURNING
        )
            return field::states::BURNING;

        return field::UNTOUCHED;
    }

    if(i == size - 1)
    {

        if(j == 0 &&( ///gdy jest w prawym gornym rogu
                    matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                    matrix[i - 1][j + 1].getCurrState() == field::states::BURNING	||
                    matrix[i][j + 1].getCurrState() == field::states::BURNING)
          )
            return field::states::BURNING;

        if(j == size - 1 &&( ///gdy jest w prawy dolnym rogu
                    matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                    matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j - 1].getCurrState() == field::states::BURNING)
          )
            return field::states::BURNING;

        if(             /// gdy jest przy prawej scianie
            matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
            matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
            matrix[i - 1][j].getCurrState() == field::states::BURNING ||
            matrix[i - 1][j + 1].getCurrState() == field::states::BURNING ||
            matrix[i][j + 1].getCurrState() == field::states::BURNING
        )
            return field::states::BURNING;

        return field::UNTOUCHED;
    }

    if(j == 0 && (          /// gdy jest przy gornej krawedzi
                matrix[i-1][j].getCurrState() == field::states::BURNING ||
                matrix[i - 1][j + 1].getCurrState() == field::states::BURNING ||
                matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                matrix[i + 1][j].getCurrState() == field::states::BURNING)
      )
        return field::states::BURNING;

    if(j == size - 1 && (    /// gdy jest przy dolnej krawedzi
                matrix[i-1][j].getCurrState() == field::states::BURNING ||
                matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                matrix[i][j - 1].getCurrState() == field::states::BURNING ||
                matrix[i + 1][j - 1].getCurrState() == field::states::BURNING ||
                matrix[i + 1][j].getCurrState() == field::states::BURNING)
      )
        return field::states::BURNING;


    if (                    /// gdy jest gdzies w srodku
        matrix[i + 1][j].getCurrState() == field::states::BURNING	||
        matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
        matrix[i + 1][j + 1].getCurrState() == field::states::BURNING	||
        matrix[i + 1][j - 1].getCurrState() == field::states::BURNING	||
        matrix[i][j + 1].getCurrState() == field::states::BURNING 	||
        matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
        matrix[i - 1][j + 1].getCurrState() == field::states::BURNING	||
        matrix[i - 1][j - 1].getCurrState() == field::states::BURNING
    )
        return field::states::BURNING;

    return field::states::UNTOUCHED;
}

////////////////////////////////////////////////////////////////////////

int percent_counter_plus(int wind_power)
{

    int x = rand()%100 + wind_power/2;
    if(x > 40)
        return 1;
    else
        return 0;
}

int percent_counter_minus(int wind_power)
{
    int x = rand()%100 - wind_power/2;
    if(x > 40)
        return 1;
    else
        return 0;

}
////////////////////////////////////////////////////////////////////////
int calculateNextStatesRANDOMandWIND(field** matrix, const int size, int i, int j,int wind_direction, int wind_power)
{
    if (matrix[i][j].getCurrState() == field::states::BURNING)
        return field::BURNING2;

    if (matrix[i][j].getCurrState() == field::states::BURNING2)
        return field::BURNT;

    if (matrix[i][j].getCurrState() == field::states::BURNT)
        return field::BURNT;

    if (matrix[i][j].getCurrState() == field::ROCK)
        return field::states::ROCK;

    if (wind_direction > 0)
    {



        if(wind_direction == 1) // z góry
        {


            if(i == 0)
            {

                if (j == 0 &&(         ///gdy jest w lweym gornym rogu
                            matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                            matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                            matrix[i + 1][j].getCurrState() == field::states::BURNING)
                   )
                    return rand()%2;

                if(j == size - 1 &&(    /// gdy jest w lewym dolnym rogu
                            matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                            matrix[i + 1][j - 1].getCurrState() == field::states::BURNING	||
                            matrix[i + 1][j].getCurrState() == field::states::BURNING)
                  )
                    return rand()%2;

                if(                     /// gdy jest przy lewej scianie
                    matrix[i + 1][j - 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                    matrix[i + 1][j].getCurrState() == field::states::BURNING ||
                    matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j + 1].getCurrState() == field::states::BURNING
                )
                    return rand()%2;

                return field::UNTOUCHED;
            }

            if(i == size - 1)
            {

                if(j == 0 &&( ///gdy jest w prawym gornym rogu
                            matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                            matrix[i - 1][j + 1].getCurrState() == field::states::BURNING	||
                            matrix[i][j + 1].getCurrState() == field::states::BURNING)
                  )
                    return rand()%2;

                if(j == size - 1 &&( ///gdy jest w prawy dolnym rogu
                            matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                            matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                            matrix[i][j - 1].getCurrState() == field::states::BURNING)
                  )
                    return rand()%2;

                if(             /// gdy jest przy prawej scianie
                    matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                    matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                    matrix[i - 1][j].getCurrState() == field::states::BURNING ||
                    matrix[i - 1][j + 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j + 1].getCurrState() == field::states::BURNING
                )
                    return rand()%2;

                return field::UNTOUCHED;
            }

            if(j == 0 && (          /// gdy jest przy gornej krawedzi
                        matrix[i-1][j].getCurrState() == field::states::BURNING ||
                        matrix[i - 1][j + 1].getCurrState() == field::states::BURNING ||
                        matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j].getCurrState() == field::states::BURNING)
              )
                return rand()%2;

            if(j == size - 1 && (    /// gdy jest przy dolnej krawedzi
                        matrix[i-1][j].getCurrState() == field::states::BURNING ||
                        matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                        matrix[i][j - 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j - 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j].getCurrState() == field::states::BURNING)
              )
                return rand()%2;


            if (                            /// gdy jest gdzies w srodku
                matrix[i + 1][j - 1].getCurrState() == field::states::BURNING	||
                matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                matrix[i - 1][j - 1].getCurrState() == field::states::BURNING
            )
                return percent_counter_plus(wind_power);

            if (
                matrix[i + 1][j].getCurrState() == field::states::BURNING	||
                matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                matrix[i + 1][j + 1].getCurrState() == field::states::BURNING	||
                matrix[i][j + 1].getCurrState() == field::states::BURNING 	||
                matrix[i - 1][j + 1].getCurrState() == field::states::BURNING

            )
                return percent_counter_minus(wind_power);


            return field::states::UNTOUCHED;

        }
        if(wind_direction == 2) // z prawej
        {

            if(i == 0)
            {

                if (j == 0 &&(         ///gdy jest w lweym gornym rogu
                            matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                            matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                            matrix[i + 1][j].getCurrState() == field::states::BURNING)
                   )
                    return rand()%2;

                if(j == size - 1 &&(    /// gdy jest w lewym dolnym rogu
                            matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                            matrix[i + 1][j - 1].getCurrState() == field::states::BURNING	||
                            matrix[i + 1][j].getCurrState() == field::states::BURNING)
                  )
                    return rand()%2;

                if(                     /// gdy jest przy lewej scianie
                    matrix[i + 1][j - 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                    matrix[i + 1][j].getCurrState() == field::states::BURNING ||
                    matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j + 1].getCurrState() == field::states::BURNING
                )
                    return rand()%2;

                return field::UNTOUCHED;
            }

            if(i == size - 1)
            {

                if(j == 0 &&( ///gdy jest w prawym gornym rogu
                            matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                            matrix[i - 1][j + 1].getCurrState() == field::states::BURNING	||
                            matrix[i][j + 1].getCurrState() == field::states::BURNING)
                  )
                    return rand()%2;

                if(j == size - 1 &&( ///gdy jest w prawy dolnym rogu
                            matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                            matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                            matrix[i][j - 1].getCurrState() == field::states::BURNING)
                  )
                    return rand()%2;

                if(             /// gdy jest przy prawej scianie
                    matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                    matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                    matrix[i - 1][j].getCurrState() == field::states::BURNING ||
                    matrix[i - 1][j + 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j + 1].getCurrState() == field::states::BURNING
                )
                    return rand()%2;

                return field::UNTOUCHED;
            }

            if(j == 0 && (          /// gdy jest przy gornej krawedzi
                        matrix[i-1][j].getCurrState() == field::states::BURNING ||
                        matrix[i - 1][j + 1].getCurrState() == field::states::BURNING ||
                        matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j].getCurrState() == field::states::BURNING)
              )
                return rand()%2;

            if(j == size - 1 && (    /// gdy jest przy dolnej krawedzi
                        matrix[i-1][j].getCurrState() == field::states::BURNING ||
                        matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                        matrix[i][j - 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j - 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j].getCurrState() == field::states::BURNING)
              )
                return rand()%2;


            if (                    /// gdy jest gdzies w srodku
                matrix[i + 1][j].getCurrState() == field::states::BURNING	||
                matrix[i + 1][j + 1].getCurrState() == field::states::BURNING	||
                matrix[i + 1][j - 1].getCurrState() == field::states::BURNING
            )
                return percent_counter_plus(wind_power);

            if(
                matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                matrix[i][j + 1].getCurrState() == field::states::BURNING 	||
                matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                matrix[i - 1][j + 1].getCurrState() == field::states::BURNING	||
                matrix[i - 1][j - 1].getCurrState() == field::states::BURNING
            )
                return percent_counter_minus(wind_power);

            return field::states::UNTOUCHED;

        }
        if(wind_direction == 3) // z dolu
        {

            if(i == 0)
            {

                if (j == 0 &&(         ///gdy jest w lweym gornym rogu
                            matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                            matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                            matrix[i + 1][j].getCurrState() == field::states::BURNING)
                   )
                    return rand()%2;

                if(j == size - 1 &&(    /// gdy jest w lewym dolnym rogu
                            matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                            matrix[i + 1][j - 1].getCurrState() == field::states::BURNING	||
                            matrix[i + 1][j].getCurrState() == field::states::BURNING)
                  )
                    return rand()%2;

                if(                     /// gdy jest przy lewej scianie
                    matrix[i + 1][j - 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                    matrix[i + 1][j].getCurrState() == field::states::BURNING ||
                    matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j + 1].getCurrState() == field::states::BURNING
                )
                    return rand()%2;

                return field::UNTOUCHED;
            }

            if(i == size - 1)
            {

                if(j == 0 &&( ///gdy jest w prawym gornym rogu
                            matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                            matrix[i - 1][j + 1].getCurrState() == field::states::BURNING	||
                            matrix[i][j + 1].getCurrState() == field::states::BURNING)
                  )
                    return rand()%2;

                if(j == size - 1 &&( ///gdy jest w prawy dolnym rogu
                            matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                            matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                            matrix[i][j - 1].getCurrState() == field::states::BURNING)
                  )
                    return rand()%2;

                if(             /// gdy jest przy prawej scianie
                    matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                    matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                    matrix[i - 1][j].getCurrState() == field::states::BURNING ||
                    matrix[i - 1][j + 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j + 1].getCurrState() == field::states::BURNING
                )
                    return rand()%2;

                return field::UNTOUCHED;
            }

            if(j == 0 && (          /// gdy jest przy gornej krawedzi
                        matrix[i-1][j].getCurrState() == field::states::BURNING ||
                        matrix[i - 1][j + 1].getCurrState() == field::states::BURNING ||
                        matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j].getCurrState() == field::states::BURNING)
              )
                return rand()%2;

            if(j == size - 1 && (    /// gdy jest przy dolnej krawedzi
                        matrix[i-1][j].getCurrState() == field::states::BURNING ||
                        matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                        matrix[i][j - 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j - 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j].getCurrState() == field::states::BURNING)
              )
                return rand()%2;


            if (                    /// gdy jest gdzies w srodku
                matrix[i + 1][j + 1].getCurrState() == field::states::BURNING	||
                matrix[i][j + 1].getCurrState() == field::states::BURNING 	||
                matrix[i - 1][j + 1].getCurrState() == field::states::BURNING
            )
                return percent_counter_plus(wind_power);

            if(
                matrix[i + 1][j].getCurrState() == field::states::BURNING	||
                matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                matrix[i + 1][j - 1].getCurrState() == field::states::BURNING	||
                matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                matrix[i - 1][j - 1].getCurrState() == field::states::BURNING
            )
                return percent_counter_minus(wind_power);

            return field::states::UNTOUCHED;

        }
        if(wind_direction == 4) // z lewej
        {

            if(i == 0)
            {

                if (j == 0 &&(         ///gdy jest w lweym gornym rogu
                            matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                            matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                            matrix[i + 1][j].getCurrState() == field::states::BURNING)
                   )
                    return rand()%2;

                if(j == size - 1 &&(    /// gdy jest w lewym dolnym rogu
                            matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                            matrix[i + 1][j - 1].getCurrState() == field::states::BURNING	||
                            matrix[i + 1][j].getCurrState() == field::states::BURNING)
                  )
                    return rand()%2;

                if(                     /// gdy jest przy lewej scianie
                    matrix[i + 1][j - 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                    matrix[i + 1][j].getCurrState() == field::states::BURNING ||
                    matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j + 1].getCurrState() == field::states::BURNING
                )
                    return rand()%2;

                return field::UNTOUCHED;
            }

            if(i == size - 1)
            {

                if(j == 0 &&( ///gdy jest w prawym gornym rogu
                            matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                            matrix[i - 1][j + 1].getCurrState() == field::states::BURNING	||
                            matrix[i][j + 1].getCurrState() == field::states::BURNING)
                  )
                    return rand()%2;

                if(j == size - 1 &&( ///gdy jest w prawy dolnym rogu
                            matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                            matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                            matrix[i][j - 1].getCurrState() == field::states::BURNING)
                  )
                    return rand()%2;

                if(             /// gdy jest przy prawej scianie
                    matrix[i][j - 1].getCurrState() == field::states::BURNING 	||
                    matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                    matrix[i - 1][j].getCurrState() == field::states::BURNING ||
                    matrix[i - 1][j + 1].getCurrState() == field::states::BURNING ||
                    matrix[i][j + 1].getCurrState() == field::states::BURNING
                )
                    return rand()%2;

                return field::UNTOUCHED;
            }

            if(j == 0 && (          /// gdy jest przy gornej krawedzi
                        matrix[i-1][j].getCurrState() == field::states::BURNING ||
                        matrix[i - 1][j + 1].getCurrState() == field::states::BURNING ||
                        matrix[i][j + 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j + 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j].getCurrState() == field::states::BURNING)
              )
                return rand()%2;

            if(j == size - 1 && (    /// gdy jest przy dolnej krawedzi
                        matrix[i-1][j].getCurrState() == field::states::BURNING ||
                        matrix[i - 1][j - 1].getCurrState() == field::states::BURNING ||
                        matrix[i][j - 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j - 1].getCurrState() == field::states::BURNING ||
                        matrix[i + 1][j].getCurrState() == field::states::BURNING)
              )
                return rand()%2;


            if (                    /// gdy jest gdzies w srodku
                matrix[i - 1][j].getCurrState() == field::states::BURNING 	||
                matrix[i - 1][j + 1].getCurrState() == field::states::BURNING	||
                matrix[i - 1][j - 1].getCurrState() == field::states::BURNING
            )
                return percent_counter_plus(wind_power);

            if(
                matrix[i + 1][j].getCurrState() == field::states::BURNING	||
                matrix[i + 1][j + 1].getCurrState() == field::states::BURNING	||
                matrix[i + 1][j - 1].getCurrState() == field::states::BURNING	||
                matrix[i][j + 1].getCurrState() == field::states::BURNING 	||
                matrix[i][j - 1].getCurrState() == field::states::BURNING
            )
                return percent_counter_minus(wind_power);


            return field::states::UNTOUCHED;

        }
    }
    return calculateNextStateRandom(matrix,size,i,j);
}
////////////////////////////////////////////////////////////////////////
bool calculateAndSetNextStatesForFieldMatrixRANDOMandWIND(field** matrix, const int size)
{
    if (size < 1 || matrix == nullptr)
        return false;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j )
        {
            matrix[i][j].setNextState(calculateNextStatesRANDOMandWIND(matrix,size,i,j,matrix[i][j].getwind_direction(),matrix[i][j].getwind_power()));
        }
    }
    return true;
}
////////////////////////////////////////////////////////////////////////

bool calculateAndSetNextStatesForFieldMatrix(field** matrix, const int size)
{
    if (size < 1 || matrix == nullptr)
        return false;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j )
        {
            matrix[i][j].setNextState(calculateNextState(matrix,size,i,j));
        }
    }
    return true;
}

////////////////////////////////////////////////////////////////////////

bool calculateAndSetNextStatesForFieldMatrixSTAR(field** matrix, const int size)
{
    if (size < 1 || matrix == nullptr)
        return false;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j )
        {
            matrix[i][j].setNextState(calculateNextStateStar(matrix,size,i,j));
        }
    }
    return true;
}

////////////////////////////////////////////////////////////////////////

bool calculateAndSetNextStatesForFieldMatrixRANDOM(field** matrix, const int size)
{
    if (size < 1 || matrix == nullptr)
        return false;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j )
        {
            matrix[i][j].setNextState(calculateNextStateRandom(matrix,size,i,j));
        }
    }
    return true;
}
