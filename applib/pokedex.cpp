
#include "pokedex.h"
#include <iostream>

using namespace std;

// Your code goes here

// initialize variables
static const int MAX = 10;
int msize = 0;
string pokemons[MAX];

// Constructor, initizlize array with empty strings
Pokedex::Pokedex() {
  for (int i = 0; i < MAX; i++) {
    pokemons[i] = "";
  }
}

// return amount of pokemon in array
int Pokedex::size() const { return msize; }

// return max amount of pokemon allowed
int Pokedex::max_size() { return MAX; }

// checks to see if array is empty. Returns true if no pokemon, false if there's
// at least one
bool Pokedex::empty() const { return (msize == 0); }

// returns pokemon at given index. If passed int is out of bounds or if there is
// no pokemon in that index, an error statment is printed
const string &Pokedex::at(int n) const {
  static const string emptyStr;

  if (n < 0 || n >= msize || pokemons[n].empty()) {
    cerr << "Error: Cannot access element at " << n << endl;
  } else {
    return pokemons[n];
  }

  return emptyStr;
}

// returns first pokemon, error statement is printed if array is empty
const string &Pokedex::front() const {
  if (empty()) {
    cerr << "Error: Cannot access front for empty Pokedex" << endl;
  }

  return pokemons[0];
}

// returns last pokemon, error statement is printed if array is empty
const string &Pokedex::back() const {
  if (empty()) {
    cerr << "Error: Cannot access back for empty Pokedex" << endl;
  } else {
    return pokemons[size() - 1];
  }

  return pokemons[0];
}

// inserts a pokemon in the array making sure to stay in alphabetical order.
// ensures the pokemon is placed correctly and all other values are shifted down
void Pokedex::insert(const string &pokemon) {
  msize++;
  string tempPokemon = pokemon;

  for (int i = 0; i < size(); i++) {
    if (i == size() - 1) {
      pokemons[i] = tempPokemon;
      break;
    } else if (tempPokemon > pokemons[i]) {

    } else if (tempPokemon < pokemons[i]) {
      string temp = pokemons[i];
      pokemons[i] = tempPokemon;
      tempPokemon = temp;
    }
  }
}

// removes the pokemon in the back. prints error statement if pokedex is empty
void Pokedex::pop_back() {
  if (!empty()) {
    pokemons[size() - 1] = "";

    msize--;
  } else {
    cerr << "Error: Cannot pop_back for empty Pokedex" << endl;
  }
}

// erases a pokemon on given index. prints error statement if index is out of
// bounds or there is no pokemon there
void Pokedex::erase(int n) {
  if (n >= size() || n < 0 || pokemons[n].empty()) {
    cerr << "Error: Cannot erase element at " << n << endl;
  } else {
    pokemons[n] = "";

    for (int i = 0; i < size() - 1; i++) {
      if (pokemons[i].empty()) {
        pokemons[i] = pokemons[i + 1];
        pokemons[i + 1] = "";
      }
    }

    msize--;
  }
}

// Creates a string of the array of pokemon for tests in main.
ostream &operator<<(ostream &out, const Pokedex &pdx) {
  out << "[";
  for (int i = 0; i < pdx.size(); i++) {
    out << pdx.pokemons[i];
    if (i < pdx.size() - 1) {
      out << ", ";
    }
  }
  out << "]";
  return out;
}