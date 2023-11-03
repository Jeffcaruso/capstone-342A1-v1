
#include "pokedex.h"
#include <iostream>

using namespace std;

/**
 *  Pokedex constructor: create empty Pokedex
 */
Pokedex::Pokedex() {
  // nothing needed to be added, variables
  //   already initialized
}

/**
 * gets size of pokeball
 *
 * @return int size
 */
int Pokedex::size() const { return msize; }

/**
 * gets maximum amount of pokemons the pokeball
 * can contain
 *
 * @return int maximum size
 */
int Pokedex::max_size() { return MAX; }

/**
 * shows whether the pokeball is empty
 * or not
 *
 * @return bool isEmpty
 */
bool Pokedex::empty() const { return msize == 0; }

/**
 * returns pokemon at index n
 *
 * @param n int index
 *
 * @return string& pokemon
 */
const string &Pokedex::at(int n) const {
  static string error = "error";

  if (n < 0 || n >= msize) {
    cerr << "no pokemon at index " << n << endl;
    return error;
  }

  return pokemons[n];
}

/**
 * gets pokemon at the front of the pokeball
 *
 * @return string& Pokemon at the front
 */
const string &Pokedex::front() const {
  static string error = "error";

  if (msize == 0) {
    cerr << "no pokemon" << endl;
    return error;
  }

  return pokemons[0];
}

/**
 * gets pokemon at the back of the pokeball
 *
 * @return string& Pokemon at the back
 */
const string &Pokedex::back() const {
  static string error = "error";

  if (msize == 0) {
    cerr << "no pokemon" << endl;
    return error;
  }

  return pokemons[msize - 1];
}

/**
 * puts a pokemon into the pokeball
 *
 * @param pokemon string& pokemon
 */
void Pokedex::insert(const string &pokemon) {
  int insertIndex = -1; // index of where the pokemon will be added
  string move[MAX];     // contains pokemon that needs to move
  // for the newly added pokemon

  if (msize == 0) {
    // if no pokemon in pokeball, just put at the start of array
    pokemons[0] = pokemon;
  } else if (msize == MAX) {
    // pokemon full, show error
    cerr << "Pokeball full" << endl;
  } else {
    for (int i = 0; i < msize; i++) {
      // finds first index found where a pokemon is aphabetically greater
      if (pokemons[i] > pokemon && insertIndex == -1) {
        insertIndex = i;
      }

      // if insertion index found, start recording pokemon that needs to move
      if (insertIndex > -1) {
        move[i] = pokemons[i];
      }
    }

    // move pokemon if necessary, if not just add the new pokemon at the end
    if (insertIndex != -1) {
      pokemons[insertIndex] = pokemon;
      for (int i = insertIndex; i < msize; i++) {
        pokemons[i + 1] = move[i];
      }
    } else {
      pokemons[msize] = pokemon;
    }
  }

  // only increases current pokeball size if no error was found
  msize = msize < MAX ? msize + 1 : msize;
}

/**
 * gets rid of last pokemon
 */
void Pokedex::pop_back() {
  if (msize == 0) {
    cerr << "no pokemons to release" << endl;
  } else {
    pokemons[msize - 1] = "";
    msize = msize - 1;
  }
}

/**
 * gets rid of pokemon at index n
 *
 * @param n int index
 */
void Pokedex::erase(int n) {
  if (n < 0 || n >= msize) {
    cerr << "no pokemon at index " << n << endl;
  } else {
    // shift pokemons to the left
    for (int i = n; i < msize - 1; i++) {
      pokemons[i] = pokemons[i + 1];
    }

    // get rid of last unshifted pokemon
    pokemons[msize - 1] = "";
    msize = msize - 1;
  }
}

/**
 * stream of pokeball
 */
ostream &operator<<(ostream &out, const Pokedex &pdx) {
  out << "[";

  for (int i = 0; i < pdx.size(); i++) {
    if (i != 0) {
      out << ", ";
    }
    out << pdx.at(i);
  }

  out << "]";

  return out;
}
