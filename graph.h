/*
 * =====================================================================================
 *
 *       Filename:  graph.h
 *
 *    Description:  This file contains the definition of all structures required to create a NetworkGraph
 *
 *        Version:  1.0
 *        Created:  Wednesday 17 Febrarury 2020 02:17:17  EST
 *       Revision:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Er. Naveen sai Muthyala, muthyalanaveensai@gmail.com

 *        This program is free software: you can redistribute it and/or modify
 *        it under the terms of the GNU General Public License as published by  
 *        the Free Software Foundation, version 3.
 *
 *        This program is distributed in the hope that it will be useful, but 
 *        WITHOUT ANY WARRANTY; without even the implied warranty of 
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 *        General Public License for more details.
 *
 *        You should have received a copy of the GNU General Public License 
 *        along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * =====================================================================================
 */


#ifndef __GRAPH__
#define __GRAPH__
#include "gluethread/glthread.h"
#include <assert.h>
#define INTERFACE_NAME_SIZE 17
#define NODE_NAME_SIZE 17
#define MAX_INTERFACES_ON_NODE 10

/* Forward declarations to avoid recursive dependency of structures interface_t with link and node data structures */

typedef struct node_ node_t;
typedef struct link_ link_t;



typedef struct interface_ {
    char interface_name [17];
    struct node_  *att_node;
    struct link_ *link;

}interface_t;

 struct link_{
    interface_t intf1;
    interface_t intf2;
    unsigned int cost;

};

 struct node_{
    char node_name[ NODE_NAME_SIZE];
    interface_t *intf[MAX_INTERFACES_ON_NODE];
    glthread_t graph_glue;
};

typedef struct graph_{
 char Topology_name[37];  /* To store Topology name of the graph */
 glthread_t nodelist;       /* To the glue thread double link list containing all nodes i.e routers */

}graph_t;

/* Helper Functions */


static inline node_t * get_nbr_node(interface_t *interface)
{   /* The function  returns the pointer to the attched  node 
        which is connected to the interface passed as an argument.

    */

    assert(interface->att_node);
    assert(interface->link);                /* Doubt */
    
    link_t *link = interface->link;
    if(&link->intf1 == interface)
        return link->intf2.att_node;
    else
        return link->intf1.att_node;
}


static inline int get_node_intf_available_slot(node_t *node)
{
    /*  Assuming that array would contain pointers to interfaces in continuous fashion, that is,  array do not have holes, 
        This function returns an empty available slot (the index of the array) into which interface address could be stored. 
        and Returns -1 if no empty slot is available.
    */

    for(int index=0; index < MAX_INTERFACES_ON_NODE; index++){
        if( node->intf[index] == 0)
        {
            return index;
        }

    }
    return -1;
}





#endif
