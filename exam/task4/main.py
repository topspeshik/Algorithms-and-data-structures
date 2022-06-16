import matplotlib.pyplot as plt
import networkx as nx
import json

def draw_graph(graph):
    pos = nx.spring_layout(graph, seed=7)
    plt.figure(figsize=(100, 100))
    nx.draw_networkx_nodes(graph, pos)
    nx.draw_networkx_edges(graph, pos, graph.edges)
    nx.draw_networkx_labels(graph, pos, font_size=8)
    labels = nx.get_edge_attributes(graph, "weight")
    nx.draw_networkx_edge_labels(graph, pos, font_size=8, edge_labels=labels)


with open('railways.json') as f:
    file = f.read()
    railways = json.loads(file)
    railways = railways['data']

with open('routes.json') as f:
    file = f.read()
    routes = json.loads(file)

arr = []
for i in range(len(routes)):
    arr.append(list(routes[i].values()))

arrCode = []
for i in range(len(railways)):
    arrCode.append(railways[i]['code'])

arrCode = json.dumps(arrCode)

dictWays = {}
for i in range(len(railways)):
    dictWays[list(railways[i].values())[1]] = list(railways[i].values())[0]


graph = nx.Graph()
#graph.add_nodes_from(arrCode)
graph.add_weighted_edges_from(arr)
graph = nx.relabel_nodes(graph, dictWays)
draw_graph(graph)
#nx.draw(graph)

plt.show()





