#include <cstring>
#include <cstdio>
#include <cstdlib>
#define SIZE 15

char board[SIZE][SIZE];       //���������ڱ�ʾ���̸��
char whiteplace[SIZE][SIZE];    //���������ڼ�¼���岼��
char blackplace[SIZE][SIZE];    //���������ڼ�¼���岼��
void preboard(void);           // �ú������ڽ�����λ�÷��� 
void displayboard(void);      //�ú���������ʾ���̼��������

int rewx, rewy;             //��¼�������һ�����ӵ�λ��
int rebx, reby;              //��¼�������һ�����ӵ�λ��

void setblack(void);
void setwhite(void);     //��������������ʵ�ָ���ָ����������
void chospatn(void);      //ѡ���սģʽ
void choside(void);      //����ѡ�ߣ��˻���ս��
void order(void);         //���ھ�����һ���ֵ���һ�������˶�ս��
void aisetblack(void);    //����AIִ����ʱ������
void aisetwhite(void);     //����AIִ����ʱ������
int trans(char c);      //������ĸ�����ֵ�ת��

void pve(void);           //pve
void pvp(void);           //pvp
void whowins(void);        //����ʤ���ж�

int main() {
	preboard();
	displayboard();
	chospatn();
	return 0;
}

void preboard(void) {
	int i, j;
	board[0][0] = 1;            //��,�������Ͻ�
	board[0][SIZE - 1] = 2;       //�����������Ͻ�
	board[SIZE - 1][0] = 3;       //�����������½�
	board[SIZE - 1][SIZE - 1] = 4;  //��,�������½�
	for (j = 1; j < SIZE - 1; j++) {
		board[0][j] = 5;        //��,�������� 
		board[SIZE - 1][j] = 6;   //�ۣ��������� 
	}
	for (i = 1; i < SIZE - 1; i++) {
		board[i][0] = 7;        //��,��������
		board[i][SIZE - 1] = 8;   //�̣��������� 
	}
	for (i = 1; i < SIZE - 1; i++) {
		for (j = 1; j < SIZE - 1; j++) {
			board[i][j] = 9;    //�࣬�����в� 
		}
	}
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			blackplace[i][j] = 0;
			whiteplace[i][j] = 0;         //��δ���ӵ�λ��ͳһ���Ϊ0
		}
	}
}

void displayboard(void) {
	int i = 0, j = 0;
	putchar('\n');
	for (i = 0; i < SIZE; i++) {
		printf("%2d", i);         //�������������
		for (j = 0; j < SIZE; j++) {
			switch (board[i][j]) {
			case 1:printf("��"); break;
			case 2:printf("��"); break;
			case 3:printf("��"); break;
			case 4:printf("��"); break;
			case 5:printf("��"); break;
			case 6:printf("��"); break;
			case 7:printf("��"); break;
			case 8:printf("��"); break;
			case 9:printf("��"); break;
			case 10:printf("��"); break;
				//case 11:printf("��");break;
			case 12:printf("��"); break;
				//case 13:printf("��");break;
			default:             break;
			}
		}
		printf("\n");
	}
	printf("  A B C D E F G H I J K L M N O \n");      //������̺�����
}

int trans(char c) {
	switch (c) {
	case 'A':return 0;
	case 'B':return 1;
	case 'C':return 2;
	case 'D':return 3;
	case 'E':return 4;
	case 'F':return 5;
	case 'G':return 6;
	case 'H':return 7;
	case 'I':return 8;
	case 'J':return 9;
	case 'K':return 10;
	case 'L':return 11;
	case 'M':return 12;
	case 'N':return 13;
	case 'O':return 14;
	}
}

void setblack(void) {
	int xb, ybi;
	char yb;
	while (1) {
		xb = ybi = 0;
		printf("��������ӵ����꣨��ʽ'3 A'��:\n");    //��ʾ����
		scanf("%d %c", &xb, &yb);             //�������ӵ�λ��
		ybi = trans(yb);
		if (xb >= 0 && xb < SIZE && ybi >= 0 && ybi < SIZE) {
			if (blackplace[xb][ybi] == 0) {
				blackplace[xb][ybi] = 1;
				whiteplace[xb][ybi] = 2;
				board[xb][ybi] = 10;                //0��ʾ�õ�Ϊ�գ�1��ʾ�õ��к��壬2��ʾ�õ��а��壬10��ʾ����������һ����
				displayboard();
				rebx = xb;
				reby = ybi;
				break;
			}
			else {
				printf("�õ��������ӣ�������;\n");
			}
		}
		else {
			printf("�������̷�Χ��������;\n");
		}
	}
}

