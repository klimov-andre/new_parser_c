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
	int a = 1e1;
	int a = b = 123;
    d *= 100;
    d = round (d);
    d /= 100;
    return d;
}

void addend(struct Node * p)
{
	int o = n->next = 1;
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
	for(int i = 0;;i>10)
		;

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
        int i = "hello\""   
        "sdadsd ""ff""";
        int i = "";
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
        printf();
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
                printf("\n������ �������� ���\n\n");
				return;
			}
			x->next = p->next;
			p = NULL;
		}
		free(p);
		printf("\n������� ������\n\n");
	}
}
void printel(struct Node *p)
{
    int i;
    printf
    (
        "��������: %s\n\f����: %s\n\f�� �������: %d\n\f������ �������: %.2lf\n\"yjhyjtyjtyjtyjtyj,
        ,p->b.name, p->b.author, p->b.year, p->b.stats
    );
    for (i = 0; i < p->b.toms; i++)
    {
        printf ("���������� ������� %d-�� ����: %d\n", i+1, p->b.pages[i]);
    }
    switch (p->b.type)
    {
        case (poem):
            printf ("(�����)\n�����: \"trhth);
            );
            switch (p->b.extra.rifma)
            {
                case (horey):
                    printf("�����\n");
                    break;
                case (yamb):
                    printf("���\n");
                    break;
            }
            break;
        case (prose):
            printf("(�����)\n");
            printf("����: %s\n", p->b.extra.janr);
            break;
    }
    printf("___________________________________\n");
    printf("\n");
}
void print()
{
	if (base == NULL)
        printf("\n������ ����\n\n");
	else
	{
        printf("\n�������� ������:\n\n");
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
        printf("\n������ ����\n\n");
	else
	{
		struct Node *p = base;
		do
		{
			base = base->next;
			free(p);
			p = base;
		} while (p != NULL);
		printf("\n������ ������\n\n");
	}
}

void search ()
{
    if (base == NULL)
        printf("\n������ ����\n\n");
	else
	{
        char s[256];
        char buf[256];
        double d;
        printf("�������� �����: ");
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
            if (!strcmp(s, "�����") && p->b.type == 0)
            {
                printf("%d)\n", i);
                printel(p);
            }
            else if (!strcmp(s, "�����") && p->b.type == 1)
            {
                printf("%d)\n", i);
                printel(p);
            }
            else if (!strcmp(s, "���") && p->b.extra.rifma == 0)
            {
                printf("%d)\n", i);
                printel(p);
            }
            else if (!strcmp(s, "�����") && p->b.extra.rifma == 1)
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
            
            int i =2;
            
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

	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

    printf("XX  XX  XX  XX  XX  XX  XXXXXX  XX  XX\nXX XX   XX  XX  XX  XX  XX      XX  XX\nXXXX    XX  XX  XX XXX  XX      XX XXX\nXXXX    XXXXXX  XXXXXX  XX      XXXXXX\nXX XX   XX  XX  XXX XX  XX      XXX XX\nXX  XX  XX  XX  XX  XX  XX      XX  XX\n\n\n");

	int x, n, y, i;
	struct Node *p;

	read();

	do
	{
		printf("\n1. �������� �������\n");
		printf("2. ������� ������\n");
		printf("3. ������� �������\n");
		printf("4. ������� ���� ������\n");
		printf("5. �����\n");
		printf("0. �����\n");
		while (1)
		{
            printf("��� ����� �������? ");
            fflush(stdin);
            if (scanf("%d",&x))
                break;
		}
		switch (x)
		{
		case 1:
			p = malloc(sizeof (struct Node));
			printf("\n1. �������� ������� � ������\n");
			printf("2. �������� ������� � �����\n");
			printf("3. �������� ������� � ����� ��� �������...\n");
			printf("0. �����\n");
			printf("��� ����� �������? ");
			fflush(stdin);
            scanf("%d",&y);
            fflush(stdin);
            if (y == 0)
                break;
            if (y == 3)
            {
                printf ("\n�� ����� ����� ��������� �������? ");
                fflush(stdin);
                scanf("%d", &n);
                fflush(stdin);
                if (!check(n))
                {
                    printf("\n������ �������� ���!\n\n");
                    break;
                }
            }
            printf("��������: ");
            fflush(stdin);
            fgets(p->b.name, 256, stdin);
            *strrchr(p->b.name, '\n') = '\0';
            printf("�����: ");
            fflush(stdin);
            fgets(p->b.author, 256, stdin);
            *strrchr(p->b.author, '\n') = '\0';
            while (1)
            {
                fflush(stdin);
                printf("���������� �����: ");
                if (scanf("%d",&p->b.toms))
                    break;
            }
            p->b.pages = (int*)calloc(p->b.toms, sizeof(int));
            for (i = 0; i < p->b.toms; i++)
            {
                while (1)
                {
                    fflush(stdin);
                    printf("���������� ������� %d-�� ����: ", i + 1);
                    if (scanf("%d",&(p->b.pages[i])))
                        break;
                }
            }
            while (1)
            {
                fflush(stdin);
                printf("���: ");
                if (scanf("%d",&p->b.year))
                    break;
            }
            while (1)
            {
                fflush(stdin);
                printf("������� �������: ");
                if (scanf("%lf",&p->b.stats))
                    break;
            }
            p->b.stats = roundDouble (p->b.stats);
            while (1)
            {
                fflush(stdin);
                printf("����� (0) ��� ����� (1): ");
                if (scanf("%d",&p->b.type) && (p->b.type == 0 || p->b.type == 1))
                    break;
            }
            if (p->b.type == 0)
            {
                while (1)
                {
                    printf("����� (��� - 0, ����� - 1): ");
                    if (scanf("%d",&p->b.extra.rifma) && (p->b.extra.rifma == 0 || p->b.extra.rifma == 1))
                        break;
                }
            }
            else
            {
                printf("����: ");
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
            printf("\n������� ��������!\n\n");
			break;
		case 2:
			print();
			break;
		case 3:
            while (1)
            {
                fflush(stdin);
                printf("����� ��������: ");
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
