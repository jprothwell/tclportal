/**
* @file liblist.h
* @brief  list Routines
*
* This is a very simple implementation of a linked list.
* <BR>There is not much to say about it... Except that it
* could be a lot improved. Sadly, it would be difficult
* to improve it without breaking the compatibility with
* older version!
*/
#ifndef _H_SML_LIBLIST_INCLUDED_
#define _H_SML_LIBLIST_INCLUDED_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
   /**
   * Structure for referencing a node in a sml_list_t element.
   * @var __sml_node_t
   */
    typedef struct __sml_node_ __sml_node_t;

   /**
   * Structure for referencing a node in a sml_list_t element.
   * @struct __sml_node_
   */
    struct __sml_node_
    {
        void *next;     /**< next __sml_node_t containing element */
        void *element;  /**< element in Current node */
    };
   /**
   * Structure for referencing a list of elements.
   * @var sml_list_t
   */
    typedef struct sml_list sml_list_t;
    /* added by bennewit@cs.tu-berlin.de */
    typedef struct
    {
        __sml_node_t *actual;
        __sml_node_t **prev;
        sml_list_t *li;
        int pos;
    } sml_list_iterator_t;

   /**
   * Structure for referencing a list of elements.
   * @struct sml_list
   */
    struct sml_list
    {
        int nb_elt;         /**< Number of element in the list */
        __sml_node_t *node; /**< Next node containing element  */

    };
   /**
   * Initialise a sml_list_t element.
   * NOTE: this element will be allocated in sml_list_new,
   * then you must free the *ll by sml_list_free/sml_list_special_free/sml_list_ofchar_free
   * @param li The element to initialise.
   */
    sml_list_t *sml_list_new(void);
    void sml_list_free(sml_list_t *li);
   /**
   * Free a list of element.
   * Each element will be free with the method given as the second parameter.
   * @param li The element to work on.
   * @param free_func The method that is able to release one element of the list.
   */
    void sml_list_special_free(sml_list_t *li, void *(*free_func) (void *));
   /**
   * Free a list of element where elements are pointer to 'char'.
   * @param li The element to work on.
   */
    void sml_list_ofchar_free(sml_list_t *li);
   /**
   * Get the size of a list of element.
   * @param li The element to work on.
   */
    int sml_list_size(const sml_list_t *li);
   /**
   * Check if the end of list is detected .
   * @param li The element to work on.
   * @param pos The index of the possible element.
   */
    int sml_list_eol(const sml_list_t *li, int pos);
   /**
   * Add an element in a list.
   * @param li The element to work on.
   * @param element The pointer on the element to add.
   * @param pos the index of the element to add. (or -1 to append the element at the end)
   */
    int sml_list_add(sml_list_t *li, void *element, int pos);
   /**
   * Get an element from a list.
   * @param li The element to work on.
   * @param pos the index of the element to get.
   */
    void *sml_list_get(const sml_list_t *li, int pos);
   /**
   * Remove an element from a list.
   * @param li The element to work on.
   * @param pos the index of the element to remove.
   */
    int sml_list_remove(sml_list_t *li, int pos);

   /*Vogins_20100625_start*/
    int sml_list_insert_to_position(sml_list_t *li, int pos_begin, int pos_end);
   /*Vogins_20100625_end*/

    /* added by bennewit@cs.tu-berlin.de */
#define sml_list_iterator_has_elem( it ) ( 0 != (it).actual && (it).pos < (it).li->nb_elt )
    /* added by bennewit@cs.tu-berlin.de */
    void *sml_list_get_first(sml_list_t *li, sml_list_iterator_t *it);
    /* added by bennewit@cs.tu-berlin.de */
    void *sml_list_get_next(sml_list_iterator_t *it);
    /* added by bennewit@cs.tu-berlin.de */
    void *sml_list_iterator_remove(sml_list_iterator_t *it);

#ifdef __cplusplus
}
#endif 

#endif /* _H_SML_LIBLIST_INCLUDED_ */ 

