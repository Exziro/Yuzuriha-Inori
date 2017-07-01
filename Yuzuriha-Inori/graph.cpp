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