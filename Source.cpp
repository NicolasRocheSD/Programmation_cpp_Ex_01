#include <iostream>
#include <iomanip>


// Données globales
char board[3][3] = { {'\0 ','\0 ','\0'},{'\0 ','\0 ','\0'},{'\0','8','9'} };
char turn = 'X';
bool draw = false;

int VictoryPlayer1 = 0;
int VictoryPlayer2 = 0;


// Mise en forme du titre
void header() {
	std::string GameName = "Jeu du Tic-Tac-Toe";
	int GameNameLength = GameName.length();

	int TotalWidth = 120;
	int Center = (TotalWidth / 2) + (GameNameLength / 2);

	std::string LineGameName("");
	LineGameName.insert(0, TotalWidth, '_');

	std::cout << LineGameName << std::endl << std::endl
	<< std::setw(Center) << GameName << std::endl // setw(x)= Longeur de la string, dernier caractère sera à la place x
	<< LineGameName << std::endl << std::endl << std::endl;
}



// Mise en forme des règles
void rules() {
	std::string RulesTitle = "Les regles";
	int RulesTitleLength = RulesTitle.length();

	std::string LineRulesTitle("");
	LineRulesTitle.insert(0, RulesTitleLength+3, '_');

	std::cout << LineRulesTitle << std::endl << std::endl
	<< RulesTitle << std::endl
	<< LineRulesTitle << std::endl << std::endl;


	std::cout << "Chaque joueur a son propre symbole : X ou O." << std::endl 
		<< "Les joueurs placent leur symbole chacun leur tour." << std::endl
		<< "Le but du jeu est de reussir a aligner 3 symboles identiques horizontalement, verticalement ou en diagonale avant son adversaire." << std::endl
		<< "Si la grille est completee sans vainqueur, il y a alors egalite." << std::endl << std::endl << std::endl;
}




// Affichage du jeu
void boarddisplay() {
	std::string BoardTitle = "Le Jeu";
	int BoardTitleLength = BoardTitle.length();

	std::string LineBoardTitle("");
	LineBoardTitle.insert(0, BoardTitleLength+3, '_');

	std::cout << LineBoardTitle << std::endl << std::endl
	<< BoardTitle << std::endl
	<< LineBoardTitle << std::endl << std::endl;


	std::cout << "   ""       |       |       " << std::endl;
	std::cout << "   ""   "<<board[0][0]<<"   |   "<<board[0][1]<< "   |   " << board[0][2] << "   " << std::endl;
	std::cout << "   ""_______|_______|_______" << std::endl;
	std::cout << "   ""       |       |       " << std::endl;
	std::cout << "   ""   " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << std::endl;
	std::cout << "   ""_______|_______|_______" << std::endl;
	std::cout << "   ""       |       |       " << std::endl;
	std::cout << "   ""    " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << std::endl;
	std::cout << "   ""       |       |       " << std::endl << std::endl << std::endl;
}




// Définir à quel joueur est-ce le tour de jouer, ainsi que son choix
void player_turn() {
	int cell = 0;
	int row, column;

	int TotalVictory = VictoryPlayer1 + VictoryPlayer2;

	if (TotalVictory % 2 == 0) {
		turn == 'X';
	}
	else {
		turn == 'O';
	}




	if (turn == 'X') {
		std::cout << "-- Tour du Joueur 1 [X] --"<< std::endl;
	}
	else if (turn == 'O') {
		std::cout << "-- Tour du Joueur 2 [O] --"<< std::endl;
	}

	std::cout << "Dans quelle case souhaitez-vous placer votre symbole ?" << std::endl;
	std::cin >> cell;

	switch (cell) {
		case 1: row = 0; column = 0; break;
		case 2: row = 0; column = 1; break;
		case 3: row = 0; column = 2; break;
		case 4: row = 1; column = 0; break;
		case 5: row = 1; column = 1; break;
		case 6: row = 1; column = 2; break;
		case 7: row = 2; column = 0; break;
		case 8: row = 2; column = 1; break;
		case 9: row = 2; column = 2; break;
		default: std::cout << "Valeur Incorrecte"; // Problème ici, il faudrait faire boucler en arrière à cout
	}


	//Vérifie si à la position indiqué n'est pas déjà occupée, et si ce n'est pas le cas, inscrit le X 
	if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
		board[row][column] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
		board[row][column] = 'O';
		turn = 'X';
	}
	else {
		std::cout << "Cellule incorrecte !" << std::endl 
			<< "Veuillez en choisir une qui n'est pas deja occupee par vous ou votre adversaire !";
		player_turn();
	}
}




bool gameover() {
	// Vérifie si les conditions de fin de jeu sont remplies
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] 
			|| board[0][i] == board[1][i] && board[0][i] == board[2][i]
			|| board[0][0] == board[1][1] && board[0][0] == board[2][2]
			|| board[0][2] == board[1][1] && board[0][2] == board[2][0])
			return false;
	}

	// Vérifie si le jeu est toujours en cours ou non
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			if (board[i][j] != 'X' && board[i][j] != 'O')
				return true;
	}

	// Vérifie s'il y a une égalité
	draw = true;
	return false;
}




void Reset() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
	boarddisplay();

}




// Rappel de toutes les fonctions
int main() {

	while (true) {
		bool win = false;

		while (gameover() && !win) {
			header();
			rules();
			gameover();
			boarddisplay();
			player_turn();
			system("cls");
		}

		if (turn == 'O' && draw == false) {
			VictoryPlayer1 = +1;
			std::cout << "Joueur 1 [0], toutes mes felicitations vous avez gagne !" << std::endl << std::endl
				<< "Joueur 1 : " << VictoryPlayer1 << " victoires" << std::endl
				<< "Joueur 2 : " << VictoryPlayer2 << " victoires" << std::endl << std::endl;
		}
		else if (turn == 'X' && draw == false) {
			VictoryPlayer2 = +1;
			std::cout << "Joueur 2 [0], toutes mes felicitations vous avez gagne !" << std::endl << std::endl
				<< "Joueur 1 : " << VictoryPlayer1 << " victoires" << std::endl
				<< "Joueur 2 : " << VictoryPlayer2 << " victoires" << std::endl << std::endl;
		}
		else {
			std::cout << "Franchement choque et decu, vous avez fait une egalite..." << std::endl << std::endl
			<< "Joueur 1 : " << VictoryPlayer1 << " victoires" << std::endl
			<< "Joueur 2 : " << VictoryPlayer2 << " victoires" << std::endl << std::endl;;
		}

		char replay = 'A';
		while (replay != 'N' && replay != 'Y') {
			std::cout << "Voulez vous rejouer ? (Y/N) : ";
			std::cin >> replay;
			if (replay == 'Y') {
				system("cls");
				Reset();
			}
			else if (replay == 'N') {
				return 0;
			}
		}
	}
}