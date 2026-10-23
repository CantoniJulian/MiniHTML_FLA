#include <iostream>
#include "stack.h"
 
stack s;

int q0(char* alpha), q1(char* alfa), q2(char* alfa), q3(char *alfa), qfin(char *alfa);

int q3(char* alpha)
{
	if (*alpha == s.peek())
	{
		std :: cout << "q3: " << alpha << std :: endl;
	
		alpha ++;
		s.pop();
		q2(alpha);
		return 1;
		
	}
	std :: cout << "Error anal en transición a q3.\n";
	return 0;
}


int q2(char* alpha)
{
std :: cout << "q2: " << alpha << std :: endl;
	if (*alpha != '>')
	{	

	
		return 0;
	}
	alpha++;
	
	q0(alpha);
	return 1;
}

int q1(char* alpha)
{
std :: cout << "q1: " << *alpha << std :: endl;


char* beta = alpha + 1;

std :: cout << "beta:" <<*beta << std :: endl;

if (*beta != '>' and *alpha != '/')
{
	alpha++;
	q0(alpha);
	return 1;
}
switch (static_cast<int>(*alpha))
{
	case 'b': case 'p': case 'i':
		s.add(*alpha);
		alpha ++;
		
		q2(alpha);
		break;

	case '/':
		beta++;
		if (*beta != '>')
		{
			alpha++;
			q0(alpha);
		}
		alpha++;
		q3(alpha);

		return 1;
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

		q1(alpha);

		return 1;
	
		case NULL:
		if (s.isEmpty())
		
		{
			std:: cout << ":D\n";
			return 1;
		}
std :: cout << ":( porque en la pila me quedé con:" << s.pop() << std :: endl;		
return 0;
		
	default:

		if (!s.isEmpty())
		{
		alpha++;
		
		
		q0(alpha);
		return 1;

		}

		std :: cout << "¡Ahora si estoy furiotsel! Porque me diste: "<< *alpha<< std :: endl;
		return 0;
}

}

int main()
{
	
	q0("<b>a<c</b>");
	std :: cout << "Finalizo el programa." << std :: endl;
}
