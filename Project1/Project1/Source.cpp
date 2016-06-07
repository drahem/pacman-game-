#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
#include<string>
using namespace std;
string GameOver = "";
struct position{
	int x, y;
	position(){
		y = x = -1;
	}
	position(int i, int j)
	{
		x = i;
		y = j;
	}
};
void equal(string map[200], string *map1)
{
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 34; j++)
		{
			if (map[i][j] != 'G')
				map1[i][j] = map[i][j];
		}

	}

}
void load_level(string *map, int &number_of_ghosts, position & playerposition, position ghostspostions[5], int eat, int &width, int &height)
{
	ifstream myfile("map.text");
	if (myfile.is_open())
	{
		height = 0;
		while (getline(myfile, map[height]))
		{
			cout << map[height] << endl;
			height++;
		}
	}
	else
		cout << "cant" << endl;
	//eat = 0;
	for (int i = 0; i < height; i++)
	{
		int size = map[i].size();
		for (int j = 0; j < size; j++)
		{

			if (map[i][j] == '.')
				eat++;
			if (map[i][j] == 'G'){
				ghostspostions[number_of_ghosts].x = i;
				ghostspostions[number_of_ghosts].y = j;
				number_of_ghosts++;

			}
			if (map[i][j] == 'P')
			{
				playerposition.x = i;
				playerposition.y = j;


			}
		}
	}

}
void load_level2(string *map, int &number_of_ghosts, position & playerposition, position ghostspostions[5], int eat, int &width, int &height)
{
	ifstream myfile("map2.text");
	if (myfile.is_open())
	{
		height = 0;
		while (getline(myfile, map[height]))
		{
			cout << map[height] << endl;
			height++;
		}
	}
	else
		cout << "cant" << endl;
	width = map[0].length();
	//eat = 0;
	for (int i = 0; i < height; i++)
	{
		int size = map[i].size();
		for (int j = 0; j < size; j++)
		{

			if (map[i][j] == '.')
				eat++;
			if (map[i][j] == 'G'){
				ghostspostions[number_of_ghosts].x = i;
				ghostspostions[number_of_ghosts].y = j;
				number_of_ghosts++;

			}
			if (map[i][j] == 'P')
			{
				playerposition.x = i;
				playerposition.y = j;


			}
		}
	}


}
/*
set function takes postions for player and board and desired change and re-intialize it
*/
void setvalue(int i, int j, string map[200], char pac)
{
	int r = rand();
	r = r % 4;
	map[i][j] = pac;

}

