#include <utility>

#include "trie.h"

/* root constructor */
Trie::Trie() : c('\0'), r("") {}

/* node constructor */
Trie::Trie(char c, std::string r) : c(c), r(r) {}

/* copy constructor */
Trie::Trie(Trie const& that) : subs(that.subs), c(that.c), r(that.r) {}

/* move constructor */
Trie::Trie(Trie&& that) : subs(std::move(that.subs)), c(that.c), r(std::move(that.r)) {}

const std::string Trie::result() const {
	return r;
}

/* find the character in the sub tries */
int Trie::find(char c) const {
	for(int i = 0; i < subs.size(); i++) {
		if(subs[i].c == c) {
			return i;
		}
	}

	return -1;
}

/* search recursively for the node matching the given string */
const std::string Trie::match(std::string in) const {
	if(in.size() == 0) {
		return r;
	}

	int i = find(in[0]);
	if(i == -1) {
		return "";
	}

	return subs[i].match(in.substr(1));
}

/* insert a key value pair */
bool Trie::insert(std::string key, std::string r) {
	if(key.size() == 0) {
		return false;
	}

	int i = find(key[0]);
	if(key.size() == 1) {
		if(i == -1) {
			subs.push_back(Trie(key[0], r));
			return true;
		} else {
			subs[i].r = r;
			return true;
		}
	} else {
		if(i == -1) {
			subs.push_back(Trie(key[0], ""));
			i = subs.size()-1;
		}
		return subs[i].insert(key.substr(1), r);
	}
}

