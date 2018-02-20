#ifndef STRUCTURE_TYPES_LIBRARY_H
#define STRUCTURE_TYPES_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>

void hello(void);

/*
 * St - будет обозначать массив
 * все новые типы данных обозначаются через _t в конце
 */


  /*
   * Структура элементов односвязного спписка
   * обЪявляем новый тип , что б не писсать структуру каждый раз
   */

typedef struct _Single_List_Node
{
    int value = 0 ;
    struct _Single_List_Node *adress ;
} Single_List_Node_t ;


/*
 * Создаем  структуру односвзяного списка
 * Храним разсер списка
 * Указатель на начало
 * указатель на конец
 */

typedef struct _Single_List
{
    /*
     * размер списка
     */

    int size ;

    /*
     * начало списка
     */

    Single_List_Node_t *head ;

    /*
     * конец списка
     */

    Single_List_Node_t *tail ;

} Single_List_t ;


/*
 * Функция инициализации массива
 * возвращает указатель на массив
 */

Single_List_t * create_Single_List ( void )
{
    /*
     * выделяем память
     */

    Single_List_t *St = ( Single_List_t *  )malloc(sizeof( Single_List_t ) ) ;

    /*
     * инициализируем элемекнты массива
     */

    St->size = 0 ;
    St->head = NULL ;
    St->tail = St->head ;

    /*
     * возвращаем указатель
     */

    return St ;
}

/*
 * добовлдяем функциию для добовления элемента в начало односвязного списка
 */

void Single_List_push( Single_List_t *St , int data )
{
    /*
     * выделяем памать под новый элемент списка
     */

    Single_List_Node_t *node = ( Single_List_Node_t * )malloc(sizeof( Single_List_Node_t ) ) ;

    /*
     * передаем в элемент какое-то значение
     * передаем в адрес элемента адрес начла списка
     */

    node->value = data ;
    node->adress = St->head ;

    /*
     * Двигаем начало списка на место нового элемента
     * увеличиваем размер на 1
     */

    St->head = node ;
    St->size ++ ;

}

/*
 * добовляем функцию извлечения элемента из начала списка
 */

int * Single_List_pop ( Single_List_t *St )
{
    /*
     * проверяем размер списка
     * если пуст возвращаем нулевой указатель
     */

    if ( St->size == 0 ) return NULL ;

    /*
     * создаем новый элемент списка с адресом начала
     */

    Single_List_Node_t *node = St->head ;

     /*
      * извлекаем значение элемента по этому адресу
      */

    int * value = node->value ;

    /*
     * уменьшаем размер списка
     * двигаем начало списка на адрес элемента
     */

    St->size -- ;
    St->head = node->adress ;

    /*
     * освобождаем место занимаемое извлекаемым элементом
     */

    free( node ) ;

    /*
     * Проверяем список на пустоту
     * если список пустой обнуляем значение конца и начала
     */

    if ( St->size == 0)
    {
        St->head = NULL ;
        St->tail = Null ;
    }

    /*
     * Возвращаем значение извлеченного элемента
     */

    return *value ;
}

/*
 * добовляем функцию добовления элемента в конец списка
 */

void Single_List_push_back ( Single_List_t *St , int data )
{
    /*
     * выделяем память под новый элемент
     */

    Single_List_Node_t *node = (Single_List_Node_t *) malloc(sizeof(Single_List_Node_t));

    /*
     * передаем значение в список
     */

    node->value = data;

    /*
     * проверяем список на пустоту,если не пуст то прписываем с конца
     * если пуст делаем его первым элементом
     */

    if (St->tail != NULL) St->tail->adress = node;
    else St->head = node;

    /*
     * двигаем конец списка на новый элемент
     * инкрементируем длинну списка
     */

    St->tail = node;
    St->size++;
}

    /*
     * структура элемента двусвязного списка
     * в каждои узле храним
     * значение
     * адрес следующего элемента
     * адрес предыдущего элемента
     */
typedef struct _Double_List_Node
    {
        int value ;
        struct _Double_List_Node *next_adress ;
        struct _Double_List_Node *prev_adress ;
    } Double_List_Node_t ;

    /*
     * добавляем структуру самого двусвязного списка
     * храним:
     * размер
     * адрес первго элемента
     * адрес последнего элемента
     */

typedef struct _Double_List
    {
        int size ;
        Double_List_Node_t *head ;
        Double_List_Node_t *tail ;
    } Double_List_t ;


    /*
     * функция создания двусвязного списка
     */

