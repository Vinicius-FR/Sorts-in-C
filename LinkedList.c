#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura do nó da lista
typedef struct node {
    int data;
    struct node* next;
} Node;

// Estrutura da lista
typedef struct list {
    Node* head;
    int length;
} List;

// Função para criar um novo nó
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Função para inserir um nó no início da lista
void insert_at_beginning(List *list, int data) {
    Node* new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
    list->length++;
}

// Função para inserir um nó no fim da lista
void insert_at_ending(List *list, int data) {
    Node* aux = list->head;
    Node* new_node = create_node(data);
    while (aux->next != NULL) {
        aux = aux->next;
    }
    new_node->data = data;
    new_node->next = NULL;
    aux->next = new_node;
    list->length++;
}

// Função para inserir nó
void insert(List *list, int data) {
    Node* aux = list->head;
    if (aux == NULL) {
        insert_at_beginning(list, data);
    } else {
        insert_at_ending(list, data);
    }
}

// Função para inserir nó em uma posição
void insert_at_position(List *list, int data, int position) {
    Node* aux = list->head;
    Node* new_node = create_node(data);

    if (position >= list->length) {
        printf("Position Out of Range! ");
    } else {
        for (int i = 0; i < position; i++) {
            aux = aux->next;
        }
        new_node->next = aux->next;
        aux->next = new_node;
        list->length++;
        printf("\n%i inserted at position %i... ", data, position);
    }
}

// Função para procurar elemento na lista
int search(List list, int value) {
    Node* aux;
    aux = list.head;
    int position = 0, found = 0;
    if (aux == NULL){
        printf("Empty List!");
        return NULL;
    } else {
        while (aux != NULL){
            if (aux->data == value) {
              printf("\nValue %d found at position %d. ", value, position);
              found = 1;
              return position;
              break;
            } else {
                aux = aux->next;
                position++;
            }
        }
    }
    if (found == 0) {
        printf("\nValue not found! ");
        return NULL;
    }
    
}

void removeNode(List *list, int data) {
    Node* aux, *ant;
    aux = ant = list->head;
    if (aux == NULL) {
        printf("\nEmpty List! ");
    } else {
        while (aux != NULL) {
            if (data == aux->data) {
                if (aux == list->head){
                    list->head = aux->next;
                    free(aux);
                    break;
                } else {
                    ant->next = aux->next;
                    free(aux);
                    break;
                }
            } else {
                ant = aux;
                aux = aux->next;
            }
        }
        list->length--;
    }
}

// Função para imprimir a lista
void print_list(List list) {
    Node* temp = list.head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função principal para testar a lista
int main() {
    List list;
    list.head = NULL; // lista vazia
    list.length = 0;

    // Testando
    for (int i = 0; i < 10; i++) {
        insert(&list, i);
    }

    // insert(&list, 5);
    // insert(&list, 15);
    // insert(&list, 20);

    // insert_at_position(&list, 10, 1);

    // removeNode(&list, 15);

    // printf("Linked List: ");
    // print_list(list);

    // int position = search(list, 20);

    while (true) {
        printf("Choose an option:\n");
        printf("1. Insert Value\n");
        printf("2. Insert Value at Position\n");
        printf("3. Remove Value\n");
        printf("4. Search Value\n");
        printf("5. Empty List\n");
        printf("6. Print List\n");
        printf("7. Exit\n");

        int option;
        printf("\nOption: ");
        scanf("%i", &option);
        int value;
        int position;

        if (option == 1) {
            printf("\nChoose value to insert: ");
            scanf("%i", &value);
            insert(&list, value);
            printf("\n%i inserted... ", value);
        } else if (option == 2) {
            printf("\nChoose value to insert: ");
            scanf("%i", &value);
            printf("\nChoose position: ");
            scanf("%i", &position);
            insert_at_position(&list, value, position);
        } else if (option == 3) {
            printf("\nChoose value to remove: ");
            scanf("%i", &value);
            removeNode(&list, value);
            printf("\n%i removed... ", value);
        } else if (option == 4) {
            printf("\nChoose value to search: ");
            scanf("%i", &value);
            position = search(list, value);
        } else if (option == 5) {
            Node* aux = list.head;
            int size = list.length;
            for (int i = 0; i < size; i++) {
                removeNode(&list, aux->data);
                aux = list.head;
            }
            printf("\nList empty... ");
        } else if (option == 6) {
            printf("Linked List: ");
            print_list(list);
        } else {
            break;
        }
    }
    return 0;
}