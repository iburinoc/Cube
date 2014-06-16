#ifndef TRIE_H
#define TRIE_H

/* Simple radix trie implementation used to store key value pairs from 
 * the output of optimizers */

#include <vector>
#include <string>

//#define TRIE_DEBUG

class Trie {
private:
#ifdef TRIE_DEBUG
public:
#endif
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
	const std::string match(std::string in) const;

	bool insert(std::string key, std::string r);
};

#endif
