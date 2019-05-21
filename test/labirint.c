#define NULL(x) sidvjcpsiedc
void getSizeL(int *w, int *l)// Получаем размеры лабиринта
{
	int x = 0B01;
	const int x = 0XFF;

	int a, b;
	printf("Размеры лабиринта\n");

	while (1)
	{
		a = 0;
		b = 0;

		printf("Ширина: ");
		do
		{
			a = 0;
			rewind(stdin);
			if (!scanf("%d", &a))
			{
				printf("Неверные данные! Повторите ввод ");
			}
			else if (a < 2 || a > 2147483647)
			{
				printf("Допустимые значения - от 2 до 2147483647! Повторите ввод ");
			}
			else
			{
				break;
			}

		} while (1);

		printf("Длина: ");
		do
		{
			b = 0;
			rewind(stdin);
			if (!scanf("%d", &b))
			{
				printf("Неверные данные! Повторите ввод: ");
			}
			else if (b < 2 || b > 43750)
			{
				printf("Допустимые значения - от 2 до 43750! Повторите ввод: ");
			}
			else
			{
				break;
			}

		} while (1);

		unsigned long long x = a*b;

		if (x <= 87500)
			break;

		printf("Слишком большие значения! Повторите ввод!\n\n");

	}
	*l = a + 2;
	*w = b + 2;
}

int checkempty(int *lab, int l, int w)// Проверка на наличие "полных" ячеек (1111)
{
	int i, j;
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (*(lab + i*w + j) == 1111)
				return 1;
		}
	}
	return 0;
}

int checkend(int *lab, int w, int i, int j)// Проверка на тупик
{
	if ((*(lab + (i - 1)*w + j) != 1111) &&
		(*(lab + i*w + (j + 1)) != 1111) &&
		(*(lab + (i + 1)*w + j) != 1111) &&
		(*(lab + i*w + (j - 1)) != 1111)
		)
		return 1;
	else
		return 0;
}

void cleanLab(int *lab, int l, int w)// Все отрицательные числа в лабиринте заменяем положительными (кроме границ)
{
	int i, j;
	for (i = 1; i < l - 1; i++)
		for (j = 1; j < w - 1; j++)
			if (*(lab + i*w + j) < 0)
				*(lab + i*w + j) = -(*(lab + i*w + j));
}

void printlab(int *lab, int l, int w)// Вывод лабиринта на экран
{

	cleanLab(lab, l, w);
	int i, j;
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < w; j++)
		{
			printf("%4d ", *(lab + i*w + j));
		}
		printf("\n");
	}
	system("pause");
}

void drawlab(int *lab, int l, int w)// Рисуем лабиринт
{
	int i, x, j;
	for (i = 0; i < 3 * w - 4; i++)
	{
		if (i == 1)
		{
			printf("   ");
			i = i + 2;
		}
		else
			printf("X");
	}
	printf("\n");
	for (i = 1; i < l - 1; i++)
	{
		for (x = 0; x < 3; x++)
		{
			for (j = 0; j < w; j++)
			{
				if (*(lab + i*w + j) == -1)
				{
					printf("X");
					j++;
				}
				switch (*(lab + i*w + j))
				{
				case 0:
					printf("   ");
					break;
				case 1:
					if (x == 0)
						printf("XXX");
					else
						printf("   ");
					break;
				case 10:
					printf("  X");
					break;
				case 11:
					if (x == 0)
						printf("XXX");
					else
						printf("  X");
					break;
				case 100:
					if (x == 2)
						printf("XXX");
					else
						printf("   ");
					break;
				case 101:
					if (x == 0 || x == 2)
						printf("XXX");
					else
						printf("   ");
					break;
				case 110:
					if (i == l - 2 && j == w - 2 && x == 2)
						printf("X X");
					else if (x == 2)
						printf("XXX");
					else
						printf("  X");
					break;
				case 111:
					if (i == l - 2 && j == w - 2 && x == 2)
						printf("X X");
					else if (x == 0 || x == 2)
						printf("XXX");
					else
						printf("  X");
					break;
				case 1000:
					printf("X  ");
					break;
				case 1001:
					if (i == 1 && j == 1 && x == 0)
						printf("X X");
					else if (x == 0)
						printf("XXX");
					else
						printf("X  ");
					break;
				case 1010:
					printf("X X");
					break;
				case 1011:
					if (i == 1 && j == 1 && x == 0)
						printf("X X");
					else if (x == 0)
						printf("XXX");
					else
						printf("X X");
					break;
				case 1100:
					if (x == 2)
						printf("XXX");
					else
						printf("X  ");
					break;
				case 1101:
					if (i == 1 && j == 1 && x == 0)
						printf("X X");
					else if (x == 2 || x == 0)
						printf("XXX");
					else
						printf("X  ");
					break;
				case 1110:
					if (i == l - 2 && j == w - 2 && x == 2)
						printf("X X");
					else if (x == 2)
						printf("XXX");
					else
						printf("X X");
					break;
				case 1111: // Не должно быть
					if (i == 1 && j == 1 && x == 0)
						printf("X X");
					else if (i == l - 2 && j == w - 2 && x == 2)
						printf("X X");
					else if (x == 2 || x == 0)
						printf("XXX");
					else
						printf("X X");
					break;
				}
			}
			printf("\n");
		}

	}
	for (i = 0; i < 3 * w - 4; i++)
	{
		if (i == 3 * w - 4 - 2 - 2)
		{
			printf("   ");
			i = i + 2;
		}
		else
			printf("X");
	}
	printf("\n");
}

