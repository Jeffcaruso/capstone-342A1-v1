
#include "pokedex.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Your code goes here

// constructor creates empty pokedex once called
Pokedex::Pokedex() {}

// size returns msize which is the size of the pokedex
int Pokedex::size() const { return msize; }

// max_size returns the MAX int which is the maximum size of the pokedex
int Pokedex::max_size() { return MAX; }

// empty returns true if the pokedex is empty or false if it contains pokemon
bool Pokedex::empty() const { return msize == 0; }

// at checks the bounds of the input n and returns either the index 0 of the
// pokedex or nth index
const string &Pokedex::at(int n) const {

  if (n < 0 || n >= msize) {
    cerr << "Error: Index out of bounds." << endl;
    return pokemons[0];
  }
  return pokemons[n];
}

// checks if pokdex is empty first, either way it returns the first index 0
const string &Pokedex::front() const {
  if (empty()) {
    return pokemons[0];
  }
  return pokemons[0];
}

// back takes the pokedex size and subtracts it by one to get the index of the
// last element in the pokedex
const string &Pokedex::back() const {
  if (empty()) {
    return pokemons[0];
  }
  return pokemons[msize - 1];
}

// insert checks first if the pokedex is full then looks for a position where
// the input pokemon is alphabetically before the ith term thats where it will
// get placed once i is done incrememnting (position of insertion is found)
// every element after i gets moved right to insert pokemon
void Pokedex::insert(const string &pokemon) {

  if (msize == MAX) {
    cerr << "Error: Pokedex is full." << endl;
    return;
  }
  int i = 0;
  while (i < msize && pokemons[i] < pokemon) {
    i++;
  }
  for (int j = msize; j > i; j--) {
    pokemons[j] = pokemons[j - 1];
  }
  pokemons[i] = pokemon;
  msize++;
}

// pop_back checks if msize is first populated if it is then the last element
// gets deleted by decreasing the pokedex size by one
void Pokedex::pop_back() {
  if (msize > 0) {
    msize--;
  }
}

// erase first determines if n is in bounds if it is then each element after is
// moved left from nth index and onward via for loop
void Pokedex::erase(int n) {

  if (n >= 0 && n < msize) {
    for (int i = n; i < msize - 1; i++) {
      pokemons[i] = pokemons[i + 1];
    }
    msize--;
  } else {
    cerr << "Error: Erase index is out of bounds." << endl;
  }
}

// ostream formats the output by first outputing a opening square brack then we
// go through each element in pdx and print it out
// at the same time we only output a , after each element until we reach the
// last element then we stop right before and close with a square bracket
ostream &operator<<(ostream &out, const Pokedex &pdx) {
  out << "[";
  for (int i = 0; i < pdx.size(); i++) {
    out << pdx.at(i);
    if (i < pdx.size() - 1) {
      out << ", ";
    }
  }
  out << "]";
  return out;
}
