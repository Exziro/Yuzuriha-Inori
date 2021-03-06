#ifndef MAIN_WTF_GARPH_H
#define MAIN_WTF_GARPH_H
#include<cstdlib>
#include<set>


namespace main_wtf_graph
{
template <class Item>
class graph
{
public:
// enum { MAXIMUN = 20; }
static const std::size_t MAXIMUN = 20;
graph():many_vetices(0) {}
size_t size() const { return many_vetices; } 
void add_vertex(const Item& label);
void add_edge(size_t source,size_t target);
bool is_edge(size_t source,size_t target) const;
void remove_edge(size_t source,size_t target);
Item& operator[](size_t vertex);
Item  operator[](size_t vertex) const;
std::set<size_t> neighbors(size_t vertex) const;
private:
bool edges[MAXIMUN][MAXIMUN];
Item labels[MAXIMUN];
std::size_t many_vetices;


};
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides size_t
#include <set>        // Provides set


namespace main_wtf_graph
{
template <class Item>
void graph<Item>::add_vertex(const Item& label)
{
size_t new_vertex_number;
size_t other_number;


assert(size() < MAXIMUN);
new_vertex_number = many_vetices;
many_vetices++;
for(other_number = 0;other_number < many_vetices; ++other_number)
{
edges[other_number][new_vertex_number] = false;
edges[new_vertex_number][other_number] = false;
}


labels[new_vertex_number] = label;


}
template <class Item>
void graph<Item>::add_edge(size_t source,size_t target)
{
if(source < many_vetices && target < many_vetices)
edges[source][target] = true;
}


template <class Item>
void graph<Item>::remove_edge(size_t source,size_t target)
{
if(source < many_vetices && target < many_vetices)
edges[source][target] = false;
}
template <class Item>
bool graph<Item>::is_edge(size_t source,size_t target) const
{
if(source < many_vetices && target < many_vetices)
return edges[source][target];

}


//template <class Item>
//Item& graph<Item>::operator[](size_t vertex)
//{
//assert(vertex < size());
//return labels[vertex];
//}
#include<iostream>
#include"graph.h"
using namespace std;
using namespace main_wtf_graph;

int main()
{
graph<double> t;


t.add_vertex(3.14);
t.add_vertex(2.17);
t.add_vertex(2.01);
t.add_edge(1,0);
t.add_edge(1,2);

set<size_t> connection;
set<size_t>::iterator it;
connection = t.neighbors(1);
for(it = connection.begin(); it!=connection.end();it++)
cout<<t[*it]<<endl;

return 0;
}