int wayout(int *lab, int l, int w, int i, int j)// Построение "главной дороги" - дороги, соединяющей вход и выход лабиринта
{
	int randNum, result;
	if (i >= l - 2 && j >= w - 2 && (!checkempty(lab, l, w)))   // Условие окончания рекурсии
		return 1;
	else if (checkend(lab, w, i, j))                        // Проверка на тупик
		return 0;
	else
	{
		do
		{

			randNum = rand() % 4 + 1;                           // Генерируем случайное число - стенку, которую будем ломать (от 1 до 4)
			switch (randNum)
			{
			case 1:
				if (checkend(lab, w, i, j))                 // Проверка на тупик
					return 0;
				if (*(lab + (i - 1)*w + j) == -1 || *(lab + (i - 1)*w + j) != 1111)  // Проверка соседней ячейки, стенку у которой тоже нужно сломать
				{//  [Граница лабиринта?]  или   [Уже здесь были?]
					result = 0;
					continue;
				}

				else
				{
					*(lab + i*w + j) -= 1;                      // Ломаем стенку текущей ячейки
					*(lab + (i - 1)*w + j) -= 100;                // Ломаем стенку соседней ячейки
					i--;
					//printlab(lab, l, w);
					result = wayout(lab, l, w, i, j);       // Продолжаем ломать стенки, продвигаясь дальше по лабиринту
					if (result == 0)                        // Если тупик
					{
						*(lab + i*w + j) = -(*(lab + i*w + j)); // Помечаем текущую ячейку как тупиковую, приписывая ей минус
						i++;                            // Возвращаемся назад
														//*(lab+i*w+j) += 1;
														//printlab(lab, l, w);
					}
				}
				//printlab(lab, l, w);
				break;                                      // Далее - аналогично
			case 2:
				if (checkend(lab, w, i, j))
					return 0;
				if (*(lab + i*w + (j + 1)) == -1 || *(lab + i*w + (j + 1)) != 1111)
				{
					result = 0;
					continue;
				}

				else
				{
					*(lab + i*w + j) -= 10;
					*(lab + i*w + (j + 1)) -= 1000;
					j++;
					//printlab(lab, l, w);
					result = wayout(lab, l, w, i, j);
					if (result == 0)
					{
						*(lab + i*w + j) = -(*(lab + i*w + j));
						j--;
						//*(lab+i*w+j) += 2;
						//printlab(lab, l, w);
					}
				}
				//printlab(lab, l, w);
				break;
			case 3:
				if (checkend(lab, w, i, j))
					return 0;
				if (*(lab + (i + 1)*w + j) == -1 || *(lab + (i + 1)*w + j) != 1111)
				{
					result = 0;
					continue;
				}

				else
				{
					*(lab + i*w + j) -= 100;
					*(lab + (i + 1)*w + j) -= 1;
					i++;
					//printlab(lab, l, w);
					result = wayout(lab, l, w, i, j);
					if (result == 0)
					{
						*(lab + i*w + j) = -(*(lab + i*w + j));
						i--;
						//*(lab+i*w+j) += 3;
						//printlab(lab, l, w);
					}
				}
				//printlab(lab, l, w);
				break;
			case 4:
				if (checkend(lab, w, i, j))
					return 0;
				if (*(lab + i*w + (j - 1)) == -1 || *(lab + i*w + (j - 1)) != 1111)
				{
					result = 0;
					continue;
				}

				else
				{
					*(lab + i*w + j) -= 1000;
					*(lab + i*w + (j - 1)) -= 10;
					j--;
					//printlab(lab, l, w);
					result = wayout(lab, l, w, i, j);
					if (result == 0)
					{
						*(lab + i*w + j) = -(*(lab + i*w + j));
						j++;
						//*(lab+i*w+j) += 4;
						//printlab(lab, l, w);
					}
				}
				//printlab(lab, l, w);
				break;
			}
		} while (result == 0);    // Цикл выполняется, пока нет результата (т.е. не достигнут конец лабиринта)
	}



	return result;
}

