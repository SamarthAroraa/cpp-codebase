#include <iostream>
#include "adjacency_list.hpp"
#include <boost/graph/labeled_graph.hpp>

int main()
{
		using namespace std;
		cout << "add_vertex():\n";
		{
			using LabeledGraph = boost::labeled_graph<boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>, string>;
			LabeledGraph g;
			const auto vd1 = g.add_vertex("123");
			const auto vd2 = g.add_vertex("123");
			cout << " string:\n";
			cout << "  " << boolalpha << (vd1 == vd2) << endl;
		}
		{
			using LabeledGraph = boost::labeled_graph<boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>, size_t>;
			LabeledGraph g;
			const auto vd1 = g.add_vertex(123);
			const auto vd2 = g.add_vertex(123);
			cout << " size_t:\n";
			cout << "  " << boolalpha << (vd1 == vd2) << endl;
		}
		cout << "insert_vertex():\n";
		{
			using LabeledGraph = boost::labeled_graph<boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>, string>;
			LabeledGraph g;
			cout << " string:\n";
			cout << "  " << boolalpha << g.insert_vertex("123").second << endl;
			cout << "  " << boolalpha << g.insert_vertex("123").second << endl;
		}
		{
			using LabeledGraph = boost::labeled_graph<boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>, size_t>;
			LabeledGraph g;
			cout << " size_t:\n";
			cout << "  " << boolalpha << g.insert_vertex(123).second << endl;
			cout << "  " << boolalpha << g.insert_vertex(123).second << endl;
		}
}