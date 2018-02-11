#ifndef STRUCTURE_TYPES_LIBRARY_H
#define STRUCTURE_TYPES_LIBRARY_H

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
    struct _Single_List *adress ;
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

   Single_List_Node_t *node = ( Single_List_Node_t * )malloc( sizeof( Single_List_Node_t ) ) ;

    /*
     * передаем значение в список
     */

    node->value = data ;

    /*
     * проверяем список на пустоту,если не пуст то прписываем с конца
     * если пуст делаем его первым элементом
     */

    if ( St->tail != NULL ) St->tail->adress = node ;
    else St->head = node ;

    /*
     * двигаем конец списка на новый элемент
     * инкрементируем длинну списка
     */

    St->tail = node ;
    St->size ++ ;


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
















}













































#endif