# include <iostream>


struct node
{
	char dt;
	struct node *next;
};


class stack
{
	private:
		node * bot = new node;
		node * top = new node;
		node * cont = new node;

	public:
		char peek();
		char pop();
		void add(char x);
		bool isEmpty();
		stack();

};

stack :: stack()
{
	top = NULL;

	// top->next = nullptr;
	bot = top;
	cont = top;

}

char stack :: peek()
{
	if(top != NULL)
	{	
	return top->dt;

	}
	return 0;
}

char stack :: pop()
{

	if (top != NULL)
	{
	
	node *aux = top->next; 
	char out = top->dt;
	
	top = aux;

	return out;
	}
	else{ return 0;
		
}
}

void stack :: add(char x)
{
	
	node *new_node = new node;
	*new_node = {x, top};
	
	top = new_node;

	return;
}

bool stack :: isEmpty()
{
	if(top == NULL)
	{
	std::  cout << "No durarías ni un día en el vacío.\n";
	return true;
	}
	std :: cout << "Más falso que billete de 2 pesos\n" << top->dt;
	return false;
}

/*int main()
{
	stack  a;
	a.add('s');
	a.add('w');

	std :: cout << a.pop();
	std :: cout << a.pop();
	std :: cout << a.pop();
	std :: cout << a.pop();
	a.add('e');
	std :: cout << "\n" << a.isEmpty();
}

*/
// Descomentar para probar :3