Double_List_t* Create_Double_List()
     {

         /*
          * выделяем память под список
          */

         Double_List_t *St = ( Double_List_t* )malloc( sizeof( Double_List_t ) ) ;

         /*
          * говорим списку, что он пустой
          * размер равен нулю
          * адрес начала равен адресу конца
          * адреса равны нулевому указателю
          */

         St->size = 0 ;
         St->head = St->tail = NULL ;

         /*
          * Возвращаем адрес массива
          */

         return St ;
     }

     /*
      * функция добовления элемента в начало
      */

void Double_List_pushFront ( Double_List_t *St , int data )
     {
         /*
          * выделяем память под новый элемент
          */

         Double_List_Node_t *node = ( Double_List_Node_t* )malloc( sizeof( Double_List_Node_t ) ) ;

         /*
          * задаем значение элемента
          * адрес следующего это адрес начала списка
          * адрес предыдущего это нулевой указатель
          */

         node->value = data ;
         node->next_adress = St->head ;
         node->prev_adress = NULL ;

         /*
          * добовляем адрес нового элемента предыдущему головномуу элементу если он был
          */

         if ( St->head ) St->head->prev_adress = node ;

         /*
          * если это единтсвенный элемент списка, то адрес конца должен указывать на этот элемент
          */

         if ( St->tail == NULL ) St->tail = node ;

         /*
          * двигаем указатель головы на новый элемент
          * инкриментируем размер списка
          */

         St->head = node ;
         St->size ++ ;

     }


/*
 * функция извлечения из начала двусвязного списка
 */

int* Double_List_popFront( Double_List_t *St )
{
    /*
     * создаем указатель для работы с элементом списка
     */

    Double_List_Node_t *node ;

    /*
     * создаем указатель для возвращения значения извлекаемого элемента
     */

    int *value ;

    /*
     * берем первый элемент списка
     */

    node = St->head ;

    /*
     * двигаем начало списка на одни элемент
     */

    St->head = St->head->next_adress ;

    /*
     * если список не пустой, то нулим адрес предыдущего элемента
     * у головного элемента списка
     */

    if ( St->head ) St->head->prev_adress = NULL ;

    /*
     * если адрес извлекаемого элемента совпадает с адресом
     * конца списка обнуляем адрес конца списка
     */

    if ( node = St->tail ) St->tail = NULL ;

    /*
     * переносим значение извлекаемого элемента в возвращаемую ячейку
     */

    value = node->value ;

    /*
     * освобождаем память выделенную под извлекаемы элемент
     */

    free( node ) ;

    /*
     * дикрементируем размер списка
     * возвращаем значение элемента
     */

    St->size -- ;
    return value ;

}


/*
 * функция вствки в конец списка
 */

void Double_List_push_back ( Double_List_t *St , int data )
{
    /*
     * выделяем память под новый элемент
     */

    Double_List_Node_t *node = ( Double_List_Node_t * )malloc( sizeof( Double_List_Node_t ) ) ;

    /*
     * заполняем значение элемента списка
     * элемент в конце поэтому следующего элемента нет
     * предыдущий элемент это конец списка
     */

    node->value = data ;
    node->next_adress = NULL ;
    node->prev_adress = St->tail ;

    /*
     * двигаем конец списка
     */

    if ( St->tail ) St->tail->next_adress = node ;

    /*
     * провепряем список на пустоту
     * если пуст, то начало списка новый элемент
     */

    if ( St->head == NULL ) St->head = node ;

    /*
     * инкрементируем размер списка
     */

    St->size ++ ;
}

/*
 * добовляем функцию для извлечения элемента из конца двусвязного списка
 */

int *Double_List_pop_back ( Double_List_t *St )
{
    /*
     * создаем узел для извлечения данных
     */

    Double_List_Node_t *node ;

    /*
     * создаем указатель для возврата извлекаемого значения
     */

    int *value ;

    /*
     * получаем последний элемент списка
     */

    node = St->tail ;

    /*
     * двигаем конец списка на один элемент
     */

    St->tail = St->tail->prev_adress ;

    /*
     * проверяем список на пустоту
     * если не пуст,то последний элемент не должен ни на что указывать
     */

    if ( St->tail ) St->tail->next_adress = NULL ;

    /*
     * если извлекаемый элемент - первый элемент списка
     * то список пуст
     */

    if ( node == St->head ) St->head = NULL ;

    /*
     * передаем значение извлекаемого элемента возвращаемому указателю
     */

    value = node->value ;

    /*
     * освобождаем место занимаемое извлекаемым эдементом
     */

    free( node ) ;

    /*
     * дикрементируем разсер списка
     * возвразаем указатель на значение элемента
     */

    St->size -- ;
    return value ;
}

