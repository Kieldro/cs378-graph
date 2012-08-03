// ----------------------
// projects/graph/Graph.h
// Copyright (C) 2012
// Glenn P. Downing
// ----------------------

#ifndef Graph_h
#define Graph_h

// --------
// includes
#include <cassert>	// assert
#include <cstddef>	// size_t
#include <utility>	// make_pair, pair
#include <typeinfo>	// typeid
#include <vector>	// vector

#define DEBUG true

using std::cerr;
using std::endl;
using std::vector;
using std::make_pair;
using std::pair;

// -----
// Graph
class Graph {
	public:
		// --------
		// typedefs
		typedef unsigned long vertex_descriptor;
		typedef pair<vertex_descriptor, vertex_descriptor> edge_descriptor;
		typedef int* vertex_iterator;	// fix!
		typedef int* edge_iterator;	  // fix!
		typedef vector<vertex_descriptor>::const_iterator adjacency_iterator;
		typedef std::size_t vertices_size_type;
		typedef std::size_t edges_size_type;

	public:
		// ----------
		// add_vertex
		/**
		 * Add a vertex to the vertex vector
		 * Also add a new empty vector<vertex_descriptor> to the graph vector
		 * Return the added vertex value.
		 */
		friend vertex_descriptor add_vertex (Graph& graph) {	
			vertex_descriptor vertex = graph.v.size();
			graph.v.push_back(vertex);
			graph.g.push_back(vector<vertex_descriptor>());
			
			assert(graph.g.size() == graph.v.size());
			return vertex;
		}
		
		// --------
		// add_edge
		/**
		 * Add an edge to the edge vector.
		 * Add edge to corresponding vector in g
		 * Return a pair with (edge, true if added)
		 */
		friend pair<edge_descriptor, bool> add_edge (vertex_descriptor v0,
				vertex_descriptor v1, Graph& graph) {
			
			edge_descriptor ed = make_pair(v0, v1);
			bool b = false;		
			vector<edge_descriptor>::iterator it = std::find(graph.e.begin(),
				graph.e.end(), ed);
			b = it == graph.e.end();		// true if edge has not been added
			
			if(b){
				// add edge to e and g
				//if(DEBUG)cerr << "BOOYAKASHA!" << endl;
				graph.e.push_back(ed);
				graph.g[ed.first].push_back(ed.second);
			}else{
				;/*if(DEBUG)cerr << "ed found ifn e" << endl;
				if(DEBUG)cerr << "*it.first: " << it->first << endl;
				if(DEBUG)cerr << "*it.second: " << it->second << endl;
				*/
			}
			
			return make_pair(ed, b);
		}

		// -----------------
		// adjacent_vertices
		/**
		 * <your documentation>
		 */
		friend pair<adjacency_iterator, adjacency_iterator> adjacent_vertices(
				vertex_descriptor vertex, const Graph& graph) {
			
			if(DEBUG)cerr << "typeid(graph.g[vertex].begin()): "
				<< typeid(graph.g[vertex].begin()).name() << endl;
			
			adjacency_iterator b = graph.g[vertex].begin();
			adjacency_iterator e = graph.g[vertex].end();
			
			return make_pair(b, e);
		}

		// ----
		// edge
		/**
		 * <your documentation>
		 */
		friend pair<edge_descriptor, bool> edge (vertex_descriptor
				, vertex_descriptor, const Graph&) {
			// <your code>
			edge_descriptor ed;
			bool			b;
			return make_pair(ed, b);
		}

		// -----
		// edges
		/**
		 * <your documentation>
		 */
		friend pair<edge_iterator, edge_iterator> edges (const Graph&) {
			// <your code>
			edge_iterator b;
			edge_iterator e;
			return make_pair(b, e);
		}

		// ---------
		// num_edges
		/**
		 * Return the number of edges in the graph.
		 */
		friend edges_size_type num_edges (const Graph& graph) {
			edges_size_type s = graph.e.size();
			
			return s;
		}

		// ------------
		// num_vertices
		/**
		 * <your documentation>
		 */
		friend vertices_size_type num_vertices (const Graph& graph) {
			vertices_size_type s = graph.v.size();
			
			return s;
		}

		// ------
		// source
		/**
		 * <your documentation>
		 */
		friend vertex_descriptor source (edge_descriptor, const Graph&) {
			// <your code>
			vertex_descriptor v;
			return v;
		}

		// ------
		// target
		/**
		 * <your documentation>
		 */
		friend vertex_descriptor target (edge_descriptor, const Graph&) {
			// <your code>
			vertex_descriptor v;
			return v;
		}

		// ------
		// vertex
		/**
		 * <your documentation>
		 */
		friend vertex_descriptor vertex (vertices_size_type, const Graph&) {
			// <your code>
			vertex_descriptor vd;
			return vd;
		}

		// --------
		// vertices
		/**
		 * <your documentation>
		 */
		friend pair<vertex_iterator, vertex_iterator> vertices (const Graph&) {
			// <your code>
			vertex_iterator b = vertex_iterator();
			vertex_iterator e = vertex_iterator();
			return make_pair(b, e);
		}

	private:
		// ----
		// data
		vector< vector<vertex_descriptor> > g; // something like this
		vector< vertex_descriptor > v;
		vector< edge_descriptor > e;
		
		// -----
		// valid
		/**
		 * <your documentation>
		 */
		bool valid () const {
			if(g.size() != v.size())
				return false;
			return true;
		}

	public:
		// ------------
		// constructors
		/**
		 * <your documentation>
		 */
		Graph () {
			g = vector< vector<vertex_descriptor> >();
			v = vector< vertex_descriptor >();
			e = vector< edge_descriptor >();
			
			assert(valid());
		}

		// Default copy, destructor, and copy assignment
		// Graph  (const Graph<T>&);
		// ~Graph ();
		// Graph& operator = (const Graph&);
	};

// ---------
// has_cycle
/**
 * depth-first traversal
 * three colors
 * <your documentation>
 */
template <typename G>
bool has_cycle (const G& g) {
	return true;}

// ----------------
// topological_sort
/**
 * depth-first traversal
 * two colors
 * <your documentation>
 * @throws Boost's not_a_dag exception if !has_cycle()
 */
template <typename G, typename OI>
void topological_sort (const G& g, OI x) {
	*x = 2;
	++x;
	*x = 0;
	++x;
	*x = 1;
}

#endif // Graph_h
