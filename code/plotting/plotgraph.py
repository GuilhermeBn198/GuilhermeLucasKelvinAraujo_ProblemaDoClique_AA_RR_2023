import networkx as nx
import matplotlib.pyplot as plt

def read_clq_file(file_name):
    graph = nx.Graph()
    
    with open(file_name, "r") as file:
        for line in file:
            tokens = line.strip().split()
            
            if tokens[0] == "p":
                num_vertices = int(tokens[2])
                graph.add_nodes_from(range(1, num_vertices + 1))
            elif tokens[0] == "n":
                vertex, weight = int(tokens[1]), int(tokens[2])
                graph.nodes[vertex]["weight"] = weight
            elif tokens[0] == "e":
                vertex1, vertex2 = int(tokens[1]), int(tokens[2])
                graph.add_edge(vertex1, vertex2)
    
    return graph

def plot_graph(graph):
    pos = nx.spring_layout(graph)
    nx.draw(graph, pos, with_labels=True, node_size=500, node_color="lightblue", font_size=10)
    # edge_labels = {(u, v): f"{graph.nodes[u].get('weight', '0')}, {graph.nodes[v].get('weight', '0')}" for u, v in graph.edges()}
    # nx.draw_networkx_edge_labels(graph, pos, edge_labels=edge_labels, font_size=8) # plott com peso
    # nx.draw_networkx_edge_labels(graph, pos, font_size=8)
    plt.show()

# Example usage:
graph = read_clq_file("graph.clq")
plot_graph(graph)
