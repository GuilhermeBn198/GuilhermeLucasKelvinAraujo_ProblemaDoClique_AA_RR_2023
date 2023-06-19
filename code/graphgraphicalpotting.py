#!/usr/bin/env python3
import networkx as nx
import matplotlib.pyplot as plt 

def read_graph_from_file(file_path):
    with open(file_path, 'r') as f:
        num_vertices = int(f.readline().strip())
        edges = [tuple(map(int, line.strip().split())) for line in f]

    return num_vertices, edges

def plot_graph(num_vertices, edges):
    G = nx.Graph()
    G.add_nodes_from(range(num_vertices))
    G.add_edges_from(edges)

    pos = nx.spring_layout(G)
    nx.draw(G, pos, with_labels=True, node_color='lightblue', edge_color='gray')
    plt.title('Graph Plot')
    plt.show()

file_path = 'ArquivoGrafo.txt'
num_vertices, edges = read_graph_from_file(file_path)
plot_graph(num_vertices, edges)
     