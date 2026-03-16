#ifndef FIELD_H
#define FIELD_H

class field
{
public:
    enum states { UNTOUCHED, BURNING, ROCK, BURNING2, BURNT}; /// 0 = untouched, 1 = burning, 2 = rock, 3 = burning1, 4 = burnt

    field(int = states::UNTOUCHED);
    virtual ~field();

    int getCurrState() const; /// podaje aktualny stan
    int getNextState() const; /// podaje nastepny stan
    int getwind_direction() const;
    int getwind_power() const;
    void setCurrState(int); /// ustawia aktualny stan
    void setNextState(int);     ///ustawia nastepny stan
    void forwardState();    /// zamienia stan aktualny na nastepny
    void set_wind_direction(int);
    void set_wind_power(int);

protected:
    int currentState;
    int nextState;
    int wind_direction;
    int wind_power;
};


int percent_counter_plus(int wind_power);
int percent_counter_minus(int wind_power);
int calculateNextState(field** matrix, const int size, int i, int j); /// sprawdza nastepny stan
bool calculateAndSetNextStatesForFieldMatrix(field** matrix, const int size); ///zamienia stany la calej tablicy
bool calculateAndSetNextStatesForFieldMatrixRANDOM(field** matrix, const int size);
bool calculateAndSetNextStatesForFieldMatrixSTAR(field** matrix, const int size);
bool calculateAndSetNextStatesForFieldMatrixRANDOMandWIND(field** matrix, const int size);
int calculateNextStateStar(field** matrix, const int size, int i, int j);
int calculateNextStateRandom(field** matrix, const int size, int i, int j);
int calculateNextStatesRANDOMandWIND(field** matrix, const int size, int i, int j,int wind_direction, int wind_power);


#endif // FIELD_H
