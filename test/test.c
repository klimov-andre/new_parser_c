
//* массивки */
int a[][1][2][3][4];
int *a[4][9];
struct sss
{
	char test;
	int *field[4][9];
} arr[99] = 0;

char * test_string = "Compiles - parasha";

extern volatile struct a
{
	int a;
  /*тип поля*/
} 
b = {10, {/*когда структура вложена в структуру*/102987, "dawdad"}};

/* тест битовых полей */
struct adasdsadsad
{
	int adsad;
	
	int bitfield : 10;
	int bitf : 1, bb1, :2, bb2 : 2;
	
	struct j
	{
		int aa;
	};
  /*тип поля*/
};


static unsigned long long int a;


// просто какая-то параша \
с инициализацией
char *a, d, u, g = 1232;


///* так тоже можно */
volatile int;


enum my_enum1
{
	hello = 2,
	bonjour
} privet;


// запятая в конце - норма
enum my_enum2
{
	buy = 0,
	au_revoir = 10,
} poka;


struct test_struct
{
	int u, oo;
	struct j
	{
		int aa;
	} a;
	struct k
	{
		int bb;
	};
} test = {10};

volatile union test_union
{

	long double dubl;
	enum my_enum a;
	struct j
	{
		int aa;
	} a;
};


