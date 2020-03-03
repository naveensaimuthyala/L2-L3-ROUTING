/*
 * =====================================================================================
 *
 *       Filename:  topologies.c
 *
 *    Description:  This file contains the definition of all structures required to create a NetworkGraph
 *
 *        Version:  1.0
 *        Created:  Wednesday 22 Febrarury 2020 01:37:17  EST
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

graph_t *build_first_topo()
{



#if 0

                          +----------+
                      0/4 |          |0/0
         +----------------+   R0_re  +---------------------------+
         |                |          |                           |
         |                +----------+                           |
         |                                                       |
         |                                                       |
         |                                                       |
         |                                                       |
         |0/5                                                    |0/1
     +---+---+                                              +----+-----+
     |       |0/3                                        0/2|          |
     | R2_re +----------------------------------------------+    R1_re |
     |       |                                              |          |
     +-------+                                              +----------+

#endif

    graph_t *topo = create_new_graph(" Naveen's first Generic graph");
    node_t *R0_re = create_graph_node(topo, "R0_re");
    node_t *R1_re = create_graph_node(topo, "R1_re");
    node_t *R2_re = create_graph_node(topo, "R2_re");

    insert_link_between_two_nodes( R0_re, R1_re, "eth0/0", "eth0/1",1);
    insert_link_between_two_nodes( R1_re, R2_re, "eth0/2", "eth0/3",1);
    insert_link_between_two_nodes( R0_re, R2_re, "eth0/4", "eth0/5",1);


    return topo;
}