void eller(int len, int height) {

	int temp = 0, temp1 = 0, temp2 = 0;
	int rowcounter = 1;
	int **rows = (int**)malloc(sizeof(int)*height * 2 + 1);
	int *field = (int*)malloc(sizeof(int)*len * 2 + 1);
	*rows = (int*)malloc(sizeof(int)*len * 2 + 1);
	for (int p = 0; p < len * 2 + 1; p++) {
		*(*(rows)+p) = -3;
	}
	*field = -1;//есть граница
	for (int i = 1, j = 1; i < len * 2; i += 2, j++) {
		*(field + i) = j;
	}
	*(field + len * 2) = -1;

	for (int i = 2; i < len * 2; i += 2) {
		if (rand() % 2) {
			*(field + i) = -1;//стенка есть
		}
		else {
			*(field + i) = -2;//стенки нет
			temp = i;
			temp1 = *(field + i + 1);
			temp2 = *(field + i - 1);
			i = 0;
			while (i < len * 2 + 1) {
				if (*(field + i + 1) == temp1) {
					*(field + i + 1) = temp2;
				}
				i += 2;
			}
			i = temp;
		}
	}
	*(rows + rowcounter) = field;
	rowcounter++;
	int i = 0, j = 0;
	int counter = 0;    //условие не точно))
	int *fieldnew = (int*)calloc(len * 2 + 1, sizeof(int));
	i = 1;
	j = 1;
	while (j < len * 2 + 1 && i < len * 2 + 1) {
		counter = 1;
		temp = *(field + i);
		while (i < len * 2 + 1) {
			i += 2;
			if (temp == *(field + i)) counter++;
			else break;
		}
		for (int p = 0; p < counter; p++, j += 2) {
			*(fieldnew + j) = (rand() % 2) - 4;
		}
		if (counter != 0) *(fieldnew + j - 2 * counter + (rand() % counter) * 2) = -4;//пола нет
	}
	for (int p = 0; p < len * 2 + 1; p += 2) {
		*(fieldnew + p) = -3;//пол есть
	}
	*(rows + rowcounter) = fieldnew;
	rowcounter++;

	while (rowcounter < height * 2 - 2) {
		i = 0, j = 0, counter = 1, temp = 0;

		field = (int*)malloc(sizeof(int)*len * 2 + 1);
		fieldnew = (int*)malloc(sizeof(int)*len * 2 + 1);
		for (int p = 1; p < len * 2 + 1; p += 2) { ////////////////////+=2????????????
			*(field + p) = *(*(rows + rowcounter - 2) + p);
		}
		for (int p = 0; p < len * 2 + 1; p++) {
			*(fieldnew + p) = *(*(rows + rowcounter - 1) + p);
		}

		if (*(fieldnew + 1) == -3) {
			*(fieldnew + 1) = -4;
			*(field + 1) = rowcounter*len + 1;
		}

		for (int p = 3; p < len * 2; p += 2) {
			if (*(fieldnew + p) == -3) {
				*(fieldnew + p) = -4;
				*(field + p) = ((rowcounter*len) + p);
			}
		}
		for (int p = 2; p < len * 2; p += 2) {
			if (*(field + p + 1) == *(field + p - 1)) {
				*(field + p) = -1;
				continue;
			}
			if (rand() % 2) {
				*(field + p) = -1;//стенка есть
			}
			else {
				*(field + p) = -2;//стенки нет
				temp = p;
				temp1 = *(field + p + 1);
				temp2 = *(field + p - 1);
				p = 0;
				while (p < len * 2 + 1) {
					if (*(field + p + 1) == temp1) {
						*(field + p + 1) = temp2;

					}
					p += 2;
				}
				p = temp;
			}
		}
		*field = -1;//есть граница
		*(field + len * 2) = -1;
		i = 1;
		j = 1;
		while (j < len * 2 + 1 && i < len * 2 + 1) {
			counter = 1;
			temp = *(field + i);
			while (i < len * 2 + 1) {
				i += 2;
				if (temp == *(field + i)) counter++;
				else break;
			}
			for (int p = 0; p < counter; p++, j += 2) {
				*(fieldnew + j) = (rand() % 2) - 4;
			}
			if (counter != 0) *(fieldnew + j - 2 * counter + (rand() % counter) * 2) = -4;//пола нет
		}
		for (int p = 0; p < len * 2 + 1; p += 2) {
			*(fieldnew + p) = -3;//пол есть
		}
		*(rows + rowcounter) = field;
		rowcounter++;
		*(rows + rowcounter) = fieldnew;
		rowcounter++;
	}
	i = 0, j = 0, counter = 0, temp = 0;

	field = (int*)malloc(sizeof(int)*len * 2 + 1);
	fieldnew = (int*)malloc(sizeof(int)*len * 2 + 1);
	for (int p = 0; p < len * 2 + 1; p++) {
		*(fieldnew + p) = *(*(rows + rowcounter - 1) + p);
	}
	for (int p = 0; p < len * 2 + 1; p++) {
		*(field + p) = *(*(rows + height * 2 - 3) + p);
	}
	if (*(fieldnew + 1) == -3) {
		*(fieldnew + 1) = -4;
		*(field + 1) = rowcounter*len + 1;
	}

	for (int p = 3; p < len * 2; p += 2) {
		if (*(fieldnew + p) == -3) {
			*(fieldnew + p) = -4;
			*(field + p) = ((rowcounter*len) + p);
		}
	}
	for (int p = 2; p < len * 2; p += 2) {
		if (*(field + p + 1) == *(field + p - 1)) {
			*(field + p) = -1;
			continue;
		}
		if (rand() % 2) {
			*(field + p) = -1;//стенка есть
		}
		else {
			*(field + p) = -2;//стенки нет
			temp = p;
			temp1 = *(field + p + 1);
			temp2 = *(field + p - 1);
			p = 0;
			while (p < len * 2 + 1) {
				if (*(field + p + 1) == temp1) {
					*(field + p + 1) = temp2;

				}
				p += 2;
			}
			p = temp;
		}
	}
	for (int p = 2; p < len * 2; p += 2) {
		if (*(field + p - 1) != *(field + p + 1)) {
			*(field + p) = -2;
			temp = p;
			temp1 = *(field + p + 1);
			temp2 = *(field + p - 1);
			p = 2;
			while (p < len * 2 + 1) {
				if (*(field + p + 1) == temp1) {
					*(field + p + 1) = temp2;

				}
				p += 2;
			}
			p = temp;
		}
	}
	*field = -1;//есть граница
	*(field + len * 2) = -1;
	for (int p = 0; p < len * 2 + 1; p++) {
		*(fieldnew + p) = -3;
	}
	*(rows + rowcounter) = field;
	rowcounter++;
	*(rows + rowcounter) = fieldnew;
	rowcounter++;

	for (i = 0; i < height * 2 + 1; i++) {
		for (j = 0; j < len * 2 + 1; j++) {
			if (*(*(rows + i) + j) == -1 || *(*(rows + i) + j) == -3) {
				printf("X");
			}
			else printf(" ");
		}
		printf("\n");
	}
}