void setwhite(void) {
	int xw, ywi;
	char yw;
	while (1) {
		xw = ywi = 0;
		printf("��������ӵ����꣨��ʽ'3 A'��:\n");    //��ʾ����
		scanf("%d %c", &xw, &yw);             //�������ӵ�λ��
		ywi = trans(yw);
		if (xw >= 0 && xw < SIZE && ywi >= 0 && ywi < SIZE) {
			if (whiteplace[xw][ywi] == 0) {
				whiteplace[xw][ywi] = 1;
				blackplace[xw][ywi] = 2;
				board[xw][ywi] = 12;                //0��ʾ�õ�Ϊ�գ�1��ʾ�õ��а��壬2��ʾ�õ��к��壬12��ʾ����������һ����
				displayboard();
				rewx = xw;
				rewy = ywi;
				break;
			}
			else {
				printf("�õ��������ӣ�������;\n");
			}
		}
		else {
			printf("�������̷�Χ��������;\n");
		}
	}
}

void chospatn(void) {
	int p;
	while (1) {
		p = 0;
		printf("��ѡ���սģʽ:����0�����˻���ս������1�������˶�ս\n");
		scanf("%d", &p);
		if (p == 0) {
			pve();   break;
		}
		else if (p == 1) {
			pvp();   break;
		}
		else {
			printf("���벻���Ϲ淶������������\n");
		}
	}
}

void choside(void) {           //���õ��ҽ���ѡ���˻���ս
	int c;
	while (1) {
		c = 0;
		printf("��ѡ�ߣ���������0ѡ����壬��������1ѡ����壺\n");      //��ʾѡ��
		scanf("%d", &c);
		if (c == 0) {
			while (1) {
				setblack();
				whowins();
				aisetwhite();
				whowins();
			}
		}
		else if (c == 1) {
			while (1) {
				aisetblack();
				whowins();
				setwhite();
				whowins();
			}
		}
		else {
			printf("���벻���Ϲ淶������������:\n");
		}
	}
}

void order(void) {        //���˶�ս������˳��     
	while (1) {
		setblack();
		whowins();
		setwhite();
		whowins();
	}
}

