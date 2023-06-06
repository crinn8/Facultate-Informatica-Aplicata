/*	Sa se construiasca forma poloneza postfixata pentru o expresie aritmetica data si sa se evalueze expresia, utilizand stive. */


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

template<typename T>

struct stack {
	struct nod {
		T info;
		nod *leg;
	};
	nod *varf;
	stack() {
		varf = NULL;
	}
	void push(T c) {
		nod *x; x = new nod;
		x->info = c;
		x->leg = NULL;
		if (varf != NULL)
			x->leg = varf;
		varf = x;
	};
	void pop() {
		nod *y; y = new nod;
		y = varf;
		varf = varf->leg;
		delete y;
	};
	T top() {
		if (varf != NULL)
			return varf->info;
	}
	bool empty() {
		if (varf == NULL)
			return 1;
		else
			return 0;
	}
};

void citire(char sir[100]) {
	cout << "Scrieti expresia aritmetica: "; cin >> sir;
	cout << endl;
}
int paranteze(char sir[100]) {
	// functia verifica daca parantezele expresiei sunt scrise in mod corect
	stack<char> st; int i, j = 0; char s[100] = "";
	for (i = 0; i < strlen(sir) - 1; i++)
		if (sir[i] == '(' && sir[i + 1] == ')')
			return 0;
	for (i = 0; i < strlen(sir); i++)
		if (sir[i] == '(' || sir[i] == ')') {
			s[j] = sir[i];
			j++;
		}
	s[i] = '\0';
	if (s[0] == '(' || s[0] == ')') {
		st.push(s[0]);
		for (i = 1; i < strlen(s); i++)
			if (st.empty())
				st.push(s[i]);
			else
				if (st.top() == '(' && s[i] == ')')
					st.pop();
				else
					st.push(s[i]);
		if (st.empty())
			return 1;
		else
			return 0;
	}
	else
		return 1;
}
int operanzi(char sir[100]) {
	// functia verifica daca este corect numarul operanzilor fata de operatori
	int i, j = 0, q = 0;
	for (i = 0; i < strlen(sir); i++) {
		if (sir[i] == '+' || sir[i] == '-' || sir[i] == '*' || sir[i] == '/' || sir[i] == '^' || sir[i] == '%')
			j++;
		if (islower(sir[i]) || isdigit(sir[i]))
			q++;
	}
	if (j == q - 1)
		return 1;
	else
		return 0;
}
int caractere(char sir[100]) {
	// functia verifica daca expresia contine si alte caractere decat cele permise
	int i;
	for (i = 0; i < strlen(sir); i++)
		if (isdigit(sir[i]) == 0 && islower(sir[i]) == 0 && sir[i] != '(' && sir[i] != ')' && sir[i] != '+' && sir[i] != '-' && sir[i] != '*' && sir[i] != '/' && sir[i] != '^' && sir[i] != '%')
			return 0;
	return 1;
}
int prim(char sir[100]) {
	// functia verifica daca primul caracter al expresiei nu este operator
	if (isdigit(sir[0]) == 0 && islower(sir[0]) == 0 && sir[0] != '(' && sir[0] != ')')
		return 0;
	return 1;
}
int corectitudine(char sir[100]) {
	if (paranteze(sir) == 0 || operanzi(sir) == 0 || caractere(sir) == 0 || prim(sir) == 0)
		return 0;
	else
		return 1;
}

void postfixare(char e[100]) {
	stack <char> st; char s[100] = ""; int i, j = 0, pr_curenta, pr_stiva;
	for (i = 0; i < strlen(e); i++) {
		if (e[i] == '(') {
			st.push(e[i]);
		}
		if (islower(e[i]) || isdigit(e[i])) {
			s[j] = e[i]; j++; s[j] = ' '; j++;
		}
		if (e[i] == '+' || e[i] == '-' || e[i] == '*' || e[i] == '/' || e[i] == '%' || e[i] == '^') {
			if (e[i] == '+' || e[i] == '-')	pr_curenta = 1;
			if (e[i] == '*' || e[i] == '/') pr_curenta = 2;
			if (e[i] == '^') pr_curenta = 3;
			if (st.empty())
				pr_stiva = -1;
			else {
				if (st.top() == '(' || st.top() == ')') pr_stiva = 0;
				if (st.top() == '+' || st.top() == '-') pr_stiva = 1;
				if (st.top() == '*' || st.top() == '/') pr_stiva = 2;
				if (st.top() == '^') pr_stiva = 3;
			}
			if (pr_stiva >= pr_curenta) {
				while (pr_stiva >= pr_curenta) {
					s[j] = st.top();
					st.pop();
					j++; s[j] = ' '; j++;
					if (st.empty())
						pr_stiva = -1;
					else {
						if (st.top() == '(' || st.top() == ')') pr_stiva = 0;
						if (st.top() == '+' || st.top() == '-') pr_stiva = 1;
						if (st.top() == '*' || st.top() == '/') pr_stiva = 2;
						if (st.top() == '^') pr_stiva = 3;
					}
				}
				st.push(e[i]);
			}
			else
				st.push(e[i]);

		}
		if (e[i] == ')') {
			while (st.top() != '(') {
				s[j] = st.top();
				j++; s[j] = ' '; j++;
				st.pop();
			}
			if (st.top() == '(')
				st.pop();
		}

	}

	while (!st.empty()) {
		s[j] = st.top();
		st.pop();
		j++; s[j] = ' '; j++;
	}
	strcpy(e, s);
	cout << "Forma poloneza postfixata a expresiei este: " << e << endl << endl;
}
void evaluare(char e[100]) {
	stack <double> st; double x = 0, y = 0, z, rez; char o[2]; unsigned i = 0;
	for (i = 0; i<strlen(e); i++) {
		if (islower(e[i])) {
			cout << e[i] << " = "; cin >> rez;
			st.push(rez);
		}
		if (isdigit(e[i])) {
			o[0] = e[i];
			st.push(atoi(o));
		}
		if (e[i] == '+' || e[i] == '-' || e[i] == '*' || e[i] == '/' || e[i] == '^') {
			x = st.top(); st.pop();
			y = st.top(); st.pop();
			if (e[i] == '+')
				z = y + x;
			if (e[i] == '-')
				z = y - x;
			if (e[i] == '*')
				z = y * x;
			if (e[i] == '/')
				z = y / x;
			if (e[i] == '^')
				z = pow(y, x);
			st.push(z);
		}
	}
	cout << "Evaluarea expresiei: " << st.top() << endl << endl;
}

int main() {
	char s[100];
	cout << endl << "Programul accepta in scrierea expresiei litere, cifre si operatorii: + , - , * , / , ^ , dar fara numere." << endl << endl;
	citire(s);
	if (corectitudine(s) == 0)
		cout << "Expresia NU este corecta." << endl << endl;
	else {
		postfixare(s);
		evaluare(s);
	}
	return 0;
}


