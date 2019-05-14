
struct book
{
	char name[256];
	char author[256];
	int toms;
	int *pages;
	int year;
	double stats;
	enum typetext {poem, prose} type;
	union ex
	{
        enum rif {yamb, horey} rifma;
        char janr[256];
	} extra;
};

struct Node
{
	struct book b;
	struct Node *next;
};

struct Node * base=NULL;

double roundDouble (double d)
{
    d *= 100;
    d = round (d);
    d /= 100;
    return d;
}

void addend(struct Node * p)
{

	p->next = NULL;
	if (base)
	{
		struct Node * n = base;
		while (n->next)
            n = n->next;
		n->next = p;
	}
	else
	{
        base = p;
    }

}

void addbegin(struct Node * p)
{
    p->next = base;
	base = p;
}

void add(struct Node * p, int n)
{
    if (n == 1)
    {
        addbegin(p);
    }
    else
    {
        struct Node *x  = base;
        int i = 1;
        while ((i < n-1) && (x))
        {
            x = x->next;
            i++;
        }
        struct Node *buf  = x->next;
        x->next = p;
        p->next = buf;
    }
}

int check(int n)
{
    struct Node *x  = base;
    int i = 1;
    while ((i < n) && (x))
    {
            x = x->next;
            i++;
    }
    if (i != n)
    {
        return 0;
    }
    return 1;
}

void del(int n)
{
	if (base == NULL)
        printf("\nСписок пуст\n\n");
	else
	{
		struct Node *p;
		if (n == 1)
		{
			p = base;
			base = base->next;
		}
		else
		{
			struct Node * x;
			int i = 2;
			x = base;
			p = base->next;
			while ((i < n) && (p))
			{
				x = p;
				p = p->next;
				i++;
			}
			if ((i != n) || !p)
			{
                printf("\nТакого элемента нет\n\n");
				return;
			}
			x->next = p->next;
			p = NULL;
		}
		free(p);
		printf("\nЭлемент удален\n\n");
	}
}
void printel(struct Node *p)
{
    int i;
    printf
    (
        "Название: %s\n\Автор: %s\n\Год издания: %d\n\Мировой рейтинг: %.2lf\n",
        p->b.name, p->b.author, p->b.year, p->b.stats
    );
    for (i = 0; i < p->b.toms; i++)
    {
        printf ("Количество страниц %d-го тома: %d\n", i+1, p->b.pages[i]);
    }
    switch (p->b.type)
    {
        case (poem):
            printf ("(стихи)\nРифма: ");
            switch (p->b.extra.rifma)
            {
                case (horey):
                    printf("хорей\n");
                    break;
                case (yamb):
                    printf("ямб\n");
                    break;
            }
            break;
        case (prose):
            printf("(проза)\n");
            printf("Жанр: %s\n", p->b.extra.janr);
            break;
    }
    printf("___________________________________\n");
    printf("\n");
}
void print()
{
	if (base == NULL)
        printf("\nСписок пуст\n\n");
	else
	{
        printf("\nЭлементы списка:\n\n");
		struct Node *p = base;
		int i = 1;
		do
		{

            printf("%d)\n", i);
            printel(p);
			i++;
			p = p->next;
		} while (p != 0);
		printf("\n\n");
	}
}

void delall()
{
	if (base == NULL)
        printf("\nСписок пуст\n\n");
	else
	{
		struct Node *p = base;
		do
		{
			base = base->next;
			free(p);
			p = base;
		} while (p != NULL);
		printf("\nСписок удален\n\n");
	}
}

void search ()
{
    if (base == NULL)
        printf("\nСписок пуст\n\n");
	else
	{
        char s[256];
        char buf[256];
        double d;
        printf("Ключевое слово: ");
        fflush(stdin);
        fgets(s, 256, stdin);
        *strrchr(s, '\n') = '\0';
        printf("\n");
        scanf(s, "%lf", &d);
        d = (double)(d);

        int i = 1;
        struct Node *p = base;

        do
        {
            if (!strcmp(s, "стихи") && p->b.type == 0)
            {
                printf("%d)\n", i);
                printel(p);
            }
            else if (!strcmp(s, "проза") && p->b.type == 1)
            {
                printf("%d)\n", i);
                printel(p);
            }
            else if (!strcmp(s, "ямб") && p->b.extra.rifma == 0)
            {
                printf("%d)\n", i);
                printel(p);
            }
            else if (!strcmp(s, "хорей") && p->b.extra.rifma == 1)
            {
                printf("%d)\n", i);
                printel(p);
            }
            if (
                    !strcmp(s, p->b.name) ||
                    !strcmp(s, p->b.author) ||
                    !strcmp(s, itoa(p->b.year, buf, 10)) ||
                    !strcmp(s, itoa(p->b.pages, buf, 10)) ||
                    !strcmp(s, itoa(p->b.stats, buf, 10)) ||
                    !strcmp(s, p->b.extra.janr) ||
                    d == p->b.stats
               )
            {
                printf("%d)\n", i);
                printel(p);
            }
            p = p->next;
            i++;
        } while (p != NULL);
    }
}

