#include <iostream>
#include "stack.h"
 
stack s;

int q0(char* alpha), q1(char* alfa), q2(char* alfa), q3(char *alfa), qfin(char *alfa);

int q3(char* alpha)
{
std :: cout << "q3: " << alpha << std :: endl;
	if (*alpha == s.peek())
	{	
		alpha ++;
		s.pop();
		q2(alpha);
		return 1;

	}
	std :: cout << "Error anal de anidacion.\n";
	return 0;
}


int q2(char* alpha)
{
std :: cout << "q2: " << alpha << std :: endl;
	if (*alpha != '>')
	{	

	
		return 0;
	}
		std :: cout << "penenelortox.com.ar\n";
	alpha++;
	
	q0(alpha);
	return 1;
}

int q1(char* alpha)
{
std :: cout << "q1: " << alpha << std :: endl;
switch (static_cast<int>(*alpha))
{
	case 'b': case 'p': case 'i':
		s.add(*alpha);
		alpha ++;
		
		std :: cout << "Leí un texto dentro de una etiqueta.\n";
		q2(alpha);
		break;
	case '/':
		alpha++;
		std:: cout << "lol\n";	
		q3(alpha);

		return 1;
 		break;
	default:
		std :: cout << "Ahora estoy enojadrium.\n";
		return 0;
}

return 1;
}

int q0(char* alpha)
{

std :: cout << "q0: " << alpha << std :: endl;
switch (static_cast<int>(*alpha)) // lo trans(hot)forma en int para usarlo en los cases
{
	case '<':
		alpha++; // pasa al siguientrium

		std :: cout << "Leí un < \n";		

		q1(alpha);

		return 1;
	
		case NULL:
		if (s.isEmpty())
		
		{
			return 1;
		}
		return 0;
		
	default:

		if (!s.isEmpty())
		{
		alpha++;
		
		std:: cout << "Leí texto entre etiquetas\n";
		
		q0(alpha);
		return 1;

		}

		std :: cout << "¡Ahora si estoy furiotsel! Porque me diste: "<< *alpha<< std :: endl;
		return 0;
}

}

int main()
{
	
	q0("<b><p>aassas</p>a</b><i>dedo en el culo</i>");
	std :: cout << "pomni" << s.pop() << "\n";
}
