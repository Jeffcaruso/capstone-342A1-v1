#include "Inc/pokedex.h"

const int Pokedex::size()
{
    return 0;
}

const bool Pokedex::empty()
{
    return false;
}

ostream &operator<<(ostream &out, const Pokedex &pdx)
{
    cout << "not correct result (intentional)" << endl;
}
