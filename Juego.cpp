#include<conio.h>
#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[])
{
#define WIDTH 70
	int characterPosition = WIDTH / 2;
	int bulletPosition = NULL;
	char bulletDirection = NULL;
	bool bulletLives = FALSE;
	bool playing = true;

	while (playing)
	{
		if (bulletDirection == 'l')
		{
			for (bulletPosition = characterPosition - 1; bulletPosition >= 0; bulletPosition--)
			{
				for (int i = 0; i <= WIDTH; i++)
				{
					if (characterPosition == i)
						printf("x");
					if (bulletPosition == i)
						printf("o");
					else
						printf("-");
				}
				printf("\r");
				Sleep(50);
			}
			bulletLives = NULL;
			bulletDirection = NULL;
		}

		else if (bulletDirection == 'r')
		{
			for (bulletPosition = characterPosition + 1; bulletPosition <= WIDTH; bulletPosition++)
			{
				for (int i = 0; i <= WIDTH; i++)
				{
					if (characterPosition == i)
						printf("x");
					if (bulletPosition == i)
						printf("o");
					else
						printf("-");
				}
				printf("\r");
				Sleep(50);
			}
			bulletLives = NULL;
			bulletDirection = NULL;
		}

		else
		{
			for (int i = 0; i <= WIDTH; i++)
			{
				if (characterPosition == i)
					printf("x");
				if (bulletPosition == i && bulletPosition != NULL)
					printf("o");
				else
					printf("-");
			}
		}

		if (_kbhit())
		{
			char pressedKey = _getch();

			if (pressedKey == 'o' && characterPosition != 0)
				characterPosition--;
			else if (pressedKey == 'p' && characterPosition != WIDTH)
				characterPosition++;
			if (pressedKey == 'k' && characterPosition != 0)
				bulletDirection = 'l';
			else if (pressedKey == 'l' && characterPosition != WIDTH)
				bulletDirection = 'r';
		}
		printf("\r");	
		Sleep(50);
	}

	getchar();
	return 0;
}