/*
 * получение n-го элемента двусвязного списка
 */

Double_List_Node_t * Double_List_get_nth_element( Double_List_t *St , int index )
{
    /*
     * берем первый элемент списка
     */

    Double_List_Node_t *node = St->head ;

    int i = 0 ;

    /*
     * двигаемся по списку до index элемента
     */

    while ( node && i < index )
    {
        node = node->next_adress ;
        i ++ ;
    }

    /*
     * возвращаем необходимый элемент
     */

    return node ;

    
}

/*
 * функция добовления элемента на n-ое место в двусвязном списке
 */

void Double_List_push_nth ( Double_List_t *St , int index , int *data )
{
    /*
     * создаем новый элемент
     */

    Double_List_Node_t *elm ;

    /*
     * берем элемент после которого должен стоять новый элемент
     */

    Double_List_Node_t *prev ;
    prev = Double_List_get_nth_element( St , index ) ;

    /*
     * выделяем память под новый элемент
     */

    elm = ( Double_List_Node_t * )malloc( sizeof( Double_List_Node_t ) ) ;

    /*
     * передаем новому элементу значение
     */

    elm->value = data ;

    /*
     * вставляем новый элемент в наш список
     */

    elm->prev_adress = prev ;
    elm->next_adress = prev->next_adress ;

    /*
     * если новый эдемент не последний , то добовляем ссылку на него
     * следуюзему эдементу
     */

    if ( elm->next_adress ) elm->next_adress->prev_adress = elm ;

    /*
     * предыдущий элемент так же должен ссылаться на только что добавленный элемент
     */

    prev->next_adress = elm ;

    /*
     * проверям есть ли предыдущий эдемент
     * если нет то новый элемент начало списка
     */

    if ( !elm->prev_adress ) St->head = elm ;

    /*
     * проверяем есть ли элемент после
     * если нет то новый элемент конец списка
     */

    if ( !elm->next_adress ) St->tail = elm ;

    /*
     * инкрементируем размер списка
     */

    St->size ++ ;
}

/*
 * функция извлечения n-го элемента из списка
 */

int *Double_List_pop_nth ( Double_List_t *St , int index )
{
     /*
      * создаем указатель на нужный элемент
      * достаем нужный элемент
      */

    Double_List_Node_t *node = Double_List_get_nth_element( St , index ) ;

    /*
     * создаем указатель на значение которое будем возвращать
     */

    int *value ;

    /*
     * удаляем элемент из списка
     */

    if ( node->prev_adress ) node->prev_adress->next_adress = node->next_adress ;

    if ( node->next_adress ) node->next_adress->prev_adress = node->prev_adress ;

    /*
     * запоминаем значение элемента по возвращаемому адресу
     */

    value = node->value ;

    /*
     * проверяем был ли элемент первым
     */

    if ( !node->prev_adress ) St->head = node->next_adress ;

    /*
     * проверяем был ли элемент последним
     */
    if ( !node->next_adress ) St->tail = node->prev_adress ;

    /*
     * освобождаем память занимаему этим эдементом
     */
    free( node ) ;

    /*
     * дикрменетируем размер списка
     * возвращаем значение извлекаемого элемента
     */

    St->size -- ;
    return value ;
}

/*
 *структура листа двоичного дерева
 */

typedef struct _Tree_node
{
    int value ;
    struct  _Tree_node *right ;
    struct  _Tree_node *left ;
} Tree_node_t ;


/*
 * структура определяющая двоичное дерево
 */

typedef struct _Tree
{
    Tree_node_t * root ;
    int size ;
} Tree_t ;

/*
 *функция создания дерева
 */

Tree_t * Creat_tree ( void )
{

    /*
     *выделяем память под новое дерево
     */

    Tree_t *tree = ( Tree_t * )malloc( sizeof( Tree_t ) ) ;

    /*
     * изначальное дерево пустое
     * корня нет
     * размер 0
     */

    tree->root = NULL ;
    tree->size = 0 ;

    /*
     * возвращаем указатель на новое дерево
     */

    return tree ;
}

