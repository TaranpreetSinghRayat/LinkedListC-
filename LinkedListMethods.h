using namespace std;

struct node{
    int data;
    struct node *link;
};

class LinkedListMethods{
private:
struct node *head,*pointer,*pointer2,*temp;
int selection,i,data;
char ans;

    void insertDataFront(struct node **start){
        int dataValue;
        this->head = *start;
        cout << "Enter Data for Node : ";
        cin >> dataValue;
        this->temp = new node();
        this->temp->data = dataValue;
        this->temp->link = this->head->link;
        this->head->link = this->temp;
        cout << "Node with data ["<< dataValue << "] added at front."<<endl;
    }

    void insertDataEnd(struct node **start){
        int dataValue;
        this->head = *start;
        cout << "Enter data for node : ";
        cin >> dataValue;
        this->temp = new node();
        this->pointer = this->head;
        while(this->pointer->link != NULL){
            this->pointer = this->pointer->link;
        }
        this->temp->data = dataValue;
        this->temp->link = this->pointer->link;
        this->pointer->link = this->temp;
        cout << "Node data ["<<dataValue<<"] added at end of node." <<endl;
    }

    void insertDataAnyPoint(struct node **start,int dataValue,int position){
        this->head = *start;
        this->temp = new node();
        this->pointer = this->head;
        while(this->pointer->link != NULL && this->pointer->data != position){
            this->pointer = this->pointer->link;
        }
        if(this->pointer->data == position){
            this->temp->data = dataValue;
            this->temp->link = this->pointer->link;
            this->pointer->link = this->temp;
            cout << "Node inserted at "<< position <<endl;
        }else{
            cout << "Value " << position << " not found."<<endl;
        }
    }

    void displayNodeData(struct node **start){
            this->pointer = *start;
            while(this->pointer->link != NULL){
                this->pointer = this->pointer->link;
                cout << this->pointer->data << " -> ";
            }
            cout <<endl;
    }

    void deleteDataFront(struct node **start){
        this->head = *start;
        if(this->head->link == NULL){
            cout << "Empty Node"<<endl;
            cout << "Please insert some data first."<<endl;
            cout << "Want to go to Insert Menu?(y/n) : ";
            cin >> ans;
            if(this->ans == 'y' || this->ans == 'Y'){
                this->insertDataMenu(&head);
            }else{
                cout << "Exit."<<endl;
            }
        }else{
            this->pointer = this->head->link;
            this->head->link = this->pointer->link;
            free(this->pointer);
            cout << "Node deleted from front."<<endl;
        }
    }

    void deleteDataEnd(struct node **start){
        this->head = *start;
       if(this->head->link == NULL){
            cout << "Empty Node"<<endl;
            cout << "Please insert some data first."<<endl;
            cout << "Want to go to Insert Menu?(y/n) : ";
            cin >> ans;
            if(this->ans == 'y' || this->ans == 'Y'){
                this->insertDataMenu(&head);
            }else{
                cout << "Exit."<<endl;
            }
        }else{
            this->pointer = this->head;
            while(this->pointer->link != NULL){
                this->pointer2 = this->pointer;
                this->pointer = this->pointer->link;
            }
            this->pointer2->link = this->pointer->link;
            free(this->pointer);
            cout << "Node deleted from last."<<endl;
        }
    }

    void deleteDataAnyPosition(struct node **start,int position){
        this->head = *start;
        if(this->head->link == NULL){
            cout << "Empty Node"<<endl;
            cout << "Please insert some data first."<<endl;
            cout << "Want to go to Insert Menu?(y/n) : ";
            cin >> ans;
            if(this->ans == 'y' || this->ans == 'Y'){
                this->insertDataMenu(&head);
            }else{
                cout << "Exit."<<endl;
            }
        }else{
            this->pointer = this->head;
            while(this->pointer->link != NULL && this->pointer->data != position){
                this->pointer2 = this->pointer->link;
                this->pointer = this->pointer->link;
            }
            if(this->pointer->data == position){
                this->pointer2->link = this->pointer->link;
                free(this->pointer);
                cout << "Node with data [" << position << "] deleted."<<endl;
            }else{
                cout << position << " not found in node."<<endl;
            }
        }
    }

