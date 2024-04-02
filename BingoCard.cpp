#include "BingoCard.h"

/* TODO: Set board_size equal to size
 *		 initialize board and marked with "new" vectors of vectors
 *		 use a for loop to put new vector<int> and new vector<bool> objects in board and marked
 *		 call fill()
 */
BingoCard::BingoCard(int size) {
	board_size = size;
	board = new vector<vector<int>*>(size);
	marked = new vector<vector<bool>*>(size);

	for (int i = 0; i < size; i++) {
		(*board)[i] = new vector<int>(size);
		(*marked)[i] = new vector<bool>(size);
	}
	fill();
}

/* TODO: Print all the values in board in a board_size x board_size grid
 *		 using parentheses around numbers which have been called
 *		 check the output example on canvas as a guide for formatting
 *		 
 * HINT: using a stringstream object makes the formatting a bit easier
 */
string BingoCard::toString() {
	stringstream ss;
	for (int row = 0; row < board_size; row++) {
		for (int col = 0; col < board_size; col++) {
			if ((*marked)[row]->at(col)) {
				ss << "(" << setw(2) << (*board)[row]->at(col) << ") ";

			}
			else {
				ss << setw(4) << (*board)[row]->at(col) << " ";
			}
		}
		ss << endl;
	}
	return ss.str();
}

/* TODO: cout which number is being called
 *		 then loop through the board to 
 *		 check for that value, and mark it off
 *       if found on marked.
 */
void BingoCard::call(int num) {
	cout << "Calling number: " << num << endl;
	for (int row = 0; row < board_size; row++) {
		for (int col = 0; col < board_size; col++) {
			if ((*board)[row]->at(col) == num) {
				(*marked)[row]->at(col) = true;
			}
		}
	}
}


/* TODO: loop through the board, setting all marked
 *       values to false 
 */
void BingoCard::clearBoard() {
	for (int row = 0; row < board_size; row++) {
		for (int col = 0; col < board_size; col++) {
			(*marked)[row]->at(col) = false;
		}
	}
}


/* HINT: Use fill as a template for looping through the board
 *		 You may also change out badRand for randomfunc if you
 *		 want to test code with actually randomly generated boards
 */
void BingoCard::fill() {
	vector<int> range{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	for (int col = 0; col < board_size; col++) {
		random_shuffle(range.begin(), range.end(), badRand);
		for (int row = 0; row < board_size; row++) {
			board->at(row)->at(col) = range.at(row) + (15 * col);
			marked->at(row)->at(col) = false;
		}
	}
}

/* TODO: Use loops to check if there are any vertical 
 *       (all values in a column marked) bingos.
 */
bool BingoCard::checkVertical() {
	for (int col = 0; col < board_size; col++) {
		bool allMarked = true;
		for (int row = 0; row < board_size; row++) {
			if (!(*marked)[row]->at(col)) {
				allMarked = false;
				break;
			}
		}
		if (allMarked) {
			return true;
		}
	}
	return false;
}

/* TODO: Use loops to check if there are any horizontal 
/ *       (all values in a row marked) bingos.
 */
bool BingoCard::checkHorizontal() {
	for (int row = 0; row < board_size; row++) {
		bool allMarked = true;
		for (int col = 0; col < board_size; col++) {
			if (!(*marked)[row]->at(col)) {
				allMarked = false;
				break;
			}
		}
		if (allMarked) {
			return true;
		}
	}
	return false;
}

/* TODO: Use loops to check if there is a bingo on
 *       either of the two main diagonals.
 */
bool BingoCard::checkDiagonal() {
	bool diagonal1Marked = true;
	bool diagonal2Marked = true;

	for (int i = 0; i < board_size; i++) {
		if (!(*marked)[i]->at(i)) {
			diagonal1Marked = false;
		}
		if (!(*marked)[i]->at(board_size - 1 - i)) {
			diagonal2Marked = false;
		}
	}
	return diagonal1Marked || diagonal2Marked;
}

/* TODO: Call checkVertical, checkHorizontal, and checkDiagonal
 /*       to search for bingos on the card. Remember that this should
 *       return true if ANY of them are true, and false if ALL of them
 *       are false.
 */
bool BingoCard::checkBingo() {
	return checkVertical() || checkHorizontal() || checkDiagonal();
}


//Do not touch these two functions.
int randomfunc(int j) {
	return rand() % j;
}

int badRand(int j) {
	return 100 % j;
}
