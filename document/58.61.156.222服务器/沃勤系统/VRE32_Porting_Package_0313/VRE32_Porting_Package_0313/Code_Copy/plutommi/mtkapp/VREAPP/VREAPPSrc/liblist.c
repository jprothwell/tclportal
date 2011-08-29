#ifdef __VRE30_AM__

#include "AMUtil.h"
#include "liblist.h"
#include <string.h>


/*****************************************************************************
 * FUNCTION
 *  sml_list_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
sml_list_t *sml_list_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sml_list_t *li;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    li = (sml_list_t*) mmi_am_malloc(sizeof(sml_list_t));
    if (!li)
    {
        return 0;
    }

    memset(li, 0, sizeof(sml_list_t));
    return li;
}


/*****************************************************************************
 * FUNCTION
 *  sml_list_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  li      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void sml_list_free(sml_list_t *li)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int pos = 0;
    void *element;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (li == NULL)
        return;
    while (!sml_list_eol(li, pos))
    {
        element = (void*)sml_list_get(li, pos);
        sml_list_remove(li, pos);
    }
    mmi_am_free(li);
}


/*****************************************************************************
 * FUNCTION
 *  sml_list_special_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  li              [IN]        
 *  free_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void sml_list_special_free(sml_list_t *li, void *(*free_func) (void *))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int pos = 0;
    void *element;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (li == NULL)
        return;
    while (!sml_list_eol(li, pos))
    {
        element = (void*)sml_list_get(li, pos);
        sml_list_remove(li, pos);
        if (free_func != NULL)
            free_func(element);
    }
    mmi_am_free(li);
}


/*****************************************************************************
 * FUNCTION
 *  sml_list_ofchar_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  li      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void sml_list_ofchar_free(sml_list_t *li)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int pos = 0;
    char *chain;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (li == NULL)
        return;
    while (!sml_list_eol(li, pos))
    {
        chain = (char*)sml_list_get(li, pos);
        sml_list_remove(li, pos);
        mmi_am_free(chain);
    }
    mmi_am_free(li);
}


/*****************************************************************************
 * FUNCTION
 *  sml_list_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  li      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int sml_list_size(const sml_list_t *li)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * Robin Nayathodan <roooot@softhome.net> 
     * N.K Electronics INDIA
     * 
     * NULL Checks  
     */

    if (li != NULL)
        return li->nb_elt;
    else
        return -1;
}


/*****************************************************************************
 * FUNCTION
 *  sml_list_eol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  li      [IN]        
 *  i       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int sml_list_eol(const sml_list_t *li, int i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (li == NULL)
        return -1;
    if (i < li->nb_elt)
        return 0;   /* not end of list */
    return 1;       /* end of list */
}

/* index starts from 0; */


/*****************************************************************************
 * FUNCTION
 *  sml_list_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  li      [IN]        
 *  el      [IN]        
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int sml_list_add(sml_list_t *li, void *el, int pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    __sml_node_t *ntmp;
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (li == NULL)
        return -1;

    if (li->nb_elt == 0)
    {
        li->node = (__sml_node_t*) mmi_am_malloc(sizeof(__sml_node_t));
        if (li->node == NULL)
            return -1;
        li->node->element = el;
        li->node->next = NULL;
        li->nb_elt++;
        return li->nb_elt;
    }

    if (pos == -1 || pos >= li->nb_elt)
    {   /* insert at the end  */
        pos = li->nb_elt;
    }

    ntmp = li->node;    /* exist because nb_elt>0  */

    if (pos == 0)   /* pos = 0 insert before first elt  */
    {
        li->node = (__sml_node_t*) mmi_am_malloc(sizeof(__sml_node_t));
        if (li->node == NULL)
        {
            /* leave the list unchanged */
            li->node = ntmp;
            return -1;
        }
        li->node->element = el;
        li->node->next = ntmp;
        li->nb_elt++;
        return li->nb_elt;
    }

    while (pos > i + 1)
    {
        i++;
        /* when pos>i next node exist  */
        ntmp = (__sml_node_t*) ntmp->next;
    }

    /* if pos==nb_elt next node does not exist  */
    if (pos == li->nb_elt)
    {
        ntmp->next = (__sml_node_t*) mmi_am_malloc(sizeof(__sml_node_t));
        if (ntmp->next == NULL)
            return -1;  /* leave the list unchanged */
        ntmp = (__sml_node_t*) ntmp->next;
        ntmp->element = el;
        ntmp->next = NULL;
        li->nb_elt++;
        return li->nb_elt;
    }

    /* here pos==i so next node is where we want to insert new node */
    {
        __sml_node_t *nextnode = (__sml_node_t*) ntmp->next;

        ntmp->next = (__sml_node_t*) mmi_am_malloc(sizeof(__sml_node_t));
        if (ntmp->next == NULL)
        {
            /* leave the list unchanged */
            ntmp->next = nextnode;
            return -1;
        }
        ntmp = (__sml_node_t*) ntmp->next;
        ntmp->element = el;
        ntmp->next = nextnode;
        li->nb_elt++;
    }
    return li->nb_elt;
}

/* index starts from 0 */


/*****************************************************************************
 * FUNCTION
 *  sml_list_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  li      [IN]        
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *sml_list_get(const sml_list_t *li, int pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    __sml_node_t *ntmp;
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (li == NULL)
        return NULL;

    if (pos < 0 || pos >= li->nb_elt)
        /* element does not exist */
        return NULL;

    ntmp = li->node;    /* exist because nb_elt>0 */

    while (pos > i)
    {
        i++;
        ntmp = (__sml_node_t*) ntmp->next;
    }
    return ntmp->element;
}

