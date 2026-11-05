#include <iostream>
#include "stack.h"
#include <fstream>
#include <string>
#include <cstdlib>

stack s;

int q0(char* alpha), q1(char* alfa), q2(char* alfa), q3(char *alfa), qfin(char *alfa);

int q3(char* alpha) //luego de leer /, cierro con el apilado
{
	if (*alpha == s.peek())
	{
		std :: cout << "q3: " << alpha << std :: endl;
	
		alpha ++;
		s.pop();
		q2(alpha);
		return 1;
		
	}
	std :: cout << "Error de anidación en transición desde q3. Esperaba:" << s.peek() << "\n";
	return 0;
}


int q2(char* alpha)// luego de leer contenido de etiqueta se cierra
{
std :: cout << "q2: " << alpha << std :: endl;
	if (*alpha != '>')
	{	

		std :: cout << "Esperaba cierre de etiqueta '>' en q2." << std :: endl;
		return 0;
	}
	alpha++;
	
	q0(alpha);
	return 1;
}

int q1(char* alpha)
{
std :: cout << "q1: " << alpha << std :: endl;

//std :: cout << "beta:" <<*beta << std :: endl;

switch (static_cast<int>(*alpha))
{
	case 'b': case 'p': case 'i': case 'x':
		s.add(*alpha);
		alpha ++;
		
		q2(alpha);
		break;

	case '/':
		if(s.isEmpty())
		{
			std :: cout << "Etiqueta de cierre sin elementos en la pila. \n";
			return 0;
		}
		alpha++;
		q3(alpha);

		return 1;
	

	default:
		
		std :: cout << "Esperaba contenido válido de etiqueta. \n";
		return 0;
}

return 1;
}

int q0(char* alpha) // texto o
{

std :: cout << "q0: " << alpha << std :: endl;
switch (static_cast<int>(*alpha)) // lo transforma en int para usarlo en los cases
{

	case '>':
		std :: cout << "En q0 encontré '>' sin abir etiqueta." << std :: endl;
		return 0;
	
	case '<':
		alpha++; // pasa al siguientrium		

		q1(alpha);

		return 1;
	
	case NULL:
		if (s.isEmpty())
		
		{
			std:: cout << "Reconozco esta cadena :D\n";
			return 1;
		}
std :: cout << "Falta cierre de etiqueta :( porque en la pila me quedé con:" << s.pop() << std :: endl;		
return 0;
		
	default:

		alpha++;
		
		
		q0(alpha);
		return 1;

}
}

int main()
{
	std :: string myText;
	std::ifstream MyReadFile("in.html");


	getline (MyReadFile, myText);

	MyReadFile.close(); 
	std :: cout << "Lectura terminada\n	"<< myText << std ::endl;

	char * input = &myText[0];
	q0(input);
	std :: cout << "Finalizo el programa." << std :: endl;
	
 }
