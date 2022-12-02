#include "fcpp.hh"


bool deck_check(int deck[], int n) {
	//Überprüfe ob das Deck in Ausgangsreihenfolge ist.
	bool ist_richtig = true;
	for(int i = 0; i < n; i++) {
		if (deck[i] != i) ist_richtig = false; }
	std::cout << ist_richtig << std::endl;
	return (ist_richtig);
};


int main(int argc, char* argv[]) {
	int deckgröße = enter_int();
	//	if (deckgröße % 2 != 0) return(69);
	int deck[deckgröße];
	// Initailisiere das Deck
	for(int j = 0; j <= deckgröße; j++) {
		deck[deckgröße] = j;
	};
		for(int i = 0; i < deckgröße; i++) {
			print(deck[i]);}
	int Zähler = 0; // Zähle die Schleifendurchläufe mit
	bool kontrolle = false; //setze eine Kontrollvariable auf false
	std::cout << "Kontrolle" << std::endl;
	while(kontrolle == false) {
		//Vollziehe einen Perfect_Out shuffle
		int hilfsdeck[deckgröße];
		for(int i = 0; i <= deckgröße; i++) {
			hilfsdeck[i] = deck[i]; };
		for(int i = 0; i < deckgröße / 2; i++) {
			deck[2*i] = hilfsdeck[i];
			deck[2*i +1] = hilfsdeck[i + (deckgröße/2)];
		};
	//	for(int i = deckgröße / 2; i <= deckgröße; i++) {


//			deck[2*i+1] = hilfsdeck[i];
//	}	};

		for(int i = 0; i < deckgröße; i++) {
			print(deck[i]);

		};
		print(Zähler);
		kontrolle =  deck_check(deck,deckgröße);
		Zähler++;
		if (Zähler > 10) kontrolle = true;
	};
	print(Zähler);
	std::cout << "Teil A abgeschlossen" << std::endl;
	return(0);
	Zähler = 0; // Zähle die Schleifendurchläufe mit
	kontrolle = false; //setze eine Kontrollvariable auf false
	while(kontrolle == false) {
		//Vollziehe einen Perfect_Out shuffle
		int hilfsdeck[deckgröße];
		for(int i = 0; i <= deckgröße; i++) {
			hilfsdeck[i] = deck[i]; };
		for(int i =0 ; i < deckgröße / 2; i++) {
			deck[2*i+1] = hilfsdeck[i];
			deck[2*i] = hilfsdeck[i + (deckgröße/2)];
		};
	//	for(int i = deckgröße / 2; i <= deckgröße; i++) {


	//		deck[2*i] = hilfsdeck[i];
	//	};


		kontrolle =  deck_check(deck, deckgröße);
		Zähler++;
	//	print(Zähler);
	};
	/*while(kontrolle == false) {
	//Vollziehe einen Perfect_Out shuffle

	//Vollziehe einen Perfect_In Schuffle

	kontrolle =  deck_check(deck, Zähler);
	Zähler++;
	};
	print(Zähler); */
	return(0);
}	