    void searchNodeData(struct node **start,int data){
        this->head = *start;
        if(this->head->link == NULL){
            cout << "Empty Node"<<endl;
            cout << "Please insert some data first."<<endl;
            cout << "Want to go to Insert Menu?(y/n) : ";
            cin >> ans;
            if(this->ans == 'y' || this->ans == 'Y'){
                this->insertDataMenu(&head);
            }else{
                cout << "Exit."<<endl;
            }
        }else{
            this->pointer = this->head;
            while(this->pointer != NULL){
                if(this->pointer->data == data){
                    cout << data << " found."<<endl;
                    return;
                }
                this->pointer = this->pointer->link;
            }
            cout << data << " not found."<<endl;
        }
    }

public:
    void insertDataMenu(struct node **start){
        system("clear");
        this->head = *start;
        cout << "Make a selection : "<<endl;
        cout << "[1] Insert Data at Front."<<endl;
        cout << "[2] Insert Data at End."<<endl;
        cout << "[3] Insert Data at Any Position."<<endl;
        cout << "[4] Search Data."<<endl;
        cout << "[5] Display Node Data"<<endl;
        cout << "[6] Exit."<<endl;
        cin >> this->selection;
        switch(this->selection){
        case 1:
            cout << "How many data values you want to enter ? : ";
            cin >> data;
            for(this->i=1;this->i<=this->data;this->i++){
                this->insertDataFront(&head);
            }
            this->displayNodeData(&head);
            cout << "[1] Back to Insert Menu ?" <<endl;
            cout << "[2] Jump to Delete Menu ?" <<endl;
            cin >> this->selection;
            switch(this->selection){
            case 1:
                    this->insertDataMenu(&head);
            break;
            case 2:
                    this->deleteDataMenu(&head);
            break;
                default:
                    this->insertDataMenu(&head);
                break;
            }
        break;
        case 2:
            cout << "How many data values you want to enter ? : ";
            cin >> data;
            for(this->i=1;this->i<=this->data;this->i++){
                this->insertDataEnd(&head);
            }
            this->displayNodeData(&head);
            cout << "[1] Back to Insert Menu ?" <<endl;
            cout << "[2] Jump to Delete Menu ?" <<endl;
            cin >> this->selection;
            switch(this->selection){
            case 1:
                    this->insertDataMenu(&head);
            break;
            case 2:
                    this->deleteDataMenu(&head);
            break;
                default:
                    this->insertDataMenu(&head);
                break;
            }
        break;
        case 3:
            this->displayNodeData(&head);
            cout << "Enter value at which you want to insert : ";
            cin >> this->selection;
            cout << "Enter Data value : ";
            cin >> this->data;
            this->insertDataAnyPoint(&head,this->data,this->selection);
            this->displayNodeData(&head);
            cout << "[1] Back to Insert Menu ?" <<endl;
            cout << "[2] Jump to Delete Menu ?" <<endl;
            cin >> this->selection;
            switch(this->selection){
            case 1:
                    this->insertDataMenu(&head);
            break;
            case 2:
                    this->deleteDataMenu(&head);
            break;
                default:
                    this->insertDataMenu(&head);
                break;
            }
        break;
        case 4:
                this->displayNodeData(&head);
                cout << "Enter data you want to search : ";
                cin >> this->data;
                this->searchNodeData(&head,data);
                cout << "[1] Back to Insert Menu ?" <<endl;
                cout << "[2] Jump to Delete Menu ?" <<endl;
                cin >> this->selection;
                switch(this->selection){
                case 1:
                        this->insertDataMenu(&head);
                break;
                case 2:
                        this->deleteDataMenu(&head);
                break;
                    default:
                        this->insertDataMenu(&head);
                    break;
                }
        break;
        case 5:
            this->displayNodeData(&head);
            cout << "[1] Back to Insert Menu ?" <<endl;
            cout << "[2] Jump to Delete Menu ?" <<endl;
            cin >> this->selection;
            switch(this->selection){
            case 1:
                    this->insertDataMenu(&head);
            break;
            case 2:
                    this->deleteDataMenu(&head);
            break;
                default:
                    this->insertDataMenu(&head);
                break;
            }
        break;
        case 6:
                return;
        break;
            default:
                this->insertDataMenu(&head);
            break;
        }
    }

