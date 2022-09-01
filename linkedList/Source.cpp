#include <iostream>

class Node {

public:
	int key;
	int data;
	Node* next;

	
};

class SinglyLinkedList {

public:
	Node* head;

	SinglyLinkedList()
	{
		head = NULL;
	}

	SinglyLinkedList(Node *ptr)
	{
		head = ptr;
	}

	Node* nodeExists(int key)
	{
		Node* temp = NULL;
		Node* ptr = head;

		while (ptr != NULL)
		{
			if (ptr->key == key)
			{
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
	}

	void appendNode(Node* n)
	{
		
		if (nodeExists(n->key) != NULL)
		{
			std::cout << "Key value already exists\n";
		}
		else if (head == NULL)
		{
			head = n;
			std::cout << "Node appended\n";
		}
		else
		{
			Node* ptr = head;

			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}

			ptr->next = n;
			std::cout << "Node appended\n";

		}
	}

	void prependNode(Node* n)
	{
		if (nodeExists(n->key) != NULL)
		{
			std::cout << "Node already exists\n";
		}
		else
		{
			n->next = head;
			head = n;

			std::cout << "Node prepended\n";
		}

	}
		
	void insertNodeAfter(int k, Node* n)
	{
		Node* ptr = nodeExists(k);

		if (ptr == NULL)
		{
			std::cout << "Node at key " << k << " does not exist\n";
		}
		else
		{
			if (nodeExists(n->key) != NULL)
			{
				std::cout << "Node already exists\n";
			}
			else
			{
				//link to next node
				n->next = ptr->next;

				//relink from previous node to new node
				ptr->next = n;
				
				
				std::cout << "Node inserted\n";
			}
			
		}
	}

	void deleteNodeByKey(int k)
	{
		if (head == NULL)
		{
			std::cout << "List does not exist\n";
		}
		else if (head->key == k)
		{
			head = head->next;
		}
		else
		{
			Node* temp = NULL;
			Node* prevPtr = head;
			Node* currentPtr = head->next;
			while (currentPtr != NULL)
			{
				if (currentPtr->key == k)
				{
					temp = currentPtr;
					currentPtr = NULL;
				}
				else 
				{
					prevPtr = prevPtr->next;
					currentPtr = currentPtr->next;
				}
			}
			if (temp != NULL)
			{
				prevPtr->next = temp->next;
				std::cout << "Node unlinked\n";
			}
			else
			{
			std::cout << "Node does not exist\n";
			}
		}
	}

	void updateNodeByKey(int k, int d)
	{
		Node* ptr = nodeExists(k);
		if (ptr != NULL)
		{
			ptr->data = d;
			std::cout << "Node updated\n";
		}
		else
		{
			std::cout << "Node does not exist\n";
		}
	}

	void printList()
	{
		std::cout << "\nSingly linked list values\n";
		Node* temp = head;
		while (temp != NULL)
		{
			std::cout << temp->key << ", " << temp->data << " --> ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}

};

int main()
{
	
	SinglyLinkedList list;

	int option;
	int k1;
	int key;
	int data;


	do {

	std::cout << "Main Menu\n";
	std::cout << "1. append node\n";
	std::cout << "2. prepend node\n";
	std::cout << "3. insert node\n";
	std::cout << "4. delete node\n";
	std::cout << "5. update node\n";
	std::cout << "6. print list\n";
	std::cout << "7. clear screen\n";
	std::cout << "0. exit\n";

	std::cin >> option;
	Node* n1 = new Node();

	switch (option)
	{
	case 1:
		std::cout << "\nenter key and data to append: ";
		std::cin >> key;
		std::cin >> data;
		n1->key = key;
		n1->data = data;
		list.appendNode(n1);
		break;
	case 2:
		std::cout << "\nenter key and data to prepend: ";
		std::cin >> key;
		std::cin >> data;
		n1->key = key;
		n1->data = data;
		list.prependNode(n1);
		break;
	case 3:
		std::cout << "insert after node key: ";
		std::cin >> k1;
		std::cout << "enter key and data to insert: ";
		std::cin >> key;
		std::cin >> data;
		n1->key = key;
		n1->data = data;
		list.insertNodeAfter(k1, n1);
		break;
	case 4:
		std::cout << "enter key of node to delete: ";
		std::cin >> k1;
		list.deleteNodeByKey(k1);
		break;
	case 5:
		std::cout << "enter key of node to update: ";
		std::cin >> k1;
		std::cout << "enter updated data: ";
		std::cin >> data;
		list.updateNodeByKey(k1, data);
		break;
	case 6:
		list.printList();
		break;
	}

	} while (option != 0);

	

}