void whowins(void) {
	int i, j, s;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < 11; j++) {
			if (blackplace[i][j] == 1 && blackplace[i][j + 1] == 1 && blackplace[i][j + 2] == 1 && blackplace[i][j + 3] == 1 && blackplace[i][j + 4] == 1) {
				printf("�����ʤ\n");
				system("pause");
				exit(1);
			}
			if (whiteplace[i][j] == 1 && whiteplace[i][j + 1] == 1 && whiteplace[i][j + 2] == 1 && whiteplace[i][j + 3] == 1 && whiteplace[i][j + 4] == 1) {
				printf("�����ʤ\n");
				system("pause");
				exit(1);
			}
		}
	}                 //��ÿһ��Ѱ������
	for (j = 0; j < SIZE; j++) {
		for (i = 0; i < 11; i++) {
			if (blackplace[i][j] == 1 && blackplace[i + 1][j] == 1 && blackplace[i + 2][j] == 1 && blackplace[i + 3][j] == 1 && blackplace[i + 4][j] == 1) {
				printf("�����ʤ\n");
				system("pause");
				exit(1);
			}
			if (whiteplace[i][j] == 1 && whiteplace[i + 1][j] == 1 && whiteplace[i + 2][j] == 1 && whiteplace[i + 3][j] == 1 && whiteplace[i + 4][j] == 1) {
				printf("�����ʤ\n");
				system("pause");
				exit(1);
			}
		}
	}                 //��ÿһ��Ѱ������
	for (s = 4; s < SIZE; s++) {
		for (i = 0, j = s; i + 4 <= s && j - 4 >= 0; i++, j--) {
			if (blackplace[i][j] == 1 && blackplace[i + 1][j - 1] == 1 && blackplace[i + 2][j - 2] == 1 && blackplace[i + 3][j - 3] == 1 && blackplace[i + 4][j - 4] == 1) {
				printf("�����ʤ\n");
				system("pause");
				exit(1);
			}
			if (whiteplace[i][j] == 1 && whiteplace[i + 1][j - 1] == 1 && whiteplace[i + 2][j - 2] == 1 && whiteplace[i + 3][j - 3] == 1 && whiteplace[i + 4][j - 4] == 1) {
				printf("�����ʤ\n");
				system("pause");
				exit(1);
			}
		}
	}
	for (s = 1; s < SIZE - 4; s++) {
		for (i = s, j = SIZE - 1; i + 4 < SIZE && j - 4 >= s; i++, j--) {
			if (blackplace[i][j] == 1 && blackplace[i + 1][j - 1] == 1 && blackplace[i + 2][j - 2] == 1 && blackplace[i + 3][j - 3] == 1 && blackplace[i + 4][j - 4] == 1) {
				printf("�����ʤ\n");
				system("pause");
				exit(1);
			}
			if (whiteplace[i][j] == 1 && whiteplace[i + 1][j - 1] == 1 && whiteplace[i + 2][j - 2] == 1 && whiteplace[i + 3][j - 3] == 1 && whiteplace[i + 4][j - 4] == 1) {
				printf("�����ʤ\n");
				system("pause");
				exit(1);
			}
		}
	}                 //��б��Ϊ����ֱ����Ѱ������
	for (s = 0; s < SIZE - 4; s++) {
		for (i = 0, j = s; i + 4 < SIZE - s && j + 4 < SIZE; i++, j++) {
			if (blackplace[i][j] == 1 && blackplace[i + 1][j + 1] == 1 && blackplace[i + 2][j + 2] == 1 && blackplace[i + 3][j + 3] == 1 && blackplace[i + 4][j + 4] == 1) {
				printf("�����ʤ\n");
				system("pause");
				exit(1);
			}
			if (whiteplace[i][j] == 1 && whiteplace[i + 1][j + 1] == 1 && whiteplace[i + 2][j + 2] == 1 && whiteplace[i + 3][j + 3] == 1 && whiteplace[i + 4][j + 4] == 1) {
				printf("�����ʤ\n");
				system("pause");
				exit(1);
			}
		}
	}
	for (s = 1; s < SIZE; s++) {
		for (i = s, j = 0; i + 4 < SIZE && j + 4 < SIZE - s; i++, j++) {
			if (blackplace[i][j] == 1 && blackplace[i + 1][j + 1] == 1 && blackplace[i + 2][j + 2] == 1 && blackplace[i + 3][j + 3] == 1 && blackplace[i + 4][j + 4] == 1) {
				printf("�����ʤ\n");
				system("pause");
				exit(1);
			}
			if (whiteplace[i][j] == 1 && whiteplace[i + 1][j + 1] == 1 && whiteplace[i + 2][j + 2] == 1 && whiteplace[i + 3][j + 3] == 1 && whiteplace[i + 4][j + 4] == 1) {
				printf("�����ʤ\n");
				system("pause");
				exit(1);
			}
		}
	}                 //��б��Ϊ����ֱ����Ѱ������
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (blackplace[i][j] == 0) {
				goto quit;
			}
		}
	}
	printf("ƽ��\n");
	exit(1);
quit:s = 0;
}

void pvp(void) {         //�������˶�ս
	order();
}

void pve(void) {        //�����˻���ս
	choside();
}


void aisetblack(void) {
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (blackplace[i][j] == 0) {
				blackplace[i][j] = 1;
				whiteplace[i][j] = 2;
				board[i][j] = 10;
				displayboard();
				goto out;
			}
		}
	}
out:i = j = 0;
}

void aisetwhite(void) {
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (whiteplace[i][j] == 0) {
				whiteplace[i][j] = 1;
				blackplace[i][j] = 2;
				board[i][j] = 12;
				displayboard();
				goto out;
			}
		}
	}
out:i = j = 0;
}