/* added by bennewit@cs.tu-berlin.de */


/*****************************************************************************
 * FUNCTION
 *  sml_list_get_first
 * DESCRIPTION
 *  
 * PARAMETERS
 *  li              [IN]        
 *  iterator        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *sml_list_get_first(sml_list_t *li, sml_list_iterator_t *iterator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 >= li->nb_elt)
    {
        iterator->actual = 0;
        return 0;
    }

    iterator->actual = li->node;
    iterator->prev = &li->node;
    iterator->li = li;
    iterator->pos = 0;

    return li->node->element;
}

/* added by bennewit@cs.tu-berlin.de */


/*****************************************************************************
 * FUNCTION
 *  sml_list_get_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  iterator        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *sml_list_get_next(sml_list_iterator_t *iterator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iterator->prev = (__sml_node_t **) & (iterator->actual->next);
    iterator->actual = iterator->actual->next;
    ++(iterator->pos);

    if (sml_list_iterator_has_elem(*iterator))
    {
        return iterator->actual->element;
    }

    iterator->actual = 0;
    return 0;
}

/* added by bennewit@cs.tu-berlin.de */


/*****************************************************************************
 * FUNCTION
 *  sml_list_iterator_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  iterator        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *sml_list_iterator_remove(sml_list_iterator_t *iterator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sml_list_iterator_has_elem(*iterator))
    {
        --(iterator->li->nb_elt);

        *(iterator->prev) = iterator->actual->next;

        mmi_am_free(iterator->actual);
        iterator->actual = *(iterator->prev);
    }

    if (sml_list_iterator_has_elem(*iterator))
    {
        return iterator->actual->element;
    }

    return 0;
}

/* return -1 if failed */


/*****************************************************************************
 * FUNCTION
 *  sml_list_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  li      [IN]        
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int sml_list_remove(sml_list_t *li, int pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    __sml_node_t *ntmp;
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (li == NULL)
        return -1;

    if (pos < 0 || pos >= li->nb_elt)
        /* element does not exist */
        return -1;

    ntmp = li->node;    /* exist because nb_elt>0 */

    if ((pos == 0))
    {   /* special case  */
        li->node = (__sml_node_t*) ntmp->next;
        li->nb_elt--;
        mmi_am_free(ntmp);
        return li->nb_elt;
    }

    while (pos > i + 1)
    {
        i++;
        ntmp = (__sml_node_t*) ntmp->next;
    }

    /* insert new node */
    {
        __sml_node_t *remnode;

        remnode = (__sml_node_t*) ntmp->next;
        ntmp->next = ((__sml_node_t*) ntmp->next)->next;
        mmi_am_free(remnode);
        li->nb_elt--;
    }
    return li->nb_elt;
}


/*Vogins_20100625_start*/
/*****************************************************************************
 * FUNCTION
 *  sml_list_insert_to_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  li      [IN]        
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int sml_list_insert_to_position(sml_list_t *li, int pos_begin, int pos_end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    __sml_node_t *ntmp_begin;
	__sml_node_t *ntmp_end;
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (li == NULL)
        return -1;

    if (pos_begin < 0 || pos_begin >= li->nb_elt ||pos_end < 0 || pos_end > li->nb_elt )
        /* element does not exist */
        return -1;

	if(pos_end - pos_begin == 1 ||pos_end == pos_begin)
		return -1;

    ntmp_begin = li->node;    /* exist because nb_elt>0 */
   ntmp_end = li->node;
    if (pos_begin == 0 && pos_end == 0)
    {   /* special case  */
        return li->nb_elt;
    }
while (pos_begin > i + 1)
    {
        i++;
        ntmp_begin = (__sml_node_t*) ntmp_begin->next;
    }

if(pos_end ==0)
{

    /* insert to first */
	if(pos_begin == li->nb_elt -1)
	{
		  __sml_node_t *ntemp;

        	ntemp = li->node;
		li->node =  (__sml_node_t*)ntmp_begin->next;	
  	      ntmp_begin->next = NULL;
	 	li->node->next = ntemp;
		return li->nb_elt;
	}
    {
        __sml_node_t *ntemp;

        ntemp = li->node;
	 li->node =  (__sml_node_t*)ntmp_begin->next;	
        ntmp_begin->next = ((__sml_node_t*) ntmp_begin->next)->next;
	 li->node->next = ntemp;
	 return li->nb_elt;
    }
}
	i = 0;
	while (pos_end > i + 1)
    {
        i++;
        ntmp_end = (__sml_node_t*) ntmp_end->next;
    }
	if(pos_begin == 0)
	{
		if(pos_end > 0 && pos_end < li->nb_elt)
		{
			li->node = (__sml_node_t*)ntmp_begin->next;
			ntmp_begin->next = (__sml_node_t*) ntmp_end->next;
			ntmp_end->next = (__sml_node_t*)ntmp_begin;
		}
		else if (pos_end == li->nb_elt)
		{
			li->node = (__sml_node_t*)ntmp_begin->next;
			ntmp_begin->next = NULL;
			ntmp_end->next = (__sml_node_t*)ntmp_begin;
		}
	}
	else
	{
		__sml_node_t *ntemp;
		ntemp = (__sml_node_t*)ntmp_begin->next;
		ntmp_begin->next = ((__sml_node_t*) ntmp_begin->next)->next;
		if(pos_end == li->nb_elt)
			ntemp->next = NULL;
		else
			ntemp->next = ntmp_end->next;
		ntmp_end->next = ntemp;
	}
	return li->nb_elt;    
}
/*Vogins_20100625_end*/
#endif /* __VRE30_AM__ */ 

