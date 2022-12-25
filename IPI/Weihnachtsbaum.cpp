/* To do:
 *Die Querstriche bei den Ästen einfügen
 * Den Stamm einfügen
 * Die Funktion für die Schneeflocken schreiben
 * Die Funktion für die Christbaumkugeln schreiben
 * Die printfunktion modifizieren so dass die zu jedem char die passende farbe wählt */





#include<string.h>
#include<iostream>
#include<random>
#include<string.h>



/*Weihnachstbaum
 *
 * Am meisten Sinn macht es den Baum als String auszugeben... Jede schicht wird zu einem Strin gemacht. Als erstes wird die höhe des Baumes eingelesen um die Anzahl der Strings zu bestimmen... danach wird der Baum in von unten nach oben wachsende sektionen aufgeteil, welche die Äste darsetellen.. das macht eine Funktion... davor muss aber noch die höhe für den Stern und für den Stamm abgezone werden... */

class Weihnachstbaum {
	public:
		int Baumhoehe;
		const int Baumbreite = 120;
		int links,rechts;
		char Baumschicht[120]; //Breite der Ausgabe
		int Glocken_Wahrscheinlichkeit = 25; //zwichen 1 und 100; Wahrscheinlichkeit für Glocken
		int Schnee_Wahrscheinlichkeit = 7; // zwiscen 1 und 100; Wahrscheinlichkeit für schnee


		Weihnachstbaum(int hoehe) {
			Baumhoehe = hoehe;
			links = Baumbreite/2;
			rechts = Baumbreite/2;

			for(int i = 0; i < Baumbreite ; i++) {
				Baumschicht[i] = ' ';
			};

		}

		void clear_schicht() {
			for(int i = 0; i < Baumbreite ; i++) {
				Baumschicht[i] = ' ';
			};
		}
		void Pflanze_Baum() {
			//Diese Funktion ruft die anderen Funktionen auf.

			sektionenaufteilung(); }
	private:

		void printlayer(){


			for(int i = 0; i < Baumbreite; i++) {

				switch (Baumschicht[i]) {
					case '/':{ std::cout << "\e[0;32m/\e[0m";
							break;}

					case '\\':{  std::cout << "\e[0;32m\\\e[0m";
							break;}

					case '*' :{ std::cout << "*";
							break; }

					case '@' :{ std::cout << "\e[0;31m@\e[0m";
							break; }

					case ' ' :{ std::cout << " ";
							break; }	

					case '+' : { std::cout << "\e[1;33m+\e[0m";
							   break; }
					case '_' : { std::cout << "\e[0;32m_\e[0m";
							   break; }
					case '|' : { std::cout << "\e[0;33m|\e[0m";
							   break; }
				}

			};
			std::cout << std::endl;
			clear_schicht();
		}
		void glocken() {


			for(int i = links +1; i < rechts  ; i++) {
			
			bool Glockenchance = (rand() % 100 ) < Glocken_Wahrscheinlichkeit;
			if (Glockenchance == true)
				if(Baumschicht[i] == ' ')
					Baumschicht[i] = '@';
			};

		}
		void schnee() {


			for(int i = 0; i < links -1; i++) {
				bool Schneechance = (rand() % 100 ) < Schnee_Wahrscheinlichkeit;
				if (Schneechance == true)
					Baumschicht[i] = '*';

			};
		
			for(int i = rechts +1; i < Baumbreite; i++) {
				bool Schneechance = (rand() % 100 ) < Schnee_Wahrscheinlichkeit;
				if (Schneechance == true)
					Baumschicht[i] = '*';

			};
				
		}
		void sektionenaufteilung() {
			//Scap diese Idee.. ich machs mit schleifen... Ich fange in der Mitte an mit dem Stern.. dann gehe ich eins nach außen und nach unten und die ersten / bzw in andere richtung werden in den String eingesetzt... dann wird wenn genug platzt im baum ist glocken eingefügt in random Farbe und dann noch schnee drann und geprintet.. die Koordinaten der letzten Äste werden gemerkt und dort wird weitergearbeitet.. die Astbreite wird durch eine laufvariable immer vergrößert... befor aber Eine neue Sektion beginnt wird aber überprüft ob sie in den übrigen Platz reinpasst,, wenn nicht wird der Stamm gepflanzt ⁄ option i
			int lauf = 0;
			int gesamthoehe = 0;
			Baumschicht[links] = '+';
			links -= 1;
			rechts += 1;
			printlayer();
			while (gesamthoehe < Baumhoehe -1) {
				lauf++;

				for(int i = 0; i < lauf ; i++) {

					Baumschicht[links] = '/';
					Baumschicht[rechts] ='\\';
					links--;
					rechts++;
					gesamthoehe++;
					//Hier muss die Zeilenweitergegeben werden
					//Schnee();
					//Glocken();
					glocken();
					schnee();
					printlayer();}
				Baumschicht[links] = '/';
				Baumschicht[rechts] = '\\';

				for(int i = 1; i < lauf; i++) {
					Baumschicht[links + i] = '_';
					Baumschicht[rechts - i] = '_';
					gesamthoehe++;
				};
				if (gesamthoehe + lauf < Baumhoehe) {
					schnee();
					printlayer();

				}	else {


					for(int i = 0; i < Baumbreite /2  - links -  lauf; i++) {
						Baumschicht[links + lauf + i  -1] = '_';
						Baumschicht[rechts - lauf -i +1] = '_'; 

					};
					printlayer();


					for(int i = 0; i < 3 ; i++) {
						Baumschicht[Baumbreite/2 -1] = '|';
						Baumschicht[Baumbreite/2 +1] = '|';
						gesamthoehe++;
						schnee();
						printlayer();

					};
					break;
				}
				links = links + lauf/2 +1;
				rechts = rechts - lauf/2 -1 ; }

			//Wenn die höhe erreiht ist, ersetzt den letzten Astzug durch den Astzug mit Stamm
		}
		//Diese Funktion für vor und nach dem Baum bis zu 3 Schneeflocken hinzu	
		//Diese Funktion fügt zwischen den Ästen glocken ein
		//void glocken();
		////Diese Funktion returnt farbige  

		//Diese Funktion fügt farben zu strings hinzu
		//Sie erhält einen String und gibt ihn dann stückweise aus und fügt passende Farben hinz: Weiss für *, grün für die äste und random für glocken


		/* Jetzt muss ich mir überlegen wie ich den Bau insgesamt ausgeben will... entweder speichere ich den Ganzen baum als Stringsammlung ab, ich speichere immer nur einen Teil ab und gebe dann aus oder ich gebe ihn kontinuerlich aus sobald ich eine Zeile fertig habe.
		*/
};


int main(int argc, char* argv[]) {
	std::cout << "Geben sie bitte die Baumhoehe ein: ";
	int hoehe;
	std::cin >> hoehe;
	Weihnachstbaum a(hoehe);
	a.Pflanze_Baum();
	return(0);
}
