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

#define INTERFACE_NAME_SIZE 17
#define NODE_NAME_SIZE 17
#define MAX_INTERFACES_ON_NODE 4

/* Forward declarations to avoid recursive dependency of structures interface_t with link and node data structures */

typedef struct node_ node_t;
typedef struct link_ link_t;



typedef struct interface_ {
    char interface_name [17];
    struct node_  *att_node;
    struct link_ *link;

}interface_t;

typedef struct link_{
    interface_t intf1;
    interface_t intf2;
    unsigned int cost;

};

typedef struct node_{
    char node_name[ NODE_NAME_SIZE];
    interface_t *intf[MAX_INTERFACES_ON_NODE];
    glthread_t graph_glue;
};

typedef struct graph_{
 char Topology_name[37];  /* To store Topology name of the graph */
 glthread_t nodelist;       /* To the glue thread double link list containing all nodes i.e routers */

}graph;

#endif
