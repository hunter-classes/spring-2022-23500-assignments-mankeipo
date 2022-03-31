#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
	bool spellbook = false;
	bool potion = false;
	bool wand = false;
	for(int i = 0; i < moves.length(); i++) {
		if(moves[i] == 'N') {
			start = start->north;
		} else if (moves[i] == 'S') {
                        start = start->south;
		} else if (moves[i] == 'W') {
                        start = start->west;
		} else if (moves[i] == 'E') {
                        start = start->east;
		}
		if(start->whatsHere == Item::SPELLBOOK) {
			spellbook = true;
		} else if(start->whatsHere == Item::POTION) {
                    	potion = true;	
		} else if(start->whatsHere == Item::WAND) {
                    	wand = true;
		}
	}
	if(spellbook && potion && wand) {
		return true;
	} else {
		return false;
	}
}