void labirint(int w, int l)
{
	int i, j;
	// Создаем массив с размерами лабиринта
	int *lab = (int*)malloc(l*w * sizeof(int));

	for (i = 0; i < l; i++)                              // В ячейке есть стенки. Кол-во стенок складывается из чисел:
	{                                                   // 0001 - верхняя, 0010 - правая, 0100 - нижняя, 1000 - левая
		for (j = 0; j < w; j++)
		{
			if (i == 0 ||
				j == 0 ||
				i == l - 1 ||
				j == w - 1)
				*(lab + i*w + j) = -1;                      // -1 - край лабиринта
			else
				*(lab + i*w + j) = 1111;
		}
	}

	//printlab(lab, l, w);
	cleanLab(lab, l, w);

	// Строим "главную дорогу", параллельно создавая тупиковые пути
	wayout(lab, l, w, 1, 1);

	// Вывод лабиринта на экран в виде массива
	//printlab(lab, l, w);
	cleanLab(lab, l, w);

	// Рисуем лабиринт
	drawlab(lab, l, w);
}

int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
	char c;

	do
	{

		printf("\n******************ЛАБИРИНТ*******************\n\n");

		int w, l, casealg;


		// Получаем размеры лабиринта: w - ширина, l - длина
		getSizeL(&w, &l);
		
		printf("\n*********************************************\n\n");

		printf("Метод генерации лабиринта:\n1 - Простой\n2 - Алгоритм Эллера\n");
		while (1)
		{
			printf(">> ");
			rewind(stdin);
			if (scanf("%d", &casealg) && (casealg == 1 || casealg == 2))
				break;
		}

		printf("\n*********************************************\n\n");
		switch (casealg)
		{
			case 1:
				labirint(l, w);
				break;
			case 2:
				eller(l, w);
				break;
		}
		
		printf("\nЧтобы построить новый лабиринт, введите любую клавишу\nДля выхода введите ноль (0)\n>> ");
		rewind(stdin);
		c = getchar();
		printf("\n");

	} while (c != '0');

	system("pause");
	return 0;
}
