#include <iostream>
#include "stack.h"
 
stack s;

int q0(char* alpha), q1(char* alfa), q2(char* alfa), q3(char *alfa), qfin(char *alfa);

int q3(char* alpha)
{
	if (*alpha == s.peek())
	{	
		alpha ++;
		s.pop();
		q2(alpha);
		return 1;

	}
	return 0;
}


int q2(char* alpha)
{
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

std :: cout << "q0\n";
switch (static_cast<int>(*alpha)) // lo trans(hot)forma en int para usarlo en los cases
{
	case '<':
		alpha++; // pasa al siguientrium

		std :: cout << "Leí un < \n";		

		q1(alpha);

		return 1;

	case NULL:
		std :: cout << "Ponele que lambda\n";
		if (s.isEmpty())
		
		{
			std :: cout << "Se encuentra el Doctor Peralta\n";
			return 1;
		}
		return 0;
		
	default:

		std :: cout << "¡Ahora si estoy furiotsel! Porque me diste: "<< *alpha;
		return 0;
}

}

int main()
{
	
	q0("<b></i>");
	std :: cout << "pomni" << s.pop() << "\n";
}
