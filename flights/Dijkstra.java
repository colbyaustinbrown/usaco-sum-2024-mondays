import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Dijkstra {
	private static class Node implements Comparable<Node> {
		Map<Node, Integer> edges = new HashMap<>();
		int value = Integer.MAX_VALUE;
		boolean visited = false;
		String name;
		
		public Node(String name) {
			this.name = name;
		}
		
		public int compareTo(Node other) {
			return value - other.value;
		}
	}
	
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		Map<String, Node> graph = new HashMap<>();
		
		for (int i = 0; i < n; i++) {
			String a = input.next();
			String b = input.next();
			int cost = input.nextInt();
			
			if (!graph.containsKey(a)) {
				graph.put(a, new Node(a));
			}
			if (!graph.containsKey(b)) {
				graph.put(b, new Node(b));
			}
			graph.get(a).edges.put(graph.get(b), cost);
		}
		
		Node start = graph.get(input.next());
		Node end = graph.get(input.next());
		
		Queue<Node> pq = new PriorityQueue<>();
		start.value = 0;
		pq.add(start);
		
		while (!pq.isEmpty()) {
			pq.add(pq.poll());
			Node node = pq.poll();
			
			// System.out.println("Looking at node " + node.name);
			
			if (node == end) {
				System.out.println(node.value);
				return;
			}
			
			for (Map.Entry<Node, Integer> edge : node.edges.entrySet()) {
				Node t = edge.getKey();
				t.value = Integer.min(t.value, node.value + edge.getValue());
				// System.out.printf("Node %s has value %d\n", t.name, t.value);
				if (!t.visited) {
					 t.visited = true;
					 pq.add(t);
				}
			}
		}
		System.out.println("No Solution");
	}
}
