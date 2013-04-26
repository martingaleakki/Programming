nodes:til 5;
edges:((0 1 1 0 0); (1 0 0 1  1); (1 0 0 1 0); (0 1 1 0 1); (0 1 0 1 0)); 	
costs:edges * (5 + 5 5 # 25?10);
{x ::costs[x;x]:0} each nodes;
costs:costs+flip costs;


dist: (100f) * (count nodes) # 1;
dist[0]:0f;
previous: -1 * (count nodes) # 1;
previous[0]:0;

visited:();

 f:{[y;u] if[edges[u;y]=1; if[dist[y] > dist[u] + costs[u;y]; dist[y]: dist[u] + costs[u;y];previous[y]:u;]]  };

 while[(count nodes)>0; 
 l:raze where dist = min dist[nodes except visited];
 u:l[0];
 nodes: nodes except u;
 visited,:u;  
 f[;u] each nodes; ]