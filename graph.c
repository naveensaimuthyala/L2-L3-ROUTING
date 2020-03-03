/*
 * =====================================================================================
 *
 *       Filename:  graph.c
 *
 *    Description:  This file contains the definition of all structures required to create a NetworkGraph
 *
 *        Version:  1.0
 *        Created:  Wednesday 22 Febrarury 2020 02:17:17  EST
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

#include "graph.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>









graph_t *create_new_graph(char *topology_name)
{

graph_t *new_graph = calloc(1, sizeof(graph_t)); /* allocate memory to create new graph*/

strncpy(new_graph->Topology_name, topology_name, 37);
new_graph->Topology_name[37] = '\0';
init_glthread(&new_graph->nodelist);  /* create a data structure thread for all nodes to get added on top it */
return new_graph; 

}


node_t *create_graph_node(graph_t *topology , char *node_name)
{
    node_t *new_node = calloc(1, sizeof(node_t));

    strncpy(new_node->node_name ,node_name, NODE_NAME_SIZE );
    new_node->node_name[NODE_NAME_SIZE]= '\0';

    init_glthread( &new_node->graph_glue);
    glthread_add_next( &topology->nodelist, &new_node->graph_glue);
    return new_node;

}


void insert_link_between_two_nodes(node_t *node1, node_t *node2, char *from_if_name,char *to_if_name , int cost)
{

link_t *new_link = calloc(1, sizeof(link_t));

/* define name to interfaces of link on two sides of the link*/ 
strncpy(new_link->intf1.interface_name, from_if_name , 17); /* since interface name is defined as 17 */
new_link->intf1.interface_name[17]= '\0';
strncpy(new_link->intf2.interface_name, to_if_name , 17); /* since interface name is defined as 17 */
new_link->intf2.interface_name[17]= '\0';

/* Now define nodes attached to the interfaces of links on both sides */

new_link->intf1.att_node = node1;
new_link->intf2.att_node= node2;

/* Now define loopback or link to interface - This enables to find neighbours or move on to next neighbour */

new_link->intf1.link = new_link;
new_link->intf2.link = new_link;

/* assign cost to the link */

new_link->cost = cost;

/* Now attach interface to empty interface available on nodes */
int empty_interface_slot_index;
empty_interface_slot_index = get_node_intf_available_slot(node1);

node1->intf[empty_interface_slot_index]= &new_link->intf1;

empty_interface_slot_index = get_node_intf_available_slot(node2);

node2->intf[empty_interface_slot_index]= &new_link->intf2;


}

