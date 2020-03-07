
#include "Deck.h"

//Picks the suit based on the card number
int ChooseSuit(int cardNum) {
	if (cardNum < 13) {
		return 1;
	}
	else if (cardNum > 12 && cardNum < 26) {
		return 2;
	}
	else if (cardNum > 25 && cardNum < 39) {
		return 3;
	}
	else if (cardNum > 38) {
		return 4;
	}
	return NULL;
}
//picks the face card value based on the number
std::string FaceCard(int a) {
	switch (a) {
	case 1:
		return "Ace";
		break;
	case 11:
		return "Jack";
		break;
	case 12:
		return "Queen";
		break;
	case 13:
		return "King";
		break;
	}
	std::string b = std::to_string(a);
	return b;
}
void DeckCreation(int c[], std::string a[]) {
	int cardVal = 0;
	std::string suit;
	for (int i = 0; i < 52; i++) {
		int b = ChooseSuit(i);
		switch (b) {
		case 1:
			cardVal = i + 1;
			suit = "Diamonds";
			break;
		case 2:
			cardVal = i - 12;
			suit = "Hearts";
			break;
		case 3:
			cardVal = i - 25;
			suit = "Spades";
			break;
		case 4:
			cardVal = i - 38;
			suit = "Clubs";
			break;
		}

		a[i] = FaceCard(cardVal) + " of " + suit;
		c[i] = cardVal;

	}

}

//Reads the arrays
void ReadArray(std::string c[], int v[]) {
	for (int i = 0; i < 52; i++) {
		std::cout << c[i] << "Value: " << v[i] << "\n";
	}
}
//start of the main function
int main() {
	std::string n;
	int count = 53;
	//Makes deck call random
	srand(time(0));
	//Creates Deck
	int valueArray[52];
	std::string cardArray[52];
	DeckCreation(valueArray, cardArray);
	//Drawing loop
	do {
		int i = 0;
		//finding a card that hasn't been drawn
		do {
			i = rand() % 52;		
		} while (cardArray[i] == "drawn");
		//Informing you of your draw
		std::cout << "You drew the " + cardArray[i];
		cardArray[i] = "drawn";
		count--;
		//Checking for final draw.
		if (count > 1) {
			std::cout << "\n Would you like to draw? (y/n)";
			std::cin >> n;
		}
		else {
			std::cout << "\n You've drawn all the card. Press any button to quit. ";
			std::cin >> n;
			return 0;
		}

	} while (count > -1 && n == "y");
}
