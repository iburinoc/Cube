std::string remove_fours(std::string moves) {
	for(int i = 0; i + 4 < moves.size(); i++) {
		/* test if theres a contiguous block of 4 chars */
		bool same = true;
		for(int j = i + 1; same && (j < i + 4); j++) {
			same = moves[j] == moves[i];
		}
		if(same) {
			std::string 
			return remove_fours(moves.substr());
		}
	}
}

std::string assemble(std::string hlm) {
	
}
