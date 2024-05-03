#include <stdio.h>
#include <stdlib.h>


#define MAX_TERMS 101


typedef struct {
	float gaesu;
	int chasu;
}polynomial;
polynomial bae[MAX_TERMS] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };
int bingoongan = 6;

//2개의 정수를 비교
char compare(int a, int b) {
	if (a > b)
		return '>';
	else if (a == b)
		return '=';
	else
		return '<';
}

//새로운 항을 다항식에 추가함.

void attach(float gaesu, int chasu) {
	if (bingoongan > MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	bae[bingoongan].gaesu = gaesu;
	//bae[bingoongan]은 구조체 배열 bae에서 인덱스가 bingoongan인 요소를 가리키고, 여기에 .gaesu를 붙이면 해당 요소의 gaesu 멤버에 접근할 수 있습니다.
	//bae[bingoongan].gaesu는 구조체 배열 bae의 bingoongan 인덱스 위치에 있는 요소의 gaesu 멤버를 나타냅니다. 이렇게 접근하여 해당 멤버에 값을 할당하거나 가져올 수 있습니다.
	bae[bingoongan].chasu = chasu;
	bingoongan++;
}

//C=A+B
void poly_sub2(int Astart, int Aend, int Bstart, int Bend, int* Cstart, int* Cend) {

	float tempgaesu;
	*Cstart = bingoongan;
	while (Astart <= Aend && Bstart <= Bend)
		switch (compare(bae[Astart].chasu, bae[Bstart].chasu)) {
		case '>': //A의 차수>B의 차수
			attach(bae[Astart].gaesu, bae[Astart].chasu);
			Astart++;
			break;
		case '=': //A의 차수==B의 차수
			tempgaesu = bae[Astart].gaesu - bae[Bstart].gaesu; //+에서 -로 바꿔준거밖에 없음.
			if (tempgaesu)
				attach(tempgaesu, bae[Astart].chasu);
			Astart++;
			Bstart++;
			break;
		case '<':
			attach(-bae[Bstart].gaesu, bae[Bstart].chasu);
			Bstart++;
			break;
		}

	//A의 나머지 항들을 이동함
	for (; Astart <= Aend; Astart++)
		attach(bae[Astart].gaesu, bae[Astart].chasu);

	//B의 나머지 항들을 이동함
	for (; Bstart <= Bend; Bstart++)
		attach(bae[Bstart].gaesu, bae[Bstart].chasu);
	*Cend = bingoongan - 1;
}

void print_poly(int start, int end) {
	for (int i = start; i < end; i++)
		printf("%3.1fx^%d + ", bae[i].gaesu, bae[i].chasu);
	printf("%3.1fx^%d\n", bae[end].gaesu, bae[end].chasu);

}


int main(void) {

	int Astart = 0, Aend = 2, Bstart = 3, Bend = 5, Cstart, Cend;
	poly_sub2(Astart, Aend, Bstart, Bend, &Cstart, &Cend);
	print_poly(Astart, Aend);
	print_poly(Bstart, Bend);
	printf("-------------------------------------------------------\n");
	print_poly(Cstart, Cend);
	return 0;

}