void moveplayer(string map[200], string map1[200], position &player, int &cheese)
{
	char input;
	cin >> input;
	if (input == 'w')
	{
		if (map[player.x - 1][player.y] == '.')
		{
			setvalue(player.x - 1, player.y, map, 'P');
			setvalue(player.x, player.y, map, ' ');
			player.x--;
			cheese++;
			equal(map, map1);
		}
		else if (map[player.x - 1][player.y] == ' ')
		{
			setvalue(player.x - 1, player.y, map, 'P');
			setvalue(player.x, player.y, map, ' ');
			player.x--;
			equal(map, map1);
		}

		else if (map[player.x - 1][player.y] == 'G')
		{
			cout << "game over" << endl;
			cout << " your score : " << cheese << endl;
			GameOver = "GameOver";
			return;
		}

	}
	if (input == 's')
	{
		if (map[player.x + 1][player.y] == '.')
		{
			setvalue(player.x + 1, player.y, map, 'P');
			setvalue(player.x, player.y, map, ' ');
			player.x++;
			cheese++;
			equal(map, map1);
		}
		else if (map[player.x + 1][player.y] == ' ')
		{
			setvalue(player.x + 1, player.y, map, 'P');
			setvalue(player.x, player.y, map, ' ');
			player.x++;
			equal(map, map1);
		}

		else if (map[player.x + 1][player.y] == 'G'){
			cout << "game over" << endl;
			cout << " your score : " << cheese << endl;
			GameOver = "GameOver";
			return;
		}

	}
	if (input == 'a')
	{
		if (map[player.x][player.y - 1] == '.')
		{
			setvalue(player.x, player.y - 1, map, 'P');
			setvalue(player.x, player.y, map, ' ');
			player.y--;
			cheese++;
			equal(map, map1);
		}
		else if (map[player.x][player.y - 1] == ' ')
		{
			setvalue(player.x, player.y - 1, map, 'P');
			setvalue(player.x, player.y, map, ' ');
			player.y--;
			equal(map, map1);
		}

		else if (map[player.x][player.y - 1] == 'G'){
			return;
			cout << "game over" << endl;
			cout << " your score : " << cheese << endl;
			GameOver = "GameOver";
			return;
		}


	}
	if (input == 'd')
	{
		if (map[player.x][player.y + 1] == '.')
		{
			setvalue(player.x, player.y + 1, map, 'P');
			setvalue(player.x, player.y, map, ' ');
			player.y++;
			cheese++;
			equal(map, map1);
		}
		else if (map[player.x][player.y + 1] == ' ')
		{
			setvalue(player.x, player.y + 1, map, 'P');
			setvalue(player.x, player.y, map, ' ');
			player.y++;
			equal(map, map1);
		}

		else if (map[player.x][player.y + 1] == 'G'){
			cout << "game over" << endl;
			cout << " your score : " << cheese << endl;
			GameOver = "GameOver";
			return;
		}


	}
}
void moveghost(string(&map)[200], string(&map1)[200], position  & ghost)
{
	int r = rand();
	r = r % 4;
	if (r == 0)
	{
		if (map[ghost.x - 1][ghost.y] == '.')
		{
			setvalue(ghost.x - 1, ghost.y, map, 'G');

			ghost.x--;
			if (map1[ghost.x][ghost.y] == '.')
				setvalue(ghost.x, ghost.y, map, '.');
			else if (map1[ghost.x][ghost.y] == ' ')
				setvalue(ghost.x, ghost.y, map, ' ');

		}
		else if (map[ghost.x - 1][ghost.y] == ' ')
		{
			setvalue(ghost.x - 1, ghost.y, map, 'G');

			ghost.x--;
			if (map1[ghost.x][ghost.y] == ' ')
				setvalue(ghost.x, ghost.y, map, ' ');
			else if (map1[ghost.x][ghost.y] == '.')
				setvalue(ghost.x, ghost.y, map, '.');

		}


	}
	if (r == 3)
	{
		if (map[ghost.x + 1][ghost.y] == '.')
		{
			setvalue(ghost.x + 1, ghost.y, map, 'G');
			ghost.x++;
			if (map1[ghost.x][ghost.y] == '.')
				setvalue(ghost.x, ghost.y, map, '.');
			else if (map1[ghost.x][ghost.y] == ' ')
				setvalue(ghost.x, ghost.y, map, ' ');

		}

		else if (map[ghost.x + 1][ghost.y] == ' ')
		{
			setvalue(ghost.x + 1, ghost.y, map, 'G');
			ghost.x++;
			if (map1[ghost.x][ghost.y] == '.')
				setvalue(ghost.x, ghost.y, map, '.');
			else if (map1[ghost.x][ghost.y] == ' ')
				setvalue(ghost.x, ghost.y, map, ' ');
		}

	}
	if (r == 1)
	{
		if (map[ghost.x][ghost.y - 1] == '.')
		{
			setvalue(ghost.x, ghost.y - 1, map, 'G');

			ghost.y--;
			if (map1[ghost.x][ghost.y] == '.')
				setvalue(ghost.x, ghost.y, map, '.');
			else if (map1[ghost.x][ghost.y] == ' ')
				setvalue(ghost.x, ghost.y, map, ' ');

		}

		else if (map[ghost.x][ghost.y - 1] == ' ')
		{
			setvalue(ghost.x, ghost.y - 1, map, 'G');

			ghost.y--;
			if (map1[ghost.x][ghost.y] == '.')
				setvalue(ghost.x, ghost.y, map, '.');
			else if (map1[ghost.x][ghost.y] == ' ')
				setvalue(ghost.x, ghost.y, map, ' ');
		}

	}
	if (r == 2)
	{
		if (map[ghost.x][ghost.y + 1] == '.')
		{
			setvalue(ghost.x, ghost.y + 1, map, 'G');

			ghost.y++;
			if (map1[ghost.x][ghost.y] == '.')
				setvalue(ghost.x, ghost.y, map, '.');
			else if (map1[ghost.x][ghost.y] == ' ')
				setvalue(ghost.x, ghost.y, map, ' ');

		}

		else if (map[ghost.x][ghost.y + 1] == ' ')
		{
			setvalue(ghost.x, ghost.y + 1, map, 'G');

			ghost.y++;
			if (map1[ghost.x][ghost.y] == '.')
				setvalue(ghost.x, ghost.y, map, '.');
			else if (map1[ghost.x][ghost.y] == ' ')
				setvalue(ghost.x, ghost.y, map, ' ');
		}

	}
}
void print(string *map, int heigth, string&name, int & cheese)
{
	system("Cls");
	cout << " player " << name << "       score : " << cheese << endl;

	for (int i = 0; i < heigth; i++)
	{
		cout << map[i] << endl;
	}
}
int main()
{
	int numberOfGhosts = 0, width = 0, height = 0, cheese = 0, eat = 0;
	string name;
	cout << "your name" << " : ";
	getline(cin, name);
	position ghost[5];
	position player;
	string map[200];
	string map1[200];
	load_level(map, numberOfGhosts, player, ghost, eat, width, height);
	cout << map[height];


	while (map[ghost[0].x][ghost[0].y] != map[player.x][player.y] || map[ghost[1].x][ghost[1].y] != map[player.x][player.y] || map[ghost[2].x][ghost[2].y] != map[player.x][player.y])
	{
		//system("cls");
		moveplayer(map, map1, player, cheese);
		moveghost(map, map1, ghost[0]);
		moveghost(map, map1, ghost[1]);
		moveghost(map, map1, ghost[2]);
		if (cheese == 40)
		{
			system("cls");
			cout << " congratulation " << endl;
			cout << " you win :D   your score: " << cheese << endl;
			cout << "level2" << endl;
			load_level2(map, numberOfGhosts, player, ghost, eat, width, height);

			while (map[ghost[0].x][ghost[0].y] != map[player.x][player.y] || map[ghost[1].x][ghost[1].y] != map[player.x][player.y] || map[ghost[2].x][ghost[2].y] != map[player.x][player.y] || map[ghost[3].x][ghost[3].y] != map[player.x][player.y] || map[ghost[4].x][ghost[4].y] != map[player.x][player.y])
			{
				//system("cls");
				moveplayer(map, map1, player, cheese);
				moveghost(map, map1, ghost[0]);
				moveghost(map, map1, ghost[1]);
				moveghost(map, map1, ghost[2]);
				moveghost(map, map1, ghost[3]);
				moveghost(map, map1, ghost[4]);
				if (GameOver != "GameOver")
					print(map, height, name, cheese);
				else
				{

					system("pause");
				}

			}
		}
		else if (GameOver != "GameOver")
			print(map, height, name, cheese);

		else
		{

			system("pause");
		}
	}


	return 0;
}