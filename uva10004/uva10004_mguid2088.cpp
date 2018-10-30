#include <cstdio>
#include <vector>
#include <queue>

int main() {

  int num_node, num_edge, tmp_link_a, tmp_link_b ;

  while(scanf("%d\n", &num_node) > 0 && num_node) {
    std::vector<std::vector<int>> graph(num_node);
    std::vector<int> color(num_node, 2);
    bool bicolorable = true;

    scanf("%d\n", &num_edge);

    while(num_edge--) {
      scanf("%d %d\n", &tmp_link_a, &tmp_link_b);
      graph[tmp_link_a].push_back(tmp_link_b);
      graph[tmp_link_b].push_back(tmp_link_a);
    }
    std::queue<int> q;
    color[0] = 0;
    q.push(0);

    while(!q.empty() && bicolorable) {
      tmp_link_a = q.front();
      q.pop();
      for(int i = 0; i < graph[tmp_link_a].size(); ++i) {
        tmp_link_b = graph[tmp_link_a][i];
        if (color[tmp_link_b] == color[tmp_link_a]) {
          bicolorable = false;
          break;
        } else if (color[tmp_link_b] == 2) {
          color[tmp_link_b] = 1 - color[tmp_link_a];
          q.push(tmp_link_b);
        }
      }
    }
    if (bicolorable) {
      printf("BICOLORABLE.\n");
    } else {
      printf("NOT BICOLORABLE.\n");
    }
  }
}


