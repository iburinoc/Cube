#include <utility>

#include "trie.h"

/* root constructor */
Trie::Trie() : c('\0'), r("") {}

/* node constructor */
Trie::Trie(char c, std::string r) : c(c), r(r) {}

/* copy constructor */
Trie::Trie(Trie const& that) : subs(that.subs), r(that.r), c(that.c) {}

/* move constructor */
Trie::Trie(Trie&& that) : subs(std::move(that.subs)), r(std::move(that.r)), c(that.c) {}

int Trie::find(char c) const {
	for(int i = 0; i < subs.size(); i++) {
		if(subs[i].c == c) {
			return i;
		}
	}

	return -1;
}

const Trie Trie::match(std::string in) const {
	if(in.size() == 0) {
		return *this;
	}

	int i = find(in[0]);
	if(i == -1) {
		return Trie();
	}

	return subs[i].match(in.substr(1));
}

const bool Trie::insert(Trie t, std::string in) {
	if(in.size() == 0) {
		return false;
	}

	int i = find(in[0]);
	if(in.size() == 1) {
		if(i == -1) {
			subs.push_back(t);
			return true;
		} else {
			return false;
		}
	} else {
		return subs[i].insert(t, in.substr(1));
	}
}
