#include "graph.h"

WeightedEdge::WeightedEdge(int _nac_ver, int _kon_ver, float _weight) 
{
	this->kon_ver = _kon_ver;
	this->nac_ver = _nac_ver;
	this->weight = _weight;
}

Graph::Graph(int _vershini)
{
	if ((_vershini < 0) || (_vershini > maxVerticesSize))
		throw "Graph: Nepravilnoe chislo vershin";
	else
		this->vershini = _vershini;
	this->rebra = _vershini * (_vershini - 1) / 2;
	tek_rebro = 0;
	vertices = new int[_vershini];
	edges = new WeightedEdge*[rebra];
}

Graph::Graph(int _vershini, int _rebra)
{
	if ((_vershini < 0) || (_vershini > maxVerticesSize))
		throw "Graph: Nepravilnoe chislo vershin";
	else
		this->vershini = _vershini;

	if ((_rebra < 0) || (_rebra > _vershini*(_vershini - 1) / 2) || (_rebra < _vershini - 1))
		throw "Graph: Nepravilnoe chislo reber";
	else
		this->rebra = _rebra;

	tek_rebro = 0;
	tek_vershina = 0;

	vertices = new int[_vershini];
	for (int i = 0; i < _vershini-1; i++) vertices[i] = -1;
	edges = new WeightedEdge*[_rebra];
}


Graph::~Graph() {
	cleaner();
	delete[] edges;
	delete[] vertices;
}


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

bool Graph::searchVershinu(int _ver)
{
	for (int i = 0; i < tek_rebro; i++) {
		if ((edges[i]->nac_ver == _ver) ||
			edges[i]->kon_ver == _ver)
			return true;
	}
	return false;
}

void Graph::addVershini(int _nac_ver, int _kon_ver)
{
	if (!searchVershinu(_nac_ver)) {
		vertices[tek_vershina] = _nac_ver;
		tek_vershina++;
	}
	if (!searchVershinu(_kon_ver)) {
		vertices[tek_vershina] = _kon_ver;
		tek_vershina++;
	}
}

void Graph::generateVertices(int & _nac_ver, int & _kon_ver)
{
	do {
		_nac_ver = rand() % vershini;
		_kon_ver = rand() % vershini;
	} while ((_nac_ver == _kon_ver) || (searchEdge(_nac_ver, _kon_ver) != -1));
}

float Graph::generateWeight(float minRange, float maxRange)
{
	double d = minRange;
	double c = (double)(maxRange - minRange) / RAND_MAX;
	double result = c * rand() + d;
	return result;
}

void Graph::cleaner()
{
	for (int i = 0; i < tek_rebro; i++)
		delete edges[i];
}

void Graph::generateGraph(float minRange, float maxRange)
{
	int nac_ver;
	int kon_ver;
	float weight;

	if (minRange > maxRange)
		throw "Graph: Invalid ranges";

	if (tek_rebro) {		// Если граф не пуст
		cleaner();
		tek_rebro = 0;
	}

	srand(time(NULL));
	for (int i = 0; i < rebra; i++) {
		generateVertices(nac_ver, kon_ver);
		weight = generateWeight(minRange, maxRange);
		edges[i] = new WeightedEdge(nac_ver, kon_ver, weight);
		addVershini(nac_ver, kon_ver);
		tek_rebro++;
	}
}


void Graph::addEdge(int _nac_ver, int _kon_ver, float _weight)
{
	if (tek_rebro == rebra)
		throw "Graph: Graph polniy";
	if (_nac_ver == _kon_ver)
		throw "Graph: Nelzya cikly";
	if (searchEdge(_nac_ver, _kon_ver) != -1)
		throw "Graph: Ne dostupni neskolko re";
	edges[tek_rebro] = new WeightedEdge(_nac_ver, _kon_ver, _weight);
	addVershini(_nac_ver, _kon_ver);
	tek_rebro++;
}

void Graph::removeEdge(int _nac_ver, int _kon_ver)
{
	int j = searchEdge(_nac_ver, _kon_ver);
	if (j == -1)
		throw "Graph: Popytka ydaleniya ne sush. rebra";
	delete edges[j];
	edges[j] = edges[tek_rebro - 1];
	tek_rebro--;
}

int Graph::getVerticesNum()
{
	return vershini;
}

int Graph::getEdgeSize()
{
	return rebra;
}

int Graph::getRealSize()
{
	return tek_rebro;
}

bool Graph::isConnectivity()
{
	for (int i = 0; i < vershini; i++)
		if (vertices[i] < 0) return false;
	return true;
}

WeightedEdge** Graph::getEdgeSet()
{
	if (tek_rebro == 0)
		return 0;
	return edges;
}

WeightedEdge* Graph::getEdge(int j)
{
	return edges[j];
}

float Graph::getWeight(int _nac_ver, int _kon_ver)
{
	int j = searchEdge(_nac_ver, _kon_ver);
	if (j == -1)
		throw "Graph: Nevernoe rebro";
	return edges[j]->weight;
}

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

void Graph::printVertices()
{
	using namespace std;
	for (int i = 0; i < vershini; i++) cout << vertices[i] << " ";
	cout << endl;
}
