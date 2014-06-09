#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

class Trie {
private:
	std::vector<Trie> subs;
	const char c;
	std::string r;

public:
	/* root constructor */
	Trie();

	/* node constructor */
	Trie(char c, std::string r);

	/* copy constructor */
	Trie(Trie const& that);

	/* move constructor */
	Trie(Trie&& that);

	const std::string result() const;

	int find(char c) const;

	/* returns a tree with null char and empty string if not matched */
	const Trie match(std::string in) const;

	bool insert(std::string key, std::string r);
};

#endif
