//*************************************************************************************
//      SIMPLE EMPLOYEE MANAGEMENT SYSTEM ---> QUEUE IMPLEMENTATION USING LINKED LIST
//*************************************************************************************

#include <iostream>

using namespace std;


struct Node {    //Struct of staff information   

    string name, address, phoneNo, dept;
    int ID, age;
    Node* next;
};



void menu() {    // Menu function


    cout << "************** UNITEN EMPLOYEE MANAGEMENT SYSTEM **************** \n"
        << "1. Insert Record\n"
        << "2. Search Record\n"
        << "3. Update Record\n"
        << "4. Display Record\n"
        << "5. Delete Record\n"
        << "6. Exit\n"
        << "*****************************************************************\n\n";

}

void insert(Node** head, Node** tail, int  &i) {      // creates and inserts the staff information into the LL

    Node* n = new Node();

    cout << "********* Enter the staff details **********\n";
    cout << "ID           : ";          cin >> n->ID;
    cout << "Name         : ";          getline (cin >> ws, n-> name);
    cout << "Age          : ";          cin >> n->age;
    cout << "Address      : ";          getline (cin >> ws, n-> address);
    cout << "Phone number : ";          cin >> n->phoneNo;
    cout << "Department   : ";          cin >> n->dept;
    n->next = NULL;


    if (*head == NULL)
        *head = *tail = n;

    else {
        (*tail)->next = n;
        *tail = n;
    }

    cout << "*******" << "Record " << i << " has been created successfully *******\n";
    ++i;  //Add 1 for the total record everytime the record is inserted
}


void search(Node* head) {  // operates the sequential search
    Node* n = head;
    int chooseID = 0;

    if (head == NULL) {
        cout << "Linked List not initialized\n";
        return;
    }

    cout << "=== Search Staff Details ===" << endl;
    cout << "Enter ID here (Search): ";
    cin >> chooseID;

    while (n != NULL) {
        if (n->ID == chooseID) {
            cout << "\n============================" << endl;
            cout << "\tRecord Found" << endl;
            cout << "============================" << endl;
            cout << "ID           : " << n->ID << endl;
            cout << "Name         : " << n->name << endl;
            cout << "Age          : " << n->age << endl;
            cout << "Address      : " << n->address << endl;
            cout << "Phone number : " << n->phoneNo << endl;
            cout << "Department   : " << n->dept << endl;
            return;
        }
        n = n->next;
    }

    if (n == NULL)
        cout << "=== Record not found ===\n";
}


void update(Node** head) { // update the data based on user's option

    Node* p = *head;
    int upd, opt;

    if (*head == NULL) {
        cout << "Linked List not initialized\n";
        return;
    }

    cout << "Enter staff ID that you would like to update: ";
    cin >> upd;

    cout << "Enter option to update :- \n"\
        << "\t1. Name\n"
        << "\t2. Age\n"
        << "\t3. Address\n"
        << "\t4. Phone Number\n"
        << "\t5. Department\n"
        << "\t6. Back to Menu\n";
    cout << "\nChoice: ";
    cin >> opt;

    while (p != NULL) {
        if (upd == p->ID) {
            if (opt == 1) {
                cout << "Enter new name: ";
                cin >> p->name;
            }

            else if (opt == 2) {
                cout << "Enter new age: ";
                cin >> p->age;
            }

            else if (opt == 3) {
                cout << "Enter new address: ";
                cin >> p->address;
            }

            else if (opt == 4) {
                cout << "Enter new phone no.: ";
                cin >> p->phoneNo;
            }

            else if (opt == 5) {
                cout << "Enter new department: ";
                cin >> p->dept;
            }

            else if (opt == 6) {
                return;
            }

            else {
                cout << "=== Invalid Input ===\n";
                return;
            }
        }
        p = p->next;
    }

    if (p == NULL)
        cout << "=== Record not found ===\n";
}


void display(Node* head) { // display all of the staff's record

    Node* n = head;
    int i = 1;

    if (head == NULL) {
        cout << "Linked List not initialized\n";
        return;
    }

    while (n != NULL) {
        cout << "\n=== Record " << i << " ===" << endl;
        cout << "ID           : " << n->ID << endl;
        cout << "Name         : " << n->name << endl;
        cout << "Age          : " << n->age << endl;
        cout << "Address      : " << n->address << endl;
        cout << "Phone number : " << n->phoneNo << endl;
        cout << "Department   : " << n->dept << endl;
        i++;
        n = n->next;
    }
}

void deleteRec(Node** head, Node **tail, int &i) { //delete the intended data based on the entered ID

    Node* p = *head;
    int delID;

    if (*head == NULL) {
        cout << "Linked List not initialized\n";
        return;
    }

    cout << "\n # Menu : Delete Record # " << endl;
    cout << " Enter Staff ID to be updated as 1st record: ";
    cin >> delID;

    int count = 0;
    char choice;

    while (p->ID != delID) {
        p = p->next;
        count++;
        if (p == NULL) {
            cout << "=== Record not found ===\n";
            return;
        }
    }

    cout << "You need to delete the first " << count << " record(s)\n";
    cout << "Press Y to proceed with deletion : ";
    cin >> choice;

    p = *head;
    if (choice == 'Y') {
        while ((*head)->ID != delID) {
            p = *head;
            *head = (*head)->next;
            if (*head == NULL)
                *tail = NULL;
            free(p);
            i--;        // It will minus 1 for the total record everytime the record is deleted
        }
    }
}


Node* swap(Node* ptr1, Node* ptr2) // swap the nodes
{
	Node* tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return ptr2;
}

/* Function to sort the list */
void bubbleSort(Node** head, Node **tail) // sort the user's name alphabetically
{
	Node** h;
	int i, j, swapped;
	int count = 0;
	
	Node *p = *head;
	while(p != NULL){
        count++;
        p = p->next;
    }

	for (i = 0; i <= count; i++)
	{

		h = head;
		swapped = 0;

		for (j = 0; j < count - i - 1; j++)
		{

			Node* p1 = *h;
			Node* p2 = p1->next;

			if (p1->name > p2->name)
			{

				/* update the link after swapping */
				*h = swap(p1, p2);
				swapped = 1;
			}

			h = &(*h)->next;
		}

		/* break if the loop ended without any swap */
		if (swapped == 0)
			break;
	}
    
    p = *head;
    while (p->next != NULL) {
        p = p->next;
    }
    *tail = p;
}


int userInput() { // Enter input

    int opt;

    cout << "Enter your choice: ";
    cin >> opt;

    return opt;
}

int main() {

    Node* head, * tail;
    head = tail = NULL;
    int opt, i = 1;

    do {
        cout << endl;
        menu();
        opt = userInput();

        switch (opt) {
        case 1: insert(&head, &tail, i);            break;
        case 2: search(head);                       break;
        case 3: update(&head);                      break;
        case 4: bubbleSort(&head, &tail); display(head);   break;
        case 5: deleteRec(&head, &tail, i);         break;
        case 6: break;
        default: cout << "=== Invalid Input ===\n"; break;
        }


    } while (opt != 6); //Sentinel Loop

    cout << "End of program\n\n";


    return 0;
}


