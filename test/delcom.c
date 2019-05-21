#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"

int main()
{
	FILE *f, *nf;
	char fileName[50];

	fgets(fileName, 49, stdin);
	*strrchr(fileName, '\n') = '\0';
	f = fopen(fileName, "r+");
	nf = fopen("newFile.cpp", "w");
	char c;
	c = fgetc(f);
	while (1)
	{
		if (c == EOF)
			break;
		if (c == '\"')
		{
			printf("%c", c);
			fputc(c, nf);
			c = fgetc(f);
			while (c != EOF)
			{
				if (c == '\"')
				{
					int a = 0;
					fseek(f, -2, SEEK_CUR);
					c = fgetc(f);
					while (c == '\\')
					{
						a++;
						fseek(f, -2, SEEK_CUR);
						c = fgetc(f);
					}
					if (a % 2 == 0)
					{
						fseek(f, a, SEEK_CUR);
						c = fgetc(f);
						break;
					} 
					else
					{
						fseek(f, a, SEEK_CUR);
						c = fgetc(f);
					}
				}
				else if (c == '\n')
				{
					fseek(f, -3, SEEK_CUR);
					c = fgetc(f);
					if (c != '\\')
					{
						c = fgetc(f);
						break;
					}
					else
					{
						c = fgetc(f);
					}
				}
				printf("%c", c);
				fputc(c, nf);
				c = fgetc(f);
			}
		}
		if (c == '\'')
		{
			printf("%c", c);
			fputc(c, nf);
			c = fgetc(f);
			while (c != EOF)
			{
				if (c == '\'')
				{
					int a = 0;
					fseek(f, -2, SEEK_CUR);
					c = fgetc(f);
					while (c == '\\')
					{
						a++;
						fseek(f, -2, SEEK_CUR);
						c = fgetc(f);
					}
					if (a % 2 == 0)
					{
						fseek(f, a, SEEK_CUR);
						c = fgetc(f);
						break;
					}
					else
					{
						fseek(f, a, SEEK_CUR);
						c = fgetc(f);
					}
				}
				if (c == '\n')
					break;
				printf("%c", c);
				fputc(c, nf);
				c = fgetc(f);
			}
		}
		if (c == '/')
		{
			c = fgetc(f);
			if (c == '/')
			{
				/*
				while (c != '\n')
				{
				c = fgetc(f);
				}
				*/
				while (c != EOF)
				{
					if (c == '\n')
					{
						fseek(f, -3, SEEK_CUR);
						c = fgetc(f);
						if (c != '\\')
						{
							c = fgetc(f);
							break;
						}
						else
						{
							c = fgetc(f);
						}
					}
					c = fgetc(f);
				}
			}
			else if (c == '*')
			{
				/*
				do
				{
				c = fgetc(f);
				} while (c != '*');
				c = fgetc(f);
				if (c == '/')
				{
				c = fgetc(f);
				}
				else
				{
				fseek(f, -1, SEEK_CUR);
				}
				*/
				c = fgetc(f);
				while (c != EOF)
				{
					if (c == '*')
					{
						c = fgetc(f);
						if (c == '/')
						{
							c = fgetc(f);
							break;
						}
						else
						{
							fseek(f, -2, SEEK_CUR);
							c = fgetc(f);
						}
					}
					c = fgetc(f);
				}
				continue;
			}
			else
			{
				if (c == EOF)
				{
					fseek(f, -1, SEEK_CUR);
					c = fgetc(f);
				}
				else if (c != '\n')
				{
					fseek(f, -2, SEEK_CUR);
					c = fgetc(f);
				}
				else
				{
					fseek(f, -3, SEEK_CUR);
					c = fgetc(f);
				}
			}
		}
		if (c != EOF)
		{
			printf("%c", c);
			fputc(c, nf);
			c = fgetc(f);
		}
	}
	fclose(nf);
	fclose(f);
	return 0;
}