    void deleteDataMenu(struct node **start){
        system("clear");
        this->head = *start;
        cout << "Make a selection : "<<endl;
        cout << "[1] Delete Data at Front."<<endl;
        cout << "[2] Delete Data at End."<<endl;
        cout << "[3] Delete Data at Any Position."<<endl;
        cout << "[4] Search Node"<<endl;
        cout << "[5] Display Node Data"<<endl;
        cout << "[6] Exit"<<endl;
        cin >> this->selection;
        switch(this->selection){
        case 1:
            cout << "How many data values you want to delete ? : ";
            cin >> data;
            for(this->i=1;this->i<=this->data;this->i++){
                this->deleteDataFront(&head);
            }
            this->displayNodeData(&head);
            cout << "[1] Back to Delete Menu ?" <<endl;
            cout << "[2] Jump to Insert Menu ?" <<endl;
            cin >> this->selection;
            switch(this->selection){
            case 1:
                     this->deleteDataMenu(&head);
            break;
            case 2:
                    this->insertDataMenu(&head);
            break;
                default:
                    this->insertDataMenu(&head);
                break;
            }
        break;
        case 2:
            cout << "How many data values you want to delete from end ? : ";
            cin >> data;
            for(this->i=1;this->i<=this->data;this->i++){
                this->deleteDataEnd(&head);
            }
            this->displayNodeData(&head);
            cout << "[1] Back to Delete Menu ?" <<endl;
            cout << "[2] Jump to Insert Menu ?" <<endl;
            cin >> this->selection;
            switch(this->selection){
            case 1:
                     this->deleteDataMenu(&head);
            break;
            case 2:
                    this->insertDataMenu(&head);
            break;
                default:
                    this->insertDataMenu(&head);
                break;
            }
        break;
        case 3:
            this->displayNodeData(&head);
            cout << "Enter the position(data of node) to be deleted : ";
            cin >> this->data;
            this->deleteDataAnyPosition(&head,data);
            this->displayNodeData(&head);
            cout << "[1] Back to Delete Menu ?" <<endl;
            cout << "[2] Jump to Insert Menu ?" <<endl;
            cin >> this->selection;
            switch(this->selection){
            case 1:
                     this->deleteDataMenu(&head);
            break;
            case 2:
                    this->insertDataMenu(&head);
            break;
                default:
                    this->insertDataMenu(&head);
                break;
            }
        break;
        case 4:
                this->displayNodeData(&head);
                cout << "Enter data you want to search : ";
                cin >> this->data;
                this->searchNodeData(&head,data);
                cout << "[1] Back to Delete Menu ?" <<endl;
                cout << "[2] Jump to Insert Menu ?" <<endl;
                cin >> this->selection;
                switch(this->selection){
                case 1:
                         this->deleteDataMenu(&head);
                break;
                case 2:
                        this->insertDataMenu(&head);
                break;
                    default:
                        this->insertDataMenu(&head);
                    break;
                }
        break;
        case 5:
            this->displayNodeData(&head);
            cout << "[1] Back to Delete Menu ?" <<endl;
            cout << "[2] Jump to Insert Menu ?" <<endl;
            cin >> this->selection;
            switch(this->selection){
            case 1:
                     this->deleteDataMenu(&head);
            break;
            case 2:
                    this->insertDataMenu(&head);
            break;
                default:
                    this->insertDataMenu(&head);
                break;
            }
        break;
        case 6:
                return;
        break;
            default:
                this->deleteDataMenu(&head);
            break;
        }
    }

}_LinkedListMethods;