void read()
{

	struct Node *p;
	FILE *f;
	struct book bk;
	int i, buf;

	if ((f=fopen("testOld.dat", "rb")) != 0)
	{
		fclose(f);
		remove("test.dat");
		rename("testOld.dat", "test.dat");
	}

	f = fopen("test.dat", "rb");
	while (fread(&bk, sizeof(struct book), 1, f))
	{
		p = malloc(sizeof (struct Node));
		p->b = bk;
		p->b.pages = (int*)calloc(p->b.toms, sizeof(int));
		for (i = 0; i < p->b.toms; i++)
		{
            fread(&buf, sizeof(int), 1, f);
            p->b.pages[i] = buf;
        }
		addend(p);
	}
	fclose(f);
}

void rec()
{
	remove("testOld.dat");
	rename("test.dat", "testOld.dat");
	FILE *f;
	f = fopen("test.dat", "wb");
	struct Node *p = base;
	int i;
	while (p != NULL)
	{
		fwrite(&(p->b), sizeof(struct book), 1, f);
		for (i = 0; i < p->b.toms; i++)
		{
            fwrite(&(p->b.pages[i]), sizeof(int), 1, f);
        }
		p = p->next;
	}
	fclose(f);
	remove("testOld.dat");
}

int main()
{
	//setlocale(LC_ALL, "Russian");

	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    printf("XX  XX  XX  XX  XX  XX  XXXXXX  XX  XX\nXX XX   XX  XX  XX  XX  XX      XX  XX\nXXXX    XX  XX  XX XXX  XX      XX XXX\nXXXX    XXXXXX  XXXXXX  XX      XXXXXX\nXX XX   XX  XX  XXX XX  XX      XXX XX\nXX  XX  XX  XX  XX  XX  XX      XX  XX\n\n\n");

	int x, n, y, i;
	struct Node *p;

	read();

	do
	{
		printf("\n1. Добавить элемент\n");
		printf("2. Вывести список\n");
		printf("3. Удалить элемент\n");
		printf("4. Удалить весь список\n");
		printf("5. Поиск\n");
		printf("0. Выйти\n");
		while (1)
		{
            printf("Что нужно сделать? ");
            fflush(stdin);
            if (scanf("%d",&x))
                break;
		}
		switch (x)
		{
		case 1:
			p = malloc(sizeof (struct Node));
			printf("\n1. Добавить элемент в начало\n");
			printf("2. Добавить элемент в конец\n");
			printf("3. Добавить элемент в место под номером...\n");
			printf("0. Назад\n");
			printf("Что нужно сделать? ");
			fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            if (y == 0)
                break;
            if (y == 3)
            {
                printf ("\nНа какое место поставить элемент? ");
                fflush(stdin);
                scanf("%d", &n);
                fflush(stdin);
                if (!check(n))
                {
                    printf("\nТакого элемента нет!\n\n");
                    break;
                }
            }
            printf("Название: ");
            fflush(stdin);
            fgets(p->b.name, 256, stdin);
            *strrchr(p->b.name, '\n') = '\0';
            printf("Автор: ");
            fflush(stdin);
            fgets(p->b.author, 256, stdin);
            *strrchr(p->b.author, '\n') = '\0';
            while (1)
            {
                fflush(stdin);
                printf("Количество томов: ");
                if (scanf("%d",&p->b.toms))
                    break;
            }
            p->b.pages = (int*)calloc(p->b.toms, sizeof(int));
            for (i = 0; i < p->b.toms; i++)
            {
                while (1)
                {
                    fflush(stdin);
                    printf("Количество страниц %d-го тома: ", i + 1);
                    if (scanf("%d",&(p->b.pages[i])))
                        break;
                }
            }
            while (1)
            {
                fflush(stdin);
                printf("Год: ");
                if (scanf("%d",&p->b.year))
                    break;
            }
            while (1)
            {
                fflush(stdin);
                printf("Мировой рейтинг: ");
                if (scanf("%lf",&p->b.stats))
                    break;
            }
            p->b.stats = roundDouble (p->b.stats);
            while (1)
            {
                fflush(stdin);
                printf("Стихи (0) или проза (1): ");
                if (scanf("%d",&p->b.type) && (p->b.type == 0 || p->b.type == 1))
                    break;
            }
            if (p->b.type == 0)
            {
                while (1)
                {
                    printf("Рифма (Ямб - 0, хорей - 1): ");
                    if (scanf("%d",&p->b.extra.rifma) && (p->b.extra.rifma == 0 || p->b.extra.rifma == 1))
                        break;
                }
            }
            else
            {
                printf("Жанр: ");
                fflush(stdin);
                fgets(p->b.extra.janr, 256, stdin);
                *strrchr(p->b.extra.janr, '\n') = '\0';
            }
            switch (y)
            {
                case 1:
                    addbegin(p);
                    break;
                case 2:
                    addend(p);
                    break;
                case 3:
                    add(p,n);
                    break;
                case 0:
                    break;
                default:
                    printf("\n");
                    break;
            }
            printf("\nЭлемент добавлен!\n\n");
			break;
		case 2:
			print();
			break;
		case 3:
            while (1)
            {
                fflush(stdin);
                printf("Номер элемента: ");
                if (scanf("%d",&n))
                    break;
            }
			del(n);
			break;
		case 4:
			delall();
			break;
        case 5:
            search();
            break;
        default:
            printf("\n");
            break;
		}
	} while (x != 0);

    rec();

    system ("pause");
	return 0;
}