/*
 * функция поиска узла в дереве
 */

int Tree_search ( Tree_t *tree , int data )
{
    /*
     * берем корень дерева
     */

    Tree_node_t *node ;
    node = tree->root ;

    /*
     * проходим все дерево
     */

    while ( TRUE )
    {
        /*
         * если узел пуст, то дерео проверенно
         * возвращаем ноль , тк в дереае нет необходимого значения
         */

        if ( node == NULL ) return 0 ;

        /*
         * если значение узла совпадает с искуемым значением возврашаем еденицу
         */

        else if ( data == node->value ) return 0 ;

        /*
         * если искомое значение больше значение узла то идем в правый лист
         */

        else if ( data > node->value ) node = node->right ;

        /*
         * в любом ином случае идем в левый лист
         */

        else node = node->left ;
    }
}

/*
 *функция добовления листа в дереаво
 */

int Tree_push ( Tree_t *tree , int data )
{

    /*
     * создаем указатель на новый узел и указаталь на узел для поиска
     */

    Tree_node_t* Snode , **new_node ;

    /*
     * присваиваем им значение корня дерева и его адрес соответственно
     */

    Snode = tree->root ;
    new_node = &tree->root ;

    /*
     * проходим све дерево
     */

    while ( TRUE )
    {
        /*
         * проверяем дерево на пустоту
         * если пустое то корень новый элемент
         */

        if ( Snode == NULL )
        {
            Snode = *new_node = malloc( sizeof * Snode ) ;
            if ( Snode != NULL )
                                  {
                                      /*
                                       * присваиваем поисковой ноде значение
                                       * инкрементируем размер дерева
                                       */

                                      Snode->value = data ;
                                      Snode->left = Snode->right = NULL ;
                                      tree->size ++ ;
                                  }
                /*
                 * если такой узел уже есть возврааем 2
                 */

            else if ( Snode->value == data ) return 2 ;

            /*
             * если добовляемое значение больше значения поискового узла
             * идем направо
             * в ином случае на лево
             */

            else if ( data > Snode->value )
            {
                new_node = &Snode->right ;
                Snode = Snode->right ;
            }
            else
            {
                new_node = &Snode->left ;
                Snode = Snode->left ;
            }
        }

    }
}


/*
 * функция удаления узла из дерева
 */

int Tree_delete ( Tree_t * tree , int ** data )
{

    Tree_node_t ** Qnode , *Znode ;

    Qnode = &tree->root ;
    Znode = tree->root ;

    /*
     * ищем удаляемый элемент
     */

    for(;;)
    {
        /*
         * провеояем на ошибку памяти
         */

        if ( Znode == NULL ) return -1 ;

            /*
             * если равно то мы нашли нужный элемент
             */

        else if ( data == ( int **  )Znode->value ) break ;

            /*
             * если значение в узле больше искомово то идем на право
             */

        else if ( data >  ( int ** )Znode->value )
        {
            Qnode = &Znode->right ;
            Znode = Znode->right ;
        }

        /*
         * во всех оставшихся случаях идем на лево
         */

        else
        {
            Qnode = &Znode->left ;
            Znode = Znode->left ;
        }
    }

    /*
     * удаляем необходимы элемент
     */

    if ( Znode->right == NULL )*Qnode = Znode->left ;
    else
    {
        Tree_node_t *Ynode = Znode->right ;
        if ( Ynode->left == NULL )
        {
            Ynode->left = Znode->left ;
            *Qnode-Ynode ;
        }
        else
        {
            Tree_node_t *Xnode = Ynode->left ;
            while ( Xnode->left != NULL )
            {
                Ynode = Xnode ;
                Xnode = Ynode->left ;
            }
            Ynode->left = Xnode->right ;
            Xnode->left = Znode->left ;
            Xnode->right = Znode->right ;
            *Qnode = Xnode ;
        }
    }

    /*
     * уменьшаем размер дерева
     * освобождаем место занимаемое удаляемым элементом
     * возвращаем еденицу как отсутствие ошибки
     */

    tree->size -- ;
    free ( Znode ) ;
    return 1 ;
}

void Tree_print(Tree_node_t *root , const char *dir , int level )
{
    if ( root )
    {
        printf("level %d %s =%d\n", level, dir, root->value);
        Tree_print(root->right, "right", level + 1);
        Tree_print(root->left, "left", level + 1);
    }
}















































#endif