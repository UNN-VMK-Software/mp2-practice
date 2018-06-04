#include "graph.h"

WeightedEdge::WeightedEdge(int _nac_ver, int _kon_ver, float _weight) 
{
	this->kon_ver = _kon_ver;
	this->nac_ver = _nac_ver;
	this->weight = _weight;
}
//============================================================||============================================================
Graph::Graph(int vershini)
{
	if ((vershini < 0) || (vershini > maxVerticesSize))
		throw "Graph: Nepravilnoe chislo vershin";
	else
		this->vershini = vershini;
	this->rebra = vershini * (vershini - 1) / 2;
	tek_rebro = 0;
	vertices = new int[vershini];
	edges = new WeightedEdge*[rebra];
}
//============================================================||============================================================
Graph::Graph(int vershini, int rebra)
{

	if ((vershini < 0) || (vershini > maxVerticesSize))
		throw "Graph: Nepravilnoe chislo vershin";
	else
		this->vershini = vershini;

	if ((rebra < 0) || (rebra > vershini*(vershini - 1) / 2) || (rebra < vershini - 1))
	{
		throw "Graph: Nepravilnoe chislo reber";
	}
	else
		this->rebra = rebra;

	tek_rebro = 0;

	vertices = new int[vershini];
	edges = new WeightedEdge*[rebra];
}
//============================================================||============================================================
Graph::~Graph() {
	cleaner();
	delete[] edges;
	delete[] vertices;
}
//============================================================||============================================================
int Graph::searchEdge(int _nac_ver, int _kon_ver)
{
	for (int i = 0; i < tek_rebro; i++) {
		if ((edges[i]->kon_ver == _kon_ver) &&
			(edges[i]->nac_ver == _nac_ver) ||
			(edges[i]->nac_ver == _kon_ver) &&
			(edges[i]->kon_ver == _nac_ver))
			return i;
	}
	return -1;
}
//============================================================||============================================================
void Graph::generateVertices(int & nac_ver, int & kon_ver)
{
	do {
		nac_ver = rand() % vershini;
		kon_ver = rand() % vershini;
	} while ((nac_ver == kon_ver) || (searchEdge(nac_ver, kon_ver) != -1));
}
//============================================================||============================================================
float Graph::generateWeight(float minRange, float maxRange)
{
	double d = minRange;
	double c = (double)(maxRange - minRange) / RAND_MAX;
	double result = c * rand() + d;
	return result;
}
//============================================================||============================================================
void Graph::cleaner()
{
	for (int i = 0; i < tek_rebro; i++)
		delete edges[i];
}
//============================================================||============================================================
void Graph::generateGraph(float minRange, float maxRange)
{
	int nac_ver;
	int kon_ver;
	float weight;

	if (minRange > maxRange)
		throw "Invalid ranges of Graph";

	if (tek_rebro) {		// Если граф не пуст
		cleaner();
		tek_rebro = 0;
	}

	srand(time(NULL));
	for (int i = 0; i < rebra; i++) {
		generateVertices(nac_ver, kon_ver);
		weight = generateWeight(minRange, maxRange);
		edges[i] = new WeightedEdge(nac_ver, kon_ver, weight);
		tek_rebro++;
	}
}
//============================================================||============================================================
void Graph::addEdge(int nac_ver, int kon_ver, float weight)
{
	if (tek_rebro == rebra)
		throw "Graph is full";
	if (nac_ver == kon_ver)
		throw "Graph can't cycle";
	if (searchEdge(nac_ver, kon_ver) != -1)
		throw "Multiple Edges aren't allowed";
	edges[tek_rebro] = new WeightedEdge(nac_ver, kon_ver, weight);
	tek_rebro++;
}
//============================================================||============================================================
void Graph::removeEdge(int _nac_ver, int _kon_ver)
{
	int j = searchEdge(_nac_ver, _kon_ver);
	if (j == -1)
		throw "tru delete is not ex. edge";
	delete edges[j];
	edges[j] = edges[tek_rebro - 1];
	tek_rebro--;
}
//============================================================||============================================================
int Graph::getVerticesNum()
{
	return vershini;
}
//============================================================||============================================================
int Graph::getEdgeSize()
{
	return rebra;
}
//============================================================||============================================================
int Graph::getRealSize()
{
	return tek_rebro;
}
//============================================================||============================================================
WeightedEdge** Graph::getEdgeSet()
{
	if (tek_rebro == 0)
		return 0;
	return edges;
}
//============================================================||============================================================
WeightedEdge* Graph::getEdge(int j)
{
	return edges[j];
}
//============================================================||============================================================
float Graph::getWeight(int _nac_ver, int _kon_ver)
{
	int j = searchEdge(_nac_ver, _kon_ver);
	if (j == -1)
		throw "invalide edge";
	return edges[j]->weight;
}
//============================================================||============================================================
void Graph::printList()
{
	using namespace std;
	for (int i = 0; i < vershini; i++)
	{
		cout << i << " : ";
		for (int j = 0; j < tek_rebro; j++)
		{
			if (edges[j]->nac_ver == i)
				cout << edges[j]->kon_ver << '(' << edges[j]->weight << ')' << ", ";
			if (edges[j]->kon_ver == i)
				cout << edges[j]->nac_ver << '(' << edges[j]->weight << ')' << ", ";
		}
		cout << endl;
	}
}